#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>

#include <QtCore>
#include <QTest>
#include "olink/olinkstructinterface.h"
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/structinterface.h"
#include "olink/olinkstructinterfaceadapter.h"


#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/remotenode.h"
#include "olink/olinkremote.h"
#include "olink/remoteregistry.h"

TEST_CASE("Olink  testbed1 StructInterface tests")
{

    ClientRegistry client_registry;
    auto clientNode = ClientNode::create(client_registry);
    auto clientStructInterface = std::make_shared< testbed1::OLinkStructInterface>();

    RemoteRegistry remote_registry;
    auto remoteNode = ApiGear::ObjectLink::RemoteNode::createRemoteNode(remote_registry);
    auto implStructInterface = std::make_shared< testbed1::StructInterface>();
    auto serviceStructInterface = std::make_shared< testbed1::OLinkStructInterfaceAdapter>(remote_registry, implStructInterface.get());
    remote_registry.addSource(serviceStructInterface);

    remoteNode->onWrite([clientNode](std::string msg){clientNode->handleMessage(msg);});
    clientNode->onWrite([remoteNode](std::string msg){remoteNode->handleMessage(msg);});

    clientNode->registry().addSink(clientStructInterface);
    clientNode->linkRemote(clientStructInterface->olinkObjectName());
    SECTION("Test setting propBool")
    {
        bool ispropBoolChanged = false;
        clientStructInterface->connect(clientStructInterface.get(), &testbed1::AbstractStructInterface::propBoolChanged, [&ispropBoolChanged ](auto value){ispropBoolChanged  = true;});
        auto test_value = testbed1::StructBool();
        testbed1::fillTestStructBool(test_value);
        clientStructInterface->setPropBool(test_value);
        REQUIRE(ispropBoolChanged  == true);
        REQUIRE(implStructInterface->propBool() == test_value);
        REQUIRE(clientStructInterface->propBool() == test_value);
    }
    SECTION("Test setting propInt")
    {
        bool ispropIntChanged = false;
        clientStructInterface->connect(clientStructInterface.get(), &testbed1::AbstractStructInterface::propIntChanged, [&ispropIntChanged ](auto value){ispropIntChanged  = true;});
        auto test_value = testbed1::StructInt();
        testbed1::fillTestStructInt(test_value);
        clientStructInterface->setPropInt(test_value);
        REQUIRE(ispropIntChanged  == true);
        REQUIRE(implStructInterface->propInt() == test_value);
        REQUIRE(clientStructInterface->propInt() == test_value);
    }
    SECTION("Test setting propFloat")
    {
        bool ispropFloatChanged = false;
        clientStructInterface->connect(clientStructInterface.get(), &testbed1::AbstractStructInterface::propFloatChanged, [&ispropFloatChanged ](auto value){ispropFloatChanged  = true;});
        auto test_value = testbed1::StructFloat();
        testbed1::fillTestStructFloat(test_value);
        clientStructInterface->setPropFloat(test_value);
        REQUIRE(ispropFloatChanged  == true);
        REQUIRE(implStructInterface->propFloat() == test_value);
        REQUIRE(clientStructInterface->propFloat() == test_value);
    }
    SECTION("Test setting propString")
    {
        bool ispropStringChanged = false;
        clientStructInterface->connect(clientStructInterface.get(), &testbed1::AbstractStructInterface::propStringChanged, [&ispropStringChanged ](auto value){ispropStringChanged  = true;});
        auto test_value = testbed1::StructString();
        testbed1::fillTestStructString(test_value);
        clientStructInterface->setPropString(test_value);
        REQUIRE(ispropStringChanged  == true);
        REQUIRE(implStructInterface->propString() == test_value);
        REQUIRE(clientStructInterface->propString() == test_value);
    }

    clientNode->unlinkRemote(clientStructInterface->olinkObjectName());
    remote_registry.removeSource(serviceStructInterface->olinkObjectName());
    client_registry.removeSink(clientStructInterface->olinkObjectName());
}
