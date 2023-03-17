#include "olink/iremotenode.h"
#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>
#include <catch2/trompeloeil.hpp>

#include "private/sourceobjectmock.hpp"

#include "olink/olinkhost.h"

#include "olink/core/types.h"
#include "olink/core/protocol.h"
#include "olink/iremotenode.h"
#include "olink/remoteregistry.h"

#include "private/messagestorage.h"

#include "nlohmann/json.hpp"

#include <QtWebSockets>
#include <QtCore>
#include <QTest>
#include <QThread>

#include <iostream>
#include <memory>

namespace {

// Message converter to translate messages for network format. Same should be used in tested classes.
ApiGear::ObjectLink::MessageConverter converter(ApiGear::ObjectLink::MessageFormat::JSON);

void sendTenPropertyMessages (const std::string& propertyId, int startingPropertyValue, ApiGear::ObjectLink::IRemoteNode& node)
{
    for (auto number = startingPropertyValue; number < startingPropertyValue +10; number++)
    {
        node.notifyPropertyChange(propertyId, {number});
    }
};

// Common data.
const std::string objectId = "tests.sink1";
uint16_t portNumber = 7681;
QString localHostAddress = "127.0.0.1";
QUrl url("ws://127.0.0.1:7681/ws");

nlohmann::json initProperties1 = { {"property1", "some_string1" }, { "property2",  92 }, { "property3", true } };
nlohmann::json initProperties2 = { {"property1", "some_string2" }, { "property2",  29 }, { "property3", false } };

const std::string any_payload = "any";

std::unique_ptr<QWebSocket> prepareClientSocketThatReceivesToStorage(MessageStorage& storage)
{
    auto clientSocket = std::make_unique<QWebSocket>(QString(), QWebSocketProtocol::VersionLatest);
    clientSocket->connect(clientSocket.get(), &QWebSocket::textMessageReceived, [&storage](auto message)
    {
        storage.receiveMessage(message);
    });
    return std::move(clientSocket);
}

}

using namespace tests;


TEST_CASE("OLinkHost tests")
{
    auto source1 = std::make_shared<SourceObjectMock>();
    ALLOW_CALL(*source1, olinkObjectName()).RETURN(objectId);

    MessageStorage client1Messages;
    auto clientSocket1 = std::move(prepareClientSocketThatReceivesToStorage(client1Messages));
    MessageStorage client2Messages;
    auto clientSocket2 = std::move(prepareClientSocketThatReceivesToStorage(client2Messages));

    ApiGear::ObjectLink::RemoteRegistry registry;

    SECTION("Server creates two nodes for link messages from different sessions for same source and sends back init message. Unlink happens before server closes.")
   {
       ApiGear::ObjectLink::OLinkHost testHost(registry);
       testHost.listen(localHostAddress, quint16(portNumber));
       registry.addSource(source1);

       // Connect two client nodes
       clientSocket1->open(url);
       clientSocket2->open(url);
       REQUIRE(QTest::qWaitFor([&clientSocket1](){return clientSocket1->isValid() && clientSocket1->state() == QAbstractSocket::ConnectedState;}, 100));
       REQUIRE(QTest::qWaitFor([&clientSocket2](){return clientSocket2->isValid() && clientSocket2->state() == QAbstractSocket::ConnectedState;}, 100));

       // When client nodes request linking same object
       // The server opens connections and source is informed about linking with olinkLinked method
       // And collectes current properties of source to pass them in init message.
       REQUIRE_CALL(*source1, olinkLinked(objectId, ANY(ApiGear::ObjectLink::IRemoteNode*))).TIMES(2);
       REQUIRE_CALL(*source1, olinkCollectProperties()).RETURN(initProperties1);
       REQUIRE_CALL(*source1, olinkCollectProperties()).RETURN(initProperties2);

       auto preparedLinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(objectId)));
       clientSocket1->sendTextMessage(preparedLinkMessage);
       clientSocket2->sendTextMessage(preparedLinkMessage);

       REQUIRE(QTest::qWaitFor([&registry](){return registry.getNodes(objectId).size() == 2;}, 40));
       // And the registry has node for each connection for this source
       auto nodes = registry.getNodes(objectId);
       REQUIRE(nodes[0].expired() == false);
       REQUIRE(nodes[1].expired() == false);
       REQUIRE(nodes[0].lock() != nodes[1].lock());

       // And the init messages are delivered to client, the order is not set.
       {
           auto expectedInitMessage1 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::initMessage(objectId, initProperties1)));
           auto expectedInitMessage2 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::initMessage(objectId, initProperties2)));
           auto msg1 = client1Messages.getMessage();
           auto msg2 = client2Messages.getMessage();
           REQUIRE(msg1 != msg2);
           auto checkReceivedMessage1 = msg1 == expectedInitMessage1 || msg1 == expectedInitMessage2;
           REQUIRE(checkReceivedMessage1);
           auto checkReceivedMessage2 = msg2 == expectedInitMessage1 || msg2 == expectedInitMessage2;
           REQUIRE(checkReceivedMessage2);
       }

       // When client requests unlink
       // the source is informed about it with olinkUnlinked
       REQUIRE_CALL(*source1, olinkUnlinked(objectId));

       auto unlinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::unlinkMessage(objectId)));
       clientSocket1->sendTextMessage(unlinkMessage);

       // Connection is closed and the node that handled this connection is removed from registry
       // The node for other connection still works.
       REQUIRE(QTest::qWaitFor([&registry](){return registry.getNodes(objectId).size() == 1;}, 100));
       nodes = registry.getNodes(objectId);
       REQUIRE(nodes[0].expired() == false);

       // Test cleanup - unlink second client
       REQUIRE_CALL(*source1, olinkUnlinked(objectId));
       clientSocket2->sendTextMessage(unlinkMessage);
       REQUIRE(QTest::qWaitFor([&registry](){return registry.getNodes(objectId).size() == 0;}, 100));
       // And clos connections
       clientSocket1->close();
       clientSocket2->close();
       REQUIRE(QTest::qWaitFor([&clientSocket1](){return !clientSocket1->isValid();}, 40));
       REQUIRE(QTest::qWaitFor([&clientSocket2](){return !clientSocket2->isValid();}, 40));

   }

    SECTION("Host close before session closes. Only information about it is that client socket is not connected.")
    {
        // When test server stars, with one source added
        // and a clients that linked an object
        auto testHost = std::make_unique<ApiGear::ObjectLink::OLinkHost>(registry);
        registry.addSource(source1);
        testHost->listen(localHostAddress, quint16(portNumber));
        clientSocket1->open(url);
        REQUIRE(QTest::qWaitFor([&clientSocket1](){return clientSocket1->isValid();}, 100));

        REQUIRE_CALL(*source1, olinkLinked(objectId, ANY(ApiGear::ObjectLink::IRemoteNode*)));
        REQUIRE_CALL(*source1, olinkCollectProperties()).RETURN(initProperties1);

        auto preparedLinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(objectId)));
        clientSocket1->sendTextMessage(preparedLinkMessage);
        REQUIRE(QTest::qWaitFor([&registry](){return registry.getNodes(objectId).size() == 1;}, 100));
        REQUIRE(registry.getNodes(objectId)[0].expired() == false);

        auto expectedInitMessage1 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::initMessage(objectId, initProperties1)));
        REQUIRE(client1Messages.getMessage() == expectedInitMessage1);

        // When server restarts, the source stays in registry without any node
        // There is no other information to source that there are no linked objects.
        testHost.reset();
        REQUIRE(QTest::qWaitFor([&registry](){return registry.getNodes(objectId).size() == 0;}, 40));
        REQUIRE(registry.getSource(objectId).lock() == source1);
        REQUIRE(QTest::qWaitFor([&clientSocket1](){return clientSocket1->state() == QAbstractSocket::UnconnectedState;}, 40));
    }


    SECTION("One of connections for same object is closed. Other connection works unaffected")
    {
        // When test server stars, with one source added
        // and a two clients that linked the object
        auto testHost = std::make_unique<ApiGear::ObjectLink::OLinkHost>(registry);
        testHost->listen(localHostAddress, quint16(portNumber));
        registry.addSource(source1);

        clientSocket1->open(url);
        clientSocket2->open(url);
        REQUIRE(QTest::qWaitFor([&clientSocket1](){return clientSocket1->isValid() && clientSocket1->state() == QAbstractSocket::ConnectedState;}, 100));
        REQUIRE(QTest::qWaitFor([&clientSocket2](){return clientSocket2->isValid() && clientSocket2->state() == QAbstractSocket::ConnectedState;}, 100));

        REQUIRE_CALL(*source1, olinkLinked(objectId, ANY(ApiGear::ObjectLink::IRemoteNode*))).TIMES(2);
        REQUIRE_CALL(*source1, olinkCollectProperties()).RETURN(initProperties1);
        REQUIRE_CALL(*source1, olinkCollectProperties()).RETURN(initProperties2);

        auto preparedLinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(objectId)));
        clientSocket1->sendTextMessage(preparedLinkMessage);
        clientSocket2->sendTextMessage(preparedLinkMessage);

        REQUIRE(QTest::qWaitFor([&registry](){return registry.getNodes(objectId).size() == 2;}, 40));
        auto nodes = registry.getNodes(objectId);
        REQUIRE(!nodes[0].expired());
        REQUIRE(!nodes[1].expired());
        REQUIRE(nodes[0].lock() != nodes[1].lock());

        // Check that server sent init messages
        {
            auto expectedInitMessage1 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::initMessage(objectId, initProperties1)));
            auto expectedInitMessage2 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::initMessage(objectId, initProperties2)));
            auto msg1 = client1Messages.getMessage();
            auto msg2 = client2Messages.getMessage();
            REQUIRE(msg1 != msg2);
            auto checkReceivedMessage1 = msg1 == expectedInitMessage1 || msg1 == expectedInitMessage2;
            REQUIRE(checkReceivedMessage1);
            auto checkReceivedMessage2 = msg2 == expectedInitMessage1 || msg2 == expectedInitMessage2;
            REQUIRE(checkReceivedMessage2);
        }

        // When client closes
        clientSocket1->close();

        REQUIRE(QTest::qWaitFor([&registry](){return registry.getNodes(objectId).size() == 1;}, 40));
        nodes = registry.getNodes(objectId);
        // The other client still works
        REQUIRE(!nodes[0].expired());
        // And when server restarts with linked and connected client
        // There is no other information to source or sink that there are no linked objects.
        testHost.reset();
        REQUIRE(QTest::qWaitFor([&clientSocket1](){return clientSocket1->state() == QAbstractSocket::UnconnectedState;}, 40));
    }

    SECTION("Reconnection scenario, host sends init message again")
    {
        // Start server used by one source one client.
        auto testHost = std::make_unique<ApiGear::ObjectLink::OLinkHost>(registry);
        registry.addSource(source1);
        testHost->listen(localHostAddress, quint16(portNumber));
        clientSocket1->open(url);
        REQUIRE(QTest::qWaitFor([&clientSocket1](){return clientSocket1->isValid();}, 150));
        // That is linked to the source
        REQUIRE_CALL(*source1, olinkLinked(objectId, ANY(ApiGear::ObjectLink::IRemoteNode*)));
        REQUIRE_CALL(*source1, olinkCollectProperties()).RETURN(initProperties1);
        auto preparedLinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(objectId)));
        clientSocket1->sendTextMessage(preparedLinkMessage);

        REQUIRE(QTest::qWaitFor([&registry](){return registry.getNodes(objectId).size() == 1;}, 150));
        auto nodes = registry.getNodes(objectId);
        REQUIRE(!nodes[0].expired());

        // And check that source responded with init message.
        auto expectedInitMessage1 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::initMessage(objectId, initProperties1)));
        REQUIRE(client1Messages.getMessage() == expectedInitMessage1);

        // When Client closes connection, there is no node working for it.
        clientSocket1->close();
        REQUIRE(QTest::qWaitFor([&registry](){return registry.getNodes(objectId).size() == 0;}, 200));
        REQUIRE(QTest::qWaitFor([&clientSocket1](){return !clientSocket1->isValid();}, 40));

        // And when it opens a new connection
        clientSocket1->open(url);
        REQUIRE(QTest::qWaitFor([&clientSocket1](){return clientSocket1->isValid();}, 100));

        // With re-sending link message, the source accepts again that client
        REQUIRE_CALL(*source1, olinkLinked(objectId, ANY(ApiGear::ObjectLink::IRemoteNode*)));
        REQUIRE_CALL(*source1, olinkCollectProperties()).RETURN(initProperties1);
        clientSocket1->sendTextMessage(preparedLinkMessage);

        REQUIRE(QTest::qWaitFor([&registry](){return registry.getNodes(objectId).size() == 1;}, 200));
        nodes = registry.getNodes(objectId);
        REQUIRE(!nodes[0].expired());

        // And responds with init message
        REQUIRE(client1Messages.getMessage() == expectedInitMessage1);

        testHost.reset();
    }

    SECTION("Sources that use node can be in different threads")
    {
        // Prepare sources and add them to registry
        registry.addSource(source1);
        std::string objectId2 = "objectId2";
        auto source2 = std::make_shared<SourceObjectMock>();
        ALLOW_CALL(*source2, olinkObjectName()).RETURN(objectId2);
        registry.addSource(source2);

        // Start a host with one client that links two objects for which the objects are added.
        auto testHost = std::make_unique<ApiGear::ObjectLink::OLinkHost>(registry);
        testHost->listen(localHostAddress, quint16(portNumber));
        clientSocket1->open(url);
        REQUIRE(QTest::qWaitFor([&clientSocket1](){return clientSocket1->isValid();}, 150));

        auto preparedLinkMessage1 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(objectId)));
        auto preparedLinkMessage2 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(objectId2)));
        REQUIRE_CALL(*source1, olinkLinked(objectId, ANY(ApiGear::ObjectLink::IRemoteNode*)));
        REQUIRE_CALL(*source1, olinkCollectProperties()).RETURN(initProperties1);
        REQUIRE_CALL(*source2, olinkLinked(objectId2, ANY(ApiGear::ObjectLink::IRemoteNode*)));
        REQUIRE_CALL(*source2, olinkCollectProperties()).RETURN(initProperties1);
        clientSocket1->sendTextMessage(preparedLinkMessage1);
        clientSocket1->sendTextMessage(preparedLinkMessage2);

        REQUIRE(QTest::qWaitFor([&registry](){return registry.getNodes(objectId).size() == 1;}, 150));
        auto nodes = registry.getNodes(objectId);
        auto node = nodes[0];
        REQUIRE(!node.expired());

        // Check that server responded with init message for both objects
        auto expectedInitMessage1 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::initMessage(objectId, initProperties1)));
        auto expectedInitMessage2 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::initMessage(objectId2, initProperties1)));
        {
            auto receivedInits = {client1Messages.getMessage(), client1Messages.getMessage()};
            REQUIRE(std::find(receivedInits.begin(), receivedInits.end(), expectedInitMessage1) != receivedInits.end());
            REQUIRE(std::find(receivedInits.begin(), receivedInits.end(), expectedInitMessage2) != receivedInits.end());
        }

        WHEN("Messages are sent for objects from different threads")
        {
            std::string propertyName = "property2";
            auto propertyId1 = ApiGear::ObjectLink::Name::createMemberId(objectId, propertyName);
            auto propertyId2 = ApiGear::ObjectLink::Name::createMemberId(objectId2, propertyName);
            sendTenPropertyMessages(propertyId1, 0,*(node.lock()));
            sendTenPropertyMessages(propertyId2, 0,*(node.lock()));
            QTest::qWait( 40); // add some delay between messages series
            auto ftObj1_1 = std::async(std::launch::async, [&propertyId1, &node](){sendTenPropertyMessages(propertyId1,10,*(node.lock()));});
            auto ftObj2_1 = std::async(std::launch::async, [&propertyId2, &node](){sendTenPropertyMessages(propertyId2,10,*(node.lock()));});
            auto ftObj1_2 = std::async(std::launch::async, [&propertyId1, &node](){sendTenPropertyMessages(propertyId1,20,*(node.lock()));});
            auto ftObj2_2 = std::async(std::launch::async, [&propertyId2, &node](){sendTenPropertyMessages(propertyId2,20,*(node.lock()));});
            auto ftObj1_3 = std::async(std::launch::async, [&propertyId1, &node](){sendTenPropertyMessages(propertyId1,30,*(node.lock()));});
            auto ftObj2_3 = std::async(std::launch::async, [&propertyId2, &node](){sendTenPropertyMessages(propertyId2,30,*(node.lock()));});
            THEN ("They arrive to client node")
            {
                std::vector<QString> messages;
                for (auto i = 0; i< 80; i++)
                {
                    REQUIRE(QTest::qWaitFor([&client1Messages, &messages]()
                    {
                        auto message = client1Messages.getMessage();
                        if (!message.isEmpty())
                        {
                            messages.push_back(message);
                        }
                        return !message.isEmpty();
                    }, 100));
                }
                std::cout << "client received "<< messages.size() <<" messages." << std::endl;
                for (auto i = 0; i< 40; i++)
                {
                    auto changePropertyRequest = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::propertyChangeMessage(propertyId1, {i})));
                    auto inContainer = std::find(messages.begin(), messages.end(), changePropertyRequest) != messages.end();
                    if (!inContainer) std::cout << "no message from source 1 with id " << i << std::endl;

                    REQUIRE(inContainer);
                }
                for (auto i = 0; i< 40; i++)
                {
                    auto changePropertyRequest = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::propertyChangeMessage(propertyId2, {i})));
                    auto inContainer = std::find(messages.begin(), messages.end(), changePropertyRequest) != messages.end();
                    if (!inContainer) std::cout << "no message from source 2 with id " << i << std::endl;

                    REQUIRE(inContainer);
                }
            }
        }
        testHost.reset();
    }
};

