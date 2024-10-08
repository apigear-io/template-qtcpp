#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>

#include <QtCore>
#include <QTest>
#include "olink/olinknam_es.h"
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/nam_es.h"
#include "olink/olinknam_esadapter.h"


#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/remotenode.h"
#include "olink/olinkremote.h"
#include "olink/remoteregistry.h"

TEST_CASE("Olink  tb.names NamEs tests")
{

    ClientRegistry client_registry;
    auto clientNode = ClientNode::create(client_registry);
    auto clientNamEs = std::make_shared< tb_names::OLinkNam_Es>();

    RemoteRegistry remote_registry;
    auto remoteNode = ApiGear::ObjectLink::RemoteNode::createRemoteNode(remote_registry);
    auto implNamEs = std::make_shared< tb_names::NamEs>();
    auto serviceNamEs = std::make_shared< tb_names::OLinkNam_EsAdapter>(remote_registry, implNamEs.get());
    remote_registry.addSource(serviceNamEs);

    remoteNode->onWrite([clientNode](std::string msg){clientNode->handleMessage(msg);});
    clientNode->onWrite([remoteNode](std::string msg){remoteNode->handleMessage(msg);});

    clientNode->registry().addSink(clientNamEs);
    clientNode->linkRemote(clientNamEs->olinkObjectName());
    SECTION("Test setting Switch")
    {
        bool isSwitchChanged = false;
        clientNamEs->connect(clientNamEs.get(), &tb_names::AbstractNamEs::SwitchChanged, [&isSwitchChanged ](auto value){isSwitchChanged  = true;});
        auto test_value = true;
        clientNamEs->setSwitch(test_value);
        REQUIRE(isSwitchChanged  == true);
        REQUIRE(implNamEs->Switch() == test_value);
        REQUIRE(clientNamEs->Switch() == test_value);
    }
    SECTION("Test setting SOME_PROPERTY")
    {
        bool isSOME_PROPERTYChanged = false;
        clientNamEs->connect(clientNamEs.get(), &tb_names::AbstractNamEs::SOME_PROPERTYChanged, [&isSOME_PROPERTYChanged ](auto value){isSOME_PROPERTYChanged  = true;});
        auto test_value = 1;
        clientNamEs->setSomeProperty(test_value);
        REQUIRE(isSOME_PROPERTYChanged  == true);
        REQUIRE(implNamEs->SOME_PROPERTY() == test_value);
        REQUIRE(clientNamEs->SOME_PROPERTY() == test_value);
    }
    SECTION("Test setting Some_Poperty2")
    {
        bool isSome_Poperty2Changed = false;
        clientNamEs->connect(clientNamEs.get(), &tb_names::AbstractNamEs::Some_Poperty2Changed, [&isSome_Poperty2Changed ](auto value){isSome_Poperty2Changed  = true;});
        auto test_value = 1;
        clientNamEs->setSomePoperty2(test_value);
        REQUIRE(isSome_Poperty2Changed  == true);
        REQUIRE(implNamEs->Some_Poperty2() == test_value);
        REQUIRE(clientNamEs->Some_Poperty2() == test_value);
    }

    clientNode->unlinkRemote(clientNamEs->olinkObjectName());
    remote_registry.removeSource(serviceNamEs->olinkObjectName());
    client_registry.removeSink(clientNamEs->olinkObjectName());
}