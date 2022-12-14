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

#include "testbed1/api/api.h"
#include "olink/iobjectsink.h"

#include <nlohmann/json.hpp>

namespace ApiGear {
namespace ObjectLink {
class IClientNode;
}}


using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace testbed1 {

class OLinkStructInterface : public AbstractStructInterface, public IObjectSink
{
    Q_OBJECT
public:
    explicit OLinkStructInterface(QObject *parent = nullptr);
    virtual ~OLinkStructInterface() = default;

    void applyState(const nlohmann::json& fields);
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
signals:
    void isReady();
public:
    virtual std::string olinkObjectName() override;
    virtual void olinkOnSignal(const std::string& signalId, const nlohmann::json& args) override;
    virtual void olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value) override;
    virtual void olinkOnInit(const std::string& objectId, const nlohmann::json& props, ::ApiGear::ObjectLink::IClientNode *node) override;
    virtual void olinkOnRelease() override;
private:
    StructBool m_propBool;
    StructInt m_propInt;
    StructFloat m_propFloat;
    StructString m_propString;
    bool m_isReady;
    IClientNode *m_node;
};

} //namespace testbed1
