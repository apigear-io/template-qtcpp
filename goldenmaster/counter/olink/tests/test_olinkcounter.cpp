#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>

#include <QtCore>
#include <QTest>
#include "olink/olinkcounter.h"
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/counter.h"
#include "olink/olinkcounteradapter.h"

#include "custom_types/api/test_struct_helper.h"
#include "extern_types/api/test_struct_helper.h"

#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/remotenode.h"
#include "olink/olinkremote.h"
#include "olink/remoteregistry.h"

TEST_CASE("Olink  counter Counter tests")
{

    ClientRegistry client_registry;
    auto clientNode = ClientNode::create(client_registry);
    auto clientCounter = std::make_shared< counter::OLinkCounter>();

    RemoteRegistry remote_registry;
    auto remoteNode = ApiGear::ObjectLink::RemoteNode::createRemoteNode(remote_registry);
    auto implCounter = std::make_shared< counter::Counter>();
    auto serviceCounter = std::make_shared< counter::OLinkCounterAdapter>(remote_registry, implCounter.get());
    remote_registry.addSource(serviceCounter);

    remoteNode->onWrite([clientNode](std::string msg){clientNode->handleMessage(msg);});
    clientNode->onWrite([remoteNode](std::string msg){remoteNode->handleMessage(msg);});

    clientNode->registry().addSink(clientCounter);
    clientNode->linkRemote(clientCounter->olinkObjectName());
    SECTION("Test setting vector")
    {
        bool isvectorChanged = false;
        clientCounter->connect(clientCounter.get(), &counter::AbstractCounter::vectorChanged, [&isvectorChanged ](auto value){isvectorChanged  = true;});
        auto test_value = custom_types::Vector3D();
        custom_types::fillTestVector3D(test_value);
        clientCounter->setVector(test_value);
        REQUIRE(isvectorChanged  == true);
        REQUIRE(implCounter->vector() == test_value);
        REQUIRE(clientCounter->vector() == test_value);
    }
    SECTION("Test method increment")
    {
        [[maybe_unused]] auto result = clientCounter->increment(QVector3D());
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method increment async")
    {
        auto resultFuture = clientCounter->incrementAsync(QVector3D());
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QVector3D());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method decrement")
    {
        [[maybe_unused]] auto result = clientCounter->decrement(custom_types::Vector3D());
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method decrement async")
    {
        auto resultFuture = clientCounter->decrementAsync(custom_types::Vector3D());
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == custom_types::Vector3D());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientNode->unlinkRemote(clientCounter->olinkObjectName());
    remote_registry.removeSource(serviceCounter->olinkObjectName());
    client_registry.removeSink(clientCounter->olinkObjectName());
}
