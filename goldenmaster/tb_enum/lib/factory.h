#pragma once

#include <QtCore>

#include "tb_enum/api/apifactory.h"

class Factory : public QObject, public ApiFactoryInterface
{
public:
    Factory(QObject *parent = nullptr);
    AbstractEnumInterface* createEnumInterface(QObject *parent) override;
};
