#pragma once

#include <QtCore>
#include <QtNetwork>

#include "../api/apifactory.h"

class WampFactory : public QObject, public ApiFactoryInterface
{
public:
    WampFactory(QObject *parent = nullptr);
{{ range .Module.Interfaces }}
    Abstract{{.Name}}* create{{Camel .Name}}(QObject *parent) override;
{{- end }}
private:
    QNetworkAccessManager *m_network;
};
