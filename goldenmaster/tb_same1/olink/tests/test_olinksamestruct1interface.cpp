#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>

#include <QtCore>
#include <QTest>
#include "olink/olinksamestruct1interface.h"
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/samestruct1interface.h"
#include "olink/olinksamestruct1interfaceadapter.h"


#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/remotenode.h"
#include "olink/olinkremote.h"
#include "olink/remoteregistry.h"

TEST_CASE("Olink  tb.same1 SameStruct1Interface tests")
{

    ClientRegistry client_registry;
    auto clientNode = ClientNode::create(client_registry);
    auto clientSameStruct1Interface = std::make_shared< tb_same1::OLinkSameStruct1Interface>();

    RemoteRegistry remote_registry;
    auto remoteNode = ApiGear::ObjectLink::RemoteNode::createRemoteNode(remote_registry);
    auto implSameStruct1Interface = std::make_shared< tb_same1::SameStruct1Interface>();
    auto serviceSameStruct1Interface = std::make_shared< tb_same1::OLinkSameStruct1InterfaceAdapter>(remote_registry, implSameStruct1Interface.get());
    remote_registry.addSource(serviceSameStruct1Interface);

    remoteNode->onWrite([clientNode](std::string msg){clientNode->handleMessage(msg);});
    clientNode->onWrite([remoteNode](std::string msg){remoteNode->handleMessage(msg);});

    clientNode->registry().addSink(clientSameStruct1Interface);
    clientNode->linkRemote(clientSameStruct1Interface->olinkObjectName());
    SECTION("Test setting prop1")
    {
        bool isprop1Changed = false;
        clientSameStruct1Interface->connect(clientSameStruct1Interface.get(), &tb_same1::AbstractSameStruct1Interface::prop1Changed, [&isprop1Changed ](auto value){isprop1Changed  = true;});
        auto test_value = tb_same1::Struct1();
        tb_same1::fillTestStruct1(test_value);
        clientSameStruct1Interface->setProp1(test_value);
        REQUIRE(isprop1Changed  == true);
        REQUIRE(implSameStruct1Interface->prop1() == test_value);
        REQUIRE(clientSameStruct1Interface->prop1() == test_value);
    }

    clientNode->unlinkRemote(clientSameStruct1Interface->olinkObjectName());
    remote_registry.removeSource(serviceSameStruct1Interface->olinkObjectName());
    client_registry.removeSink(clientSameStruct1Interface->olinkObjectName());
}
