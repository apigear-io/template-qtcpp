#pragma once

#include <QtCore>
#include <QtNetwork>

#include "extern_types/api/iapifactory.h"

namespace extern_types {

class HttpFactory : public QObject, public IApiFactory
{
public:
    HttpFactory(QObject *parent = nullptr);
private:
    QNetworkAccessManager *m_network;
};

} // namespace extern_types
