#pragma once

#include "olink/remotenode.h"
#include <iostream>

using namespace ApiGear::ObjectLink;

class CalcSource: public IObjectSource {
public:
    CalcSource()
        : m_node(nullptr)
        , m_total(1)
    {
        RemoteNode::addObjectSource(this);
    }
    virtual ~CalcSource() override {
        RemoteNode::removeObjectSource(this);
    }

    IRemoteNode* remoteNode() const {
        assert(m_node);
        return m_node;
    }

    int add(int value) {
        m_total += value;
        remoteNode()->notifyPropertyChange("demo.Calc/total", m_total);
        m_events.push_back({ "demo.Calc/add", value });
        m_events.push_back({ "demo.Calc/total", m_total });
        if(m_total >= 10) {
            remoteNode()->notifySignal("demo.Calc/hitUpper", { 10 });
            m_events.push_back({ "demo.Calc/hitUpper", 10 });
        }
        return m_total;
    }

    int sub(int value) {
        m_total -= value;
        remoteNode()->notifyPropertyChange("demo.Calc/total", m_total);
        m_events.push_back({ "demo.Calc/sub", value });
        m_events.push_back({ "demo.Calc/total", m_total });
        if(m_total <= 0) {
            remoteNode()->notifySignal("demo.Calc/hitLower", { 0 });
            m_events.push_back({ "demo.Calc/hitLower", 0 });
        }
        return m_total;
    }
    void notifyShutdown(int timeout) {
        remoteNode()->notifySignal("demo.Calc/timeout", { timeout });
    }
    // IServiceObjectListener interface
public:
    std::string olinkObjectName() override {
        return "demo.Calc";
    }
    json olinkInvoke(std::string name, json args) override {
        std::cout << "invoke" << name << args.dump();
        std::string path = Name::pathFromName(name);
        if(path == "add") {
            int a = args[0].get<int>();
            int result = add(a);
            return result;
        }
        return json();
    }
    void olinkSetProperty(std::string name, json value) override {
        std::cout << "setProperty" << name << value.dump();
        std::string path = Name::pathFromName(name);
        if(path == "total") {
            int total = value.get<int>();
            if(m_total != total) {
                m_total = total;
                remoteNode()->notifyPropertyChange(name, total);
            }
        }
    }
    void olinkLinked(std::string name, IRemoteNode *node) override {
        std::cout << "linked" << name;
        m_node = node;
    }
    void olinkUnlinked(std::string name) override
    {
        std::cout << "unlinked" << name;
        m_node = nullptr;
    }
    json olinkCollectProperties() override
    {
        return {{ "total", m_total }};
    }
private:
    IRemoteNode* m_node;
    int m_total;
    std::vector<json> m_events;
};
