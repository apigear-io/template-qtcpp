#pragma once

#include <QtCore>
#include <QtNetwork>

#include "../api/apifactory.h"

class WampFactory : public QObject, public ApiFactoryInterface
{
public:
    WampFactory(QObject *parent = nullptr);
    AbstractInterface1* createInterface1(QObject *parent) override;
    AbstractInterface2* createInterface2(QObject *parent) override;
private:
    QNetworkAccessManager *m_network;
};
