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


#include "qmlnestedstruct1interface.h"
#include "testbed2/api/apifactory.h"

#include <QtQml>

namespace testbed2 {

QmlNestedStruct1Interface::QmlNestedStruct1Interface(QObject *parent)
    : AbstractNestedStruct1Interface(parent)
{
    m_obj = ApiFactory::get()->createNestedStruct1Interface();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlNestedStruct1Interface::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractNestedStruct1Interface::Property Changed signal
    // for usage, where QmlNestedStruct1Interface is used by the AbstractTuner interface and for connections with AbstractNestedStruct1Interface::Property Changed signal
    connect(m_obj.get(), &AbstractNestedStruct1Interface::prop1Changed, this, &QmlNestedStruct1Interface::prop1Changed);
    connect(m_obj.get(), &AbstractNestedStruct1Interface::prop1Changed, this, &AbstractNestedStruct1Interface::prop1Changed);

    // Forward the singals emitted by backend implementation to QmlNestedStruct1Interface wrapper.
    //  Have in mind that there is no forwarding from the QmlNestedStruct1Interface wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractNestedStruct1Interface::sig1, this, &AbstractNestedStruct1Interface::sig1);
}

QmlNestedStruct1Interface::~QmlNestedStruct1Interface()
{
}

NestedStruct1 QmlNestedStruct1Interface::prop1() const
{
    return m_obj->prop1();
}

void QmlNestedStruct1Interface::setProp1(const NestedStruct1& prop1)
{
    return m_obj->setProp1(prop1);
}

NestedStruct1 QmlNestedStruct1Interface::func1(const NestedStruct1& param1)
{
    return m_obj->func1(param1);
}

} //namespace testbed2
