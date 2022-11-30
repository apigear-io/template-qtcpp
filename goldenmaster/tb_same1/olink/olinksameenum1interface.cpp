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
#include "olinksameenum1interface.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

OLinkSameEnum1Interface::OLinkSameEnum1Interface(ClientRegistry& registry, QObject *parent)
    : AbstractSameEnum1Interface(parent)
    , m_prop1(Enum1::value1)
    , m_isReady(false)
    , m_node()
    , m_registry(registry)
{        
    qDebug() << Q_FUNC_INFO;
    m_node = m_registry.addObjectSink(this);
}

OLinkSameEnum1Interface::~OLinkSameEnum1Interface()
{
    m_registry.removeObjectSink(this);
}

void OLinkSameEnum1Interface::applyState(const nlohmann::json& fields) 
{
    qDebug() << Q_FUNC_INFO;
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Enum1::Enum1Enum>());
    }
}

void OLinkSameEnum1Interface::setProp1(const Enum1::Enum1Enum prop1)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.same1.SameEnum1Interface/prop1", prop1);
}

void OLinkSameEnum1Interface::setProp1Local(const Enum1::Enum1Enum prop1)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        SameEnum1InterfaceAgent::trace_state(this);
    }
}

Enum1::Enum1Enum OLinkSameEnum1Interface::prop1() const
{
    return m_prop1;
}

Enum1::Enum1Enum OLinkSameEnum1Interface::func1(const Enum1::Enum1Enum param1)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return Enum1::value1;
    }
    Enum1::Enum1Enum value{ Enum1::value1 };
    func1Async(param1)
        .then([&](Enum1::Enum1Enum result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<Enum1::Enum1Enum> OLinkSameEnum1Interface::func1Async(const Enum1::Enum1Enum param1)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<Enum1::Enum1Enum>::reject("not initialized");
    }
    return QtPromise::QPromise<Enum1::Enum1Enum>{[&](
        const QtPromise::QPromiseResolve<Enum1::Enum1Enum>& resolve) {
            m_node->invokeRemote("tb.same1.SameEnum1Interface/func1", nlohmann::json::array({param1}), [resolve](InvokeReplyArg arg) {                
                const Enum1::Enum1Enum& value = arg.value.get<Enum1::Enum1Enum>();
                resolve(value);
            });
        }
    };
}


std::string OLinkSameEnum1Interface::olinkObjectName()
{
    return "tb.same1.SameEnum1Interface";
}

void OLinkSameEnum1Interface::olinkOnSignal(std::string name, nlohmann::json args)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "sig1") {
        emit sig1(args[0].get<Enum1::Enum1Enum>());   
        return;
    }
}

void OLinkSameEnum1Interface::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    applyState({ {path, value} });
}
void OLinkSameEnum1Interface::olinkOnInit(std::string name, nlohmann::json props, IClientNode *node)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkSameEnum1Interface::olinkOnRelease()
{
    qDebug() << Q_FUNC_INFO;
    m_isReady = false;
    m_node = nullptr;
}


