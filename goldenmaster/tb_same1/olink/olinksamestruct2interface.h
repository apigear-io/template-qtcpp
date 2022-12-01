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

class OLinkSameStruct2Interface : public AbstractSameStruct2Interface, public IObjectSink
{
    Q_OBJECT
public:
    explicit OLinkSameStruct2Interface(QObject *parent = nullptr);
    virtual ~OLinkSameStruct2Interface() = default;

    void applyState(const nlohmann::json& fields);
    Struct2 prop1() const override;
    void setProp1(const Struct2& prop1) override;
    void setProp1Local(const Struct2& prop1);
    Struct2 prop2() const override;
    void setProp2(const Struct2& prop2) override;
    void setProp2Local(const Struct2& prop2);
    Struct1 func1(const Struct1& param1) override;
    QtPromise::QPromise<Struct1> func1Async(const Struct1& param1);
    Struct1 func2(const Struct1& param1, const Struct2& param2) override;
    QtPromise::QPromise<Struct1> func2Async(const Struct1& param1, const Struct2& param2);
signals:
    void isReady();
public:
    virtual std::string olinkObjectName() override;
    virtual void olinkOnSignal(const std::string& signalId, const nlohmann::json& args) override;
    virtual void olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value) override;
    virtual void olinkOnInit(const std::string& objectId, const nlohmann::json& props, ::ApiGear::ObjectLink::IClientNode *node) override;
    virtual void olinkOnRelease() override;
private:
    Struct2 m_prop1;
    Struct2 m_prop2;
    bool m_isReady;
    IClientNode *m_node;
};
