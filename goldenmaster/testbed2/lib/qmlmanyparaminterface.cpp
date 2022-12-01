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


#include "qmlmanyparaminterface.h"
#include "testbed2/api/apifactory.h"
#include "testbed2/api/agent.h"

#include <QtQml>

namespace testbed2 {

QmlManyParamInterface::QmlManyParamInterface(QObject *parent)
    : AbstractManyParamInterface(parent)
{
    m_obj = ApiFactory::get()->createManyParamInterface(this);
    connect(m_obj, &AbstractManyParamInterface::prop1Changed, this, &QmlManyParamInterface::prop1Changed);
    connect(m_obj, &AbstractManyParamInterface::prop1Changed, this, &AbstractManyParamInterface::prop1Changed);
    connect(m_obj, &AbstractManyParamInterface::prop2Changed, this, &QmlManyParamInterface::prop2Changed);
    connect(m_obj, &AbstractManyParamInterface::prop2Changed, this, &AbstractManyParamInterface::prop2Changed);
    connect(m_obj, &AbstractManyParamInterface::prop3Changed, this, &QmlManyParamInterface::prop3Changed);
    connect(m_obj, &AbstractManyParamInterface::prop3Changed, this, &AbstractManyParamInterface::prop3Changed);
    connect(m_obj, &AbstractManyParamInterface::prop4Changed, this, &QmlManyParamInterface::prop4Changed);
    connect(m_obj, &AbstractManyParamInterface::prop4Changed, this, &AbstractManyParamInterface::prop4Changed);
    connect(m_obj, &AbstractManyParamInterface::sig1, this, &QmlManyParamInterface::sig1);
    connect(m_obj, &AbstractManyParamInterface::sig1, this, &AbstractManyParamInterface::sig1);
    connect(m_obj, &AbstractManyParamInterface::sig2, this, &QmlManyParamInterface::sig2);
    connect(m_obj, &AbstractManyParamInterface::sig2, this, &AbstractManyParamInterface::sig2);
    connect(m_obj, &AbstractManyParamInterface::sig3, this, &QmlManyParamInterface::sig3);
    connect(m_obj, &AbstractManyParamInterface::sig3, this, &AbstractManyParamInterface::sig3);
    connect(m_obj, &AbstractManyParamInterface::sig4, this, &QmlManyParamInterface::sig4);
    connect(m_obj, &AbstractManyParamInterface::sig4, this, &AbstractManyParamInterface::sig4);
}

QmlManyParamInterface::~QmlManyParamInterface()
{
}

int QmlManyParamInterface::prop1() const
{
    return m_obj->prop1();
}

void QmlManyParamInterface::setProp1(int prop1)
{
    ManyParamInterfaceAgent::capture_state(this);
    return m_obj->setProp1(prop1);
}

int QmlManyParamInterface::prop2() const
{
    return m_obj->prop2();
}

void QmlManyParamInterface::setProp2(int prop2)
{
    ManyParamInterfaceAgent::capture_state(this);
    return m_obj->setProp2(prop2);
}

int QmlManyParamInterface::prop3() const
{
    return m_obj->prop3();
}

void QmlManyParamInterface::setProp3(int prop3)
{
    ManyParamInterfaceAgent::capture_state(this);
    return m_obj->setProp3(prop3);
}

int QmlManyParamInterface::prop4() const
{
    return m_obj->prop4();
}

void QmlManyParamInterface::setProp4(int prop4)
{
    ManyParamInterfaceAgent::capture_state(this);
    return m_obj->setProp4(prop4);
}

int QmlManyParamInterface::func1(int param1)
{
    ManyParamInterfaceAgent::trace_func1(this, param1);
	
    return m_obj->func1(param1);
}

int QmlManyParamInterface::func2(int param1, int param2)
{
    ManyParamInterfaceAgent::trace_func2(this, param1, param2);
	
    return m_obj->func2(param1,param2);
}

int QmlManyParamInterface::func3(int param1, int param2, int param3)
{
    ManyParamInterfaceAgent::trace_func3(this, param1, param2, param3);
	
    return m_obj->func3(param1,param2,param3);
}

int QmlManyParamInterface::func4(int param1, int param2, int param3, int param4)
{
    ManyParamInterfaceAgent::trace_func4(this, param1, param2, param3, param4);
	
    return m_obj->func4(param1,param2,param3,param4);
}

} //namespace testbed2
