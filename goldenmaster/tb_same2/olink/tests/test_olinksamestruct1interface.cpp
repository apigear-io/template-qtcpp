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

TEST_CASE("Olink  tb.same2 SameStruct1Interface tests")
{

    ClientRegistry client_registry;
    auto clientNode = ClientNode::create(client_registry);
    auto clientSameStruct1Interface = std::make_shared< tb_same2::OLinkSameStruct1Interface>();

    RemoteRegistry remote_registry;
    auto remoteNode = ApiGear::ObjectLink::RemoteNode::createRemoteNode(remote_registry);
    auto implSameStruct1Interface = std::make_shared< tb_same2::SameStruct1Interface>();
    auto serviceSameStruct1Interface = std::make_shared< tb_same2::OLinkSameStruct1InterfaceAdapter>(remote_registry, implSameStruct1Interface.get());
    remote_registry.addSource(serviceSameStruct1Interface);

    remoteNode->onWrite([clientNode](std::string msg){clientNode->handleMessage(msg);});
    clientNode->onWrite([remoteNode](std::string msg){remoteNode->handleMessage(msg);});

    clientNode->registry().addSink(clientSameStruct1Interface);
    clientNode->linkRemote(clientSameStruct1Interface->olinkObjectName());
    SECTION("Test setting prop1")
    {
        bool isprop1Changed = false;
        clientSameStruct1Interface->connect(clientSameStruct1Interface.get(), &tb_same2::AbstractSameStruct1Interface::prop1Changed, [&isprop1Changed ](auto value){isprop1Changed  = true;});
        auto test_value = tb_same2::Struct1();
        tb_same2::fillTestStruct1(test_value);
        clientSameStruct1Interface->setProp1(test_value);
        REQUIRE(isprop1Changed  == true);
        REQUIRE(implSameStruct1Interface->prop1() == test_value);
        REQUIRE(clientSameStruct1Interface->prop1() == test_value);
    }
    SECTION("Test emit sig1")
    {
        bool issig1Emitted = false;
        auto local_param1_struct = tb_same2::Struct1();
        tb_same2::fillTestStruct1(local_param1_struct);

        clientSameStruct1Interface->connect(clientSameStruct1Interface.get(), &tb_same2::AbstractSameStruct1Interface::sig1,
        [&issig1Emitted, &local_param1_struct](const tb_same2::Struct1& param1)
        {
            REQUIRE(param1 ==local_param1_struct);
            issig1Emitted  = true;
        });

        emit implSameStruct1Interface->sig1(local_param1_struct);
        REQUIRE(issig1Emitted  == true);
    }
    SECTION("Test method func1")
    {
        [[maybe_unused]] auto result = clientSameStruct1Interface->func1(tb_same2::Struct1());
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method func1 async")
    {
        auto resultFuture = clientSameStruct1Interface->func1Async(tb_same2::Struct1());
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == tb_same2::Struct1());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientNode->unlinkRemote(clientSameStruct1Interface->olinkObjectName());
    remote_registry.removeSource(serviceSameStruct1Interface->olinkObjectName());
    client_registry.removeSink(clientSameStruct1Interface->olinkObjectName());
}
