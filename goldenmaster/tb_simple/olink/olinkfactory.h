#pragma once

#include <QtCore>

#include "tb_simple/api/apifactory.h"

namespace tb_simple {

class OLinkFactory : public QObject, public ApiFactoryInterface
{
public:
    OLinkFactory(QObject *parent = nullptr);
    AbstractSimpleInterface* createSimpleInterface(QObject *parent) override;
    AbstractSimpleArrayInterface* createSimpleArrayInterface(QObject *parent) override;
};

} //namespace tb_simple
