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

#include "tb_same2/api/api.h"
#include "olink/iobjectsink.h"

#include <nlohmann/json.hpp>

namespace ApiGear {
namespace ObjectLink {
class IClientNode;
}}


using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace tb_same2 {

class OLinkSameEnum1Interface : public AbstractSameEnum1Interface, public IObjectSink
{
    Q_OBJECT
public:
    explicit OLinkSameEnum1Interface(QObject *parent = nullptr);
    virtual ~OLinkSameEnum1Interface() = default;

    void applyState(const nlohmann::json& fields);
    Enum1::Enum1Enum prop1() const override;
    void setProp1(const Enum1::Enum1Enum prop1) override;
    void setProp1Local(const Enum1::Enum1Enum prop1);
    Enum1::Enum1Enum func1(const Enum1::Enum1Enum param1) override;
    QtPromise::QPromise<Enum1::Enum1Enum> func1Async(const Enum1::Enum1Enum param1);
signals:
    void isReady();
public:
    virtual std::string olinkObjectName() override;
    virtual void olinkOnSignal(const std::string& signalId, const nlohmann::json& args) override;
    virtual void olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value) override;
    virtual void olinkOnInit(const std::string& objectId, const nlohmann::json& props, ::ApiGear::ObjectLink::IClientNode *node) override;
    virtual void olinkOnRelease() override;
private:
    Enum1::Enum1Enum m_prop1;
    bool m_isReady;
    IClientNode *m_node;
};

} //namespace tb_same2
