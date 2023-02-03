#pragma once

#include <QtCore>
#include <QtNetwork>

#include "tb_simple/api/apifactory.h"

namespace tb_simple {

class HttpFactory : public QObject, public ApiFactoryInterface
{
public:
    HttpFactory(QObject *parent = nullptr);
    std::shared_ptr<AbstractSimpleInterface> createSimpleInterface(QObject *parent) override;
    std::shared_ptr<AbstractSimpleArrayInterface> createSimpleArrayInterface(QObject *parent) override;
private:
    QNetworkAccessManager *m_network;
};

} // namespace tb_simple
