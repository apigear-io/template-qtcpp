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
    qreal propFloat() const override;
    void setPropFloat(qreal propFloat) override;
    QString propString() const override;
    void setPropString(const QString& propString) override;
    bool funcBool(bool paramBool) override;
    int funcInt(int paramInt) override;
    qreal funcFloat(qreal paramFloat) override;
    QString funcString(const QString& paramString) override;
private:
    QJsonObject post(const QString& path, const QJsonObject &payload);
    void applyState(const QJsonObject &state);
private:
    QNetworkAccessManager *m_network;
    bool m_propBool;
    int m_propInt;
    qreal m_propFloat;
    QString m_propString;
};
