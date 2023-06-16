/*
* MIT License
*
* Copyright (c) 2021 ApiGear
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#include "olinkhost.h"

#include "olinkremote.h"
#include "olink/remoteregistry.h"
#include "../utilities/logger.h"

using namespace ApiGear::ObjectLink;



OLinkHost::OLinkHost(RemoteRegistry& registry, QObject *parent)
    : QObject(parent)
    , m_registry(registry)
    , m_wss(new QWebSocketServer("olink", QWebSocketServer::NonSecureMode, this))
{
    m_registry.onLog(m_log.logFunc());
}

OLinkHost::~OLinkHost()
{
}

void OLinkHost::listen(const QString& host, int port)
{
    AG_LOG_INFO("wss.listen ");
    m_wss->listen(QHostAddress(host), quint16(port));
    AG_LOG_INFO(m_wss->serverAddress().toString().toStdString() + ":" + std::to_string(m_wss->serverPort()));
    connect(m_wss, &QWebSocketServer::newConnection, this, &OLinkHost::onNewConnection);
    connect(m_wss, &QWebSocketServer::closed, this, &OLinkHost::onClosed);
}

void OLinkHost::onNewConnection()
{
    AG_LOG_INFO("wss.newConnection");
    auto ws = m_wss->nextPendingConnection();
    OLinkRemote* connectionUser = new OLinkRemote(m_registry, ws);
    ws->setParent(connectionUser);
    // make sure gets cleaned up, latest with this object deletion.
    connectionUser->setParent(this);
}

void OLinkHost::onClosed()
{
    AG_LOG_INFO("wss.closed");
}

RemoteRegistry &OLinkHost::registry()
{
    return m_registry;
}

