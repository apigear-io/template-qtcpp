#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>

#include <QtCore>
#include <QTest>
#include "olink/olinksamestruct2interface.h"
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/samestruct2interface.h"
#include "olink/olinksamestruct2interfaceadapter.h"


#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/remotenode.h"
#include "olink/olinkremote.h"
#include "olink/remoteregistry.h"

TEST_CASE("Olink  tb.same1 SameStruct2Interface tests")
{

    ClientRegistry client_registry;
    auto clientNode = ClientNode::create(client_registry);
    auto clientSameStruct2Interface = std::make_shared< tb_same1::OLinkSameStruct2Interface>();

    RemoteRegistry remote_registry;
    auto remoteNode = ApiGear::ObjectLink::RemoteNode::createRemoteNode(remote_registry);
    auto implSameStruct2Interface = std::make_shared< tb_same1::SameStruct2Interface>();
    auto serviceSameStruct2Interface = std::make_shared< tb_same1::OLinkSameStruct2InterfaceAdapter>(remote_registry, implSameStruct2Interface.get());
    remote_registry.addSource(serviceSameStruct2Interface);

    remoteNode->onWrite([clientNode](std::string msg){clientNode->handleMessage(msg);});
    clientNode->onWrite([remoteNode](std::string msg){remoteNode->handleMessage(msg);});

    clientNode->registry().addSink(clientSameStruct2Interface);
    clientNode->linkRemote(clientSameStruct2Interface->olinkObjectName());
    SECTION("Test setting prop1")
    {
        bool isprop1Changed = false;
        clientSameStruct2Interface->connect(clientSameStruct2Interface.get(), &tb_same1::AbstractSameStruct2Interface::prop1Changed, [&isprop1Changed ](auto value){isprop1Changed  = true;});
        auto test_value = tb_same1::Struct2();
        tb_same1::fillTestStruct2(test_value);
        clientSameStruct2Interface->setProp1(test_value);
        REQUIRE(isprop1Changed  == true);
        REQUIRE(implSameStruct2Interface->prop1() == test_value);
        REQUIRE(clientSameStruct2Interface->prop1() == test_value);
    }
    SECTION("Test setting prop2")
    {
        bool isprop2Changed = false;
        clientSameStruct2Interface->connect(clientSameStruct2Interface.get(), &tb_same1::AbstractSameStruct2Interface::prop2Changed, [&isprop2Changed ](auto value){isprop2Changed  = true;});
        auto test_value = tb_same1::Struct2();
        tb_same1::fillTestStruct2(test_value);
        clientSameStruct2Interface->setProp2(test_value);
        REQUIRE(isprop2Changed  == true);
        REQUIRE(implSameStruct2Interface->prop2() == test_value);
        REQUIRE(clientSameStruct2Interface->prop2() == test_value);
    }

    clientNode->unlinkRemote(clientSameStruct2Interface->olinkObjectName());
    remote_registry.removeSource(serviceSameStruct2Interface->olinkObjectName());
    client_registry.removeSink(clientSameStruct2Interface->olinkObjectName());
}
