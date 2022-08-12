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

class WampSimpleInterface : public AbstractSimpleInterface
{
    Q_OBJECT
public:
    explicit WampSimpleInterface(QObject *parent = nullptr);
    virtual ~WampSimpleInterface() override;

    void applyState(const json& fields);
    bool propBool() const override;
    void setPropBool(bool propBool) override;
    void setPropBoolLocal(bool propBool);
    int propInt() const override;
    void setPropInt(int propInt) override;
    void setPropIntLocal(int propInt);
    qreal propFloat() const override;
    void setPropFloat(qreal propFloat) override;
    void setPropFloatLocal(qreal propFloat);
    QString propString() const override;
    void setPropString(const QString& propString) override;
    void setPropStringLocal(const QString& propString);
    bool funcBool(bool paramBool) override;
    QtPromise::QPromise<bool> funcBoolAsync(bool paramBool);
    int funcInt(int paramInt) override;
    QtPromise::QPromise<int> funcIntAsync(int paramInt);
    qreal funcFloat(qreal paramFloat) override;
    QtPromise::QPromise<qreal> funcFloatAsync(qreal paramFloat);
    QString funcString(const QString& paramString) override;
    QtPromise::QPromise<QString> funcStringAsync(const QString& paramString);
void notifySigBool(WAMP::EventArg arg);
void notifySigInt(WAMP::EventArg arg);
void notifySigFloat(WAMP::EventArg arg);
void notifySigString(WAMP::EventArg arg);

private:
    bool m_propBool;
    int m_propInt;
    qreal m_propFloat;
    QString m_propString;
};
