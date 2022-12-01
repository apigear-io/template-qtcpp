{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $class := printf "Http%s" .Interface.Name }}
#pragma once

#include <QtCore>
#include <QtNetwork>

#include "{{snake .Module.Name}}/api/api.h"

class {{$class}} : public Abstract{{.Interface.Name}}
{
    Q_OBJECT
public:
    explicit {{$class}}(QNetworkAccessManager *network, QObject *parent = nullptr);
    virtual ~{{$class}}() override;

{{- range .Interface.Properties }}
    {{qtReturn "" .}} {{.Name}}() const override;
    void set{{Camel .Name}}({{qtParam "" .}}) override;
{{- end }}

{{- range .Interface.Operations }}
    {{qtReturn "" .Return}} {{.Name}}({{qtParams "" .Params}}) override;
{{- end }}
private:
    QJsonObject post(const QString& path, const QJsonObject &payload);
    void applyState(const QJsonObject &state);
private:
    QNetworkAccessManager *m_network;
{{- range .Interface.Properties }}
    {{qtReturn "" .}} m_{{.Name}};
{{- end }}
};
