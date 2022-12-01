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


#include "manyparaminterface.h"

#include <QtQml>

#include "testbed2/api/agent.h"

ManyParamInterface::ManyParamInterface(QObject *parent)
    : AbstractManyParamInterface(parent)
    , m_prop1(0)
    , m_prop2(0)
    , m_prop3(0)
    , m_prop4(0)
{
}

ManyParamInterface::~ManyParamInterface()
{
}

void ManyParamInterface::setProp1(int prop1)
{
    if (m_prop1 != prop1) {
        m_prop1 = prop1;
        emit prop1Changed(prop1);
        ManyParamInterfaceAgent::trace_state(this);
    }
}

int ManyParamInterface::prop1() const
{
    return m_prop1;
}

void ManyParamInterface::setProp2(int prop2)
{
    if (m_prop2 != prop2) {
        m_prop2 = prop2;
        emit prop2Changed(prop2);
        ManyParamInterfaceAgent::trace_state(this);
    }
}

int ManyParamInterface::prop2() const
{
    return m_prop2;
}

void ManyParamInterface::setProp3(int prop3)
{
    if (m_prop3 != prop3) {
        m_prop3 = prop3;
        emit prop3Changed(prop3);
        ManyParamInterfaceAgent::trace_state(this);
    }
}

int ManyParamInterface::prop3() const
{
    return m_prop3;
}

void ManyParamInterface::setProp4(int prop4)
{
    if (m_prop4 != prop4) {
        m_prop4 = prop4;
        emit prop4Changed(prop4);
        ManyParamInterfaceAgent::trace_state(this);
    }
}

int ManyParamInterface::prop4() const
{
    return m_prop4;
}

int ManyParamInterface::func1(int param1)
{
    qDebug() << Q_FUNC_INFO;
    ManyParamInterfaceAgent::trace_func1(this, param1);
    return 0;
}

int ManyParamInterface::func2(int param1, int param2)
{
    qDebug() << Q_FUNC_INFO;
    ManyParamInterfaceAgent::trace_func2(this, param1, param2);
    return 0;
}

int ManyParamInterface::func3(int param1, int param2, int param3)
{
    qDebug() << Q_FUNC_INFO;
    ManyParamInterfaceAgent::trace_func3(this, param1, param2, param3);
    return 0;
}

int ManyParamInterface::func4(int param1, int param2, int param3, int param4)
{
    qDebug() << Q_FUNC_INFO;
    ManyParamInterfaceAgent::trace_func4(this, param1, param2, param3, param4);
    return 0;
}
