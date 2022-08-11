#pragma once
#include "olink/remotenode.h"

using namespace ApiGear::ObjectLink;


class CalcSource: public IObjectSource {
public:
    CalcSource();
    virtual ~CalcSource() override;

    IRemoteNode *node() const;

    int add(int value);

    int sub(int value);
    void clear();
    void notifyShutdown(int timeout);
    // IObjectSource interface
public:
    std::string olinkObjectName() override;
    json olinkInvoke(std::string name, json args) override;
    void olinkSetProperty(std::string name, json value) override;
    void olinkLinked(std::string name, IRemoteNode *node) override;
    void olinkUnlinked(std::string name) override;
    json olinkCollectProperties() override;
private:
    IRemoteNode* m_node;
    int m_total;
};

