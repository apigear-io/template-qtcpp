#pragma once

#include <QtCore>

#include "testbed2/api/apifactory.h"

class Factory : public QObject, public ApiFactoryInterface
{
public:
    Factory(QObject *parent = nullptr);
    AbstractManyParamInterface* createManyParamInterface(QObject *parent) override;
    AbstractNestedStruct1Interface* createNestedStruct1Interface(QObject *parent) override;
    AbstractNestedStruct2Interface* createNestedStruct2Interface(QObject *parent) override;
    AbstractNestedStruct3Interface* createNestedStruct3Interface(QObject *parent) override;
};
