#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>
#include <catch2/trompeloeil.hpp>

#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/core/types.h"
#include "olink/core/protocol.h"

#include "private/sinkobjectmock.hpp"

#include "olink/olinkclient.h"

#include "private/messagestorage.h"
#include "private/test_server/testserver.h"
#include <iostream>

#include <QtCore>
#include <QTest>

#include "nlohmann/json.hpp"
#include <algorithm>


using namespace tests;

namespace {

// Message converter to translate messages for network format. Same should be used in tested classes.
ApiGear::ObjectLink::MessageConverter converter(ApiGear::ObjectLink::MessageFormat::JSON);

bool checkMessageInContainer(const std::vector<QString>& container, const QString& payload)
{
   return std::find_if(container.begin(),
                       container.end(),
                       [&payload](auto& element){return element == payload; })
       != container.end();
}

auto portNumber = 8000;
QString localHostAddress =  "ws://127.0.0.1";
QString localHostAddressWithPort = "ws://127.0.0.1:" + QString::fromStdString(std::to_string(portNumber)) + QString("/ws");
const std::string sink1Id = "tests.sink1";
const std::string sink2Id = "tests.sink2";
nlohmann::json initProperties = { {"property1", "some_string" }, { "property2",  9 }, { "property3", false } };
}

TEST_CASE("OlinkConnection tests")
{

    auto sink1 = std::make_shared<SinkObjectMock>();
    ALLOW_CALL(*sink1, olinkObjectName()).RETURN(sink1Id);

    auto sink2 = std::make_shared<SinkObjectMock>();
    ALLOW_CALL(*sink2, olinkObjectName()).RETURN(sink2Id);

    // Given a running server
    MessageStorage serverReceivedMessages;
    TestServer server(serverReceivedMessages);
    server.listen(localHostAddress, quint16(portNumber));
    //And a test client that created with empty registry
    ApiGear::ObjectLink::ClientRegistry registry;
    auto testOlinkClient = std::make_shared<ApiGear::ObjectLink::OLinkClient>(registry);

    SECTION("Client node connects to host before the object is linked. On teardown first disconnect sink then the client")
    {
        testOlinkClient->connectToHost(QUrl(localHostAddressWithPort));

        REQUIRE(QTest::qWaitFor([&server](){return server.isSocketConnected();}, 100));
        testOlinkClient->linkObjectSource(sink1);
        REQUIRE(registry.getSink(sink1Id).lock() == sink1);

        // Node is available from registry when the object is linked
        REQUIRE(QTest::qWaitFor([&registry](){return !registry.getNode(sink1Id).expired();}, 100));
        REQUIRE(registry.getNode(sink1Id).lock().get() == testOlinkClient->node());

        // And server received link message
        auto expectedLinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(sink1Id)));
        REQUIRE(serverReceivedMessages.getMessage() == expectedLinkMessage );

        // When server sends init message from server, the source gests initalized with init properties and a client node
        auto preparedInitMessage = converter.toString(ApiGear::ObjectLink::Protocol::initMessage(sink1Id, initProperties));
        REQUIRE_CALL(*sink1, olinkOnInit(sink1Id, initProperties, testOlinkClient->node()));
        server.writeMessage(preparedInitMessage);

        // When object is unlinked, the sink gets information that link was released, and the registry
        // does't contain neither the sink nor the node for unlinked this objectId
        REQUIRE_CALL(*sink1, olinkOnRelease());
        testOlinkClient->unlinkObjectSource(sink1Id);
        REQUIRE(registry.getSink(sink1Id).lock() == nullptr);
        REQUIRE(registry.getNode(sink1Id).lock() == nullptr);
        // And the server receives unlink message
        auto expectedUnlinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::unlinkMessage(sink1Id)));
        REQUIRE(serverReceivedMessages.getMessage() == expectedUnlinkMessage);

        testOlinkClient->disconnect();
        REQUIRE(QTest::qWaitFor([&server](){return !server.isSocketConnected();}, 40));
    }

    SECTION("Client node connects to host after the object is linked. On teardown client node disconnects befor unlink.")
    {
        testOlinkClient->linkObjectSource(sink1);
        QTest::qWait(100); //make sure the process event is not blocking
        // The registry contains the sink
        // But node is not added yet/
        REQUIRE(registry.getSink(sink1Id).lock() == sink1);
        REQUIRE(registry.getNode(sink1Id).lock() == nullptr);

        // When client establishes connection
        testOlinkClient->connectToHost(QUrl(localHostAddressWithPort));
        REQUIRE(QTest::qWaitFor([&server](){return server.isSocketConnected();}, 100));
        // The server receives link message
        auto expectedLinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(sink1Id)));
        REQUIRE(serverReceivedMessages.getMessage() == expectedLinkMessage);
        // And the node is available in registry.
        REQUIRE(QTest::qWaitFor([&registry](){return !registry.getNode(sink1Id).expired();}, 40));
        REQUIRE(registry.getNode(sink1Id).lock().get() == testOlinkClient->node());

        // When server sends init message from server, the source gests initalized with init properties and a client node
        REQUIRE_CALL(*sink1, olinkOnInit(sink1Id, initProperties, testOlinkClient->node()));
        auto preparedInitMessage = converter.toString(ApiGear::ObjectLink::Protocol::initMessage(sink1Id, initProperties));
        server.writeMessage(preparedInitMessage);

        // When client disconnects with linked sinks, sink is informed about link release
        REQUIRE_CALL(*sink1, olinkOnRelease());
        testOlinkClient->disconnect();

        // Sink stays in registry in case user wants to reconnect.
        REQUIRE(registry.getSink(sink1Id).lock() == sink1);
        REQUIRE(registry.getNode(sink1Id).lock() == nullptr);

        // And server receives unlink message.
        auto expectedUnlinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::unlinkMessage(sink1Id)));
        REQUIRE(serverReceivedMessages.getMessage() == expectedUnlinkMessage);

        // When object is then unlinked, there is no duplicated information about link release or unlink sent to server
        testOlinkClient->unlinkObjectSource(sink1Id);
        // And registry is cleaned up
        REQUIRE(registry.getSink(sink1Id).lock() == nullptr);
        REQUIRE(QTest::qWaitFor([&server](){return !server.isSocketConnected();}, 40));
    }

    SECTION("Disconnect and reconnect scenario for two sinks, from which one is unlinked during disconnected time.")
    {
        // Given test client with two sinks linked
        testOlinkClient->linkObjectSource(sink1);
        testOlinkClient->linkObjectSource(sink2);
        testOlinkClient->connectToHost(QUrl(localHostAddressWithPort));
        QTest::qWait(100); //make sure the process event is not blocking

        auto expectedLinkMessage1 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(sink1Id)));
        auto expectedLinkMessage2 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(sink2Id)));
        {
            auto msg1 = serverReceivedMessages.getMessage();
            auto msg2 = serverReceivedMessages.getMessage();
            REQUIRE(checkMessageInContainer({msg1, msg2}, expectedLinkMessage1));
            REQUIRE(checkMessageInContainer({msg1, msg2}, expectedLinkMessage2));
        }

        // When client disconnects, sinks get informed about link released and server gets the unlink message.
        REQUIRE_CALL(*sink1, olinkOnRelease());
        REQUIRE_CALL(*sink2, olinkOnRelease());
        testOlinkClient->disconnect();

        auto expectedUnlinkMessage1 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::unlinkMessage(sink1Id)));
        auto expectedUnlinkMessage2 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::unlinkMessage(sink2Id)));
        {
            auto msg1 = serverReceivedMessages.getMessage();
            auto msg2 = serverReceivedMessages.getMessage();

            REQUIRE(checkMessageInContainer({msg1, msg2}, expectedUnlinkMessage1));
            REQUIRE(checkMessageInContainer({msg1, msg2}, expectedUnlinkMessage2));
        }

        REQUIRE( QTest::qWaitFor([&server](){return !server.isSocketConnected();}, 100));

        // And sink2 is unlikend
        testOlinkClient->unlinkObjectSource(sink2Id);

        // And when client connects again
        testOlinkClient->connectToHost(QUrl(localHostAddressWithPort));
        REQUIRE(QTest::qWaitFor([&server](){return server.isSocketConnected();}, 100));
        // Then client node sends link message only for sink1.
        REQUIRE(serverReceivedMessages.getMessage() == expectedLinkMessage1);

        // Test teardown and cleanup
        REQUIRE_CALL(*sink1, olinkOnRelease());
        testOlinkClient->unlinkObjectSource(sink1Id);
        testOlinkClient.reset();

        REQUIRE(serverReceivedMessages.getMessage() == expectedUnlinkMessage1);
        REQUIRE(QTest::qWaitFor([&server](){return !server.isSocketConnected();}, 40));
    }

    SECTION("Cleanup resources olink connection destruction.")
    {
        // Given a sink linked to object on server side
        testOlinkClient->linkObjectSource(sink1);
        REQUIRE(registry.getSink(sink1Id).lock() == sink1);
        testOlinkClient->connectToHost(QUrl(localHostAddressWithPort));
        REQUIRE(QTest::qWaitFor([&registry](){return !registry.getNode(sink1Id).expired();}, 100));
        REQUIRE(registry.getNode(sink1Id).lock().get() == testOlinkClient->node());
        auto expectedLinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(sink1Id)));
        REQUIRE(serverReceivedMessages.getMessage() == expectedLinkMessage);

        // When OlinkClient ir deleted
        // Sink is informed about the link release, registry is cleaned
        REQUIRE_CALL(*sink1, olinkOnRelease());
        testOlinkClient.reset();
        REQUIRE(registry.getSink(sink1Id).lock() == nullptr);
        REQUIRE(registry.getNode(sink1Id).lock() == nullptr);
        // And server receives the unlink message
        auto expectedUnlinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::unlinkMessage(sink1Id)));
        REQUIRE(serverReceivedMessages.getMessage() == expectedUnlinkMessage);
        REQUIRE(QTest::qWaitFor([&server](){return !server.isSocketConnected();}, 40));
    }
}



TEST_CASE("Connection closed for client from server side tests")
{
    //GIVEN OlinkClient with a sink linked to an object on server side
    //Sink mock
    auto sink1 = std::make_shared<SinkObjectMock>();
    ALLOW_CALL(*sink1, olinkObjectName()).RETURN(sink1Id);
    // Ready server
    MessageStorage serverReceivedMessages;
    TestServer server(serverReceivedMessages);
    server.listen(localHostAddress, quint16(portNumber));
    // test client with a connection estblished
    ApiGear::ObjectLink::ClientRegistry registry;
    auto testOlinkClient = std::make_shared<ApiGear::ObjectLink::OLinkClient>(registry);
    testOlinkClient->connectToHost(QUrl(localHostAddressWithPort));
    testOlinkClient->linkObjectSource(sink1);

    REQUIRE(registry.getSink(sink1Id).lock() == sink1);
    REQUIRE(QTest::qWaitFor([&registry](){return !registry.getNode(sink1Id).expired();}, 200));
    REQUIRE(registry.getNode(sink1Id).lock().get() == testOlinkClient->node());

    auto expectedLinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(sink1Id)));
    REQUIRE(serverReceivedMessages.getMessage() == expectedLinkMessage);

    // When server sends init message from server, the source gests initalized with init properties and a client node
    REQUIRE_CALL(*sink1, olinkOnInit(sink1Id, initProperties, testOlinkClient->node()));
    auto preparedInitMessage = converter.toString(ApiGear::ObjectLink::Protocol::initMessage(sink1Id, initProperties));
    server.writeMessage(preparedInitMessage);
    QTest::qWait(100);// Wait for init message to be delivered and handled before the sink will be released

    SECTION("Server stops connection. During that time socket wants to unlink - connection will be reestablished and unlik will be send after link message")
    {
        WHEN("Connection is closed from socket side after that client wants to send a message")
        {
            server.closeSocket();
            REQUIRE(QTest::qWaitFor([&testOlinkClient](){return testOlinkClient->getConnectionState() == QAbstractSocket::UnconnectedState;}, 200));

            auto propertyId = ApiGear::ObjectLink::Name::createMemberId(sink1Id, "propertyName");
            testOlinkClient->node()->setRemoteProperty(propertyId, { "someValue" });

            THEN("connection should be re-established and server should receive both unlink and link message")
            {
                QString msg = {};
                REQUIRE(QTest::qWaitFor([&msg, &serverReceivedMessages](){msg = serverReceivedMessages.getMessage(); return !msg.isEmpty();}, 1400));
                auto changePropertyRequest = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::setPropertyMessage(propertyId, { "someValue"})));
                REQUIRE(msg == changePropertyRequest);
                REQUIRE(serverReceivedMessages.getMessage() == expectedLinkMessage);
            }
        }
        // Test cleanup
       REQUIRE_CALL(*sink1, olinkOnRelease());
       testOlinkClient->disconnect();

       auto expectedUnlinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::unlinkMessage(sink1Id)));
       REQUIRE(serverReceivedMessages.getMessage() == expectedUnlinkMessage);

       REQUIRE(QTest::qWaitFor([&server](){return !server.isSocketConnected();}, 100));
    }

    SECTION("Messages send during disconnected time are queued and send  when connection is back, along with the link message. Some messages are sent before the link message.")
    {
        WHEN("Connection is closed from socket side")
        {
            server.closeSocket();

            REQUIRE(QTest::qWaitFor([&testOlinkClient](){return testOlinkClient->getConnectionState() == QAbstractSocket::UnconnectedState;}, 200));
            AND_WHEN ("Messages are sent during the not connected time")
            {
                auto propertyName = "property2";
                auto propertyId = ApiGear::ObjectLink::Name::createMemberId(sink1Id, propertyName);
                auto node = testOlinkClient->node();

                auto sendTenSetPropertyMessages = [&propertyId, node](int startingPropertyValue)
                {
                    for (auto number = startingPropertyValue; number < startingPropertyValue +10; number++)
                    {
                        node->setRemoteProperty(propertyId, { number });
                    }
                };
                sendTenSetPropertyMessages(0);
                QTest::qWait( 40); // add some delay between messages series
                auto future1 = std::async(std::launch::async, [sendTenSetPropertyMessages](){sendTenSetPropertyMessages(10);});
                auto future2 = std::async(std::launch::async, [sendTenSetPropertyMessages](){sendTenSetPropertyMessages(20);});
                auto future3 = std::async(std::launch::async, [sendTenSetPropertyMessages](){sendTenSetPropertyMessages(30);});
                QTest::qWait( 40); // add some delay between messages series
                auto future4 = std::async(std::launch::async, [sendTenSetPropertyMessages](){sendTenSetPropertyMessages(40);});
                auto future5 = std::async(std::launch::async, [sendTenSetPropertyMessages](){sendTenSetPropertyMessages(50);});
                auto future6 = std::async(std::launch::async, [sendTenSetPropertyMessages](){sendTenSetPropertyMessages(60);});
                auto future7 = std::async(std::launch::async, [sendTenSetPropertyMessages](){sendTenSetPropertyMessages(70);});
                QTest::qWait(100);
            THEN ("Connection is re-established due to messages waiting to be sent and messages will be received on server side")
            {
                // wait for re-connection
                REQUIRE(QTest::qWaitFor([&server](){return server.isSocketConnected();}, 1200));
                std::vector<QString> messages;
                for (auto i = 0; i< 81; i++)
                {
                    for (size_t i = 0; i < 25; i++)
                    {
                        QCoreApplication::processEvents();
                    }
                    auto message = serverReceivedMessages.getMessage();
                    if (!message.isEmpty())
                    {
                        messages.push_back(message);
                    }
                }
                for (auto i = 0; i< 80; i++)
                {
                    auto changePropertyRequest = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::setPropertyMessage(propertyId, {i})));
                    REQUIRE(checkMessageInContainer(messages, changePropertyRequest));
                }

                REQUIRE(checkMessageInContainer(messages, expectedLinkMessage));
                // The link message is not first neither the last, so there will be some messages that reach the server before client is linked.
                // They won't be processed by server.
                REQUIRE(messages[0] !=  expectedLinkMessage);
                REQUIRE(messages[messages.size()-1] != expectedLinkMessage);
                }
            }
        }
       // Test cleanup
       REQUIRE_CALL(*sink1, olinkOnRelease());
       testOlinkClient->disconnect();
       QTest::qWait(100);

       auto expectedUnlinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::unlinkMessage(sink1Id)));
       REQUIRE(serverReceivedMessages.getMessage() == expectedUnlinkMessage);
       REQUIRE(QTest::qWaitFor([&server](){return !server.isSocketConnected();}, 100));
    }
}
