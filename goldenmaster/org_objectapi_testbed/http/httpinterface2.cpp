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
#include "httpinterface2.h"

#include "../api/agent.h"
#include <QtQml>

HttpInterface2::HttpInterface2(QNetworkAccessManager *network, QObject *parent)
    : AbstractInterface2(parent)
    , m_network(network)
    , m_prop200(0)
    , m_prop201(0)
    , m_prop202(0)
    , m_prop203(0.0)
    , m_prop204(0.0)
    , m_prop205(QString())
{
}

HttpInterface2::~HttpInterface2()
{
}

void HttpInterface2::setProp200(int prop200)
{
    if (m_prop200 != prop200) {
        m_prop200 = prop200;
        emit prop200Changed(prop200);
        Interface2Agent::trace_state(this);
    }
}

int HttpInterface2::prop200() const
{
    return m_prop200;
}

void HttpInterface2::setProp201(int prop201)
{
    if (m_prop201 != prop201) {
        m_prop201 = prop201;
        emit prop201Changed(prop201);
        Interface2Agent::trace_state(this);
    }
}

int HttpInterface2::prop201() const
{
    return m_prop201;
}

void HttpInterface2::setProp202(int prop202)
{
    if (m_prop202 != prop202) {
        m_prop202 = prop202;
        emit prop202Changed(prop202);
        Interface2Agent::trace_state(this);
    }
}

int HttpInterface2::prop202() const
{
    return m_prop202;
}

void HttpInterface2::setProp203(qreal prop203)
{
    if (m_prop203 != prop203) {
        m_prop203 = prop203;
        emit prop203Changed(prop203);
        Interface2Agent::trace_state(this);
    }
}

qreal HttpInterface2::prop203() const
{
    return m_prop203;
}

void HttpInterface2::setProp204(qreal prop204)
{
    if (m_prop204 != prop204) {
        m_prop204 = prop204;
        emit prop204Changed(prop204);
        Interface2Agent::trace_state(this);
    }
}

qreal HttpInterface2::prop204() const
{
    return m_prop204;
}

void HttpInterface2::setProp205(const QString& prop205)
{
    if (m_prop205 != prop205) {
        m_prop205 = prop205;
        emit prop205Changed(prop205);
        Interface2Agent::trace_state(this);
    }
}

QString HttpInterface2::prop205() const
{
    return m_prop205;
}

QJsonObject HttpInterface2::post(const QString& path, const QJsonObject &payload)
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


void HttpInterface2::applyState(const QJsonObject &state)
{
  if(state.contains("prop200")) {
    const QJsonValue &jsValue = state.value("prop200");
    setProp200(jsValue.toVariant().value<int>());
  }
  if(state.contains("prop201")) {
    const QJsonValue &jsValue = state.value("prop201");
    setProp201(jsValue.toVariant().value<int>());
  }
  if(state.contains("prop202")) {
    const QJsonValue &jsValue = state.value("prop202");
    setProp202(jsValue.toVariant().value<int>());
  }
  if(state.contains("prop203")) {
    const QJsonValue &jsValue = state.value("prop203");
    setProp203(jsValue.toVariant().value<qreal>());
  }
  if(state.contains("prop204")) {
    const QJsonValue &jsValue = state.value("prop204");
    setProp204(jsValue.toVariant().value<qreal>());
  }
  if(state.contains("prop205")) {
    const QJsonValue &jsValue = state.value("prop205");
    setProp205(jsValue.toVariant().value<QString>());
  }
}