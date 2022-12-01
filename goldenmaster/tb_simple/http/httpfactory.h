#pragma once

#include <QtCore>
#include <QtNetwork>

#include "tb_simple/api/apifactory.h"

class HttpFactory : public QObject, public ApiFactoryInterface
{
public:
    HttpFactory(QObject *parent = nullptr);
    AbstractSimpleInterface* createSimpleInterface(QObject *parent) override;
    AbstractSimpleArrayInterface* createSimpleArrayInterface(QObject *parent) override;
private:
    QNetworkAccessManager *m_network;
};
