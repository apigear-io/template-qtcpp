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
#include "httpnestedstruct2interface.h"

#include "testbed2/api/agent.h"
#include <QtQml>

HttpNestedStruct2Interface::HttpNestedStruct2Interface(QNetworkAccessManager *network, QObject *parent)
    : AbstractNestedStruct2Interface(parent)
    , m_network(network)
    , m_prop1(NestedStruct1())
    , m_prop2(NestedStruct2())
{
}

HttpNestedStruct2Interface::~HttpNestedStruct2Interface()
{
}

void HttpNestedStruct2Interface::setProp1(const NestedStruct1& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        NestedStruct2InterfaceAgent::trace_state(this);
    }
}

NestedStruct1 HttpNestedStruct2Interface::prop1() const
{
    return m_prop1;
}

void HttpNestedStruct2Interface::setProp2(const NestedStruct2& prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
        NestedStruct2InterfaceAgent::trace_state(this);
    }
}

NestedStruct2 HttpNestedStruct2Interface::prop2() const
{
    return m_prop2;
}

NestedStruct1 HttpNestedStruct2Interface::func1(const NestedStruct1& param1)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["param1"] = QJsonValue::fromVariant(QVariant::fromValue< NestedStruct1 >(param1));
    QJsonObject reply = post("testbed2/NestedStruct2Interface/func1", payload);
    qDebug() << QJsonDocument(reply).toJson();
    NestedStruct2InterfaceAgent::trace_func1(this, param1);
    return NestedStruct1();
}

NestedStruct1 HttpNestedStruct2Interface::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["param1"] = QJsonValue::fromVariant(QVariant::fromValue< NestedStruct1 >(param1));
    payload["param2"] = QJsonValue::fromVariant(QVariant::fromValue< NestedStruct2 >(param2));
    QJsonObject reply = post("testbed2/NestedStruct2Interface/func2", payload);
    qDebug() << QJsonDocument(reply).toJson();
    NestedStruct2InterfaceAgent::trace_func2(this, param1, param2);
    return NestedStruct1();
}

QJsonObject HttpNestedStruct2Interface::post(const QString& path, const QJsonObject &payload)
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


void HttpNestedStruct2Interface::applyState(const QJsonObject &state)
{
  if(state.contains("prop1")) {
    const QJsonValue &jsValue = state.value("prop1");
    setProp1(jsValue.toVariant().value<NestedStruct1>());
  }
  if(state.contains("prop2")) {
    const QJsonValue &jsValue = state.value("prop2");
    setProp2(jsValue.toVariant().value<NestedStruct2>());
  }
}