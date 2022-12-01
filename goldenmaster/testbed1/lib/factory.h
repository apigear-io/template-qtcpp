#pragma once

#include <QtCore>

#include "testbed1/api/apifactory.h"

namespace testbed1 {

class Factory : public QObject, public ApiFactoryInterface
{
public:
    Factory(QObject *parent = nullptr);
    AbstractStructInterface* createStructInterface(QObject *parent) override;
    AbstractStructArrayInterface* createStructArrayInterface(QObject *parent) override;
};

} // namespace testbed1

