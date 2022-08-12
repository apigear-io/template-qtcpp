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
#include <nlohmann/json.hpp>

#include "../api/api.h"
#include "../shared/wampclient.h"

using namespace ApiGear;

class WampEnumInterfaceAdapter : public QObject
{
    Q_OBJECT
public:
    explicit WampEnumInterfaceAdapter(AbstractEnumInterface* impl, QObject *parent = nullptr);
    virtual ~WampEnumInterfaceAdapter() override;
public:
    void publishState();
    nlohmann::json captureState();
    void applyState(const nlohmann::json& state);
    // handler functions
    void handleGetState(WAMP::ProcedureArg arg);
    void handleSetState(WAMP::ProcedureArg arg);
    void handleFunc0(WAMP::ProcedureArg arg);
    void handleFunc1(WAMP::ProcedureArg arg);
    void handleFunc2(WAMP::ProcedureArg arg);
    void handleFunc3(WAMP::ProcedureArg arg);
    void publishSig0(const Enum0::Enum0Enum param0);
    void publishSig1(const Enum1::Enum1Enum param1);
    void publishSig2(const Enum2::Enum2Enum param2);
    void publishSig3(const Enum3::Enum3Enum param3);
private:
    AbstractEnumInterface* m_impl;
};
