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
#include "httpnestedstruct3interface.h"
#include "apigear/utilities/logger.h"


namespace testbed2 {

HttpNestedStruct3Interface::HttpNestedStruct3Interface(QNetworkAccessManager *network, QObject *parent)
    : AbstractNestedStruct3Interface(parent)
    , m_network(network)
    , m_prop1(NestedStruct1())
    , m_prop2(NestedStruct2())
    , m_prop3(NestedStruct3())
{
}

HttpNestedStruct3Interface::~HttpNestedStruct3Interface()
{
}

void HttpNestedStruct3Interface::setProp1(const NestedStruct1& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
    }
}

NestedStruct1 HttpNestedStruct3Interface::prop1() const
{
    return m_prop1;
}

void HttpNestedStruct3Interface::setProp2(const NestedStruct2& prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
    }
}

NestedStruct2 HttpNestedStruct3Interface::prop2() const
{
    return m_prop2;
}

void HttpNestedStruct3Interface::setProp3(const NestedStruct3& prop3)
{
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        emit prop3Changed(prop3);
    }
}

NestedStruct3 HttpNestedStruct3Interface::prop3() const
{
    return m_prop3;
}

NestedStruct1 HttpNestedStruct3Interface::func1(const NestedStruct1& param1)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["param1"] = QJsonValue::fromVariant(QVariant::fromValue< NestedStruct1 >(param1));
    QJsonObject reply = post("testbed2/NestedStruct3Interface/func1", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return NestedStruct1();
}

NestedStruct1 HttpNestedStruct3Interface::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["param1"] = QJsonValue::fromVariant(QVariant::fromValue< NestedStruct1 >(param1));
    payload["param2"] = QJsonValue::fromVariant(QVariant::fromValue< NestedStruct2 >(param2));
    QJsonObject reply = post("testbed2/NestedStruct3Interface/func2", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return NestedStruct1();
}

NestedStruct1 HttpNestedStruct3Interface::func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["param1"] = QJsonValue::fromVariant(QVariant::fromValue< NestedStruct1 >(param1));
    payload["param2"] = QJsonValue::fromVariant(QVariant::fromValue< NestedStruct2 >(param2));
    payload["param3"] = QJsonValue::fromVariant(QVariant::fromValue< NestedStruct3 >(param3));
    QJsonObject reply = post("testbed2/NestedStruct3Interface/func3", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return NestedStruct1();
}

QJsonObject HttpNestedStruct3Interface::post(const QString& path, const QJsonObject &payload)
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


void HttpNestedStruct3Interface::applyState(const QJsonObject &state)
{
  if(state.contains("prop1")) {
    const QJsonValue &jsValue = state.value("prop1");
    setProp1(jsValue.toVariant().value<NestedStruct1>());
  }
  if(state.contains("prop2")) {
    const QJsonValue &jsValue = state.value("prop2");
    setProp2(jsValue.toVariant().value<NestedStruct2>());
  }
  if(state.contains("prop3")) {
    const QJsonValue &jsValue = state.value("prop3");
    setProp3(jsValue.toVariant().value<NestedStruct3>());
  }
}

} // namespace testbed2 