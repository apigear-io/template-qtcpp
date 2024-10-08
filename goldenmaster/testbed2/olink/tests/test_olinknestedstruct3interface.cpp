#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>

#include <QtCore>
#include <QTest>
#include "olink/olinknestedstruct3interface.h"
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/nestedstruct3interface.h"
#include "olink/olinknestedstruct3interfaceadapter.h"


#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/remotenode.h"
#include "olink/olinkremote.h"
#include "olink/remoteregistry.h"

TEST_CASE("Olink  testbed2 NestedStruct3Interface tests")
{

    ClientRegistry client_registry;
    auto clientNode = ClientNode::create(client_registry);
    auto clientNestedStruct3Interface = std::make_shared< testbed2::OLinkNestedStruct3Interface>();

    RemoteRegistry remote_registry;
    auto remoteNode = ApiGear::ObjectLink::RemoteNode::createRemoteNode(remote_registry);
    auto implNestedStruct3Interface = std::make_shared< testbed2::NestedStruct3Interface>();
    auto serviceNestedStruct3Interface = std::make_shared< testbed2::OLinkNestedStruct3InterfaceAdapter>(remote_registry, implNestedStruct3Interface.get());
    remote_registry.addSource(serviceNestedStruct3Interface);

    remoteNode->onWrite([clientNode](std::string msg){clientNode->handleMessage(msg);});
    clientNode->onWrite([remoteNode](std::string msg){remoteNode->handleMessage(msg);});

    clientNode->registry().addSink(clientNestedStruct3Interface);
    clientNode->linkRemote(clientNestedStruct3Interface->olinkObjectName());
    SECTION("Test setting prop1")
    {
        bool isprop1Changed = false;
        clientNestedStruct3Interface->connect(clientNestedStruct3Interface.get(), &testbed2::AbstractNestedStruct3Interface::prop1Changed, [&isprop1Changed ](auto value){isprop1Changed  = true;});
        auto test_value = testbed2::NestedStruct1();
        testbed2::fillTestNestedStruct1(test_value);
        clientNestedStruct3Interface->setProp1(test_value);
        REQUIRE(isprop1Changed  == true);
        REQUIRE(implNestedStruct3Interface->prop1() == test_value);
        REQUIRE(clientNestedStruct3Interface->prop1() == test_value);
    }
    SECTION("Test setting prop2")
    {
        bool isprop2Changed = false;
        clientNestedStruct3Interface->connect(clientNestedStruct3Interface.get(), &testbed2::AbstractNestedStruct3Interface::prop2Changed, [&isprop2Changed ](auto value){isprop2Changed  = true;});
        auto test_value = testbed2::NestedStruct2();
        testbed2::fillTestNestedStruct2(test_value);
        clientNestedStruct3Interface->setProp2(test_value);
        REQUIRE(isprop2Changed  == true);
        REQUIRE(implNestedStruct3Interface->prop2() == test_value);
        REQUIRE(clientNestedStruct3Interface->prop2() == test_value);
    }
    SECTION("Test setting prop3")
    {
        bool isprop3Changed = false;
        clientNestedStruct3Interface->connect(clientNestedStruct3Interface.get(), &testbed2::AbstractNestedStruct3Interface::prop3Changed, [&isprop3Changed ](auto value){isprop3Changed  = true;});
        auto test_value = testbed2::NestedStruct3();
        testbed2::fillTestNestedStruct3(test_value);
        clientNestedStruct3Interface->setProp3(test_value);
        REQUIRE(isprop3Changed  == true);
        REQUIRE(implNestedStruct3Interface->prop3() == test_value);
        REQUIRE(clientNestedStruct3Interface->prop3() == test_value);
    }

    clientNode->unlinkRemote(clientNestedStruct3Interface->olinkObjectName());
    remote_registry.removeSource(serviceNestedStruct3Interface->olinkObjectName());
    client_registry.removeSink(clientNestedStruct3Interface->olinkObjectName());
}
