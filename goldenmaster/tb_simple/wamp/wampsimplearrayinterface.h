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

class WampSimpleArrayInterface : public AbstractSimpleArrayInterface
{
    Q_OBJECT
public:
    explicit WampSimpleArrayInterface(QObject *parent = nullptr);
    virtual ~WampSimpleArrayInterface() override;

    void applyState(const json& fields);
    QList<bool> propBool() const override;
    void setPropBool(const QList<bool>& propBool) override;
    void setPropBoolLocal(const QList<bool>& propBool);
    QList<int> propInt() const override;
    void setPropInt(const QList<int>& propInt) override;
    void setPropIntLocal(const QList<int>& propInt);
    QList<qreal> propFloat() const override;
    void setPropFloat(const QList<qreal>& propFloat) override;
    void setPropFloatLocal(const QList<qreal>& propFloat);
    QList<QString> propString() const override;
    void setPropString(const QList<QString>& propString) override;
    void setPropStringLocal(const QList<QString>& propString);
    QList<bool> funcBool(const QList<bool>& paramBool) override;
    QtPromise::QPromise<QList<bool>> funcBoolAsync(const QList<bool>& paramBool);
    QList<int> funcInt(const QList<int>& paramInt) override;
    QtPromise::QPromise<QList<int>> funcIntAsync(const QList<int>& paramInt);
    QList<qreal> funcFloat(const QList<qreal>& paramFloat) override;
    QtPromise::QPromise<QList<qreal>> funcFloatAsync(const QList<qreal>& paramFloat);
    QList<QString> funcString(const QList<QString>& paramString) override;
    QtPromise::QPromise<QList<QString>> funcStringAsync(const QList<QString>& paramString);
void notifySigBool(WAMP::EventArg arg);
void notifySigInt(WAMP::EventArg arg);
void notifySigFloat(WAMP::EventArg arg);
void notifySigString(WAMP::EventArg arg);

private:
    QList<bool> m_propBool;
    QList<int> m_propInt;
    QList<qreal> m_propFloat;
    QList<QString> m_propString;
};
