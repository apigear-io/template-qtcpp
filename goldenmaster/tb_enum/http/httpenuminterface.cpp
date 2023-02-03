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
#include "httpenuminterface.h"

#include "tb_enum/api/agent.h"
#include <QtQml>

namespace tb_enum {

HttpEnumInterface::HttpEnumInterface(QNetworkAccessManager *network, QObject *parent)
    : AbstractEnumInterface(parent)
    , m_network(network)
    , m_prop0(Enum0::value0)
    , m_prop1(Enum1::value1)
    , m_prop2(Enum2::value2)
    , m_prop3(Enum3::value3)
{
}

HttpEnumInterface::~HttpEnumInterface()
{
}

void HttpEnumInterface::setProp0(Enum0::Enum0Enum prop0)
{
    if (m_prop0 != prop0) {
        m_prop0 = prop0;
        emit prop0Changed(prop0);
        EnumInterfaceAgent::trace_state(this);
    }
}

Enum0::Enum0Enum HttpEnumInterface::prop0() const
{
    return m_prop0;
}

void HttpEnumInterface::setProp1(Enum1::Enum1Enum prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        EnumInterfaceAgent::trace_state(this);
    }
}

Enum1::Enum1Enum HttpEnumInterface::prop1() const
{
    return m_prop1;
}

void HttpEnumInterface::setProp2(Enum2::Enum2Enum prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
        EnumInterfaceAgent::trace_state(this);
    }
}

Enum2::Enum2Enum HttpEnumInterface::prop2() const
{
    return m_prop2;
}

void HttpEnumInterface::setProp3(Enum3::Enum3Enum prop3)
{
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        emit prop3Changed(prop3);
        EnumInterfaceAgent::trace_state(this);
    }
}

Enum3::Enum3Enum HttpEnumInterface::prop3() const
{
    return m_prop3;
}

Enum0::Enum0Enum HttpEnumInterface::func0(Enum0::Enum0Enum param0)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["param0"] = QJsonValue::fromVariant(QVariant::fromValue< Enum0::Enum0Enum >(param0));
    QJsonObject reply = post("tb.enum/EnumInterface/func0", payload);
    qDebug() << QJsonDocument(reply).toJson();
    EnumInterfaceAgent::trace_func0(this, param0);
    return Enum0::value0;
}

Enum1::Enum1Enum HttpEnumInterface::func1(Enum1::Enum1Enum param1)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["param1"] = QJsonValue::fromVariant(QVariant::fromValue< Enum1::Enum1Enum >(param1));
    QJsonObject reply = post("tb.enum/EnumInterface/func1", payload);
    qDebug() << QJsonDocument(reply).toJson();
    EnumInterfaceAgent::trace_func1(this, param1);
    return Enum1::value1;
}

Enum2::Enum2Enum HttpEnumInterface::func2(Enum2::Enum2Enum param2)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["param2"] = QJsonValue::fromVariant(QVariant::fromValue< Enum2::Enum2Enum >(param2));
    QJsonObject reply = post("tb.enum/EnumInterface/func2", payload);
    qDebug() << QJsonDocument(reply).toJson();
    EnumInterfaceAgent::trace_func2(this, param2);
    return Enum2::value2;
}

Enum3::Enum3Enum HttpEnumInterface::func3(Enum3::Enum3Enum param3)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["param3"] = QJsonValue::fromVariant(QVariant::fromValue< Enum3::Enum3Enum >(param3));
    QJsonObject reply = post("tb.enum/EnumInterface/func3", payload);
    qDebug() << QJsonDocument(reply).toJson();
    EnumInterfaceAgent::trace_func3(this, param3);
    return Enum3::value3;
}

QJsonObject HttpEnumInterface::post(const QString& path, const QJsonObject &payload)
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


void HttpEnumInterface::applyState(const QJsonObject &state)
{
  if(state.contains("prop0")) {
    const QJsonValue &jsValue = state.value("prop0");
    setProp0(jsValue.toVariant().value<Enum0::Enum0Enum>());
  }
  if(state.contains("prop1")) {
    const QJsonValue &jsValue = state.value("prop1");
    setProp1(jsValue.toVariant().value<Enum1::Enum1Enum>());
  }
  if(state.contains("prop2")) {
    const QJsonValue &jsValue = state.value("prop2");
    setProp2(jsValue.toVariant().value<Enum2::Enum2Enum>());
  }
  if(state.contains("prop3")) {
    const QJsonValue &jsValue = state.value("prop3");
    setProp3(jsValue.toVariant().value<Enum3::Enum3Enum>());
  }
}

} // namespace tb_enum 