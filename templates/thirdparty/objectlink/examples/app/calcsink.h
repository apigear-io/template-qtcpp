#pragma once

#include <QtCore>

#include "olink/clientnode.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

using namespace ApiGear::ObjectLink;

class CalcSink
    : public QObject
    , public IObjectSink
{
    Q_OBJECT
    Q_PROPERTY(int total READ total WRITE setTotal NOTIFY totalChanged)
    Q_PROPERTY(bool isReady READ isReady NOTIFY readyChanged)
public:
    CalcSink(QObject *parent=nullptr);
    virtual ~CalcSink();
    Q_INVOKABLE void add(int a);
    Q_INVOKABLE void sub(int a);
    Q_INVOKABLE void clear();

    int total() const;
    void setTotal(int total);
    bool isReady() const;
signals:
    void totalChanged(int a);
    void readyChanged(bool ready);
    void maxReached(int value);
    void minReached(int value);
public: // IObjectLinkSink
    virtual std::string olinkObjectName() override;
    virtual void olinkOnSignal(std::string name, json args) override;
    virtual void olinkOnPropertyChanged(std::string name, json value) override;
    virtual void olinkOnInit(std::string name, json props, IClientNode *node) override;
    virtual void olinkOnRelease() override;
private:
    int m_total;
    bool m_ready;
    std::string m_name;
    IClientNode *m_node;
};
