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
#include "objectlink/olink/clientnode.h"

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

class OLinkStructArrayInterface : public AbstractStructArrayInterface, public IObjectSink
{
    Q_OBJECT
public:
    explicit OLinkStructArrayInterface(QObject *parent = nullptr);
    virtual ~OLinkStructArrayInterface() override;

    void applyState(const json& fields);
    QList<StructBool> propBool() const override;
    void setPropBool(const QList<StructBool>& propBool) override;
    void setPropBoolLocal(const QList<StructBool>& propBool);
    QList<StructInt> propInt() const override;
    void setPropInt(const QList<StructInt>& propInt) override;
    void setPropIntLocal(const QList<StructInt>& propInt);
    QList<StructFloat> propFloat() const override;
    void setPropFloat(const QList<StructFloat>& propFloat) override;
    void setPropFloatLocal(const QList<StructFloat>& propFloat);
    QList<StructString> propString() const override;
    void setPropString(const QList<StructString>& propString) override;
    void setPropStringLocal(const QList<StructString>& propString);
    StructBool funcBool(const QList<StructBool>& paramBool) override;
    QtPromise::QPromise<StructBool> funcBoolAsync(const QList<StructBool>& paramBool);
    StructBool funcInt(const QList<StructInt>& paramInt) override;
    QtPromise::QPromise<StructBool> funcIntAsync(const QList<StructInt>& paramInt);
    StructBool funcFloat(const QList<StructFloat>& paramFloat) override;
    QtPromise::QPromise<StructBool> funcFloatAsync(const QList<StructFloat>& paramFloat);
    StructBool funcString(const QList<StructString>& paramString) override;
    QtPromise::QPromise<StructBool> funcStringAsync(const QList<StructString>& paramString);
signals:
    void isReady();
public:
    virtual std::string olinkObjectName() override;
    virtual void olinkOnSignal(std::string name, json args) override;
    virtual void olinkOnPropertyChanged(std::string name, json value) override;
    virtual void olinkOnInit(std::string name, json props, IClientNode *node) override;
    virtual void olinkOnRelease() override;
private:
    QList<StructBool> m_propBool;
    QList<StructInt> m_propInt;
    QList<StructFloat> m_propFloat;
    QList<StructString> m_propString;
    bool m_isReady;
    IClientNode *m_node;
};
