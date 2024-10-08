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

    clientNode->unlinkRemote(clientManyParamInterface->olinkObjectName());
    remote_registry.removeSource(serviceManyParamInterface->olinkObjectName());
    client_registry.removeSink(clientManyParamInterface->olinkObjectName());
}
