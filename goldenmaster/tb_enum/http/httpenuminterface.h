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

#include "tb_enum/api/api.h"

class HttpEnumInterface : public AbstractEnumInterface
{
    Q_OBJECT
public:
    explicit HttpEnumInterface(QNetworkAccessManager *network, QObject *parent = nullptr);
    virtual ~HttpEnumInterface() override;
    Enum0::Enum0Enum prop0() const override;
    void setProp0(const Enum0::Enum0Enum prop0) override;
    Enum1::Enum1Enum prop1() const override;
    void setProp1(const Enum1::Enum1Enum prop1) override;
    Enum2::Enum2Enum prop2() const override;
    void setProp2(const Enum2::Enum2Enum prop2) override;
    Enum3::Enum3Enum prop3() const override;
    void setProp3(const Enum3::Enum3Enum prop3) override;
    Enum0::Enum0Enum func0(const Enum0::Enum0Enum param0) override;
    Enum1::Enum1Enum func1(const Enum1::Enum1Enum param1) override;
    Enum2::Enum2Enum func2(const Enum2::Enum2Enum param2) override;
    Enum3::Enum3Enum func3(const Enum3::Enum3Enum param3) override;
private:
    QJsonObject post(const QString& path, const QJsonObject &payload);
    void applyState(const QJsonObject &state);
private:
    QNetworkAccessManager *m_network;
    Enum0::Enum0Enum m_prop0;
    Enum1::Enum1Enum m_prop1;
    Enum2::Enum2Enum m_prop2;
    Enum3::Enum3Enum m_prop3;
};
