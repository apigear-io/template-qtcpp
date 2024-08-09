#pragma once

#include <QtCore>
#include <QtNetwork>

#include "counter/api/iapifactory.h"

namespace counter {

class HttpFactory : public QObject, public IApiFactory
{
public:
    HttpFactory(QObject *parent = nullptr);
    std::shared_ptr<AbstractCounter> createCounter(QObject *parent) override;
private:
    QNetworkAccessManager *m_network;
};

} // namespace counter
