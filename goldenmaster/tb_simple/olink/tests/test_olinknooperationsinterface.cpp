#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>

#include <QtCore>
#include <QTest>
#include "olink/olinknooperationsinterface.h"
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/nooperationsinterface.h"
#include "olink/olinknooperationsinterfaceadapter.h"


#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/remotenode.h"
#include "olink/olinkremote.h"
#include "olink/remoteregistry.h"

TEST_CASE("Olink  tb.simple NoOperationsInterface tests")
{

    ClientRegistry client_registry;
    auto clientNode = ClientNode::create(client_registry);
    auto clientNoOperationsInterface = std::make_shared< tb_simple::OLinkNoOperationsInterface>();

    RemoteRegistry remote_registry;
    auto remoteNode = ApiGear::ObjectLink::RemoteNode::createRemoteNode(remote_registry);
    auto implNoOperationsInterface = std::make_shared< tb_simple::NoOperationsInterface>();
    auto serviceNoOperationsInterface = std::make_shared< tb_simple::OLinkNoOperationsInterfaceAdapter>(remote_registry, implNoOperationsInterface.get());
    remote_registry.addSource(serviceNoOperationsInterface);

    remoteNode->onWrite([clientNode](std::string msg){clientNode->handleMessage(msg);});
    clientNode->onWrite([remoteNode](std::string msg){remoteNode->handleMessage(msg);});

    clientNode->registry().addSink(clientNoOperationsInterface);
    clientNode->linkRemote(clientNoOperationsInterface->olinkObjectName());
    SECTION("Test setting propBool")
    {
        bool ispropBoolChanged = false;
        clientNoOperationsInterface->connect(clientNoOperationsInterface.get(), &tb_simple::AbstractNoOperationsInterface::propBoolChanged, [&ispropBoolChanged ](auto value){ispropBoolChanged  = true;});
        auto test_value = true;
        clientNoOperationsInterface->setPropBool(test_value);
        REQUIRE(ispropBoolChanged  == true);
        REQUIRE(implNoOperationsInterface->propBool() == test_value);
        REQUIRE(clientNoOperationsInterface->propBool() == test_value);
    }
    SECTION("Test setting propInt")
    {
        bool ispropIntChanged = false;
        clientNoOperationsInterface->connect(clientNoOperationsInterface.get(), &tb_simple::AbstractNoOperationsInterface::propIntChanged, [&ispropIntChanged ](auto value){ispropIntChanged  = true;});
        auto test_value = 1;
        clientNoOperationsInterface->setPropInt(test_value);
        REQUIRE(ispropIntChanged  == true);
        REQUIRE(implNoOperationsInterface->propInt() == test_value);
        REQUIRE(clientNoOperationsInterface->propInt() == test_value);
    }

    clientNode->unlinkRemote(clientNoOperationsInterface->olinkObjectName());
    remote_registry.removeSource(serviceNoOperationsInterface->olinkObjectName());
    client_registry.removeSink(clientNoOperationsInterface->olinkObjectName());
}
