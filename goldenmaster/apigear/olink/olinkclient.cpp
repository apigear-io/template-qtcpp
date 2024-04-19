#include "olinkclient.h"
#include "olinkclientimpl.h"
#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/iobjectsink.h"
#include <QThread>
#include <memory>

using namespace ApiGear::ObjectLink;


OLinkClient::OLinkClient(ClientRegistry& registry, QObject *parent)
    :m_registry(registry)
{
    client = new OLinkClientImpl(registry);
    clientthread = new QThread();
    client->moveToThread(clientthread);

    connect(this, &OLinkClient::requestLinkObjectSource, client, &OLinkClientImpl::linkObjectSource);
    connect(this, &OLinkClient::requestUnlinkObjectSource, client, &OLinkClientImpl::unlinkObjectSource);
    connect(this, &OLinkClient::requestConnectToHost, client, &OLinkClientImpl::connectToHost);
    connect(this, &OLinkClient::requestDisconnect, client, &OLinkClientImpl::disconnect);
    connect(client, &OLinkClientImpl::connectionStatusChanged, [this](auto status){m_socektStatus = status;});
    connect(clientthread, &QThread::started, client, &OLinkClientImpl::init);
    connect(this, &OLinkClient::requestTearDown, client, &OLinkClientImpl::tearDown);
    connect(clientthread, &QThread::finished, client, &OLinkClientImpl::deleteLater);

    clientthread->start();
}

OLinkClient::~OLinkClient()
{
    emit requestTearDown();
    while(!client->isFinished()){};
    clientthread->exit();
    clientthread->wait();
    delete(clientthread);
}


void OLinkClient::connectToHost(QUrl url)
{
    emit requestConnectToHost(url);
}
void OLinkClient::disconnect()
{
    emit requestDisconnect();
}

ClientRegistry& OLinkClient::registry()
{
    return m_registry;
}

ClientNode* OLinkClient::node()
{
    return client->node();
}
void OLinkClient::linkObjectSource(std::weak_ptr<IObjectSink> objectSink)
{
    return emit requestLinkObjectSource(objectSink);
}
void OLinkClient::unlinkObjectSource(std::string objectId)
{
    return emit requestUnlinkObjectSource(objectId);
}

QAbstractSocket::SocketState OLinkClient::getConnectionState()
{
    return m_socektStatus;
}
