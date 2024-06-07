#pragma once

#include <QtCore>
#include <QtNetwork>

#include "{{snake .Module.Name}}/api/iapifactory.h"

namespace {{qtNamespace .Module.Name }} {

class HttpFactory : public QObject, public IApiFactory
{
public:
    HttpFactory(QObject *parent = nullptr);
{{- range .Module.Interfaces }}
    std::shared_ptr<Abstract{{Camel .Name}}> create{{Camel .Name}}(QObject *parent) override;
{{- end }}
private:
    QNetworkAccessManager *m_network;
};

} // namespace {{qtNamespace .Module.Name }}
