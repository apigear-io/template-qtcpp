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
#include "apifactory.h"

#include <QtQml>

namespace testbed2 {

QmlManyParamInterface::QmlManyParamInterface(QObject *parent)
    : AbstractManyParamInterface(parent)
{
    m_obj = ApiFactory::get()->createManyParamInterface();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlManyParamInterface::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractManyParamInterface::Property Changed signal
    // for usage, where QmlManyParamInterface is used by the AbstractTuner interface and for connections with AbstractManyParamInterface::Property Changed signal
    connect(m_obj.get(), &AbstractManyParamInterface::prop1Changed, this, &QmlManyParamInterface::prop1Changed);
    connect(m_obj.get(), &AbstractManyParamInterface::prop1Changed, this, &AbstractManyParamInterface::prop1Changed);
    connect(m_obj.get(), &AbstractManyParamInterface::prop2Changed, this, &QmlManyParamInterface::prop2Changed);
    connect(m_obj.get(), &AbstractManyParamInterface::prop2Changed, this, &AbstractManyParamInterface::prop2Changed);
    connect(m_obj.get(), &AbstractManyParamInterface::prop3Changed, this, &QmlManyParamInterface::prop3Changed);
    connect(m_obj.get(), &AbstractManyParamInterface::prop3Changed, this, &AbstractManyParamInterface::prop3Changed);
    connect(m_obj.get(), &AbstractManyParamInterface::prop4Changed, this, &QmlManyParamInterface::prop4Changed);
    connect(m_obj.get(), &AbstractManyParamInterface::prop4Changed, this, &AbstractManyParamInterface::prop4Changed);

    // Forward the singals emitted by backend implementation to QmlManyParamInterface wrapper.
    //  Have in mind that there is no forwarding from the QmlManyParamInterface wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractManyParamInterface::sig1, this, &AbstractManyParamInterface::sig1);
    connect(m_obj.get(), &AbstractManyParamInterface::sig2, this, &AbstractManyParamInterface::sig2);
    connect(m_obj.get(), &AbstractManyParamInterface::sig3, this, &AbstractManyParamInterface::sig3);
    connect(m_obj.get(), &AbstractManyParamInterface::sig4, this, &AbstractManyParamInterface::sig4);
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
    return m_obj->setProp1(prop1);
}

int QmlManyParamInterface::prop2() const
{
    return m_obj->prop2();
}

void QmlManyParamInterface::setProp2(int prop2)
{
    return m_obj->setProp2(prop2);
}

int QmlManyParamInterface::prop3() const
{
    return m_obj->prop3();
}

void QmlManyParamInterface::setProp3(int prop3)
{
    return m_obj->setProp3(prop3);
}

int QmlManyParamInterface::prop4() const
{
    return m_obj->prop4();
}

void QmlManyParamInterface::setProp4(int prop4)
{
    return m_obj->setProp4(prop4);
}

int QmlManyParamInterface::func1(int param1)
{
    return m_obj->func1(param1);
}

int QmlManyParamInterface::func2(int param1, int param2)
{
    return m_obj->func2(param1,param2);
}

int QmlManyParamInterface::func3(int param1, int param2, int param3)
{
    return m_obj->func3(param1,param2,param3);
}

int QmlManyParamInterface::func4(int param1, int param2, int param3, int param4)
{
    return m_obj->func4(param1,param2,param3,param4);
}

} //namespace testbed2
