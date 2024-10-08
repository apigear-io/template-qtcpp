#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>

#include <QtCore>
#include <QTest>
#include "olink/olinknosignalsinterface.h"
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/nosignalsinterface.h"
#include "olink/olinknosignalsinterfaceadapter.h"


#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/remotenode.h"
#include "olink/olinkremote.h"
#include "olink/remoteregistry.h"

TEST_CASE("Olink  tb.simple NoSignalsInterface tests")
{

    ClientRegistry client_registry;
    auto clientNode = ClientNode::create(client_registry);
    auto clientNoSignalsInterface = std::make_shared< tb_simple::OLinkNoSignalsInterface>();

    RemoteRegistry remote_registry;
    auto remoteNode = ApiGear::ObjectLink::RemoteNode::createRemoteNode(remote_registry);
    auto implNoSignalsInterface = std::make_shared< tb_simple::NoSignalsInterface>();
    auto serviceNoSignalsInterface = std::make_shared< tb_simple::OLinkNoSignalsInterfaceAdapter>(remote_registry, implNoSignalsInterface.get());
    remote_registry.addSource(serviceNoSignalsInterface);

    remoteNode->onWrite([clientNode](std::string msg){clientNode->handleMessage(msg);});
    clientNode->onWrite([remoteNode](std::string msg){remoteNode->handleMessage(msg);});

    clientNode->registry().addSink(clientNoSignalsInterface);
    clientNode->linkRemote(clientNoSignalsInterface->olinkObjectName());
    SECTION("Test setting propBool")
    {
        bool ispropBoolChanged = false;
        clientNoSignalsInterface->connect(clientNoSignalsInterface.get(), &tb_simple::AbstractNoSignalsInterface::propBoolChanged, [&ispropBoolChanged ](auto value){ispropBoolChanged  = true;});
        auto test_value = true;
        clientNoSignalsInterface->setPropBool(test_value);
        REQUIRE(ispropBoolChanged  == true);
        REQUIRE(implNoSignalsInterface->propBool() == test_value);
        REQUIRE(clientNoSignalsInterface->propBool() == test_value);
    }
    SECTION("Test setting propInt")
    {
        bool ispropIntChanged = false;
        clientNoSignalsInterface->connect(clientNoSignalsInterface.get(), &tb_simple::AbstractNoSignalsInterface::propIntChanged, [&ispropIntChanged ](auto value){ispropIntChanged  = true;});
        auto test_value = 1;
        clientNoSignalsInterface->setPropInt(test_value);
        REQUIRE(ispropIntChanged  == true);
        REQUIRE(implNoSignalsInterface->propInt() == test_value);
        REQUIRE(clientNoSignalsInterface->propInt() == test_value);
    }

    clientNode->unlinkRemote(clientNoSignalsInterface->olinkObjectName());
    remote_registry.removeSource(serviceNoSignalsInterface->olinkObjectName());
    client_registry.removeSink(clientNoSignalsInterface->olinkObjectName());
}
