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

#include "tb_same2/api/api.h"

namespace tb_same2 {

class HttpSameStruct2Interface : public AbstractSameStruct2Interface
{
    Q_OBJECT
public:
    explicit HttpSameStruct2Interface(QNetworkAccessManager *network, QObject *parent = nullptr);
    virtual ~HttpSameStruct2Interface() override;
    Struct2 prop1() const override;
    void setProp1(const Struct2& prop1) override;
    Struct2 prop2() const override;
    void setProp2(const Struct2& prop2) override;
    Struct1 func1(const Struct1& param1) override;
    Struct1 func2(const Struct1& param1, const Struct2& param2) override;
private:
    QJsonObject post(const QString& path, const QJsonObject &payload);
    void applyState(const QJsonObject &state);
private:
    QNetworkAccessManager *m_network;
    Struct2 m_prop1;
    Struct2 m_prop2;
};

} // namespace tb_same2 