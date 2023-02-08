#pragma once

#include <QtCore>
#include <QtNetwork>

#include "testbed1/api/iapifactory.h"

namespace testbed1 {

class HttpFactory : public QObject, public IApiFactory
{
public:
    HttpFactory(QObject *parent = nullptr);
    std::shared_ptr<AbstractStructInterface> createStructInterface(QObject *parent) override;
    std::shared_ptr<AbstractStructArrayInterface> createStructArrayInterface(QObject *parent) override;
private:
    QNetworkAccessManager *m_network;
};

} // namespace testbed1
