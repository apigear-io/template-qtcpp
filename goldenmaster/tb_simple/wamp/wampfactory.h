#pragma once

#include <QtCore>
#include <QtNetwork>

#include "../api/apifactory.h"

class WampFactory : public QObject, public ApiFactoryInterface
{
public:
    WampFactory(QObject *parent = nullptr);
    AbstractSimpleInterface* createSimpleInterface(QObject *parent) override;
    AbstractSimpleArrayInterface* createSimpleArrayInterface(QObject *parent) override;
private:
    QNetworkAccessManager *m_network;
};
