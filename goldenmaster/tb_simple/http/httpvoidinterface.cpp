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
#include "httpvoidinterface.h"
#include "apigear/utilities/logger.h"


namespace tb_simple {

HttpVoidInterface::HttpVoidInterface(QNetworkAccessManager *network, QObject *parent)
    : AbstractVoidInterface(parent)
    , m_network(network)
{
}

HttpVoidInterface::~HttpVoidInterface()
{
}

void HttpVoidInterface::funcVoid()
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    QJsonObject payload;
    QJsonObject reply = post("tb.simple/VoidInterface/funcVoid", payload);
    AG_LOG_DEBUG(qPrintable(QJsonDocument(reply).toJson()));
    return;
}

QJsonObject HttpVoidInterface::post(const QString& path, const QJsonObject &payload)
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


void HttpVoidInterface::applyState(const QJsonObject &state)
{
}

} // namespace tb_simple 