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

#include "testbed1/api/api.h"

namespace testbed1 {

class HttpStructArrayInterface : public AbstractStructArrayInterface
{
    Q_OBJECT
public:
    explicit HttpStructArrayInterface(QNetworkAccessManager *network, QObject *parent = nullptr);
    virtual ~HttpStructArrayInterface() override;
    QList<StructBool> propBool() const override;
    void setPropBool(const QList<StructBool>& propBool) override;
    QList<StructInt> propInt() const override;
    void setPropInt(const QList<StructInt>& propInt) override;
    QList<StructFloat> propFloat() const override;
    void setPropFloat(const QList<StructFloat>& propFloat) override;
    QList<StructString> propString() const override;
    void setPropString(const QList<StructString>& propString) override;
    StructBool funcBool(const QList<StructBool>& paramBool) override;
    StructBool funcInt(const QList<StructInt>& paramInt) override;
    StructBool funcFloat(const QList<StructFloat>& paramFloat) override;
    StructBool funcString(const QList<StructString>& paramString) override;
private:
    QJsonObject post(const QString& path, const QJsonObject &payload);
    void applyState(const QJsonObject &state);
private:
    QNetworkAccessManager *m_network;
    QList<StructBool> m_propBool;
    QList<StructInt> m_propInt;
    QList<StructFloat> m_propFloat;
    QList<StructString> m_propString;
};

} // namespace testbed1 