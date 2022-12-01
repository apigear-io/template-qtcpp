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

#include "tb_same1/api/api.h"
#include "olink/iobjectsink.h"

#include <nlohmann/json.hpp>

namespace ApiGear {
namespace ObjectLink {
class IClientNode;
}}


using namespace ApiGear;
using namespace ApiGear::ObjectLink;

class OLinkSameStruct1Interface : public AbstractSameStruct1Interface, public IObjectSink
{
    Q_OBJECT
public:
    explicit OLinkSameStruct1Interface(QObject *parent = nullptr);
    virtual ~OLinkSameStruct1Interface() = default;

    void applyState(const nlohmann::json& fields);
    Struct1 prop1() const override;
    void setProp1(const Struct1& prop1) override;
    void setProp1Local(const Struct1& prop1);
    Struct1 func1(const Struct1& param1) override;
    QtPromise::QPromise<Struct1> func1Async(const Struct1& param1);
signals:
    void isReady();
public:
    virtual std::string olinkObjectName() override;
    virtual void olinkOnSignal(const std::string& signalId, const nlohmann::json& args) override;
    virtual void olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value) override;
    virtual void olinkOnInit(const std::string& objectId, const nlohmann::json& props, ::ApiGear::ObjectLink::IClientNode *node) override;
    virtual void olinkOnRelease() override;
private:
    Struct1 m_prop1;
    bool m_isReady;
    IClientNode *m_node;
};
