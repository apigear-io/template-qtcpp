{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $class := printf "Http%s" .Interface.Name }}
{{- $module := .Module.Name }}
{{- $iface := .Interface.Name }}
#include "{{lower $class}}.h"

#include "{{snake .Module.Name}}/api/agent.h"
#include <QtQml>

{{$class}}::{{$class}}(QNetworkAccessManager *network, QObject *parent)
    : Abstract{{.Interface.Name}}(parent)
    , m_network(network)
{{- range .Interface.Properties }}
    , m_{{.Name}}({{qtDefault "" .}})
{{- end }}
{
}

{{$class}}::~{{$class}}()
{
}

{{- range .Interface.Properties }}

void {{$class}}::set{{Camel .Name}}({{qtParam "" .}})
{
    if (m_{{.Name}} != {{.Name}}) {
        m_{{.Name}} = {{.Name}};
        emit {{.Name}}Changed({{.Name}});
        {{$iface}}Agent::trace_state(this);
    }
}

{{qtReturn "" .}} {{$class}}::{{.Name}}() const
{
    return m_{{.Name}};
}

{{- end }}
{{- range .Interface.Operations }}

{{qtReturn "" .Return}} {{$class}}::{{.Name}}({{qtParams "" .Params}})
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
{{- range  .Params }}
    payload["{{.Name}}"] = QJsonValue::fromVariant(QVariant::fromValue< {{qtReturn "" .}} >({{.Name}}));
{{- end }}
    QJsonObject reply = post("{{$module}}/{{$iface}}/{{.Name}}", payload);
    qDebug() << QJsonDocument(reply).toJson();
    {{$iface}}Agent::trace_{{.Name}}(this, {{qtVars .Params }});
    return {{qtDefault "" .Return}};
}
{{- end }}

QJsonObject {{$class}}::post(const QString& path, const QJsonObject &payload)
{
    const QString address = qEnvironmentVariable("APIGEAR_API_SERVER", "http://localhost:8000");
    QNetworkRequest request;
    request.setUrl(QUrl(QString("%1/%2").arg(address).arg(path)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    const QByteArray& data = QJsonDocument(payload).toJson(QJsonDocument::Compact);
    qDebug() << qPrintable(data);
    QNetworkReply* reply = m_network->post(request, data);
    // wait for finished signal
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    if(reply->error()) {
        qDebug() << reply->errorString();
        return QJsonObject();
    }
    const QJsonObject &response = QJsonDocument::fromJson(reply->readAll()).object();
    if(response.contains("state")) {
      applyState(response.value("state").toObject());
    }
    return response;
}


void {{$class}}::applyState(const QJsonObject &state)
{
  {{- range .Interface.Properties }}
  if(state.contains("{{.Name}}")) {
    const QJsonValue &jsValue = state.value("{{.Name}}");
    set{{Camel .Name}}(jsValue.toVariant().value<{{qtReturn "" .}}>());
  }
  {{- end }}
}