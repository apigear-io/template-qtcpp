#pragma once

#include <QtCore>
#include <QtNetwork>

#include "{{snake .Module.Name}}/api/apifactory.h"

namespace {{snake  .Module.Name }} {

class HttpFactory : public QObject, public ApiFactoryInterface
{
public:
    HttpFactory(QObject *parent = nullptr);
{{- range .Module.Interfaces }}
    std::shared_ptr<Abstract{{Camel .Name}}> create{{Camel .Name}}(QObject *parent) override;
{{- end }}
private:
    QNetworkAccessManager *m_network;
};

} // namespace {{snake  .Module.Name }}
