/**
NO TITLE
Copyright (C) 2020 ApiGear UG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include "httpnam_es.h"
#include "apigear/utilities/logger.h"

#include <QtQml>

namespace tb_names {

HttpNam_Es::HttpNam_Es(QNetworkAccessManager *network, QObject *parent)
    : AbstractNamEs(parent)
    , m_network(network)
    , m_Switch(false)
    , m_SOME_PROPERTY(0)
    , m_Some_Poperty2(0)
{
}

HttpNam_Es::~HttpNam_Es()
{
}

void HttpNam_Es::setSwitch(bool Switch)
{
    if (m_Switch != Switch) {
        m_Switch = Switch;
        emit SwitchChanged(Switch);
    }
}

bool HttpNam_Es::Switch() const
{
    return m_Switch;
}

void HttpNam_Es::setSomeProperty(int SOME_PROPERTY)
{
    if (m_SOME_PROPERTY != SOME_PROPERTY) {
        m_SOME_PROPERTY = SOME_PROPERTY;
        emit SOME_PROPERTYChanged(SOME_PROPERTY);
    }
}

int HttpNam_Es::SOME_PROPERTY() const
{
    return m_SOME_PROPERTY;
}

void HttpNam_Es::setSomePoperty2(int Some_Poperty2)
{
    if (m_Some_Poperty2 != Some_Poperty2) {
        m_Some_Poperty2 = Some_Poperty2;
        emit Some_Poperty2Changed(Some_Poperty2);
    }
}

int HttpNam_Es::Some_Poperty2() const
{
    return m_Some_Poperty2;
}

void HttpNam_Es::someFunction(bool SOME_PARAM)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["SOME_PARAM"] = QJsonValue::fromVariant(QVariant::fromValue< bool >(SOME_PARAM));
    QJsonObject reply = post("tb.names/Nam_Es/SOME_FUNCTION", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return;
}

void HttpNam_Es::someFunction2(bool Some_Param)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["Some_Param"] = QJsonValue::fromVariant(QVariant::fromValue< bool >(Some_Param));
    QJsonObject reply = post("tb.names/Nam_Es/Some_Function2", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return;
}

QJsonObject HttpNam_Es::post(const QString& path, const QJsonObject &payload)
{
    const QString address = qEnvironmentVariable("APIGEAR_API_SERVER", "http://localhost:8000");
    QNetworkRequest request;
    request.setUrl(QUrl(QString("%1/%2").arg(address).arg(path)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    const QByteArray& data = QJsonDocument(payload).toJson(QJsonDocument::Compact);
    AG_LOG_DEBUG( qPrintable(data));
    QNetworkReply* reply = m_network->post(request, data);
    // wait for finished signal
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    if(reply->error()) {
        AG_LOG_ERROR(reply->errorString());
        return QJsonObject();
    }
    const QJsonObject &response = QJsonDocument::fromJson(reply->readAll()).object();
    if(response.contains("state")) {
      applyState(response.value("state").toObject());
    }
    return response;
}


void HttpNam_Es::applyState(const QJsonObject &state)
{
  if(state.contains("Switch")) {
    const QJsonValue &jsValue = state.value("Switch");
    setSwitch(jsValue.toVariant().value<bool>());
  }
  if(state.contains("SOME_PROPERTY")) {
    const QJsonValue &jsValue = state.value("SOME_PROPERTY");
    setSomeProperty(jsValue.toVariant().value<int>());
  }
  if(state.contains("Some_Poperty2")) {
    const QJsonValue &jsValue = state.value("Some_Poperty2");
    setSomePoperty2(jsValue.toVariant().value<int>());
  }
}

} // namespace tb_names 