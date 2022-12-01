#pragma once

#include <QtCore>

#include "tb_same1/api/apifactory.h"
#include "olink/clientnode.h"

class OLinkFactory : public QObject, public ApiFactoryInterface
{
public:
    OLinkFactory(ApiGear::ObjectLink::ClientRegistry& registry, QObject *parent = nullptr);
    AbstractSameStruct1Interface* createSameStruct1Interface(QObject *parent) override;
    AbstractSameStruct2Interface* createSameStruct2Interface(QObject *parent) override;
    AbstractSameEnum1Interface* createSameEnum1Interface(QObject *parent) override;
    AbstractSameEnum2Interface* createSameEnum2Interface(QObject *parent) override;
private:
ApiGear::ObjectLink::ClientRegistry& m_registry;
};
