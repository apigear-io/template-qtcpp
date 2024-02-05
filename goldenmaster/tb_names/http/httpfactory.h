#pragma once

#include <QtCore>
#include <QtNetwork>

#include "tb_names/api/iapifactory.h"

namespace tb_names {

class HttpFactory : public QObject, public IApiFactory
{
public:
    HttpFactory(QObject *parent = nullptr);
    std::shared_ptr<AbstractNamEs> createNamEs(QObject *parent) override;
private:
    QNetworkAccessManager *m_network;
};

} // namespace tb_names
