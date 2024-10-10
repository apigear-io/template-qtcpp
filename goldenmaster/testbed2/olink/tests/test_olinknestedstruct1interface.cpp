#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>

#include <QtCore>
#include <QTest>
#include "olink/olinknestedstruct1interface.h"
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/nestedstruct1interface.h"
#include "olink/olinknestedstruct1interfaceadapter.h"


#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/remotenode.h"
#include "olink/olinkremote.h"
#include "olink/remoteregistry.h"

TEST_CASE("Olink  testbed2 NestedStruct1Interface tests")
{

    ClientRegistry client_registry;
    auto clientNode = ClientNode::create(client_registry);
    auto clientNestedStruct1Interface = std::make_shared< testbed2::OLinkNestedStruct1Interface>();

    RemoteRegistry remote_registry;
    auto remoteNode = ApiGear::ObjectLink::RemoteNode::createRemoteNode(remote_registry);
    auto implNestedStruct1Interface = std::make_shared< testbed2::NestedStruct1Interface>();
    auto serviceNestedStruct1Interface = std::make_shared< testbed2::OLinkNestedStruct1InterfaceAdapter>(remote_registry, implNestedStruct1Interface.get());
    remote_registry.addSource(serviceNestedStruct1Interface);

    remoteNode->onWrite([clientNode](std::string msg){clientNode->handleMessage(msg);});
    clientNode->onWrite([remoteNode](std::string msg){remoteNode->handleMessage(msg);});

    clientNode->registry().addSink(clientNestedStruct1Interface);
    clientNode->linkRemote(clientNestedStruct1Interface->olinkObjectName());
    SECTION("Test setting prop1")
    {
        bool isprop1Changed = false;
        clientNestedStruct1Interface->connect(clientNestedStruct1Interface.get(), &testbed2::AbstractNestedStruct1Interface::prop1Changed, [&isprop1Changed ](auto value){isprop1Changed  = true;});
        auto test_value = testbed2::NestedStruct1();
        testbed2::fillTestNestedStruct1(test_value);
        clientNestedStruct1Interface->setProp1(test_value);
        REQUIRE(isprop1Changed  == true);
        REQUIRE(implNestedStruct1Interface->prop1() == test_value);
        REQUIRE(clientNestedStruct1Interface->prop1() == test_value);
    }
    SECTION("Test emit sig1")
    {
        bool issig1Emitted = false;
        auto local_param1_struct = testbed2::NestedStruct1();
        testbed2::fillTestNestedStruct1(local_param1_struct);

        clientNestedStruct1Interface->connect(clientNestedStruct1Interface.get(), &testbed2::AbstractNestedStruct1Interface::sig1,
        [&issig1Emitted, &local_param1_struct](const testbed2::NestedStruct1& param1)
        {
            REQUIRE(param1 ==local_param1_struct);
            issig1Emitted  = true;
        });

        emit implNestedStruct1Interface->sig1(local_param1_struct);
        REQUIRE(issig1Emitted  == true);
    }
    SECTION("Test method func1")
    {
        [[maybe_unused]] auto result = clientNestedStruct1Interface->func1(testbed2::NestedStruct1());
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method func1 async")
    {
        auto resultFuture = clientNestedStruct1Interface->func1Async(testbed2::NestedStruct1());
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == testbed2::NestedStruct1());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientNode->unlinkRemote(clientNestedStruct1Interface->olinkObjectName());
    remote_registry.removeSource(serviceNestedStruct1Interface->olinkObjectName());
    client_registry.removeSink(clientNestedStruct1Interface->olinkObjectName());
}
