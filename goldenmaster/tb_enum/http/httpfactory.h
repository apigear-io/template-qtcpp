#pragma once

#include <QtCore>
#include <QtNetwork>

#include "tb_enum/api/apifactory.h"

namespace tb_enum {

class HttpFactory : public QObject, public ApiFactoryInterface
{
public:
    HttpFactory(QObject *parent = nullptr);
    AbstractEnumInterface* createEnumInterface(QObject *parent) override;
private:
    QNetworkAccessManager *m_network;
};

} // namespace tb_enum
