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

class WampManyParamInterfaceAdapter : public QObject
{
    Q_OBJECT
public:
    explicit WampManyParamInterfaceAdapter(AbstractManyParamInterface* impl, QObject *parent = nullptr);
    virtual ~WampManyParamInterfaceAdapter() override;
public:
    void publishState();
    nlohmann::json captureState();
    void applyState(const nlohmann::json& state);
    // handler functions
    void handleGetState(WAMP::ProcedureArg arg);
    void handleSetState(WAMP::ProcedureArg arg);
    void handleFunc1(WAMP::ProcedureArg arg);
    void handleFunc2(WAMP::ProcedureArg arg);
    void handleFunc3(WAMP::ProcedureArg arg);
    void handleFunc4(WAMP::ProcedureArg arg);
    void publishSig1(int param1);
    void publishSig2(int param1, int param2);
    void publishSig3(int param1, int param2, int param3);
    void publishSig4(int param1, int param2, int param3, int param4);
private:
    AbstractManyParamInterface* m_impl;
};
