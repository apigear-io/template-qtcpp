#pragma once

#include "olink/clientnode.h"
#include <iostream>

using namespace ApiGear::ObjectLink;

class CalcSink: public IObjectSink {
public:
    CalcSink()
        : m_client(nullptr)
        , m_total(0)
        , m_ready(false)
    {
        m_client = ClientNode::addObjectSink(this);
    }
    virtual ~CalcSink() override {
        ClientNode::removeObjectSink(this);
    }
    int total() const {
        return m_total;
    }
    void setTotal(int value) {
        client()->setRemoteProperty("demo.Calc/total", value);
    }
    int add(int a) {
        InvokeReplyFunc func = [](InvokeReplyArg arg) {
            std::cout << "invoke reply" << arg.name << arg.value.dump();
        };
        client()->invokeRemote("demo.Calc/add", { a }, func);

        return -1;
    }
    int sub(int a) {
        InvokeReplyFunc func = [](InvokeReplyArg arg) {
            std::cout << "invoke reply " << arg.name << arg.value.dump();
        };
        client()->invokeRemote("demo.Calc/sub", { a }, func);
        return -1;
    }
    IClientNode *client() const {
        assert(m_client);
        return m_client;
    }
    bool isReady() const {
        return m_ready;
    }
    // IClientObjectHandler interface
public:
    std::string olinkObjectName() override {
        return "demo.Calc";
    }
    void olinkOnSignal(std::string name, json args) override {
        std::cout << "onSignal" << name  << args.dump() << std::endl;
        events.push_back({name, args});

    }
    void olinkOnPropertyChanged(std::string name, json value) override {
        std::cout << "onPropertyChanged" << name << value.dump() << std::endl;
        std::string path = Name::pathFromName(name);
        if(path == "total") {
            int total = value.get<int>();
            if(m_total != total) {
                m_total = total;
            }
        }

    }
    void olinkOnInit(std::string name, json props, IClientNode *client) override {
        std::cout << "CalcSink.olinkOnInit: " << name << props.dump() << std::endl;
        m_client = client;
        m_ready = true;
        if(props.contains("total")) {
            int total = props["total"].get<int>();
            if(m_total != total) {
                m_total = total;
            }
        }
    }
    void olinkOnRelease() override {
        m_ready = false;
        m_client = nullptr;
    }
public:
    std::list<json> events;
private:
    IClientNode *m_client;
    int m_total;
    bool m_ready;

};
