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
#include <QtPromise>

#include "../api/api.h"
#include "../shared/wampclient.h"

using namespace ApiGear;

class WampSameEnum1Interface : public AbstractSameEnum1Interface
{
    Q_OBJECT
public:
    explicit WampSameEnum1Interface(QObject *parent = nullptr);
    virtual ~WampSameEnum1Interface() override;

    void applyState(const json& fields);
    Enum1::Enum1Enum prop1() const override;
    void setProp1(const Enum1::Enum1Enum prop1) override;
    void setProp1Local(const Enum1::Enum1Enum prop1);
    Enum1::Enum1Enum func1(const Enum1::Enum1Enum param1) override;
    QtPromise::QPromise<Enum1::Enum1Enum> func1Async(const Enum1::Enum1Enum param1);
void notifySig1(WAMP::EventArg arg);

private:
    Enum1::Enum1Enum m_prop1;
};
