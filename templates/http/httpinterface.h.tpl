{% comment %} // Copyright (c) ApiGear UG 2020 {% endcomment -%}
{{ cppGpl .Module }}
{{- $class := printf "%sHttp" .Name }}

#pragma once

#include <QtCore>
#include <QtNetwork>

#include "../api/api.h"

class {{$class}} : public Abstract{{.Name}}
{
    Q_OBJECT
public:
    explicit {{$class}}(QNetworkAccessManager *network, QObject *parent = nullptr);
    virtual ~{{$class}}() override;

{{- range .Properties }}
    {{qtReturn "" .}} {{.Name}}() const override;
    void set{{Camel .Name}}({{qtParam "" .}}) override;
{{- end }}

{{- range .Operations }}
    {{qtReturn "" .Return}} {{.Name}}({{qtParams "" .Params}}) override;
{{- end }}
private:
    QJsonObject post(const QString& path, const QJsonObject &payload);
    void applyState(const QJsonObject &state);
private:
    QNetworkAccessManager *m_network;
{{- range .Properties }}
    {{qtReturn "" .}} m_{{.Name}};
{{- end }}
};
