#pragma once

#include "olink/remotenode.h"
#include <iostream>

using namespace ApiGear::ObjectLink;

class MockSource: public IObjectSource {
public:
    MockSource()
        : m_node(nullptr)
    {
        RemoteNode::addObjectSource(this);
    }
    virtual ~MockSource() override {
        RemoteNode::removeObjectSource(this);
    }

    IRemoteNode* remoteNode() const {
        assert(m_node);
        return m_node;
    }

    void notifyPropertyChange(std::string name, json value) {
        remoteNode()->notifyPropertyChange(name, value);
    }

    void notifySignal(std::string name, json args) {
        remoteNode()->notifySignal(name, args);
    }
    // IServiceObjectListener interface
public:
    std::string olinkObjectName() override {
        return "demo.Mock";
    }
    json olinkInvoke(std::string name, json args) override {
        std::cout << "invoke" << name << args.dump();
        std::string path = Name::pathFromName(name);
        m_events.push_back({ {"type", "invoke"}, { "name", name}, {"args", args } });
        return 42;
    }
    void olinkSetProperty(std::string name, json value) override {
        std::cout << "setProperty" << name << value.dump();
        std::string path = Name::pathFromName(name);
        m_events.push_back({ {"type", "setProperty"}, { "name", name}, {"value", value } });
        m_properties[name] = value;
    }
    void olinkLinked(std::string name, IRemoteNode *node) override {
        std::cout << "linked" << name;
        m_events.push_back({ {"type", "link"}, { "name", name} });
        m_node = node;
    }
    void olinkUnlinked(std::string name) override
    {
        std::cout << "unlinked" << name;
        m_events.push_back({ {"type", "unlink"}, { "name", name} });
        m_node = nullptr;
    }
    json olinkCollectProperties() override
    {
        return m_properties;
    }
private:
    IRemoteNode* m_node;
    std::list<json> m_events;
    json m_properties;
};
