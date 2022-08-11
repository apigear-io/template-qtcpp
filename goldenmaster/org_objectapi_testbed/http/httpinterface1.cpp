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
#include "httpinterface1.h"

#include "../api/agent.h"
#include <QtQml>

HttpInterface1::HttpInterface1(QNetworkAccessManager *network, QObject *parent)
    : AbstractInterface1(parent)
    , m_network(network)
    , m_prop1(false)
    , m_prop2(0)
    , m_prop3(0.0)
    , m_prop4(QString())
    , m_prop5(QList<int>())
    , m_prop6(Struct1())
    , m_prop7(0)
    , m_prop10(QList<int>())
    , m_prop11(QList<Struct1>())
    , m_prop12(QList<Enum1::Enum1Enum>())
    , m_prop14(QList<Struct1>())
{
}

HttpInterface1::~HttpInterface1()
{
}

void HttpInterface1::setProp1(bool prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        Interface1Agent::trace_state(this);
    }
}

bool HttpInterface1::prop1() const
{
    return m_prop1;
}

void HttpInterface1::setProp2(int prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
        Interface1Agent::trace_state(this);
    }
}

int HttpInterface1::prop2() const
{
    return m_prop2;
}

void HttpInterface1::setProp3(qreal prop3)
{
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        emit prop3Changed(prop3);
        Interface1Agent::trace_state(this);
    }
}

qreal HttpInterface1::prop3() const
{
    return m_prop3;
}

void HttpInterface1::setProp4(const QString& prop4)
{
    if (m_prop4 != prop4) {
        m_prop4 = prop4;
        emit prop4Changed(prop4);
        Interface1Agent::trace_state(this);
    }
}

QString HttpInterface1::prop4() const
{
    return m_prop4;
}

void HttpInterface1::setProp5(const QList<int>& prop5)
{
    if (m_prop5 != prop5) {
        m_prop5 = prop5;
        emit prop5Changed(prop5);
        Interface1Agent::trace_state(this);
    }
}

QList<int> HttpInterface1::prop5() const
{
    return m_prop5;
}

void HttpInterface1::setProp6(const Struct1& prop6)
{
    if (m_prop6 != prop6) {
        m_prop6 = prop6;
        emit prop6Changed(prop6);
        Interface1Agent::trace_state(this);
    }
}

Struct1 HttpInterface1::prop6() const
{
    return m_prop6;
}

void HttpInterface1::setProp7(int prop7)
{
    if (m_prop7 != prop7) {
        m_prop7 = prop7;
        emit prop7Changed(prop7);
        Interface1Agent::trace_state(this);
    }
}

int HttpInterface1::prop7() const
{
    return m_prop7;
}

void HttpInterface1::setProp10(const QList<int>& prop10)
{
    if (m_prop10 != prop10) {
        m_prop10 = prop10;
        emit prop10Changed(prop10);
        Interface1Agent::trace_state(this);
    }
}

QList<int> HttpInterface1::prop10() const
{
    return m_prop10;
}

void HttpInterface1::setProp11(const QList<Struct1>& prop11)
{
    if (m_prop11 != prop11) {
        m_prop11 = prop11;
        emit prop11Changed(prop11);
        Interface1Agent::trace_state(this);
    }
}

QList<Struct1> HttpInterface1::prop11() const
{
    return m_prop11;
}

void HttpInterface1::setProp12(const QList<Enum1::Enum1Enum>& prop12)
{
    if (m_prop12 != prop12) {
        m_prop12 = prop12;
        emit prop12Changed(prop12);
        Interface1Agent::trace_state(this);
    }
}

QList<Enum1::Enum1Enum> HttpInterface1::prop12() const
{
    return m_prop12;
}

void HttpInterface1::setProp14(const QList<Struct1>& prop14)
{
    if (m_prop14 != prop14) {
        m_prop14 = prop14;
        emit prop14Changed(prop14);
        Interface1Agent::trace_state(this);
    }
}

QList<Struct1> HttpInterface1::prop14() const
{
    return m_prop14;
}

void HttpInterface1::op1()
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    QJsonObject reply = post("org.objectapi.testbed/Interface1/op1", payload);
    qDebug() << QJsonDocument(reply).toJson();
    Interface1Agent::trace_op1(this);
    return ;
}

void HttpInterface1::op2(int step)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["step"] = QJsonValue::fromVariant(QVariant::fromValue< int >(step));
    QJsonObject reply = post("org.objectapi.testbed/Interface1/op2", payload);
    qDebug() << QJsonDocument(reply).toJson();
    Interface1Agent::trace_op2(this, step);
    return ;
}

int HttpInterface1::op3()
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    QJsonObject reply = post("org.objectapi.testbed/Interface1/op3", payload);
    qDebug() << QJsonDocument(reply).toJson();
    Interface1Agent::trace_op3(this);
    return 0;
}

QJsonObject HttpInterface1::post(const QString& path, const QJsonObject &payload)
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


void HttpInterface1::applyState(const QJsonObject &state)
{
  if(state.contains("prop1")) {
    const QJsonValue &jsValue = state.value("prop1");
    setProp1(jsValue.toVariant().value<bool>());
  }
  if(state.contains("prop2")) {
    const QJsonValue &jsValue = state.value("prop2");
    setProp2(jsValue.toVariant().value<int>());
  }
  if(state.contains("prop3")) {
    const QJsonValue &jsValue = state.value("prop3");
    setProp3(jsValue.toVariant().value<qreal>());
  }
  if(state.contains("prop4")) {
    const QJsonValue &jsValue = state.value("prop4");
    setProp4(jsValue.toVariant().value<QString>());
  }
  if(state.contains("prop5")) {
    const QJsonValue &jsValue = state.value("prop5");
    setProp5(jsValue.toVariant().value<QList<int>>());
  }
  if(state.contains("prop6")) {
    const QJsonValue &jsValue = state.value("prop6");
    setProp6(jsValue.toVariant().value<Struct1>());
  }
  if(state.contains("prop7")) {
    const QJsonValue &jsValue = state.value("prop7");
    setProp7(jsValue.toVariant().value<int>());
  }
  if(state.contains("prop10")) {
    const QJsonValue &jsValue = state.value("prop10");
    setProp10(jsValue.toVariant().value<QList<int>>());
  }
  if(state.contains("prop11")) {
    const QJsonValue &jsValue = state.value("prop11");
    setProp11(jsValue.toVariant().value<QList<Struct1>>());
  }
  if(state.contains("prop12")) {
    const QJsonValue &jsValue = state.value("prop12");
    setProp12(jsValue.toVariant().value<QList<Enum1::Enum1Enum>>());
  }
  if(state.contains("prop14")) {
    const QJsonValue &jsValue = state.value("prop14");
    setProp14(jsValue.toVariant().value<QList<Struct1>>());
  }
}