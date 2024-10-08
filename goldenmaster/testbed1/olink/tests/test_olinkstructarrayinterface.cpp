#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>

#include <QtCore>
#include <QTest>
#include "olink/olinkstructarrayinterface.h"
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/structarrayinterface.h"
#include "olink/olinkstructarrayinterfaceadapter.h"


#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/remotenode.h"
#include "olink/olinkremote.h"
#include "olink/remoteregistry.h"

TEST_CASE("Olink  testbed1 StructArrayInterface tests")
{

    ClientRegistry client_registry;
    auto clientNode = ClientNode::create(client_registry);
    auto clientStructArrayInterface = std::make_shared< testbed1::OLinkStructArrayInterface>();

    RemoteRegistry remote_registry;
    auto remoteNode = ApiGear::ObjectLink::RemoteNode::createRemoteNode(remote_registry);
    auto implStructArrayInterface = std::make_shared< testbed1::StructArrayInterface>();
    auto serviceStructArrayInterface = std::make_shared< testbed1::OLinkStructArrayInterfaceAdapter>(remote_registry, implStructArrayInterface.get());
    remote_registry.addSource(serviceStructArrayInterface);

    remoteNode->onWrite([clientNode](std::string msg){clientNode->handleMessage(msg);});
    clientNode->onWrite([remoteNode](std::string msg){remoteNode->handleMessage(msg);});

    clientNode->registry().addSink(clientStructArrayInterface);
    clientNode->linkRemote(clientStructArrayInterface->olinkObjectName());
    SECTION("Test setting propBool")
    {
        bool ispropBoolChanged = false;
        clientStructArrayInterface->connect(clientStructArrayInterface.get(), &testbed1::AbstractStructArrayInterface::propBoolChanged, [&ispropBoolChanged ](auto value){ispropBoolChanged  = true;});
        auto test_value = QList<testbed1::StructBool>();
        auto element = testbed1::StructBool();
        testbed1::fillTestStructBool(element);
        test_value.append(element);
        clientStructArrayInterface->setPropBool(test_value);
        REQUIRE(ispropBoolChanged  == true);
        REQUIRE(implStructArrayInterface->propBool() == test_value);
        REQUIRE(clientStructArrayInterface->propBool() == test_value);
    }
    SECTION("Test setting propInt")
    {
        bool ispropIntChanged = false;
        clientStructArrayInterface->connect(clientStructArrayInterface.get(), &testbed1::AbstractStructArrayInterface::propIntChanged, [&ispropIntChanged ](auto value){ispropIntChanged  = true;});
        auto test_value = QList<testbed1::StructInt>();
        auto element = testbed1::StructInt();
        testbed1::fillTestStructInt(element);
        test_value.append(element);
        clientStructArrayInterface->setPropInt(test_value);
        REQUIRE(ispropIntChanged  == true);
        REQUIRE(implStructArrayInterface->propInt() == test_value);
        REQUIRE(clientStructArrayInterface->propInt() == test_value);
    }
    SECTION("Test setting propFloat")
    {
        bool ispropFloatChanged = false;
        clientStructArrayInterface->connect(clientStructArrayInterface.get(), &testbed1::AbstractStructArrayInterface::propFloatChanged, [&ispropFloatChanged ](auto value){ispropFloatChanged  = true;});
        auto test_value = QList<testbed1::StructFloat>();
        auto element = testbed1::StructFloat();
        testbed1::fillTestStructFloat(element);
        test_value.append(element);
        clientStructArrayInterface->setPropFloat(test_value);
        REQUIRE(ispropFloatChanged  == true);
        REQUIRE(implStructArrayInterface->propFloat() == test_value);
        REQUIRE(clientStructArrayInterface->propFloat() == test_value);
    }
    SECTION("Test setting propString")
    {
        bool ispropStringChanged = false;
        clientStructArrayInterface->connect(clientStructArrayInterface.get(), &testbed1::AbstractStructArrayInterface::propStringChanged, [&ispropStringChanged ](auto value){ispropStringChanged  = true;});
        auto test_value = QList<testbed1::StructString>();
        auto element = testbed1::StructString();
        testbed1::fillTestStructString(element);
        test_value.append(element);
        clientStructArrayInterface->setPropString(test_value);
        REQUIRE(ispropStringChanged  == true);
        REQUIRE(implStructArrayInterface->propString() == test_value);
        REQUIRE(clientStructArrayInterface->propString() == test_value);
    }

    clientNode->unlinkRemote(clientStructArrayInterface->olinkObjectName());
    remote_registry.removeSource(serviceStructArrayInterface->olinkObjectName());
    client_registry.removeSink(clientStructArrayInterface->olinkObjectName());
}
