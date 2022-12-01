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
#include "httpmanyparaminterface.h"

#include "testbed2/api/agent.h"
#include <QtQml>

HttpManyParamInterface::HttpManyParamInterface(QNetworkAccessManager *network, QObject *parent)
    : AbstractManyParamInterface(parent)
    , m_network(network)
    , m_prop1(0)
    , m_prop2(0)
    , m_prop3(0)
    , m_prop4(0)
{
}

HttpManyParamInterface::~HttpManyParamInterface()
{
}

void HttpManyParamInterface::setProp1(int prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        ManyParamInterfaceAgent::trace_state(this);
    }
}

int HttpManyParamInterface::prop1() const
{
    return m_prop1;
}

void HttpManyParamInterface::setProp2(int prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
        ManyParamInterfaceAgent::trace_state(this);
    }
}

int HttpManyParamInterface::prop2() const
{
    return m_prop2;
}

void HttpManyParamInterface::setProp3(int prop3)
{
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        emit prop3Changed(prop3);
        ManyParamInterfaceAgent::trace_state(this);
    }
}

int HttpManyParamInterface::prop3() const
{
    return m_prop3;
}

void HttpManyParamInterface::setProp4(int prop4)
{
    if (m_prop4 != prop4) {
        m_prop4 = prop4;
        emit prop4Changed(prop4);
        ManyParamInterfaceAgent::trace_state(this);
    }
}

int HttpManyParamInterface::prop4() const
{
    return m_prop4;
}

int HttpManyParamInterface::func1(int param1)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["param1"] = QJsonValue::fromVariant(QVariant::fromValue< int >(param1));
    QJsonObject reply = post("testbed2/ManyParamInterface/func1", payload);
    qDebug() << QJsonDocument(reply).toJson();
    ManyParamInterfaceAgent::trace_func1(this, param1);
    return 0;
}

int HttpManyParamInterface::func2(int param1, int param2)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["param1"] = QJsonValue::fromVariant(QVariant::fromValue< int >(param1));
    payload["param2"] = QJsonValue::fromVariant(QVariant::fromValue< int >(param2));
    QJsonObject reply = post("testbed2/ManyParamInterface/func2", payload);
    qDebug() << QJsonDocument(reply).toJson();
    ManyParamInterfaceAgent::trace_func2(this, param1, param2);
    return 0;
}

int HttpManyParamInterface::func3(int param1, int param2, int param3)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["param1"] = QJsonValue::fromVariant(QVariant::fromValue< int >(param1));
    payload["param2"] = QJsonValue::fromVariant(QVariant::fromValue< int >(param2));
    payload["param3"] = QJsonValue::fromVariant(QVariant::fromValue< int >(param3));
    QJsonObject reply = post("testbed2/ManyParamInterface/func3", payload);
    qDebug() << QJsonDocument(reply).toJson();
    ManyParamInterfaceAgent::trace_func3(this, param1, param2, param3);
    return 0;
}

int HttpManyParamInterface::func4(int param1, int param2, int param3, int param4)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["param1"] = QJsonValue::fromVariant(QVariant::fromValue< int >(param1));
    payload["param2"] = QJsonValue::fromVariant(QVariant::fromValue< int >(param2));
    payload["param3"] = QJsonValue::fromVariant(QVariant::fromValue< int >(param3));
    payload["param4"] = QJsonValue::fromVariant(QVariant::fromValue< int >(param4));
    QJsonObject reply = post("testbed2/ManyParamInterface/func4", payload);
    qDebug() << QJsonDocument(reply).toJson();
    ManyParamInterfaceAgent::trace_func4(this, param1, param2, param3, param4);
    return 0;
}

QJsonObject HttpManyParamInterface::post(const QString& path, const QJsonObject &payload)
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


void HttpManyParamInterface::applyState(const QJsonObject &state)
{
  if(state.contains("prop1")) {
    const QJsonValue &jsValue = state.value("prop1");
    setProp1(jsValue.toVariant().value<int>());
  }
  if(state.contains("prop2")) {
    const QJsonValue &jsValue = state.value("prop2");
    setProp2(jsValue.toVariant().value<int>());
  }
  if(state.contains("prop3")) {
    const QJsonValue &jsValue = state.value("prop3");
    setProp3(jsValue.toVariant().value<int>());
  }
  if(state.contains("prop4")) {
    const QJsonValue &jsValue = state.value("prop4");
    setProp4(jsValue.toVariant().value<int>());
  }
}