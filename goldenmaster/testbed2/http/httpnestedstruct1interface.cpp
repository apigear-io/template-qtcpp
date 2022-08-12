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
#include "httpnestedstruct1interface.h"

#include "../api/agent.h"
#include <QtQml>

HttpNestedStruct1Interface::HttpNestedStruct1Interface(QNetworkAccessManager *network, QObject *parent)
    : AbstractNestedStruct1Interface(parent)
    , m_network(network)
    , m_prop1(NestedStruct1())
{
}

HttpNestedStruct1Interface::~HttpNestedStruct1Interface()
{
}

void HttpNestedStruct1Interface::setProp1(const NestedStruct1& prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        NestedStruct1InterfaceAgent::trace_state(this);
    }
}

NestedStruct1 HttpNestedStruct1Interface::prop1() const
{
    return m_prop1;
}

NestedStruct1 HttpNestedStruct1Interface::func1(const NestedStruct1& param1)
{
    qDebug() << Q_FUNC_INFO;

    QJsonObject payload;
    payload["param1"] = QJsonValue::fromVariant(QVariant::fromValue< NestedStruct1 >(param1));
    QJsonObject reply = post("testbed2/NestedStruct1Interface/func1", payload);
    qDebug() << QJsonDocument(reply).toJson();
    NestedStruct1InterfaceAgent::trace_func1(this, param1);
    return NestedStruct1();
}

QJsonObject HttpNestedStruct1Interface::post(const QString& path, const QJsonObject &payload)
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


void HttpNestedStruct1Interface::applyState(const QJsonObject &state)
{
  if(state.contains("prop1")) {
    const QJsonValue &jsValue = state.value("prop1");
    setProp1(jsValue.toVariant().value<NestedStruct1>());
  }
}