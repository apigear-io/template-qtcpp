#pragma once

#include <QtCore>

#include "../api/apifactory.h"

class Factory : public QObject, public ApiFactoryInterface
{
public:
    Factory(QObject *parent = nullptr);
    AbstractStructInterface* createStructInterface(QObject *parent) override;
    AbstractStructArrayInterface* createStructArrayInterface(QObject *parent) override;
};
