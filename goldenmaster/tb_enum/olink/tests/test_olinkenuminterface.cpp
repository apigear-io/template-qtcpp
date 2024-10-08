#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>

#include <QtCore>
#include <QTest>
#include "olink/olinkenuminterface.h"
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/enuminterface.h"
#include "olink/olinkenuminterfaceadapter.h"


#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/remotenode.h"
#include "olink/olinkremote.h"
#include "olink/remoteregistry.h"

TEST_CASE("Olink  tb.enum EnumInterface tests")
{

    ClientRegistry client_registry;
    auto clientNode = ClientNode::create(client_registry);
    auto clientEnumInterface = std::make_shared< tb_enum::OLinkEnumInterface>();

    RemoteRegistry remote_registry;
    auto remoteNode = ApiGear::ObjectLink::RemoteNode::createRemoteNode(remote_registry);
    auto implEnumInterface = std::make_shared< tb_enum::EnumInterface>();
    auto serviceEnumInterface = std::make_shared< tb_enum::OLinkEnumInterfaceAdapter>(remote_registry, implEnumInterface.get());
    remote_registry.addSource(serviceEnumInterface);

    remoteNode->onWrite([clientNode](std::string msg){clientNode->handleMessage(msg);});
    clientNode->onWrite([remoteNode](std::string msg){remoteNode->handleMessage(msg);});

    clientNode->registry().addSink(clientEnumInterface);
    clientNode->linkRemote(clientEnumInterface->olinkObjectName());
    SECTION("Test setting prop0")
    {
        bool isprop0Changed = false;
        clientEnumInterface->connect(clientEnumInterface.get(), &tb_enum::AbstractEnumInterface::prop0Changed, [&isprop0Changed ](auto value){isprop0Changed  = true;});
        auto test_value = tb_enum::Enum0::Value1;
        clientEnumInterface->setProp0(test_value);
        REQUIRE(isprop0Changed  == true);
        REQUIRE(implEnumInterface->prop0() == test_value);
        REQUIRE(clientEnumInterface->prop0() == test_value);
    }
    SECTION("Test setting prop1")
    {
        bool isprop1Changed = false;
        clientEnumInterface->connect(clientEnumInterface.get(), &tb_enum::AbstractEnumInterface::prop1Changed, [&isprop1Changed ](auto value){isprop1Changed  = true;});
        auto test_value = tb_enum::Enum1::Value2;
        clientEnumInterface->setProp1(test_value);
        REQUIRE(isprop1Changed  == true);
        REQUIRE(implEnumInterface->prop1() == test_value);
        REQUIRE(clientEnumInterface->prop1() == test_value);
    }
    SECTION("Test setting prop2")
    {
        bool isprop2Changed = false;
        clientEnumInterface->connect(clientEnumInterface.get(), &tb_enum::AbstractEnumInterface::prop2Changed, [&isprop2Changed ](auto value){isprop2Changed  = true;});
        auto test_value = tb_enum::Enum2::Value1;
        clientEnumInterface->setProp2(test_value);
        REQUIRE(isprop2Changed  == true);
        REQUIRE(implEnumInterface->prop2() == test_value);
        REQUIRE(clientEnumInterface->prop2() == test_value);
    }
    SECTION("Test setting prop3")
    {
        bool isprop3Changed = false;
        clientEnumInterface->connect(clientEnumInterface.get(), &tb_enum::AbstractEnumInterface::prop3Changed, [&isprop3Changed ](auto value){isprop3Changed  = true;});
        auto test_value = tb_enum::Enum3::Value2;
        clientEnumInterface->setProp3(test_value);
        REQUIRE(isprop3Changed  == true);
        REQUIRE(implEnumInterface->prop3() == test_value);
        REQUIRE(clientEnumInterface->prop3() == test_value);
    }

    clientNode->unlinkRemote(clientEnumInterface->olinkObjectName());
    remote_registry.removeSource(serviceEnumInterface->olinkObjectName());
    client_registry.removeSink(clientEnumInterface->olinkObjectName());
}
