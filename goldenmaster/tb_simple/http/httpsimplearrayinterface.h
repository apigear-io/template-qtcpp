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

class HttpSimpleArrayInterface : public AbstractSimpleArrayInterface
{
    Q_OBJECT
public:
    explicit HttpSimpleArrayInterface(QNetworkAccessManager *network, QObject *parent = nullptr);
    virtual ~HttpSimpleArrayInterface() override;
    QList<bool> propBool() const override;
    void setPropBool(const QList<bool>& propBool) override;
    QList<int> propInt() const override;
    void setPropInt(const QList<int>& propInt) override;
    QList<qreal> propFloat() const override;
    void setPropFloat(const QList<qreal>& propFloat) override;
    QList<QString> propString() const override;
    void setPropString(const QList<QString>& propString) override;
    QList<bool> funcBool(const QList<bool>& paramBool) override;
    QList<int> funcInt(const QList<int>& paramInt) override;
    QList<qreal> funcFloat(const QList<qreal>& paramFloat) override;
    QList<QString> funcString(const QList<QString>& paramString) override;
private:
    QJsonObject post(const QString& path, const QJsonObject &payload);
    void applyState(const QJsonObject &state);
private:
    QNetworkAccessManager *m_network;
    QList<bool> m_propBool;
    QList<int> m_propInt;
    QList<qreal> m_propFloat;
    QList<QString> m_propString;
};

} // namespace tb_simple 