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
#include "apigear/utilities/logger.h"


namespace tb_simple {

HttpSimpleInterface::HttpSimpleInterface(QNetworkAccessManager *network, QObject *parent)
    : AbstractSimpleInterface(parent)
    , m_network(network)
    , m_propBool(false)
    , m_propInt(0)
    , m_propInt32(0)
    , m_propInt64(0LL)
    , m_propFloat(0.0f)
    , m_propFloat32(0.0f)
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
    }
}

QString HttpSimpleInterface::propString() const
{
    return m_propString;
}

void HttpSimpleInterface::funcNoReturnValue(bool paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["paramBool"] = QJsonValue::fromVariant(QVariant::fromValue< bool >(paramBool));
    QJsonObject reply = post("tb.simple/SimpleInterface/funcNoReturnValue", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return;
}

bool HttpSimpleInterface::funcBool(bool paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["paramBool"] = QJsonValue::fromVariant(QVariant::fromValue< bool >(paramBool));
    QJsonObject reply = post("tb.simple/SimpleInterface/funcBool", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return false;
}

int HttpSimpleInterface::funcInt(int paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["paramInt"] = QJsonValue::fromVariant(QVariant::fromValue< int >(paramInt));
    QJsonObject reply = post("tb.simple/SimpleInterface/funcInt", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return 0;
}

qint32 HttpSimpleInterface::funcInt32(qint32 paramInt32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["paramInt32"] = QJsonValue::fromVariant(QVariant::fromValue< qint32 >(paramInt32));
    QJsonObject reply = post("tb.simple/SimpleInterface/funcInt32", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return 0;
}

qint64 HttpSimpleInterface::funcInt64(qint64 paramInt64)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["paramInt64"] = QJsonValue::fromVariant(QVariant::fromValue< qint64 >(paramInt64));
    QJsonObject reply = post("tb.simple/SimpleInterface/funcInt64", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return 0LL;
}

qreal HttpSimpleInterface::funcFloat(qreal paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["paramFloat"] = QJsonValue::fromVariant(QVariant::fromValue< qreal >(paramFloat));
    QJsonObject reply = post("tb.simple/SimpleInterface/funcFloat", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return 0.0f;
}

float HttpSimpleInterface::funcFloat32(float paramFloat32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["paramFloat32"] = QJsonValue::fromVariant(QVariant::fromValue< float >(paramFloat32));
    QJsonObject reply = post("tb.simple/SimpleInterface/funcFloat32", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return 0.0f;
}

double HttpSimpleInterface::funcFloat64(double paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["paramFloat"] = QJsonValue::fromVariant(QVariant::fromValue< double >(paramFloat));
    QJsonObject reply = post("tb.simple/SimpleInterface/funcFloat64", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return 0.0;
}

QString HttpSimpleInterface::funcString(const QString& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["paramString"] = QJsonValue::fromVariant(QVariant::fromValue< QString >(paramString));
    QJsonObject reply = post("tb.simple/SimpleInterface/funcString", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return QString();
}

QJsonObject HttpSimpleInterface::post(const QString& path, const QJsonObject &payload)
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