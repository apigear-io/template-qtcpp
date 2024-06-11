#pragma once

#include <QtCore>
#include <QtNetwork>

#include "tb_simple/api/iapifactory.h"

namespace tb_simple {

class HttpFactory : public QObject, public IApiFactory
{
public:
    HttpFactory(QObject *parent = nullptr);
    std::shared_ptr<AbstractVoidInterface> createVoidInterface(QObject *parent) override;
    std::shared_ptr<AbstractSimpleInterface> createSimpleInterface(QObject *parent) override;
    std::shared_ptr<AbstractSimpleArrayInterface> createSimpleArrayInterface(QObject *parent) override;
    std::shared_ptr<AbstractNoPropertiesInterface> createNoPropertiesInterface(QObject *parent) override;
    std::shared_ptr<AbstractNoOperationsInterface> createNoOperationsInterface(QObject *parent) override;
    std::shared_ptr<AbstractNoSignalsInterface> createNoSignalsInterface(QObject *parent) override;
private:
    QNetworkAccessManager *m_network;
};

} // namespace tb_simple
