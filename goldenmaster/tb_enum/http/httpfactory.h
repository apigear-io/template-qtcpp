#pragma once

#include <QtCore>
#include <QtNetwork>

#include "tb_enum/api/iapifactory.h"

namespace tb_enum {

class HttpFactory : public QObject, public IApiFactory
{
public:
    HttpFactory(QObject *parent = nullptr);
    std::shared_ptr<AbstractEnumInterface> createEnumInterface(QObject *parent) override;
private:
    QNetworkAccessManager *m_network;
};

} // namespace tb_enum
