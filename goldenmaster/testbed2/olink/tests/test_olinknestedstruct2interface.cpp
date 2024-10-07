#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>

#include <QtCore>
#include <QTest>
#include "olink/olinknestedstruct2interface.h"
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/nestedstruct2interface.h"
#include "olink/olinknestedstruct2interfaceadapter.h"


#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/remotenode.h"
#include "olink/olinkremote.h"
#include "olink/remoteregistry.h"

TEST_CASE("Olink  testbed2 NestedStruct2Interface tests")
{

    ClientRegistry client_registry;
    auto clientNode = ClientNode::create(client_registry);
    auto clientNestedStruct2Interface = std::make_shared< testbed2::OLinkNestedStruct2Interface>();

    RemoteRegistry remote_registry;
    auto remoteNode = ApiGear::ObjectLink::RemoteNode::createRemoteNode(remote_registry);
    auto implNestedStruct2Interface = std::make_shared< testbed2::NestedStruct2Interface>();
    auto serviceNestedStruct2Interface = std::make_shared< testbed2::OLinkNestedStruct2InterfaceAdapter>(remote_registry, implNestedStruct2Interface.get());
    remote_registry.addSource(serviceNestedStruct2Interface);

    remoteNode->onWrite([clientNode](std::string msg){clientNode->handleMessage(msg);});
    clientNode->onWrite([remoteNode](std::string msg){remoteNode->handleMessage(msg);});

    clientNode->registry().addSink(clientNestedStruct2Interface);
    clientNode->linkRemote(clientNestedStruct2Interface->olinkObjectName());
    SECTION("Test setting prop1")
    {
        bool isprop1Changed = false;
        clientNestedStruct2Interface->connect(clientNestedStruct2Interface.get(), &testbed2::AbstractNestedStruct2Interface::prop1Changed, [&isprop1Changed ](auto value){isprop1Changed  = true;});
        auto test_value = testbed2::NestedStruct1();
        testbed2::fillTestNestedStruct1(test_value);
        clientNestedStruct2Interface->setProp1(test_value);
        REQUIRE(isprop1Changed  == true);
        REQUIRE(implNestedStruct2Interface->prop1() == test_value);
        REQUIRE(clientNestedStruct2Interface->prop1() == test_value);
    }
    SECTION("Test setting prop2")
    {
        bool isprop2Changed = false;
        clientNestedStruct2Interface->connect(clientNestedStruct2Interface.get(), &testbed2::AbstractNestedStruct2Interface::prop2Changed, [&isprop2Changed ](auto value){isprop2Changed  = true;});
        auto test_value = testbed2::NestedStruct2();
        testbed2::fillTestNestedStruct2(test_value);
        clientNestedStruct2Interface->setProp2(test_value);
        REQUIRE(isprop2Changed  == true);
        REQUIRE(implNestedStruct2Interface->prop2() == test_value);
        REQUIRE(clientNestedStruct2Interface->prop2() == test_value);
    }
    SECTION("Test emit sig1")
    {
        bool issig1Emitted = false;
        auto local_param1_struct = testbed2::NestedStruct1();
        testbed2::fillTestNestedStruct1(local_param1_struct);

        clientNestedStruct2Interface->connect(clientNestedStruct2Interface.get(), &testbed2::AbstractNestedStruct2Interface::sig1,
        [&issig1Emitted, &local_param1_struct](const testbed2::NestedStruct1& param1)
        {
            REQUIRE(param1 ==local_param1_struct);
            issig1Emitted  = true;
        });

        emit implNestedStruct2Interface->sig1(local_param1_struct);
        REQUIRE(issig1Emitted  == true);
    }
    SECTION("Test emit sig2")
    {
        bool issig2Emitted = false;
        auto local_param1_struct = testbed2::NestedStruct1();
        testbed2::fillTestNestedStruct1(local_param1_struct);
        auto local_param2_struct = testbed2::NestedStruct2();
        testbed2::fillTestNestedStruct2(local_param2_struct);

        clientNestedStruct2Interface->connect(clientNestedStruct2Interface.get(), &testbed2::AbstractNestedStruct2Interface::sig2,
        [&issig2Emitted, &local_param1_struct, &local_param2_struct](const testbed2::NestedStruct1& param1, const testbed2::NestedStruct2& param2)
        {
            REQUIRE(param1 ==local_param1_struct);
            REQUIRE(param2 ==local_param2_struct);
            issig2Emitted  = true;
        });

        emit implNestedStruct2Interface->sig2(local_param1_struct, local_param2_struct);
        REQUIRE(issig2Emitted  == true);
    }

    clientNode->unlinkRemote(clientNestedStruct2Interface->olinkObjectName());
    remote_registry.removeSource(serviceNestedStruct2Interface->olinkObjectName());
    client_registry.removeSink(clientNestedStruct2Interface->olinkObjectName());
}
