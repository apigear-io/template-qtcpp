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

#include "tb_simple/api/api.h"

namespace tb_simple {

class HttpSimpleInterface : public AbstractSimpleInterface
{
    Q_OBJECT
public:
    explicit HttpSimpleInterface(QNetworkAccessManager *network, QObject *parent = nullptr);
    virtual ~HttpSimpleInterface() override;
    bool propBool() const override;
    void setPropBool(bool propBool) override;
    int propInt() const override;
    void setPropInt(int propInt) override;
    qint32 propInt32() const override;
    void setPropInt32(qint32 propInt32) override;
    qint64 propInt64() const override;
    void setPropInt64(qint64 propInt64) override;
    qreal propFloat() const override;
    void setPropFloat(qreal propFloat) override;
    float propFloat32() const override;
    void setPropFloat32(float propFloat32) override;
    double propFloat64() const override;
    void setPropFloat64(double propFloat64) override;
    QString propString() const override;
    void setPropString(const QString& propString) override;
    void funcVoid() override;
    bool funcBool(bool paramBool) override;
    int funcInt(int paramInt) override;
    qint32 funcInt32(qint32 paramInt32) override;
    qint64 funcInt64(qint64 paramInt64) override;
    qreal funcFloat(qreal paramFloat) override;
    float funcFloat32(float paramFloat32) override;
    double funcFloat64(double paramFloat) override;
    QString funcString(const QString& paramString) override;
private:
    QJsonObject post(const QString& path, const QJsonObject &payload);
    void applyState(const QJsonObject &state);
private:
    QNetworkAccessManager *m_network;
    bool m_propBool;
    int m_propInt;
    qint32 m_propInt32;
    qint64 m_propInt64;
    qreal m_propFloat;
    float m_propFloat32;
    double m_propFloat64;
    QString m_propString;
};

} // namespace tb_simple 