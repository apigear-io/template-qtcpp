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
#include "olink/clientnode.h"
#include "olink/consolelogger.h"

using namespace ApiGear::ObjectLink;

class OLinkClient
        : public QObject
{
    Q_OBJECT
public:
    explicit OLinkClient(QWebSocket *socket=nullptr, QObject *parent=nullptr);
    virtual ~OLinkClient() override;
    void connectToHost(QUrl url);
    ClientNode &node();
    void linkObjectSource(std::string name);
public:

    void onConnected();
    void onDisconnected();
    void handleTextMessage(const QString& message);
    void processMessages();

private:
    QWebSocket *m_socket;
    ClientNode m_node;
    QQueue<std::string> m_queue;
};
