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


#include "qmlsamestruct1interface.h"
#include "apifactory.h"

#include <QtQml>

namespace tb_same2 {

QmlSameStruct1Interface::QmlSameStruct1Interface(QObject *parent)
    : AbstractSameStruct1Interface(parent)
{
    m_obj = ApiFactory::get()->createSameStruct1Interface();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlSameStruct1Interface::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractSameStruct1Interface::Property Changed signal
    // for usage, where QmlSameStruct1Interface is used by the AbstractTuner interface and for connections with AbstractSameStruct1Interface::Property Changed signal
    connect(m_obj.get(), &AbstractSameStruct1Interface::prop1Changed, this, &QmlSameStruct1Interface::prop1Changed);
    connect(m_obj.get(), &AbstractSameStruct1Interface::prop1Changed, this, &AbstractSameStruct1Interface::prop1Changed);

    // Forward the singals emitted by backend implementation to QmlSameStruct1Interface wrapper.
    //  Have in mind that there is no forwarding from the QmlSameStruct1Interface wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractSameStruct1Interface::sig1, this, &AbstractSameStruct1Interface::sig1);
}

QmlSameStruct1Interface::~QmlSameStruct1Interface()
{
}

Struct1 QmlSameStruct1Interface::prop1() const
{
    return m_obj->prop1();
}

void QmlSameStruct1Interface::setProp1(const Struct1& prop1)
{
    return m_obj->setProp1(prop1);
}

Struct1 QmlSameStruct1Interface::func1(const Struct1& param1)
{
    return m_obj->func1(param1);
}

} //namespace tb_same2
