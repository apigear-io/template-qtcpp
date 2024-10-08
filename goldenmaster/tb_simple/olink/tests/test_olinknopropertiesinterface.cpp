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

    clientNode->unlinkRemote(clientNoPropertiesInterface->olinkObjectName());
    remote_registry.removeSource(serviceNoPropertiesInterface->olinkObjectName());
    client_registry.removeSink(clientNoPropertiesInterface->olinkObjectName());
}