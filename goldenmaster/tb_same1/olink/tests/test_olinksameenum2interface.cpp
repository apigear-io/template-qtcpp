#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>

#include <QtCore>
#include <QTest>
#include "olink/olinksameenum2interface.h"
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/sameenum2interface.h"
#include "olink/olinksameenum2interfaceadapter.h"


#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/remotenode.h"
#include "olink/olinkremote.h"
#include "olink/remoteregistry.h"

TEST_CASE("Olink  tb.same1 SameEnum2Interface tests")
{

    ClientRegistry client_registry;
    auto clientNode = ClientNode::create(client_registry);
    auto clientSameEnum2Interface = std::make_shared< tb_same1::OLinkSameEnum2Interface>();

    RemoteRegistry remote_registry;
    auto remoteNode = ApiGear::ObjectLink::RemoteNode::createRemoteNode(remote_registry);
    auto implSameEnum2Interface = std::make_shared< tb_same1::SameEnum2Interface>();
    auto serviceSameEnum2Interface = std::make_shared< tb_same1::OLinkSameEnum2InterfaceAdapter>(remote_registry, implSameEnum2Interface.get());
    remote_registry.addSource(serviceSameEnum2Interface);

    remoteNode->onWrite([clientNode](std::string msg){clientNode->handleMessage(msg);});
    clientNode->onWrite([remoteNode](std::string msg){remoteNode->handleMessage(msg);});

    clientNode->registry().addSink(clientSameEnum2Interface);
    clientNode->linkRemote(clientSameEnum2Interface->olinkObjectName());
    SECTION("Test setting prop1")
    {
        bool isprop1Changed = false;
        clientSameEnum2Interface->connect(clientSameEnum2Interface.get(), &tb_same1::AbstractSameEnum2Interface::prop1Changed, [&isprop1Changed ](auto value){isprop1Changed  = true;});
        auto test_value = tb_same1::Enum1::Value2;
        clientSameEnum2Interface->setProp1(test_value);
        REQUIRE(isprop1Changed  == true);
        REQUIRE(implSameEnum2Interface->prop1() == test_value);
        REQUIRE(clientSameEnum2Interface->prop1() == test_value);
    }
    SECTION("Test setting prop2")
    {
        bool isprop2Changed = false;
        clientSameEnum2Interface->connect(clientSameEnum2Interface.get(), &tb_same1::AbstractSameEnum2Interface::prop2Changed, [&isprop2Changed ](auto value){isprop2Changed  = true;});
        auto test_value = tb_same1::Enum2::Value2;
        clientSameEnum2Interface->setProp2(test_value);
        REQUIRE(isprop2Changed  == true);
        REQUIRE(implSameEnum2Interface->prop2() == test_value);
        REQUIRE(clientSameEnum2Interface->prop2() == test_value);
    }
    SECTION("Test emit sig1")
    {
        bool issig1Emitted = false;

        clientSameEnum2Interface->connect(clientSameEnum2Interface.get(), &tb_same1::AbstractSameEnum2Interface::sig1,
        [&issig1Emitted](tb_same1::Enum1::Enum1Enum param1)
        {
            REQUIRE(param1 == tb_same1::Enum1::Value2);
            issig1Emitted  = true;
        });

        emit implSameEnum2Interface->sig1(tb_same1::Enum1::Value2);
        REQUIRE(issig1Emitted  == true);
    }
    SECTION("Test emit sig2")
    {
        bool issig2Emitted = false;

        clientSameEnum2Interface->connect(clientSameEnum2Interface.get(), &tb_same1::AbstractSameEnum2Interface::sig2,
        [&issig2Emitted](tb_same1::Enum1::Enum1Enum param1, tb_same1::Enum2::Enum2Enum param2)
        {
            REQUIRE(param1 == tb_same1::Enum1::Value2);
            REQUIRE(param2 == tb_same1::Enum2::Value2);
            issig2Emitted  = true;
        });

        emit implSameEnum2Interface->sig2(tb_same1::Enum1::Value2, tb_same1::Enum2::Value2);
        REQUIRE(issig2Emitted  == true);
    }
    SECTION("Test method func1")
    {
        [[maybe_unused]] auto result = clientSameEnum2Interface->func1(tb_same1::Enum1::Value1);
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method func1 async")
    {
        auto resultFuture = clientSameEnum2Interface->func1Async(tb_same1::Enum1::Value1);
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == tb_same1::Enum1::Value1);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method func2")
    {
        [[maybe_unused]] auto result = clientSameEnum2Interface->func2(tb_same1::Enum1::Value1, tb_same1::Enum2::Value1);
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method func2 async")
    {
        auto resultFuture = clientSameEnum2Interface->func2Async(tb_same1::Enum1::Value1, tb_same1::Enum2::Value1);
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == tb_same1::Enum1::Value1);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientNode->unlinkRemote(clientSameEnum2Interface->olinkObjectName());
    remote_registry.removeSource(serviceSameEnum2Interface->olinkObjectName());
    client_registry.removeSink(clientSameEnum2Interface->olinkObjectName());
}
