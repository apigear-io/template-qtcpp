#pragma once

#include "olink/clientnode.h"
#include <iostream>

using namespace ApiGear::ObjectLink;

class MockSink: public IObjectSink {
public:
    MockSink()
        : m_client(nullptr)
        , m_ready(false)
    {
        m_client = ClientNode::addObjectSink(this);
    }
    virtual ~MockSink() override {
        ClientNode::removeObjectSink(this);
    }
    IClientNode *client() const {
        assert(m_client);
        return m_client;
    }
    void invoke(std::string name, json args) {
        m_client->invokeRemote(name, args, [this](InvokeReplyArg arg) {
            m_events.push_back({{ "type", "invokeReply"}, { "name", arg.name}, { "value", arg.value }});
        });
    }
public:
    std::string olinkObjectName() override {
        return "demo.Mock";
    }
    void olinkOnSignal(std::string name, json args) override {
        std::cout << "MockSink.olinkOnSignal" << name  << args.dump() << std::endl;
        m_events.push_back({ {"type", "signal"}, { "name", "name"}, { "args", args } });

    }
    void olinkOnPropertyChanged(std::string name, json value) override {
        std::cout << "MockSink.olinkOnPropertyChanged" << name << value.dump() << std::endl;
        std::string path = Name::pathFromName(name);
        m_properties[path] = value;
        m_events.push_back({ {"type", "propertyChange"}, { "name", "name"}, { "value", value }});
    }
    void olinkOnInit(std::string name, json props, IClientNode *client) override {
        std::cout << "MockSink.olinkOnInit: " << name << props.dump() << std::endl;
        m_client = client;
        m_ready = true;
        m_events.push_back({{ "type", "init",}, { "name", name}});
        m_properties = props;
    }
    void olinkOnRelease() override {
        m_ready = false;
        m_client = nullptr;
    }
public:
    std::list<json> m_events;
    json m_properties;
    IClientNode *m_client;
    bool m_ready;

};
