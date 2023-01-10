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
}

TEST_CASE("OlinkConnection tests")
{
    auto portNumber = 8000;
    QString localHostAddress =  "ws://127.0.0.1";
    QString localHostAddressWithPort = "ws://127.0.0.1:" + QString::fromStdString(std::to_string(portNumber));

    ApiGear::ObjectLink::ClientRegistry registry;
    auto testOlinkClient = std::make_shared<ApiGear::ObjectLink::OLinkClient>(registry);

    auto sink1 = std::make_shared<SinkObjectMock>();
    std::string sink1Id = "tests.sink1";

    MessageStorage serverReceivedMessages;
    TestServer server(serverReceivedMessages);

    ALLOW_CALL(*sink1, olinkObjectName()).RETURN(sink1Id);

    SECTION("Connect to host when sink is added and server is running. On teardown first disconnect sink then the client")
    {
        server.listen(localHostAddress, quint16(portNumber));

        testOlinkClient->connectToHost(QUrl(localHostAddressWithPort));
        testOlinkClient->linkObjectSource(sink1);

        REQUIRE(QTest::qWaitFor([&server](){return server.isSocketConnected();}, 100));

        REQUIRE(registry.getSink(sink1Id).lock() == sink1);
        // Node is available from registry when the object is linked
        REQUIRE(QTest::qWaitFor([&registry, &sink1Id](){return !registry.getNode(sink1Id).expired();}, 100));
        REQUIRE(registry.getNode(sink1Id).lock().get() == testOlinkClient->node());

        // Check that server received link message
        auto expectedLinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(sink1Id)));
        REQUIRE(serverReceivedMessages.getMessage() == expectedLinkMessage );
        

        // Send init message from server and check it is delivered and decoded
        nlohmann::json initProperties = { {"property1", "some_string" }, { "property2",  9 }, { "property3", false } };
        auto preparedInitMessage = converter.toString(ApiGear::ObjectLink::Protocol::initMessage(sink1Id, initProperties));
        REQUIRE_CALL(*sink1, olinkOnInit(sink1Id, initProperties, testOlinkClient->node()));
        server.writeMessage(preparedInitMessage);


        // Remove sink: unlink, detach from node, remove from registry.
        REQUIRE_CALL(*sink1, olinkOnRelease());
        testOlinkClient->unlinkObjectSource(sink1Id);

        REQUIRE(registry.getSink(sink1Id).lock() == nullptr);
        REQUIRE(registry.getNode(sink1Id).lock() == nullptr);

        //Check the unlink message
        auto expectedUnlinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::unlinkMessage(sink1Id)));
        REQUIRE(serverReceivedMessages.getMessage() == expectedUnlinkMessage);
        
        testOlinkClient->disconnect();
        REQUIRE(QTest::qWaitFor([&server](){return !server.isSocketConnected();}, 40));
    }

    SECTION("Add sink after connecting to host. On teardown disconnect the client from server first. ")
    {
        server.listen(localHostAddress, quint16(portNumber));
        // Connect sink
        testOlinkClient->linkObjectSource(sink1);
        QTest::qWait(100); //make sure the process event is not blocking
        REQUIRE(registry.getSink(sink1Id).lock() == sink1);
        // Node will be added to registry after it is linked - so connection needs to be established first.
        REQUIRE(registry.getNode(sink1Id).lock() == nullptr);

        // Connect to server
        testOlinkClient->connectToHost(QUrl(localHostAddressWithPort));
        REQUIRE(QTest::qWaitFor([&server](){return server.isSocketConnected();}, 100));
        // expect the link message to be received on server side
        auto expectedLinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(sink1Id)));
        REQUIRE(serverReceivedMessages.getMessage() == expectedLinkMessage);

        // Node is available from registry when the object is linked
        REQUIRE(QTest::qWaitFor([&registry, &sink1Id](){return !registry.getNode(sink1Id).expired();}, 40));
        REQUIRE(registry.getNode(sink1Id).lock().get() == testOlinkClient->node());


        // Send from server init message
        nlohmann::json initProperties = { {"property1", "some_string" }, { "property2",  9 }, { "property3", false } };
        REQUIRE_CALL(*sink1, olinkOnInit(sink1Id, initProperties, testOlinkClient->node()));
        auto preparedInitMessage = converter.toString(ApiGear::ObjectLink::Protocol::initMessage(sink1Id, initProperties));
        server.writeMessage(preparedInitMessage);
        
        // Stop connection
        REQUIRE_CALL(*sink1, olinkOnRelease());
        testOlinkClient->disconnect();

        // Sink stays in registry in case user wants to reconnect.
        REQUIRE(registry.getSink(sink1Id).lock() == sink1);
        REQUIRE(registry.getNode(sink1Id).lock() == nullptr);

        auto expectedUnlinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::unlinkMessage(sink1Id)));
        REQUIRE(serverReceivedMessages.getMessage() == expectedUnlinkMessage);

        testOlinkClient->unlinkObjectSource(sink1Id);
        REQUIRE(registry.getSink(sink1Id).lock() == nullptr);
        REQUIRE(QTest::qWaitFor([&server](){return !server.isSocketConnected();}, 40));
    }

    SECTION("Disconnect and reconnect scenario")
    {
        auto sink2 = std::make_shared<SinkObjectMock>();
        std::string sink2Id = "tests.sink2";
        ALLOW_CALL(*sink2, olinkObjectName()).RETURN(sink2Id);

        server.listen(localHostAddress, quint16(portNumber));
        testOlinkClient->linkObjectSource(sink1);
        testOlinkClient->linkObjectSource(sink2);

        // Connect to server
        testOlinkClient->connectToHost(QUrl(localHostAddressWithPort));
        QTest::qWait(100); //make sure the process event is not blocking

        auto expectedLinkMessage1 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(sink1Id)));
        auto expectedLinkMessage2 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(sink2Id)));
        {
            auto msg1 = serverReceivedMessages.getMessage();
            auto msg2 = serverReceivedMessages.getMessage();
            // expect the link message to be received on server side

            REQUIRE(checkMessageInContainer({msg1, msg2}, expectedLinkMessage1));
            REQUIRE(checkMessageInContainer({msg1, msg2}, expectedLinkMessage2));
        }

        // Disconnect
        REQUIRE_CALL(*sink1, olinkOnRelease());
        REQUIRE_CALL(*sink2, olinkOnRelease());
        testOlinkClient->disconnect();

        // Check unlink and close connection messages.

        auto expectedUnlinkMessage1 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::unlinkMessage(sink1Id)));
        auto expectedUnlinkMessage2 = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::unlinkMessage(sink2Id)));
        {
            auto msg1 = serverReceivedMessages.getMessage();
            auto msg2 = serverReceivedMessages.getMessage();

            REQUIRE(checkMessageInContainer({msg1, msg2}, expectedUnlinkMessage1));
            REQUIRE(checkMessageInContainer({msg1, msg2}, expectedUnlinkMessage2));
        }

        REQUIRE( QTest::qWaitFor([&server](){return !server.isSocketConnected();}, 100));

        // Remove sink2 during disconnected
        testOlinkClient->unlinkObjectSource(sink2Id);

        // Connect again, node sends link message only for sink1.
        testOlinkClient->connectToHost(QUrl(localHostAddressWithPort));
        REQUIRE(QTest::qWaitFor([&server](){return server.isSocketConnected();}, 100));
        REQUIRE(serverReceivedMessages.getMessage() == expectedLinkMessage1);

        //Test teardown and cleanup
        REQUIRE_CALL(*sink1, olinkOnRelease());
        testOlinkClient->unlinkObjectSource(sink1Id);
        testOlinkClient.reset();

        REQUIRE(serverReceivedMessages.getMessage() == expectedUnlinkMessage1);

        REQUIRE(QTest::qWaitFor([&server](){return !server.isSocketConnected();}, 40));
    }

    SECTION("Cleanup resources olink connection destruction.")
    {
        server.listen(localHostAddress, quint16(portNumber));
        // Connect sink
        testOlinkClient->linkObjectSource(sink1);
        REQUIRE(registry.getSink(sink1Id).lock() == sink1);


        // Connect to server
        testOlinkClient->connectToHost(QUrl(localHostAddressWithPort));
        // Wait for message to be sent with queue flush on tick, and action after sent happen.
        REQUIRE(QTest::qWaitFor([&registry, &sink1Id](){return !registry.getNode(sink1Id).expired();}, 100));
        REQUIRE(registry.getNode(sink1Id).lock().get() == testOlinkClient->node());

        // expect the link message to be received on server side
        auto expectedLinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::linkMessage(sink1Id)));
        REQUIRE(serverReceivedMessages.getMessage() == expectedLinkMessage);

        REQUIRE_CALL(*sink1, olinkOnRelease());
        testOlinkClient.reset();
        REQUIRE(registry.getSink(sink1Id).lock() == nullptr);
        REQUIRE(registry.getNode(sink1Id).lock() == nullptr);

        // Check unlink was sent
        auto expectedUnlinkMessage = QString::fromStdString(converter.toString(ApiGear::ObjectLink::Protocol::unlinkMessage(sink1Id)));

        REQUIRE(serverReceivedMessages.getMessage() == expectedUnlinkMessage);
        // Check close frame was sent
        REQUIRE(QTest::qWaitFor([&server](){return !server.isSocketConnected();}, 40));
    }
}


