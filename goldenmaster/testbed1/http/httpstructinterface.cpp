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
#include "httpstructinterface.h"

#include "../api/agent.h"
#include <QtQml>

HttpStructInterface::HttpStructInterface(QNetworkAccessManager *network, QObject *parent)
    : AbstractStructInterface(parent)
    , m_network(network)
    , m_propBool(StructBool())
    , m_propInt(StructInt())
    , m_propFloat(StructFloat())
    , m_propString(StructString())
{
}

HttpStructInterface::~HttpStructInterface()
{
}

void HttpStructInterface::setPropBool(const StructBool& propBool)
{
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
        StructInterfaceAgent::trace_state(this);
    }
}

StructBool HttpStructInterface::propBool() const
{
    return m_propBool;
}

void HttpStructInterface::setPropInt(const StructInt& propInt)
{
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
        StructInterfaceAgent::trace_state(this);
    }
}

StructInt HttpStructInterface::propInt() const
{
    return m_propInt;
}

void HttpStructInterface::setPropFloat(const StructFloat& propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
        StructInterfaceAgent::trace_state(this);
    }
}

StructFloat HttpStructInterface::propFloat() const
{
    return m_propFloat;
}

void HttpStructInterface::setPropString(const StructString& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
        StructInterfaceAgent::trace_state(this);
    }
}

StructString HttpStructInterface::propString() const
{
    return m_propString;
}

StructBool HttpStructInterface::funcBool(const StructBool& paramBool)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["paramBool"] = QJsonValue::fromVariant(QVariant::fromValue< StructBool >(paramBool));
    QJsonObject reply = post("testbed1/StructInterface/funcBool", payload);
    qDebug() << QJsonDocument(reply).toJson();
    StructInterfaceAgent::trace_funcBool(this, paramBool);
    return StructBool();
}

StructBool HttpStructInterface::funcInt(const StructInt& paramInt)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["paramInt"] = QJsonValue::fromVariant(QVariant::fromValue< StructInt >(paramInt));
    QJsonObject reply = post("testbed1/StructInterface/funcInt", payload);
    qDebug() << QJsonDocument(reply).toJson();
    StructInterfaceAgent::trace_funcInt(this, paramInt);
    return StructBool();
}

StructFloat HttpStructInterface::funcFloat(const StructFloat& paramFloat)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["paramFloat"] = QJsonValue::fromVariant(QVariant::fromValue< StructFloat >(paramFloat));
    QJsonObject reply = post("testbed1/StructInterface/funcFloat", payload);
    qDebug() << QJsonDocument(reply).toJson();
    StructInterfaceAgent::trace_funcFloat(this, paramFloat);
    return StructFloat();
}

StructString HttpStructInterface::funcString(const StructString& paramString)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["paramString"] = QJsonValue::fromVariant(QVariant::fromValue< StructString >(paramString));
    QJsonObject reply = post("testbed1/StructInterface/funcString", payload);
    qDebug() << QJsonDocument(reply).toJson();
    StructInterfaceAgent::trace_funcString(this, paramString);
    return StructString();
}

QJsonObject HttpStructInterface::post(const QString& path, const QJsonObject &payload)
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


void HttpStructInterface::applyState(const QJsonObject &state)
{
  if(state.contains("propBool")) {
    const QJsonValue &jsValue = state.value("propBool");
    setPropBool(jsValue.toVariant().value<StructBool>());
  }
  if(state.contains("propInt")) {
    const QJsonValue &jsValue = state.value("propInt");
    setPropInt(jsValue.toVariant().value<StructInt>());
  }
  if(state.contains("propFloat")) {
    const QJsonValue &jsValue = state.value("propFloat");
    setPropFloat(jsValue.toVariant().value<StructFloat>());
  }
  if(state.contains("propString")) {
    const QJsonValue &jsValue = state.value("propString");
    setPropString(jsValue.toVariant().value<StructString>());
  }
}