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

class WampStructInterface : public AbstractStructInterface
{
    Q_OBJECT
public:
    explicit WampStructInterface(QObject *parent = nullptr);
    virtual ~WampStructInterface() override;

    void applyState(const json& fields);
    StructBool propBool() const override;
    void setPropBool(const StructBool& propBool) override;
    void setPropBoolLocal(const StructBool& propBool);
    StructInt propInt() const override;
    void setPropInt(const StructInt& propInt) override;
    void setPropIntLocal(const StructInt& propInt);
    StructFloat propFloat() const override;
    void setPropFloat(const StructFloat& propFloat) override;
    void setPropFloatLocal(const StructFloat& propFloat);
    StructString propString() const override;
    void setPropString(const StructString& propString) override;
    void setPropStringLocal(const StructString& propString);
    StructBool funcBool(const StructBool& paramBool) override;
    QtPromise::QPromise<StructBool> funcBoolAsync(const StructBool& paramBool);
    StructBool funcInt(const StructInt& paramInt) override;
    QtPromise::QPromise<StructBool> funcIntAsync(const StructInt& paramInt);
    StructFloat funcFloat(const StructFloat& paramFloat) override;
    QtPromise::QPromise<StructFloat> funcFloatAsync(const StructFloat& paramFloat);
    StructString funcString(const StructString& paramString) override;
    QtPromise::QPromise<StructString> funcStringAsync(const StructString& paramString);
void notifySigBool(WAMP::EventArg arg);
void notifySigInt(WAMP::EventArg arg);
void notifySigFloat(WAMP::EventArg arg);
void notifySigString(WAMP::EventArg arg);

private:
    StructBool m_propBool;
    StructInt m_propInt;
    StructFloat m_propFloat;
    StructString m_propString;
};
