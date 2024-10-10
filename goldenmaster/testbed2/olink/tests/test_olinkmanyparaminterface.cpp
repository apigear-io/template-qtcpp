#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>

#include <QtCore>
#include <QTest>
#include "olink/olinkmanyparaminterface.h"
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/manyparaminterface.h"
#include "olink/olinkmanyparaminterfaceadapter.h"


#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/remotenode.h"
#include "olink/olinkremote.h"
#include "olink/remoteregistry.h"

TEST_CASE("Olink  testbed2 ManyParamInterface tests")
{

    ClientRegistry client_registry;
    auto clientNode = ClientNode::create(client_registry);
    auto clientManyParamInterface = std::make_shared< testbed2::OLinkManyParamInterface>();

    RemoteRegistry remote_registry;
    auto remoteNode = ApiGear::ObjectLink::RemoteNode::createRemoteNode(remote_registry);
    auto implManyParamInterface = std::make_shared< testbed2::ManyParamInterface>();
    auto serviceManyParamInterface = std::make_shared< testbed2::OLinkManyParamInterfaceAdapter>(remote_registry, implManyParamInterface.get());
    remote_registry.addSource(serviceManyParamInterface);

    remoteNode->onWrite([clientNode](std::string msg){clientNode->handleMessage(msg);});
    clientNode->onWrite([remoteNode](std::string msg){remoteNode->handleMessage(msg);});

    clientNode->registry().addSink(clientManyParamInterface);
    clientNode->linkRemote(clientManyParamInterface->olinkObjectName());
    SECTION("Test setting prop1")
    {
        bool isprop1Changed = false;
        clientManyParamInterface->connect(clientManyParamInterface.get(), &testbed2::AbstractManyParamInterface::prop1Changed, [&isprop1Changed ](auto value){isprop1Changed  = true;});
        auto test_value = 1;
        clientManyParamInterface->setProp1(test_value);
        REQUIRE(isprop1Changed  == true);
        REQUIRE(implManyParamInterface->prop1() == test_value);
        REQUIRE(clientManyParamInterface->prop1() == test_value);
    }
    SECTION("Test setting prop2")
    {
        bool isprop2Changed = false;
        clientManyParamInterface->connect(clientManyParamInterface.get(), &testbed2::AbstractManyParamInterface::prop2Changed, [&isprop2Changed ](auto value){isprop2Changed  = true;});
        auto test_value = 1;
        clientManyParamInterface->setProp2(test_value);
        REQUIRE(isprop2Changed  == true);
        REQUIRE(implManyParamInterface->prop2() == test_value);
        REQUIRE(clientManyParamInterface->prop2() == test_value);
    }
    SECTION("Test setting prop3")
    {
        bool isprop3Changed = false;
        clientManyParamInterface->connect(clientManyParamInterface.get(), &testbed2::AbstractManyParamInterface::prop3Changed, [&isprop3Changed ](auto value){isprop3Changed  = true;});
        auto test_value = 1;
        clientManyParamInterface->setProp3(test_value);
        REQUIRE(isprop3Changed  == true);
        REQUIRE(implManyParamInterface->prop3() == test_value);
        REQUIRE(clientManyParamInterface->prop3() == test_value);
    }
    SECTION("Test setting prop4")
    {
        bool isprop4Changed = false;
        clientManyParamInterface->connect(clientManyParamInterface.get(), &testbed2::AbstractManyParamInterface::prop4Changed, [&isprop4Changed ](auto value){isprop4Changed  = true;});
        auto test_value = 1;
        clientManyParamInterface->setProp4(test_value);
        REQUIRE(isprop4Changed  == true);
        REQUIRE(implManyParamInterface->prop4() == test_value);
        REQUIRE(clientManyParamInterface->prop4() == test_value);
    }
    SECTION("Test emit sig1")
    {
        bool issig1Emitted = false;

        clientManyParamInterface->connect(clientManyParamInterface.get(), &testbed2::AbstractManyParamInterface::sig1,
        [&issig1Emitted](int param1)
        {
            REQUIRE(param1 == 1);
            issig1Emitted  = true;
        });

        emit implManyParamInterface->sig1(1);
        REQUIRE(issig1Emitted  == true);
    }
    SECTION("Test emit sig2")
    {
        bool issig2Emitted = false;

        clientManyParamInterface->connect(clientManyParamInterface.get(), &testbed2::AbstractManyParamInterface::sig2,
        [&issig2Emitted](int param1, int param2)
        {
            REQUIRE(param1 == 1);
            REQUIRE(param2 == 1);
            issig2Emitted  = true;
        });

        emit implManyParamInterface->sig2(1, 1);
        REQUIRE(issig2Emitted  == true);
    }
    SECTION("Test emit sig3")
    {
        bool issig3Emitted = false;

        clientManyParamInterface->connect(clientManyParamInterface.get(), &testbed2::AbstractManyParamInterface::sig3,
        [&issig3Emitted](int param1, int param2, int param3)
        {
            REQUIRE(param1 == 1);
            REQUIRE(param2 == 1);
            REQUIRE(param3 == 1);
            issig3Emitted  = true;
        });

        emit implManyParamInterface->sig3(1, 1, 1);
        REQUIRE(issig3Emitted  == true);
    }
    SECTION("Test emit sig4")
    {
        bool issig4Emitted = false;

        clientManyParamInterface->connect(clientManyParamInterface.get(), &testbed2::AbstractManyParamInterface::sig4,
        [&issig4Emitted](int param1, int param2, int param3, int param4)
        {
            REQUIRE(param1 == 1);
            REQUIRE(param2 == 1);
            REQUIRE(param3 == 1);
            REQUIRE(param4 == 1);
            issig4Emitted  = true;
        });

        emit implManyParamInterface->sig4(1, 1, 1, 1);
        REQUIRE(issig4Emitted  == true);
    }
    SECTION("Test method func1")
    {
        [[maybe_unused]] auto result = clientManyParamInterface->func1(0);
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method func1 async")
    {
        auto resultFuture = clientManyParamInterface->func1Async(0);
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == 0);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method func2")
    {
        [[maybe_unused]] auto result = clientManyParamInterface->func2(0, 0);
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method func2 async")
    {
        auto resultFuture = clientManyParamInterface->func2Async(0, 0);
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == 0);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method func3")
    {
        [[maybe_unused]] auto result = clientManyParamInterface->func3(0, 0, 0);
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method func3 async")
    {
        auto resultFuture = clientManyParamInterface->func3Async(0, 0, 0);
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == 0);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method func4")
    {
        [[maybe_unused]] auto result = clientManyParamInterface->func4(0, 0, 0, 0);
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method func4 async")
    {
        auto resultFuture = clientManyParamInterface->func4Async(0, 0, 0, 0);
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == 0);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientNode->unlinkRemote(clientManyParamInterface->olinkObjectName());
    remote_registry.removeSource(serviceManyParamInterface->olinkObjectName());
    client_registry.removeSink(clientManyParamInterface->olinkObjectName());
}
