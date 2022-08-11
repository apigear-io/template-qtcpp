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
#include "olinkclient.h"
#include "olink/clientnode.h"

using namespace ApiGear::ObjectLink;

OLinkClient::OLinkClient(QWebSocket *socket, QObject *parent)
    : QObject(parent)
    , m_socket(socket ? socket : new QWebSocket(QString(), QWebSocketProtocol::VersionLatest, this))
{
    m_node.onLog(ConsoleLogger::logFunc());
    connect(m_socket, &QWebSocket::connected, this, &OLinkClient::onConnected);
    connect(m_socket, &QWebSocket::disconnected, this, &OLinkClient::onDisconnected);
    connect(m_socket, &QWebSocket::textMessageReceived, this, &OLinkClient::handleTextMessage);
    WriteMessageFunc func = [this](std::string msg) {
        m_queue << msg;
        processMessages();
    };
    m_node.onWrite(func);
}

OLinkClient::~OLinkClient()
{
}


void OLinkClient::connectToHost(QUrl url)
{
    qDebug() << Q_FUNC_INFO;
    m_socket->open(QUrl(url));
}

ClientNode &OLinkClient::node()
{
    return m_node;
}

void OLinkClient::linkObjectSource(std::string name)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_node.registry().linkClientNode(name, &m_node);
    m_node.linkRemote(name);
}


void OLinkClient::onConnected()
{
    qDebug() << Q_FUNC_INFO;
    processMessages();
}

void OLinkClient::onDisconnected()
{
    qDebug() << Q_FUNC_INFO;
}

void OLinkClient::handleTextMessage(const QString &message)
{
    m_node.handleMessage(message.toStdString());
}


void OLinkClient::processMessages()
{
    qDebug() << Q_FUNC_INFO;
    if (m_socket->state() == QAbstractSocket::ConnectedState) {
        while(!m_queue.isEmpty()) {
            // if we are using JSON we need to use txt message
            // otherwise binary messages
            //    m_socket->sendBinaryMessage(QByteArray::fromStdString(message));
            const QString& msg = QString::fromStdString(m_queue.dequeue());
            qDebug() << "write message to socket: " << msg;
            m_socket->sendTextMessage(msg);
        }
    }

}
