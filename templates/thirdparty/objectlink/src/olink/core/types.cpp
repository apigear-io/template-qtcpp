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
#include "types.h"

#include <string>
#include <map>
#include <list>
#include "iostream"


namespace ApiGear { namespace ObjectLink {

// ********************************************************************
// Name
// ********************************************************************

std::string Name::resourceFromName(std::string name)
{
    return name.substr(0, name.find("/"));
}

std::string Name::pathFromName(std::string name)
{
    return name.substr(name.find("/")+1);
}

bool Name::hasPath(std::string name)
{
    return name.find("/") != std::string::npos;
}

std::string Name::createName(std::string resource, std::string path)
{
    return resource + "/" + path;
}

// ********************************************************************
// MessageConverter
// ********************************************************************

MessageConverter::MessageConverter(MessageFormat format)
    : m_format(format)
{
}

void MessageConverter::setMessageFormat(MessageFormat format)
{
    m_format = format;
}

json MessageConverter::fromString(std::string message)
{
    switch(m_format) {
    case MessageFormat::JSON:
        return json::parse(message);
    case MessageFormat::BSON:
        return json::from_bson(message);
    case MessageFormat::MSGPACK:
        return json::from_msgpack(message);
    case MessageFormat::CBOR:
        return json::from_cbor(message);
    }

    return json();
}

std::string MessageConverter::toString(json j)
{
    std::vector<uint8_t> v;
    switch(m_format) {
    case MessageFormat::JSON:
        return j.dump();
    case MessageFormat::BSON:
        v = json::to_bson(j);
        return std::string(v.begin(), v.end());
    case MessageFormat::MSGPACK:
        v = json::to_msgpack(j);
        return std::string(v.begin(), v.end());
    case MessageFormat::CBOR:
        v = json::to_cbor(j);
        return std::string(v.begin(), v.end());
    }
    return std::string();
}

std::string toString(MsgType type) {
    static std::map<MsgType, std::string> typeNames = {
        { MsgType::Link, "link" },
        { MsgType::Unlink, "unlink" },
        { MsgType::Init, "init" },
        { MsgType::SetProperty, "property_change" },
        { MsgType::PropertyChange, "signal_property_change" },
        { MsgType::Invoke, "invoke" },
        { MsgType::InvokeReply, "invoke_reply" },
        { MsgType::Signal, "signal" },
        { MsgType::Error, "error"
        },
    };
    auto result = typeNames.find(type);
    if (result == typeNames.end()) {
        return std::string("unknown");
    }

    return result->second;
}

// ********************************************************************
// IMessageHandler
// ********************************************************************


IMessageHandler::~IMessageHandler() {}

// ********************************************************************
// ILogger
// ********************************************************************

ILogger::~ILogger() {}




LoopbackWriter::LoopbackWriter(IMessageHandler *handler)
    : m_handler(handler)
    , m_converter(MessageFormat::JSON)
{
    m_writeFunc = [this](json j) {
        std::string data = m_converter.toString(j);
        if(m_handler) {
            m_handler->handleMessage(data);
        }
    };
}

void LoopbackWriter::writeMessage(json j) {
    m_writeFunc(j);
}

WriteMessageFunc& LoopbackWriter::writeFunc() {
    return m_writeFunc;
}



// ********************************************************************
// Base
// ********************************************************************

Base::Base()
    : m_logFunc(nullptr)
{

}

Base::~Base()
{
}

void Base::onLog(WriteLogFunc func)
{
    m_logFunc = func;
}

void Base::emitLog(LogLevel level, std::string msg)
{
    if(m_logFunc) {
        m_logFunc(level, msg);
    }
}



} } // ApiGear::ObjectLink

