#pragma once

#include <QtCore>
#include <QtNetwork>

#include "custom_types/api/iapifactory.h"

namespace custom_types {

class HttpFactory : public QObject, public IApiFactory
{
public:
    HttpFactory(QObject *parent = nullptr);
private:
    QNetworkAccessManager *m_network;
};

} // namespace custom_types
