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
#include "httpsimplearrayinterface.h"

#include "../api/agent.h"
#include <QtQml>

HttpSimpleArrayInterface::HttpSimpleArrayInterface(QNetworkAccessManager *network, QObject *parent)
    : AbstractSimpleArrayInterface(parent)
    , m_network(network)
    , m_propBool(QList<bool>())
    , m_propInt(QList<int>())
    , m_propFloat(QList<qreal>())
    , m_propString(QList<QString>())
{
}

HttpSimpleArrayInterface::~HttpSimpleArrayInterface()
{
}

void HttpSimpleArrayInterface::setPropBool(const QList<bool>& propBool)
{
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
        SimpleArrayInterfaceAgent::trace_state(this);
    }
}

QList<bool> HttpSimpleArrayInterface::propBool() const
{
    return m_propBool;
}

void HttpSimpleArrayInterface::setPropInt(const QList<int>& propInt)
{
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
        SimpleArrayInterfaceAgent::trace_state(this);
    }
}

QList<int> HttpSimpleArrayInterface::propInt() const
{
    return m_propInt;
}

void HttpSimpleArrayInterface::setPropFloat(const QList<qreal>& propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
        SimpleArrayInterfaceAgent::trace_state(this);
    }
}

QList<qreal> HttpSimpleArrayInterface::propFloat() const
{
    return m_propFloat;
}

void HttpSimpleArrayInterface::setPropString(const QList<QString>& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
        SimpleArrayInterfaceAgent::trace_state(this);
    }
}

QList<QString> HttpSimpleArrayInterface::propString() const
{
    return m_propString;
}

QList<bool> HttpSimpleArrayInterface::funcBool(const QList<bool>& paramBool)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["paramBool"] = QJsonValue::fromVariant(QVariant::fromValue< QList<bool> >(paramBool));
    QJsonObject reply = post("tb.simple/SimpleArrayInterface/funcBool", payload);
    qDebug() << QJsonDocument(reply).toJson();
    SimpleArrayInterfaceAgent::trace_funcBool(this, paramBool);
    return QList<bool>();
}

QList<int> HttpSimpleArrayInterface::funcInt(const QList<int>& paramInt)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["paramInt"] = QJsonValue::fromVariant(QVariant::fromValue< QList<int> >(paramInt));
    QJsonObject reply = post("tb.simple/SimpleArrayInterface/funcInt", payload);
    qDebug() << QJsonDocument(reply).toJson();
    SimpleArrayInterfaceAgent::trace_funcInt(this, paramInt);
    return QList<int>();
}

QList<qreal> HttpSimpleArrayInterface::funcFloat(const QList<qreal>& paramFloat)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["paramFloat"] = QJsonValue::fromVariant(QVariant::fromValue< QList<qreal> >(paramFloat));
    QJsonObject reply = post("tb.simple/SimpleArrayInterface/funcFloat", payload);
    qDebug() << QJsonDocument(reply).toJson();
    SimpleArrayInterfaceAgent::trace_funcFloat(this, paramFloat);
    return QList<qreal>();
}

QList<QString> HttpSimpleArrayInterface::funcString(const QList<QString>& paramString)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["paramString"] = QJsonValue::fromVariant(QVariant::fromValue< QList<QString> >(paramString));
    QJsonObject reply = post("tb.simple/SimpleArrayInterface/funcString", payload);
    qDebug() << QJsonDocument(reply).toJson();
    SimpleArrayInterfaceAgent::trace_funcString(this, paramString);
    return QList<QString>();
}

QJsonObject HttpSimpleArrayInterface::post(const QString& path, const QJsonObject &payload)
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


void HttpSimpleArrayInterface::applyState(const QJsonObject &state)
{
  if(state.contains("propBool")) {
    const QJsonValue &jsValue = state.value("propBool");
    setPropBool(jsValue.toVariant().value<QList<bool>>());
  }
  if(state.contains("propInt")) {
    const QJsonValue &jsValue = state.value("propInt");
    setPropInt(jsValue.toVariant().value<QList<int>>());
  }
  if(state.contains("propFloat")) {
    const QJsonValue &jsValue = state.value("propFloat");
    setPropFloat(jsValue.toVariant().value<QList<qreal>>());
  }
  if(state.contains("propString")) {
    const QJsonValue &jsValue = state.value("propString");
    setPropString(jsValue.toVariant().value<QList<QString>>());
  }
}