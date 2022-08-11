#pragma once

#include <QtCore>

#include "../api/apifactory.h"

class Factory : public QObject, public ApiFactoryInterface
{
public:
    Factory(QObject *parent = nullptr);
    AbstractInterface1* createInterface1(QObject *parent) override;
    AbstractInterface2* createInterface2(QObject *parent) override;
};
