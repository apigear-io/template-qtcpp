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
#include "olinknestedstruct1interface.h"

#include "testbed2/api/agent.h"
#include "testbed2/api/json.adapter.h"

#include "olink/iclientnode.h"

#include <QtCore>

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

OLinkNestedStruct1Interface::OLinkNestedStruct1Interface(QObject *parent)
    : AbstractNestedStruct1Interface(parent)
    , m_prop1(NestedStruct1())
    , m_isReady(false)
    , m_node(nullptr)
{        
    qDebug() << Q_FUNC_INFO;
}

void OLinkNestedStruct1Interface::applyState(const nlohmann::json& fields) 
{
    qDebug() << Q_FUNC_INFO;
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<NestedStruct1>());
    }
}

void OLinkNestedStruct1Interface::setProp1(const NestedStruct1& prop1)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("testbed2.NestedStruct1Interface/prop1", prop1);
}

void OLinkNestedStruct1Interface::setProp1Local(const NestedStruct1& prop1)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        NestedStruct1InterfaceAgent::trace_state(this);
    }
}

NestedStruct1 OLinkNestedStruct1Interface::prop1() const
{
    return m_prop1;
}

NestedStruct1 OLinkNestedStruct1Interface::func1(const NestedStruct1& param1)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return NestedStruct1();
    }
    NestedStruct1 value{ NestedStruct1() };
    func1Async(param1)
        .then([&](NestedStruct1 result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<NestedStruct1> OLinkNestedStruct1Interface::func1Async(const NestedStruct1& param1)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<NestedStruct1>::reject("not initialized");
    }
    return QtPromise::QPromise<NestedStruct1>{[&](
        const QtPromise::QPromiseResolve<NestedStruct1>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func1");
            m_node->invokeRemote(operationId, nlohmann::json::array({param1}), [resolve](InvokeReplyArg arg) {                
                const NestedStruct1& value = arg.value.get<NestedStruct1>();
                resolve(value);
            });
        }
    };
}


std::string OLinkNestedStruct1Interface::olinkObjectName()
{
    return "testbed2.NestedStruct1Interface";
}

void OLinkNestedStruct1Interface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(signalId);
    auto signalName = Name::getMemberName(signalId);
    if(signalName == "sig1") {
        emit sig1(args[0].get<NestedStruct1>());   
        return;
    }
}

void OLinkNestedStruct1Interface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyState({ {propertyName, value} });
}
void OLinkNestedStruct1Interface::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(objectId);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkNestedStruct1Interface::olinkOnRelease()
{
    qDebug() << Q_FUNC_INFO;
    m_isReady = false;
    m_node = nullptr;
}


