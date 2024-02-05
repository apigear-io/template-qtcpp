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
#include "httpsameenum2interface.h"
#include "apigear/utilities/logger.h"

#include <QtQml>

namespace tb_same1 {

HttpSameEnum2Interface::HttpSameEnum2Interface(QNetworkAccessManager *network, QObject *parent)
    : AbstractSameEnum2Interface(parent)
    , m_network(network)
    , m_prop1(Enum1::Value1)
    , m_prop2(Enum2::Value1)
{
}

HttpSameEnum2Interface::~HttpSameEnum2Interface()
{
}

void HttpSameEnum2Interface::setProp1(Enum1::Enum1Enum prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
    }
}

Enum1::Enum1Enum HttpSameEnum2Interface::prop1() const
{
    return m_prop1;
}

void HttpSameEnum2Interface::setProp2(Enum2::Enum2Enum prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
    }
}

Enum2::Enum2Enum HttpSameEnum2Interface::prop2() const
{
    return m_prop2;
}

Enum1::Enum1Enum HttpSameEnum2Interface::func1(Enum1::Enum1Enum param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["param1"] = QJsonValue::fromVariant(QVariant::fromValue< Enum1::Enum1Enum >(param1));
    QJsonObject reply = post("tb.same1/SameEnum2Interface/func1", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return Enum1::Value1;
}

Enum1::Enum1Enum HttpSameEnum2Interface::func2(Enum1::Enum1Enum param1, Enum2::Enum2Enum param2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["param1"] = QJsonValue::fromVariant(QVariant::fromValue< Enum1::Enum1Enum >(param1));
    payload["param2"] = QJsonValue::fromVariant(QVariant::fromValue< Enum2::Enum2Enum >(param2));
    QJsonObject reply = post("tb.same1/SameEnum2Interface/func2", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return Enum1::Value1;
}

QJsonObject HttpSameEnum2Interface::post(const QString& path, const QJsonObject &payload)
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


void HttpSameEnum2Interface::applyState(const QJsonObject &state)
{
  if(state.contains("prop1")) {
    const QJsonValue &jsValue = state.value("prop1");
    setProp1(jsValue.toVariant().value<Enum1::Enum1Enum>());
  }
  if(state.contains("prop2")) {
    const QJsonValue &jsValue = state.value("prop2");
    setProp2(jsValue.toVariant().value<Enum2::Enum2Enum>());
  }
}

} // namespace tb_same1 