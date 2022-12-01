#pragma once

#include <QtCore>
#include <QtNetwork>

#include "{{snake .Module.Name}}/api/apifactory.h"

class HttpFactory : public QObject, public ApiFactoryInterface
{
public:
    HttpFactory(QObject *parent = nullptr);
{{- range .Module.Interfaces }}
    Abstract{{.Name}}* create{{Camel .Name}}(QObject *parent) override;
{{- end }}
private:
    QNetworkAccessManager *m_network;
};
