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
#pragma once

#include <QtCore>
#include <QtWebSockets>
#include "olink/consolelogger.h"
#include "olink_common.h"

namespace ApiGear {
namespace ObjectLink {

class RemoteRegistry;

/**
* Class that hosts a server for olink services.
* Stores connections requested by clients and provides connection endpoints used by sources to the registry.
* May hold multiple connections.
*/
class OLINKQT_EXPORT OLinkHost :public QObject
{
    Q_OBJECT
public:
    /**
     * ctor
    * @param registry A global registry to which network endpoints for sources are added.
    */
    explicit OLinkHost(RemoteRegistry& registry, QObject *parent=nullptr);
    /** dtor */
    virtual ~OLinkHost() override;
    /** Starts a server and puts it in a listen state.
    * @param host A host address should.
    * @param port A port number on which the server should listen.
    */
    void listen(const QString& host, int port);
    /** A getter to a registry it uses for nodes and sources */
    RemoteRegistry &registry();

private:
    /** Handler for new incoming connection */
    void onNewConnection();
    /** Handler for closing server */
    void onClosed();

    /** A global registry for sources and network endpoints.*/
    RemoteRegistry& m_registry;
    /** A server used for connections.*/
    QWebSocketServer* m_wss;
    /** Logger */
    ConsoleLogger m_log;
};

}} // namespace ApiGear::ObjectLink
