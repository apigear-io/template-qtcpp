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

#include "types.h"

namespace ApiGear { namespace ObjectLink {


/**
 * @brief listener for the protocol.
 */
class IProtocolListener
{
public:
    virtual ~IProtocolListener();

    virtual void handleLink(std::string name) = 0;
    virtual void handleUnlink(std::string name) = 0;
    virtual void handleInit(std::string name, json props) = 0;
    virtual void handleSetProperty(std::string name, json value) = 0;
    virtual void handlePropertyChange(std::string name, json value) = 0;
    virtual void handleInvoke(int requestId, std::string name, json args) = 0;
    virtual void handleInvokeReply(int requestId, std::string name, json value) = 0;
    virtual void handleSignal(std::string name, json args) = 0;
    virtual void handleError(int msgType, int requestId, std::string error) = 0;
};

/**
 * @brief The ObjectLink protocol
 * Functions to create olik messages and to handle all olink messages
 * On incoming messages the listeners is called.
 * A base implementation is available in BaseNode (see ndoe.h)
 */
class Protocol : public Base
{
public:
    Protocol(IProtocolListener *listener);
    // lifecycle
    static json linkMessage(std::string name);
    static json unlinkMessage(std::string name);
    static json initMessage(std::string name, json props);
    // properties
    static json setPropertyMessage(std::string name, json value);
    static json propertyChangeMessage(std::string name, json value);
    // remote invoke
    static json invokeMessage(int requestId, std::string name, json args);
    static json invokeReplyMessage(int requestId, std::string name, json value);
    // signal
    static json signalMessage(std::string name, json args);
    // error
    static json errorMessage(MsgType msgType, int requestId, std::string error);
    bool handleMessage(json msg);
    std::string lastError();
private:
    IProtocolListener *listener() const;
private:
    IProtocolListener* m_listener;
    std::string m_lastError;
};

} } // Apigear::ObjectLink

