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

class WampInterface2Adapter : public QObject
{
    Q_OBJECT
public:
    explicit WampInterface2Adapter(AbstractInterface2* impl, QObject *parent = nullptr);
    virtual ~WampInterface2Adapter() override;
public:
    void publishState();
    nlohmann::json captureState();
    void applyState(const nlohmann::json& state);
    // handler functions
    void handleGetState(WAMP::ProcedureArg arg);
    void handleSetState(WAMP::ProcedureArg arg);
private:
    AbstractInterface2* m_impl;
};
