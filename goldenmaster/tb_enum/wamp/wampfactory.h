#pragma once

#include <QtCore>
#include <QtNetwork>

#include "../api/apifactory.h"

class WampFactory : public QObject, public ApiFactoryInterface
{
public:
    WampFactory(QObject *parent = nullptr);
    AbstractEnumInterface* createEnumInterface(QObject *parent) override;
private:
    QNetworkAccessManager *m_network;
};
