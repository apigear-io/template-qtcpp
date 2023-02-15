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
#include "httpsimpleinterface.h"

#include "tb_simple/api/agent.h"
#include <QtQml>

namespace tb_simple {

HttpSimpleInterface::HttpSimpleInterface(QNetworkAccessManager *network, QObject *parent)
    : AbstractSimpleInterface(parent)
    , m_network(network)
    , m_propBool(false)
    , m_propInt(0)
    , m_propInt32(0)
    , m_propInt64(0)
    , m_propFloat(0.0)
    , m_propFloat32(0.0)
    , m_propFloat64(0.0)
    , m_propString(QString())
{
}

HttpSimpleInterface::~HttpSimpleInterface()
{
}

void HttpSimpleInterface::setPropBool(bool propBool)
{
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
        SimpleInterfaceAgent::trace_state(this);
    }
}

bool HttpSimpleInterface::propBool() const
{
    return m_propBool;
}

void HttpSimpleInterface::setPropInt(int propInt)
{
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
        SimpleInterfaceAgent::trace_state(this);
    }
}

int HttpSimpleInterface::propInt() const
{
    return m_propInt;
}

void HttpSimpleInterface::setPropInt32(qint32 propInt32)
{
    if (m_propInt32 != propInt32) {
        m_propInt32 = propInt32;
        emit propInt32Changed(propInt32);
        SimpleInterfaceAgent::trace_state(this);
    }
}

qint32 HttpSimpleInterface::propInt32() const
{
    return m_propInt32;
}

void HttpSimpleInterface::setPropInt64(qint64 propInt64)
{
    if (m_propInt64 != propInt64) {
        m_propInt64 = propInt64;
        emit propInt64Changed(propInt64);
        SimpleInterfaceAgent::trace_state(this);
    }
}

qint64 HttpSimpleInterface::propInt64() const
{
    return m_propInt64;
}

void HttpSimpleInterface::setPropFloat(qreal propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
        SimpleInterfaceAgent::trace_state(this);
    }
}

qreal HttpSimpleInterface::propFloat() const
{
    return m_propFloat;
}

void HttpSimpleInterface::setPropFloat32(float propFloat32)
{
    if (m_propFloat32 != propFloat32) {
        m_propFloat32 = propFloat32;
        emit propFloat32Changed(propFloat32);
        SimpleInterfaceAgent::trace_state(this);
    }
}

float HttpSimpleInterface::propFloat32() const
{
    return m_propFloat32;
}

void HttpSimpleInterface::setPropFloat64(double propFloat64)
{
    if (m_propFloat64 != propFloat64) {
        m_propFloat64 = propFloat64;
        emit propFloat64Changed(propFloat64);
        SimpleInterfaceAgent::trace_state(this);
    }
}

double HttpSimpleInterface::propFloat64() const
{
    return m_propFloat64;
}

void HttpSimpleInterface::setPropString(const QString& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
        SimpleInterfaceAgent::trace_state(this);
    }
}

QString HttpSimpleInterface::propString() const
{
    return m_propString;
}

bool HttpSimpleInterface::funcBool(bool paramBool)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["paramBool"] = QJsonValue::fromVariant(QVariant::fromValue< bool >(paramBool));
    QJsonObject reply = post("tb.simple/SimpleInterface/funcBool", payload);
    qDebug() << QJsonDocument(reply).toJson();
    SimpleInterfaceAgent::trace_funcBool(this, paramBool);
    return false;
}

int HttpSimpleInterface::funcInt(int paramInt)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["paramInt"] = QJsonValue::fromVariant(QVariant::fromValue< int >(paramInt));
    QJsonObject reply = post("tb.simple/SimpleInterface/funcInt", payload);
    qDebug() << QJsonDocument(reply).toJson();
    SimpleInterfaceAgent::trace_funcInt(this, paramInt);
    return 0;
}

qint32 HttpSimpleInterface::funcInt32(qint32 paramInt32)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["paramInt32"] = QJsonValue::fromVariant(QVariant::fromValue< qint32 >(paramInt32));
    QJsonObject reply = post("tb.simple/SimpleInterface/funcInt32", payload);
    qDebug() << QJsonDocument(reply).toJson();
    SimpleInterfaceAgent::trace_funcInt32(this, paramInt32);
    return 0;
}

qint64 HttpSimpleInterface::funcInt64(qint64 paramInt64)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["paramInt64"] = QJsonValue::fromVariant(QVariant::fromValue< qint64 >(paramInt64));
    QJsonObject reply = post("tb.simple/SimpleInterface/funcInt64", payload);
    qDebug() << QJsonDocument(reply).toJson();
    SimpleInterfaceAgent::trace_funcInt64(this, paramInt64);
    return 0;
}

qreal HttpSimpleInterface::funcFloat(qreal paramFloat)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["paramFloat"] = QJsonValue::fromVariant(QVariant::fromValue< qreal >(paramFloat));
    QJsonObject reply = post("tb.simple/SimpleInterface/funcFloat", payload);
    qDebug() << QJsonDocument(reply).toJson();
    SimpleInterfaceAgent::trace_funcFloat(this, paramFloat);
    return 0.0;
}

float HttpSimpleInterface::funcFloat32(float paramFloat32)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["paramFloat32"] = QJsonValue::fromVariant(QVariant::fromValue< float >(paramFloat32));
    QJsonObject reply = post("tb.simple/SimpleInterface/funcFloat32", payload);
    qDebug() << QJsonDocument(reply).toJson();
    SimpleInterfaceAgent::trace_funcFloat32(this, paramFloat32);
    return 0.0;
}

double HttpSimpleInterface::funcFloat64(double paramFloat)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["paramFloat"] = QJsonValue::fromVariant(QVariant::fromValue< double >(paramFloat));
    QJsonObject reply = post("tb.simple/SimpleInterface/funcFloat64", payload);
    qDebug() << QJsonDocument(reply).toJson();
    SimpleInterfaceAgent::trace_funcFloat64(this, paramFloat);
    return 0.0;
}

QString HttpSimpleInterface::funcString(const QString& paramString)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["paramString"] = QJsonValue::fromVariant(QVariant::fromValue< QString >(paramString));
    QJsonObject reply = post("tb.simple/SimpleInterface/funcString", payload);
    qDebug() << QJsonDocument(reply).toJson();
    SimpleInterfaceAgent::trace_funcString(this, paramString);
    return QString();
}

QJsonObject HttpSimpleInterface::post(const QString& path, const QJsonObject &payload)
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


void HttpSimpleInterface::applyState(const QJsonObject &state)
{
  if(state.contains("propBool")) {
    const QJsonValue &jsValue = state.value("propBool");
    setPropBool(jsValue.toVariant().value<bool>());
  }
  if(state.contains("propInt")) {
    const QJsonValue &jsValue = state.value("propInt");
    setPropInt(jsValue.toVariant().value<int>());
  }
  if(state.contains("propInt32")) {
    const QJsonValue &jsValue = state.value("propInt32");
    setPropInt32(jsValue.toVariant().value<qint32>());
  }
  if(state.contains("propInt64")) {
    const QJsonValue &jsValue = state.value("propInt64");
    setPropInt64(jsValue.toVariant().value<qint64>());
  }
  if(state.contains("propFloat")) {
    const QJsonValue &jsValue = state.value("propFloat");
    setPropFloat(jsValue.toVariant().value<qreal>());
  }
  if(state.contains("propFloat32")) {
    const QJsonValue &jsValue = state.value("propFloat32");
    setPropFloat32(jsValue.toVariant().value<float>());
  }
  if(state.contains("propFloat64")) {
    const QJsonValue &jsValue = state.value("propFloat64");
    setPropFloat64(jsValue.toVariant().value<double>());
  }
  if(state.contains("propString")) {
    const QJsonValue &jsValue = state.value("propString");
    setPropString(jsValue.toVariant().value<QString>());
  }
}

} // namespace tb_simple 