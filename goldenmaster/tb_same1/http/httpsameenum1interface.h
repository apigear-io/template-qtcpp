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

#include "tb_same1/api/api.h"

namespace tb_same1 {

class HttpSameEnum1Interface : public AbstractSameEnum1Interface
{
    Q_OBJECT
public:
    explicit HttpSameEnum1Interface(QNetworkAccessManager *network, QObject *parent = nullptr);
    virtual ~HttpSameEnum1Interface() override;
    Enum1::Enum1Enum prop1() const override;
    void setProp1(Enum1::Enum1Enum prop1) override;
    Enum1::Enum1Enum func1(Enum1::Enum1Enum param1) override;
private:
    QJsonObject post(const QString& path, const QJsonObject &payload);
    void applyState(const QJsonObject &state);
private:
    QNetworkAccessManager *m_network;
    Enum1::Enum1Enum m_prop1;
};

} // namespace tb_same1 