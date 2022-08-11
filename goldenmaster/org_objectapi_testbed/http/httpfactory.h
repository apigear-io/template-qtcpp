#pragma once

#include <QtCore>
#include <QtNetwork>

#include "../api/apifactory.h"

class HttpFactory : public QObject, public ApiFactoryInterface
{
public:
    HttpFactory(QObject *parent = nullptr);
    AbstractInterface1* createInterface1(QObject *parent) override;
    AbstractInterface2* createInterface2(QObject *parent) override;
private:
    QNetworkAccessManager *m_network;
};
