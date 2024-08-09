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

class HttpStructInterface : public AbstractStructInterface
{
    Q_OBJECT
public:
    explicit HttpStructInterface(QNetworkAccessManager *network, QObject *parent = nullptr);
    virtual ~HttpStructInterface() override;
    StructBool propBool() const override;
    void setPropBool(const StructBool& propBool) override;
    StructInt propInt() const override;
    void setPropInt(const StructInt& propInt) override;
    StructFloat propFloat() const override;
    void setPropFloat(const StructFloat& propFloat) override;
    StructString propString() const override;
    void setPropString(const StructString& propString) override;
    StructBool funcBool(const StructBool& paramBool) override;
    StructInt funcInt(const StructInt& paramInt) override;
    StructFloat funcFloat(const StructFloat& paramFloat) override;
    StructString funcString(const StructString& paramString) override;
private:
    QJsonObject post(const QString& path, const QJsonObject &payload);
    void applyState(const QJsonObject &state);
private:
    QNetworkAccessManager *m_network;
    StructBool m_propBool;
    StructInt m_propInt;
    StructFloat m_propFloat;
    StructString m_propString;
};

} // namespace testbed1 