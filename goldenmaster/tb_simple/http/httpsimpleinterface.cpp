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
    , m_propFloat(0.0)
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
  if(state.contains("propFloat")) {
    const QJsonValue &jsValue = state.value("propFloat");
    setPropFloat(jsValue.toVariant().value<qreal>());
  }
  if(state.contains("propString")) {
    const QJsonValue &jsValue = state.value("propString");
    setPropString(jsValue.toVariant().value<QString>());
  }
}

} // namespace tb_simple 