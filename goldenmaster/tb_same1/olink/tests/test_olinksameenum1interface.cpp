#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>

#include <QtCore>
#include <QTest>
#include "olink/olinksameenum1interface.h"
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/sameenum1interface.h"
#include "olink/olinksameenum1interfaceadapter.h"


#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/remotenode.h"
#include "olink/olinkremote.h"
#include "olink/remoteregistry.h"

TEST_CASE("Olink  tb.same1 SameEnum1Interface tests")
{

    ClientRegistry client_registry;
    auto clientNode = ClientNode::create(client_registry);
    auto clientSameEnum1Interface = std::make_shared< tb_same1::OLinkSameEnum1Interface>();

    RemoteRegistry remote_registry;
    auto remoteNode = ApiGear::ObjectLink::RemoteNode::createRemoteNode(remote_registry);
    auto implSameEnum1Interface = std::make_shared< tb_same1::SameEnum1Interface>();
    auto serviceSameEnum1Interface = std::make_shared< tb_same1::OLinkSameEnum1InterfaceAdapter>(remote_registry, implSameEnum1Interface.get());
    remote_registry.addSource(serviceSameEnum1Interface);

    remoteNode->onWrite([clientNode](std::string msg){clientNode->handleMessage(msg);});
    clientNode->onWrite([remoteNode](std::string msg){remoteNode->handleMessage(msg);});

    clientNode->registry().addSink(clientSameEnum1Interface);
    clientNode->linkRemote(clientSameEnum1Interface->olinkObjectName());
    SECTION("Test setting prop1")
    {
        bool isprop1Changed = false;
        clientSameEnum1Interface->connect(clientSameEnum1Interface.get(), &tb_same1::AbstractSameEnum1Interface::prop1Changed, [&isprop1Changed ](auto value){isprop1Changed  = true;});
        auto test_value = tb_same1::Enum1::Value2;
        clientSameEnum1Interface->setProp1(test_value);
        REQUIRE(isprop1Changed  == true);
        REQUIRE(implSameEnum1Interface->prop1() == test_value);
        REQUIRE(clientSameEnum1Interface->prop1() == test_value);
    }
    SECTION("Test emit sig1")
    {
        bool issig1Emitted = false;

        clientSameEnum1Interface->connect(clientSameEnum1Interface.get(), &tb_same1::AbstractSameEnum1Interface::sig1,
        [&issig1Emitted](tb_same1::Enum1::Enum1Enum param1)
        {
            REQUIRE(param1 == tb_same1::Enum1::Value2);
            issig1Emitted  = true;
        });

        emit implSameEnum1Interface->sig1(tb_same1::Enum1::Value2);
        REQUIRE(issig1Emitted  == true);
    }

    clientNode->unlinkRemote(clientSameEnum1Interface->olinkObjectName());
    remote_registry.removeSource(serviceSameEnum1Interface->olinkObjectName());
    client_registry.removeSink(clientSameEnum1Interface->olinkObjectName());
}
