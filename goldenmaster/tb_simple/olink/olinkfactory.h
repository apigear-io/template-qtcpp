#pragma once

#include <QtCore>

#include "../api/apifactory.h"
#include "olink/clientnode.h"

class OLinkFactory : public QObject, public ApiFactoryInterface
{
public:
    OLinkFactory(ApiGear::ObjectLink::ClientRegistry& registry, QObject *parent = nullptr);
    AbstractSimpleInterface* createSimpleInterface(QObject *parent) override;
    AbstractSimpleArrayInterface* createSimpleArrayInterface(QObject *parent) override;
private:
ApiGear::ObjectLink::ClientRegistry& m_registry;
};
