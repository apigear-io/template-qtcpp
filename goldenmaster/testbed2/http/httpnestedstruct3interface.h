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

#include "testbed2/api/api.h"

namespace testbed2 {

class HttpNestedStruct3Interface : public AbstractNestedStruct3Interface
{
    Q_OBJECT
public:
    explicit HttpNestedStruct3Interface(QNetworkAccessManager *network, QObject *parent = nullptr);
    virtual ~HttpNestedStruct3Interface() override;
    NestedStruct1 prop1() const override;
    void setProp1(const NestedStruct1& prop1) override;
    NestedStruct2 prop2() const override;
    void setProp2(const NestedStruct2& prop2) override;
    NestedStruct3 prop3() const override;
    void setProp3(const NestedStruct3& prop3) override;
    NestedStruct1 func1(const NestedStruct1& param1) override;
    NestedStruct1 func2(const NestedStruct1& param1, const NestedStruct2& param2) override;
    NestedStruct1 func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) override;
private:
    QJsonObject post(const QString& path, const QJsonObject &payload);
    void applyState(const QJsonObject &state);
private:
    QNetworkAccessManager *m_network;
    NestedStruct1 m_prop1;
    NestedStruct2 m_prop2;
    NestedStruct3 m_prop3;
};

} // namespace testbed2 