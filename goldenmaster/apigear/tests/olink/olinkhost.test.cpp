#pragma warning (disable: 4251) 
#pragma warning (disable: 4099) 

#include <catch2/catch.hpp>
#include <catch2/trompeloeil.hpp>

#include "private/sourceobjectmock.hpp"

#include "olink/olinkhost.h"

#include "olink/remoteregistry.h"
#include "olink/core/types.h"
#include "olink/core/protocol.h"

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

}

using namespace tests;


TEST_CASE("OLinkHost tests")
{
    // Common data.
    ApiGear::ObjectLink::RemoteRegistry registry;
    std::string objectId = "tests.sink1";
    uint16_t portNumber = 7681;
    QString localHostAddress = "127.0.0.1";
    QUrl url("ws://127.0.0.1:7681");

    nlohmann::json initProperties1 = { {"property1", "some_string1" }, { "property2",  92 }, { "property3", true } };
    nlohmann::json initProperties2 = { {"property1", "some_string2" }, { "property2",  29 }, { "property3", false } };

    std::string any_payload = "any";


    MessageStorage client1Messages;
    MessageStorage client2Messages;
    std::shared_ptr<SourceObjectMock> source1;
    std::unique_ptr<QWebSocket> clientSocket1;
    std::unique_ptr<QWebSocket> clientSocket2;

    registry.onLog([](auto /*level*/, auto msg){ std::cout << msg << std::endl; });

    source1 = std::make_shared<SourceObjectMock>();
    ALLOW_CALL(*source1, olinkObjectName()).RETURN(objectId);
    clientSocket1 = std::make_unique<QWebSocket>(QString(), QWebSocketProtocol::VersionLatest);
    clientSocket2 = std::make_unique<QWebSocket>(QString(), QWebSocketProtocol::VersionLatest);
    clientSocket1->connect(clientSocket1.get(), &QWebSocket::textMessageReceived, [&client1Messages](auto message)
    {
        client1Messages.receiveMessage(message);
    }
    );
    clientSocket1->connect(clientSocket2.get(), &QWebSocket::textMessageReceived, [&client2Messages](auto message)
    {
        client2Messages.receiveMessage(message);
    }
    );

    SECTION("Regular scenario")
   {

       std::cout << "Server creates two nodes for link messages from different sessions for same source and sends back init message. Unlink happens before server closes." << std::endl;
       ApiGear::ObjectLink::OLinkHost testHost(registry);
       testHost.listen(localHostAddress, quint16(portNumber));

       registry.addSource(source1);

       clientSocket1->open(url);
       clientSocket2->open(url);
       REQUIRE(QTest::qWaitFor([&clientSocket1](){return clientSocket1->isValid() && clientSocket1->state() == QAbstractSocket::ConnectedState;}, 100));
       REQUIRE(QTest::qWaitFor([&clientSocket2](){return clientSocket2->isValid() && clientSocket2->state() == QAbstractSocket::ConnectedState;}, 100));

       auto preparedLinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(objectId)));
       REQUIRE_CALL(*source1, olinkLinked(objectId, ANY(ApiGear::ObjectLink::IRemoteNode*)));
       REQUIRE_CALL(*source1, olinkLinked(objectId, ANY(ApiGear::ObjectLink::IRemoteNode*)));

       REQUIRE_CALL(*source1, olinkCollectProperties()).RETURN(initProperties1);
       REQUIRE_CALL(*source1, olinkCollectProperties()).RETURN(initProperties2);

       clientSocket1->sendTextMessage(preparedLinkMessage);
       clientSocket2->sendTextMessage(preparedLinkMessage);

       REQUIRE(QTest::qWaitFor([&registry, &objectId](){return registry.getNodes(objectId).size() == 2;}, 40));

       auto nodes = registry.getNodes(objectId);
       auto nodeA = nodes[0];
       auto nodeB = nodes[1];
       REQUIRE(nodeA.expired() == false);
       REQUIRE(nodeB.expired() == false);
       REQUIRE(nodeA.lock() != nodeB.lock());

       // Check that server sent init messages
       auto expectedInitMessage1 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::initMessage(objectId, initProperties1)));
       auto expectedInitMessage2 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::initMessage(objectId, initProperties2)));
       {
           auto msg1 = client1Messages.getMessage();
           auto checkReceivedMessage = msg1 == expectedInitMessage1 || msg1 == expectedInitMessage2;
           REQUIRE(checkReceivedMessage);
       }

       {
           auto msg2 = client2Messages.getMessage();
           auto checkReceivedMessage = msg2 == expectedInitMessage1 || msg2 == expectedInitMessage2;
           REQUIRE(checkReceivedMessage);
       }

       REQUIRE_CALL(*source1, olinkUnlinked(objectId));

       auto unlinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::unlinkMessage(objectId)));
       clientSocket1->sendTextMessage(unlinkMessage);

       REQUIRE(QTest::qWaitFor([&registry, &objectId](){return registry.getNodes(objectId).size() == 1;}, 100));

       nodes = registry.getNodes(objectId);
       auto node2 = nodes[0];
       REQUIRE(node2.expired() == false);
       bool nodeDidNotChanged = node2.lock() == nodeA.lock() || node2.lock() == nodeB.lock();
       REQUIRE(nodeDidNotChanged);

       REQUIRE_CALL(*source1, olinkUnlinked(objectId));
       clientSocket2->sendTextMessage(unlinkMessage);

       REQUIRE(QTest::qWaitFor([&registry, &objectId](){return registry.getNodes(objectId).size() == 0;}, 100));

       clientSocket1->close();
       clientSocket2->close();
       REQUIRE(QTest::qWaitFor([&clientSocket1](){return !clientSocket1->isValid();}, 40));
       REQUIRE(QTest::qWaitFor([&clientSocket2](){return !clientSocket2->isValid();}, 40));

   }

    SECTION("Host close before session closes. Only information about it is that client socket is not connected.")
    {
        auto testHost = std::make_unique<ApiGear::ObjectLink::OLinkHost>(registry);
        registry.addSource(source1);
        testHost->listen(localHostAddress, quint16(portNumber));
        clientSocket1->open(url);
        clientSocket2->open(url);
        REQUIRE(QTest::qWaitFor([&clientSocket1](){return clientSocket1->isValid();}, 100));
        REQUIRE(QTest::qWaitFor([&clientSocket2](){return clientSocket2->isValid();}, 100));

        auto preparedLinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(objectId)));
        REQUIRE_CALL(*source1, olinkLinked(objectId, ANY(ApiGear::ObjectLink::IRemoteNode*)));

        REQUIRE_CALL(*source1, olinkCollectProperties()).RETURN(initProperties1);

        clientSocket1->sendTextMessage(preparedLinkMessage);
        REQUIRE(QTest::qWaitFor([&registry, &objectId](){return registry.getNodes(objectId).size() == 1;}, 100));
        REQUIRE(registry.getNodes(objectId)[0].expired() == false);

        // Check that server sent init messages
        auto expectedInitMessage1 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::initMessage(objectId, initProperties1)));
        {
            auto msg1 = client1Messages.getMessage();
            REQUIRE(msg1 == expectedInitMessage1);
        }

        testHost.reset();
        REQUIRE(QTest::qWaitFor([&registry, &objectId](){return registry.getNodes(objectId).size() == 0;}, 40));
        REQUIRE(registry.getSource(objectId).lock() == source1);
        REQUIRE(QTest::qWaitFor([&clientSocket1](){return clientSocket1->state() == QAbstractSocket::UnconnectedState;}, 40));
    }


    SECTION("One of connections for same object is closed. Other connection works unaffected")
    {
        auto testHost = std::make_unique<ApiGear::ObjectLink::OLinkHost>(registry);
        testHost->listen(localHostAddress, quint16(portNumber));

        registry.addSource(source1);

        clientSocket1->open(url);
        clientSocket2->open(url);
        REQUIRE(QTest::qWaitFor([&clientSocket1](){return clientSocket1->isValid() && clientSocket1->state() == QAbstractSocket::ConnectedState;}, 100));
        REQUIRE(QTest::qWaitFor([&clientSocket2](){return clientSocket2->isValid() && clientSocket2->state() == QAbstractSocket::ConnectedState;}, 100));

        auto preparedLinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(objectId)));
        REQUIRE_CALL(*source1, olinkLinked(objectId, ANY(ApiGear::ObjectLink::IRemoteNode*)));
        REQUIRE_CALL(*source1, olinkLinked(objectId, ANY(ApiGear::ObjectLink::IRemoteNode*)));

        REQUIRE_CALL(*source1, olinkCollectProperties()).RETURN(initProperties1);
        REQUIRE_CALL(*source1, olinkCollectProperties()).RETURN(initProperties2);

        clientSocket1->sendTextMessage(preparedLinkMessage);
        clientSocket2->sendTextMessage(preparedLinkMessage);

        REQUIRE(QTest::qWaitFor([&registry, &objectId](){return registry.getNodes(objectId).size() == 2;}, 40));
        auto nodes = registry.getNodes(objectId);
        auto nodeA = nodes[0];
        auto nodeB = nodes[1];
        REQUIRE(!nodeA.expired());
        REQUIRE(!nodeB.expired());
        REQUIRE(nodeA.lock() != nodeB.lock());

        // Check that server sent init messages
        auto expectedInitMessage1 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::initMessage(objectId, initProperties1)));
        auto expectedInitMessage2 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::initMessage(objectId, initProperties2)));
        {
            auto msg1 = client1Messages.getMessage();;
            auto checkReceivedMessage = msg1 == expectedInitMessage1 || msg1 == expectedInitMessage2;
            REQUIRE(checkReceivedMessage);
        }

        {
            auto msg2 = client2Messages.getMessage();;
            auto checkReceivedMessage = msg2 == expectedInitMessage1 || msg2 == expectedInitMessage2;
            REQUIRE(checkReceivedMessage);
        }

        // START TEST
        clientSocket1->close();

        REQUIRE(QTest::qWaitFor([&registry, &objectId](){return registry.getNodes(objectId).size() == 1;}, 40));
        nodes = registry.getNodes(objectId);
        // Node 2 still works for source
        auto node2 = nodes[0];
        REQUIRE(!node2.expired());
        bool nodeDidNotChanged = node2.lock() == nodeA.lock() || node2.lock() == nodeB.lock();
        REQUIRE(nodeDidNotChanged);
        // client 2 receives close frame
        testHost.reset();
        REQUIRE(QTest::qWaitFor([&clientSocket1](){return clientSocket1->state() == QAbstractSocket::UnconnectedState;}, 40));
    }

    SECTION("Reconnection scenario, host sends init message again")
    {
        auto testHost = std::make_unique<ApiGear::ObjectLink::OLinkHost>(registry);
        registry.addSource(source1);
        testHost->listen(localHostAddress, quint16(portNumber));
        clientSocket1->open(url);
        REQUIRE(QTest::qWaitFor([&clientSocket1](){return clientSocket1->isValid();}, 150));

        auto preparedLinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(objectId)));
        REQUIRE_CALL(*source1, olinkLinked(objectId, ANY(ApiGear::ObjectLink::IRemoteNode*)));
        REQUIRE_CALL(*source1, olinkCollectProperties()).RETURN(initProperties1);
        clientSocket1->sendTextMessage(preparedLinkMessage);

        REQUIRE(QTest::qWaitFor([&registry, &objectId](){return registry.getNodes(objectId).size() == 1;}, 150));
        auto nodes = registry.getNodes(objectId);
        REQUIRE(!nodes[0].expired());

        // Check that server sent init message
        auto expectedInitMessage1 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::initMessage(objectId, initProperties1)));
        {
            auto receivedInit = client1Messages.getMessage();
            REQUIRE(receivedInit == expectedInitMessage1);
        }

        // START TEST
        clientSocket1->close();
        REQUIRE(QTest::qWaitFor([&registry, &objectId](){return registry.getNodes(objectId).size() == 0;}, 200));
        nodes = registry.getNodes(objectId);
        REQUIRE(QTest::qWaitFor([&clientSocket1](){return !clientSocket1->isValid();}, 40));

        // Open a new connection
        clientSocket1->open(url);
        REQUIRE(QTest::qWaitFor([&clientSocket1](){return clientSocket1->isValid();}, 100));

        REQUIRE_CALL(*source1, olinkLinked(objectId, ANY(ApiGear::ObjectLink::IRemoteNode*)));
        REQUIRE_CALL(*source1, olinkCollectProperties()).RETURN(initProperties1);
        clientSocket1->sendTextMessage(preparedLinkMessage);

        REQUIRE(QTest::qWaitFor([&registry, &objectId](){return registry.getNodes(objectId).size() == 1;}, 200));
        nodes = registry.getNodes(objectId);
        REQUIRE(!nodes[0].expired());

        // Check that server sent init message
        {
            auto receivedInit = client1Messages.getMessage();;
            REQUIRE(receivedInit == expectedInitMessage1);
        }

        testHost.reset();
    }
};

