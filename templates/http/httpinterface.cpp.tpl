{% comment %} // Copyright (c) ApiGear UG 2020 {% endcomment -%}
{{ cppGpl .Module }}
{{- $class := printf "%sHttp" .Name }}
{{- $module := .Module.Name }}
#include "{{lower $class}}.h"

#include "../api/agent.h"
#include <QtQml>

{{$class}}::{{$class}}(QNetworkAccessManager *network, QObject *parent)
    : Abstract{{.Name}}(parent)
    , m_network(network)
{{- range .Properties }}
    , m_{{.Name}}({{qtDefault "" .}})
{{- end }}
{
}

{{$class}}::~{{$class}}()
{
}

{{- range .Properties }}

void {{$class}}::set{{Camel .Name}}({{qtParam "" .}})
{
    if (m_{{.Name}} != {{.Name}}) {
        m_{{.Name}} = {{.Name}};
        emit {{.Name}}Changed({{.Name}});
        {{.Name}}Agent::trace_state(this);
    }
}

{{qtReturn "" .}} {{$class}}::{{.Name}}() const
{
    return m_{{.Name}};
}

{{- end }}
{{- range .Operations }}

{{qtReturn "" .Return}} {{$class}}::{{.Name}}({{qtParams "" .Params}})
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
{{- range  .Params }}
    payload["{{.Name}}"] = QJsonValue::fromVariant(QVariant::fromValue< {{qtReturn "" .}} >({{.Name}}));
{{- end }}
    QJsonObject reply = post("{{$module}}/{{.Interface.Name}}/{{.Name}}", payload);
    qDebug() << QJsonDocument(reply).toJson();

    
    {{.Name}}Agent::trace_{{.Name}}(this, "{{join ", " .Params }});
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
  {{- range .Properties }}
  if(state.contains("{{.Name}}")) {
    const QJsonValue &jsValue = state.value("{{.Name}}");
    set{{Camel .Name}}(jsValue.toVariant().value<{{qtReturn "" .}}>());
  }
  {{- end }}
}