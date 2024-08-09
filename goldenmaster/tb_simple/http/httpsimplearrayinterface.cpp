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
#include "apigear/utilities/logger.h"


namespace tb_simple {

HttpSimpleArrayInterface::HttpSimpleArrayInterface(QNetworkAccessManager *network, QObject *parent)
    : AbstractSimpleArrayInterface(parent)
    , m_network(network)
    , m_propBool(QList<bool>())
    , m_propInt(QList<int>())
    , m_propInt32(QList<qint32>())
    , m_propInt64(QList<qint64>())
    , m_propFloat(QList<qreal>())
    , m_propFloat32(QList<float>())
    , m_propFloat64(QList<double>())
    , m_propString(QList<QString>())
    , m_propReadOnlyString(QString())
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
    }
}

QList<int> HttpSimpleArrayInterface::propInt() const
{
    return m_propInt;
}

void HttpSimpleArrayInterface::setPropInt32(const QList<qint32>& propInt32)
{
    if (m_propInt32 != propInt32) {
        m_propInt32 = propInt32;
        emit propInt32Changed(propInt32);
    }
}

QList<qint32> HttpSimpleArrayInterface::propInt32() const
{
    return m_propInt32;
}

void HttpSimpleArrayInterface::setPropInt64(const QList<qint64>& propInt64)
{
    if (m_propInt64 != propInt64) {
        m_propInt64 = propInt64;
        emit propInt64Changed(propInt64);
    }
}

QList<qint64> HttpSimpleArrayInterface::propInt64() const
{
    return m_propInt64;
}

void HttpSimpleArrayInterface::setPropFloat(const QList<qreal>& propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
    }
}

QList<qreal> HttpSimpleArrayInterface::propFloat() const
{
    return m_propFloat;
}

void HttpSimpleArrayInterface::setPropFloat32(const QList<float>& propFloat32)
{
    if (m_propFloat32 != propFloat32) {
        m_propFloat32 = propFloat32;
        emit propFloat32Changed(propFloat32);
    }
}

QList<float> HttpSimpleArrayInterface::propFloat32() const
{
    return m_propFloat32;
}

void HttpSimpleArrayInterface::setPropFloat64(const QList<double>& propFloat64)
{
    if (m_propFloat64 != propFloat64) {
        m_propFloat64 = propFloat64;
        emit propFloat64Changed(propFloat64);
    }
}

QList<double> HttpSimpleArrayInterface::propFloat64() const
{
    return m_propFloat64;
}

void HttpSimpleArrayInterface::setPropString(const QList<QString>& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
    }
}

QList<QString> HttpSimpleArrayInterface::propString() const
{
    return m_propString;
}

void HttpSimpleArrayInterface::setPropReadOnlyString(const QString& propReadOnlyString)
{
    if (m_propReadOnlyString != propReadOnlyString) {
        m_propReadOnlyString = propReadOnlyString;
        emit propReadOnlyStringChanged(propReadOnlyString);
    }
}

QString HttpSimpleArrayInterface::propReadOnlyString() const
{
    return m_propReadOnlyString;
}

QList<bool> HttpSimpleArrayInterface::funcBool(const QList<bool>& paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["paramBool"] = QJsonValue::fromVariant(QVariant::fromValue< QList<bool> >(paramBool));
    QJsonObject reply = post("tb.simple/SimpleArrayInterface/funcBool", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return QList<bool>();
}

QList<int> HttpSimpleArrayInterface::funcInt(const QList<int>& paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["paramInt"] = QJsonValue::fromVariant(QVariant::fromValue< QList<int> >(paramInt));
    QJsonObject reply = post("tb.simple/SimpleArrayInterface/funcInt", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return QList<int>();
}

QList<qint32> HttpSimpleArrayInterface::funcInt32(const QList<qint32>& paramInt32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["paramInt32"] = QJsonValue::fromVariant(QVariant::fromValue< QList<qint32> >(paramInt32));
    QJsonObject reply = post("tb.simple/SimpleArrayInterface/funcInt32", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return QList<qint32>();
}

QList<qint64> HttpSimpleArrayInterface::funcInt64(const QList<qint64>& paramInt64)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["paramInt64"] = QJsonValue::fromVariant(QVariant::fromValue< QList<qint64> >(paramInt64));
    QJsonObject reply = post("tb.simple/SimpleArrayInterface/funcInt64", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return QList<qint64>();
}

QList<qreal> HttpSimpleArrayInterface::funcFloat(const QList<qreal>& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["paramFloat"] = QJsonValue::fromVariant(QVariant::fromValue< QList<qreal> >(paramFloat));
    QJsonObject reply = post("tb.simple/SimpleArrayInterface/funcFloat", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return QList<qreal>();
}

QList<float> HttpSimpleArrayInterface::funcFloat32(const QList<float>& paramFloat32)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["paramFloat32"] = QJsonValue::fromVariant(QVariant::fromValue< QList<float> >(paramFloat32));
    QJsonObject reply = post("tb.simple/SimpleArrayInterface/funcFloat32", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return QList<float>();
}

QList<double> HttpSimpleArrayInterface::funcFloat64(const QList<double>& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["paramFloat"] = QJsonValue::fromVariant(QVariant::fromValue< QList<double> >(paramFloat));
    QJsonObject reply = post("tb.simple/SimpleArrayInterface/funcFloat64", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return QList<double>();
}

QList<QString> HttpSimpleArrayInterface::funcString(const QList<QString>& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["paramString"] = QJsonValue::fromVariant(QVariant::fromValue< QList<QString> >(paramString));
    QJsonObject reply = post("tb.simple/SimpleArrayInterface/funcString", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return QList<QString>();
}

QJsonObject HttpSimpleArrayInterface::post(const QString& path, const QJsonObject &payload)
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
  if(state.contains("propInt32")) {
    const QJsonValue &jsValue = state.value("propInt32");
    setPropInt32(jsValue.toVariant().value<QList<qint32>>());
  }
  if(state.contains("propInt64")) {
    const QJsonValue &jsValue = state.value("propInt64");
    setPropInt64(jsValue.toVariant().value<QList<qint64>>());
  }
  if(state.contains("propFloat")) {
    const QJsonValue &jsValue = state.value("propFloat");
    setPropFloat(jsValue.toVariant().value<QList<qreal>>());
  }
  if(state.contains("propFloat32")) {
    const QJsonValue &jsValue = state.value("propFloat32");
    setPropFloat32(jsValue.toVariant().value<QList<float>>());
  }
  if(state.contains("propFloat64")) {
    const QJsonValue &jsValue = state.value("propFloat64");
    setPropFloat64(jsValue.toVariant().value<QList<double>>());
  }
  if(state.contains("propString")) {
    const QJsonValue &jsValue = state.value("propString");
    setPropString(jsValue.toVariant().value<QList<QString>>());
  }
  if(state.contains("propReadOnlyString")) {
    const QJsonValue &jsValue = state.value("propReadOnlyString");
    setPropReadOnlyString(jsValue.toVariant().value<QString>());
  }
}

} // namespace tb_simple 