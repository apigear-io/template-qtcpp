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
#include "httpcounter.h"
#include "apigear/utilities/logger.h"


namespace counter {

HttpCounter::HttpCounter(QNetworkAccessManager *network, QObject *parent)
    : AbstractCounter(parent)
    , m_network(network)
    , m_vector(custom_types::Vector3D())
    , m_extern_vector(QVector3D())
{
}

HttpCounter::~HttpCounter()
{
}

void HttpCounter::setVector(const custom_types::Vector3D& vector)
{
    if (m_vector != vector) {
        m_vector = vector;
        emit vectorChanged(vector);
    }
}

custom_types::Vector3D HttpCounter::vector() const
{
    return m_vector;
}

void HttpCounter::setExternVector(const QVector3D& extern_vector)
{
    if (m_extern_vector != extern_vector) {
        m_extern_vector = extern_vector;
        emit extern_vectorChanged(extern_vector);
    }
}

QVector3D HttpCounter::extern_vector() const
{
    return m_extern_vector;
}

QVector3D HttpCounter::increment(const QVector3D& vec)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["vec"] = QJsonValue::fromVariant(QVariant::fromValue< QVector3D >(vec));
    QJsonObject reply = post("counter/Counter/increment", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return QVector3D();
}

custom_types::Vector3D HttpCounter::decrement(const custom_types::Vector3D& vec)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["vec"] = QJsonValue::fromVariant(QVariant::fromValue< custom_types::Vector3D >(vec));
    QJsonObject reply = post("counter/Counter/decrement", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return custom_types::Vector3D();
}

QJsonObject HttpCounter::post(const QString& path, const QJsonObject &payload)
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


void HttpCounter::applyState(const QJsonObject &state)
{
  if(state.contains("vector")) {
    const QJsonValue &jsValue = state.value("vector");
    setVector(jsValue.toVariant().value<custom_types::Vector3D>());
  }
  if(state.contains("extern_vector")) {
    const QJsonValue &jsValue = state.value("extern_vector");
    setExternVector(jsValue.toVariant().value<QVector3D>());
  }
}

} // namespace counter 