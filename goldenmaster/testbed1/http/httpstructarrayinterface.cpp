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
#include "httpstructarrayinterface.h"
#include "apigear/utilities/logger.h"

#include <QtQml>

namespace testbed1 {

HttpStructArrayInterface::HttpStructArrayInterface(QNetworkAccessManager *network, QObject *parent)
    : AbstractStructArrayInterface(parent)
    , m_network(network)
    , m_propBool(QList<StructBool>())
    , m_propInt(QList<StructInt>())
    , m_propFloat(QList<StructFloat>())
    , m_propString(QList<StructString>())
{
}

HttpStructArrayInterface::~HttpStructArrayInterface()
{
}

void HttpStructArrayInterface::setPropBool(const QList<StructBool>& propBool)
{
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
    }
}

QList<StructBool> HttpStructArrayInterface::propBool() const
{
    return m_propBool;
}

void HttpStructArrayInterface::setPropInt(const QList<StructInt>& propInt)
{
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
    }
}

QList<StructInt> HttpStructArrayInterface::propInt() const
{
    return m_propInt;
}

void HttpStructArrayInterface::setPropFloat(const QList<StructFloat>& propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
    }
}

QList<StructFloat> HttpStructArrayInterface::propFloat() const
{
    return m_propFloat;
}

void HttpStructArrayInterface::setPropString(const QList<StructString>& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
    }
}

QList<StructString> HttpStructArrayInterface::propString() const
{
    return m_propString;
}

StructBool HttpStructArrayInterface::funcBool(const QList<StructBool>& paramBool)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["paramBool"] = QJsonValue::fromVariant(QVariant::fromValue< QList<StructBool> >(paramBool));
    QJsonObject reply = post("testbed1/StructArrayInterface/funcBool", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return StructBool();
}

StructBool HttpStructArrayInterface::funcInt(const QList<StructInt>& paramInt)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["paramInt"] = QJsonValue::fromVariant(QVariant::fromValue< QList<StructInt> >(paramInt));
    QJsonObject reply = post("testbed1/StructArrayInterface/funcInt", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return StructBool();
}

StructBool HttpStructArrayInterface::funcFloat(const QList<StructFloat>& paramFloat)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["paramFloat"] = QJsonValue::fromVariant(QVariant::fromValue< QList<StructFloat> >(paramFloat));
    QJsonObject reply = post("testbed1/StructArrayInterface/funcFloat", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return StructBool();
}

StructBool HttpStructArrayInterface::funcString(const QList<StructString>& paramString)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    payload["paramString"] = QJsonValue::fromVariant(QVariant::fromValue< QList<StructString> >(paramString));
    QJsonObject reply = post("testbed1/StructArrayInterface/funcString", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return StructBool();
}

QJsonObject HttpStructArrayInterface::post(const QString& path, const QJsonObject &payload)
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


void HttpStructArrayInterface::applyState(const QJsonObject &state)
{
  if(state.contains("propBool")) {
    const QJsonValue &jsValue = state.value("propBool");
    setPropBool(jsValue.toVariant().value<QList<StructBool>>());
  }
  if(state.contains("propInt")) {
    const QJsonValue &jsValue = state.value("propInt");
    setPropInt(jsValue.toVariant().value<QList<StructInt>>());
  }
  if(state.contains("propFloat")) {
    const QJsonValue &jsValue = state.value("propFloat");
    setPropFloat(jsValue.toVariant().value<QList<StructFloat>>());
  }
  if(state.contains("propString")) {
    const QJsonValue &jsValue = state.value("propString");
    setPropString(jsValue.toVariant().value<QList<StructString>>());
  }
}

} // namespace testbed1 