#pragma once

#include <QtCore>

#include "tb_simple/api/apifactory.h"

namespace tb_simple {

class Factory : public QObject, public ApiFactoryInterface
{
public:
    Factory(QObject *parent = nullptr);
    AbstractSimpleInterface* createSimpleInterface(QObject *parent) override;
    AbstractSimpleArrayInterface* createSimpleArrayInterface(QObject *parent) override;
};

} // namespace tb_simple

