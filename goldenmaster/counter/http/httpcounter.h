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
#pragma once

#include <QtCore>
#include <QtNetwork>

#include "counter/api/api.h"

namespace counter {

class HttpCounter : public AbstractCounter
{
    Q_OBJECT
public:
    explicit HttpCounter(QNetworkAccessManager *network, QObject *parent = nullptr);
    virtual ~HttpCounter() override;
    custom_types::Vector3D vector() const override;
    void setVector(const custom_types::Vector3D& vector) override;
    QVector3D extern_vector() const override;
    void setExternVector(const QVector3D& extern_vector) override;
    QVector3D increment(const QVector3D& vec) override;
    custom_types::Vector3D decrement(const custom_types::Vector3D& vec) override;
private:
    QJsonObject post(const QString& path, const QJsonObject &payload);
    void applyState(const QJsonObject &state);
private:
    QNetworkAccessManager *m_network;
    custom_types::Vector3D m_vector;
    QVector3D m_extern_vector;
};

} // namespace counter 