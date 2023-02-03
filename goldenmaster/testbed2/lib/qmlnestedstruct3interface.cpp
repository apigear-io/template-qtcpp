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


#include "qmlnestedstruct3interface.h"
#include "testbed2/api/apifactory.h"
#include "testbed2/api/agent.h"

#include <QtQml>

namespace testbed2 {

QmlNestedStruct3Interface::QmlNestedStruct3Interface(QObject *parent)
    : AbstractNestedStruct3Interface(parent)
{
    m_obj = ApiFactory::get()->createNestedStruct3Interface();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlNestedStruct3Interface::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractNestedStruct3Interface::Property Changed signal
    // for usage, where QmlNestedStruct3Interface is used by the AbstractTuner interface and for connections with AbstractNestedStruct3Interface::Property Changed signal
    connect(m_obj.get(), &AbstractNestedStruct3Interface::prop1Changed, this, &QmlNestedStruct3Interface::prop1Changed);
    connect(m_obj.get(), &AbstractNestedStruct3Interface::prop1Changed, this, &AbstractNestedStruct3Interface::prop1Changed);
    connect(m_obj.get(), &AbstractNestedStruct3Interface::prop2Changed, this, &QmlNestedStruct3Interface::prop2Changed);
    connect(m_obj.get(), &AbstractNestedStruct3Interface::prop2Changed, this, &AbstractNestedStruct3Interface::prop2Changed);
    connect(m_obj.get(), &AbstractNestedStruct3Interface::prop3Changed, this, &QmlNestedStruct3Interface::prop3Changed);
    connect(m_obj.get(), &AbstractNestedStruct3Interface::prop3Changed, this, &AbstractNestedStruct3Interface::prop3Changed);

    // Forward the singals emitted by backend implementation to QmlNestedStruct3Interface wrapper.
    //  Have in mind that there is no forwarding from the QmlNestedStruct3Interface wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractNestedStruct3Interface::sig1, this, &AbstractNestedStruct3Interface::sig1);
    connect(m_obj.get(), &AbstractNestedStruct3Interface::sig2, this, &AbstractNestedStruct3Interface::sig2);
    connect(m_obj.get(), &AbstractNestedStruct3Interface::sig3, this, &AbstractNestedStruct3Interface::sig3);
}

QmlNestedStruct3Interface::~QmlNestedStruct3Interface()
{
}

NestedStruct1 QmlNestedStruct3Interface::prop1() const
{
    return m_obj->prop1();
}

void QmlNestedStruct3Interface::setProp1(const NestedStruct1& prop1)
{
    NestedStruct3InterfaceAgent::capture_state(this);
    return m_obj->setProp1(prop1);
}

NestedStruct2 QmlNestedStruct3Interface::prop2() const
{
    return m_obj->prop2();
}

void QmlNestedStruct3Interface::setProp2(const NestedStruct2& prop2)
{
    NestedStruct3InterfaceAgent::capture_state(this);
    return m_obj->setProp2(prop2);
}

NestedStruct3 QmlNestedStruct3Interface::prop3() const
{
    return m_obj->prop3();
}

void QmlNestedStruct3Interface::setProp3(const NestedStruct3& prop3)
{
    NestedStruct3InterfaceAgent::capture_state(this);
    return m_obj->setProp3(prop3);
}

NestedStruct1 QmlNestedStruct3Interface::func1(const NestedStruct1& param1)
{
    NestedStruct3InterfaceAgent::trace_func1(this, param1);
	
    return m_obj->func1(param1);
}

NestedStruct1 QmlNestedStruct3Interface::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    NestedStruct3InterfaceAgent::trace_func2(this, param1, param2);
	
    return m_obj->func2(param1,param2);
}

NestedStruct1 QmlNestedStruct3Interface::func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    NestedStruct3InterfaceAgent::trace_func3(this, param1, param2, param3);
	
    return m_obj->func3(param1,param2,param3);
}

} //namespace testbed2
