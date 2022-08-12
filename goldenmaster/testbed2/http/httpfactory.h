#pragma once

#include <QtCore>
#include <QtNetwork>

#include "../api/apifactory.h"

class HttpFactory : public QObject, public ApiFactoryInterface
{
public:
    HttpFactory(QObject *parent = nullptr);
    AbstractManyParamInterface* createManyParamInterface(QObject *parent) override;
    AbstractNestedStruct1Interface* createNestedStruct1Interface(QObject *parent) override;
    AbstractNestedStruct2Interface* createNestedStruct2Interface(QObject *parent) override;
    AbstractNestedStruct3Interface* createNestedStruct3Interface(QObject *parent) override;
private:
    QNetworkAccessManager *m_network;
};
