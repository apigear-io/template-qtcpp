#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>

#include <QtCore>
#include <QTest>
#include "olink/olinknopropertiesinterface.h"
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/nopropertiesinterface.h"
#include "olink/olinknopropertiesinterfaceadapter.h"


#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/remotenode.h"
#include "olink/olinkremote.h"
#include "olink/remoteregistry.h"

TEST_CASE("Olink  tb.simple NoPropertiesInterface tests")
{

    ClientRegistry client_registry;
    auto clientNode = ClientNode::create(client_registry);
    auto clientNoPropertiesInterface = std::make_shared< tb_simple::OLinkNoPropertiesInterface>();

    RemoteRegistry remote_registry;
    auto remoteNode = ApiGear::ObjectLink::RemoteNode::createRemoteNode(remote_registry);
    auto implNoPropertiesInterface = std::make_shared< tb_simple::NoPropertiesInterface>();
    auto serviceNoPropertiesInterface = std::make_shared< tb_simple::OLinkNoPropertiesInterfaceAdapter>(remote_registry, implNoPropertiesInterface.get());
    remote_registry.addSource(serviceNoPropertiesInterface);

    remoteNode->onWrite([clientNode](std::string msg){clientNode->handleMessage(msg);});
    clientNode->onWrite([remoteNode](std::string msg){remoteNode->handleMessage(msg);});

    clientNode->registry().addSink(clientNoPropertiesInterface);
    clientNode->linkRemote(clientNoPropertiesInterface->olinkObjectName());
    SECTION("Test emit sigVoid")
    {
        bool issigVoidEmitted = false;

        clientNoPropertiesInterface->connect(clientNoPropertiesInterface.get(), &tb_simple::AbstractNoPropertiesInterface::sigVoid,
        [&issigVoidEmitted]()
        {
            issigVoidEmitted  = true;
        });

        emit implNoPropertiesInterface->sigVoid();
        REQUIRE(issigVoidEmitted  == true);
    }
    SECTION("Test emit sigBool")
    {
        bool issigBoolEmitted = false;

        clientNoPropertiesInterface->connect(clientNoPropertiesInterface.get(), &tb_simple::AbstractNoPropertiesInterface::sigBool,
        [&issigBoolEmitted](bool paramBool)
        {
            REQUIRE(paramBool == true);
            issigBoolEmitted  = true;
        });

        emit implNoPropertiesInterface->sigBool(true);
        REQUIRE(issigBoolEmitted  == true);
    }
    SECTION("Test method funcVoid")
    {
        clientNoPropertiesInterface->funcVoid();
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method funcVoid async")
    {
        auto resultFuture = clientNoPropertiesInterface->funcVoidAsync();
        resultFuture.waitForFinished();
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcBool")
    {
        [[maybe_unused]] auto result = clientNoPropertiesInterface->funcBool(false);
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method funcBool async")
    {
        auto resultFuture = clientNoPropertiesInterface->funcBoolAsync(false);
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == false);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientNode->unlinkRemote(clientNoPropertiesInterface->olinkObjectName());
    remote_registry.removeSource(serviceNoPropertiesInterface->olinkObjectName());
    client_registry.removeSink(clientNoPropertiesInterface->olinkObjectName());
}
