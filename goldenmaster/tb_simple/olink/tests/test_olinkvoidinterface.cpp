#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>

#include <QtCore>
#include <QTest>
#include "olink/olinkvoidinterface.h"
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/voidinterface.h"
#include "olink/olinkvoidinterfaceadapter.h"


#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/remotenode.h"
#include "olink/olinkremote.h"
#include "olink/remoteregistry.h"

TEST_CASE("Olink  tb.simple VoidInterface tests")
{

    ClientRegistry client_registry;
    auto clientNode = ClientNode::create(client_registry);
    auto clientVoidInterface = std::make_shared< tb_simple::OLinkVoidInterface>();

    RemoteRegistry remote_registry;
    auto remoteNode = ApiGear::ObjectLink::RemoteNode::createRemoteNode(remote_registry);
    auto implVoidInterface = std::make_shared< tb_simple::VoidInterface>();
    auto serviceVoidInterface = std::make_shared< tb_simple::OLinkVoidInterfaceAdapter>(remote_registry, implVoidInterface.get());
    remote_registry.addSource(serviceVoidInterface);

    remoteNode->onWrite([clientNode](std::string msg){clientNode->handleMessage(msg);});
    clientNode->onWrite([remoteNode](std::string msg){remoteNode->handleMessage(msg);});

    clientNode->registry().addSink(clientVoidInterface);
    clientNode->linkRemote(clientVoidInterface->olinkObjectName());

    clientNode->unlinkRemote(clientVoidInterface->olinkObjectName());
    remote_registry.removeSource(serviceVoidInterface->olinkObjectName());
    client_registry.removeSink(clientVoidInterface->olinkObjectName());
}
