#pragma once

#include <QtCore>
#include <QtNetwork>

#include "../api/apifactory.h"

class HttpFactory : public QObject, public ApiFactoryInterface
{
public:
    HttpFactory(QObject *parent = nullptr);
    AbstractEnumInterface* createEnumInterface(QObject *parent) override;
private:
    QNetworkAccessManager *m_network;
};
