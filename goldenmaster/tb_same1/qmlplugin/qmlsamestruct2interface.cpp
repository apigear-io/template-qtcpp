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


#include "qmlsamestruct2interface.h"
#include "apifactory.h"

#include <QtQml>

namespace tb_same1 {

QmlSameStruct2Interface::QmlSameStruct2Interface(QObject *parent)
    : AbstractSameStruct2Interface(parent)
{
    m_obj = ApiFactory::get()->createSameStruct2Interface();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlSameStruct2Interface::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractSameStruct2Interface::Property Changed signal
    // for usage, where QmlSameStruct2Interface is used by the AbstractTuner interface and for connections with AbstractSameStruct2Interface::Property Changed signal
    connect(m_obj.get(), &AbstractSameStruct2Interface::prop1Changed, this, &QmlSameStruct2Interface::prop1Changed);
    connect(m_obj.get(), &AbstractSameStruct2Interface::prop1Changed, this, &AbstractSameStruct2Interface::prop1Changed);
    connect(m_obj.get(), &AbstractSameStruct2Interface::prop2Changed, this, &QmlSameStruct2Interface::prop2Changed);
    connect(m_obj.get(), &AbstractSameStruct2Interface::prop2Changed, this, &AbstractSameStruct2Interface::prop2Changed);

    // Forward the singals emitted by backend implementation to QmlSameStruct2Interface wrapper.
    //  Have in mind that there is no forwarding from the QmlSameStruct2Interface wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractSameStruct2Interface::sig1, this, &AbstractSameStruct2Interface::sig1);
    connect(m_obj.get(), &AbstractSameStruct2Interface::sig2, this, &AbstractSameStruct2Interface::sig2);
}

QmlSameStruct2Interface::~QmlSameStruct2Interface()
{
}

Struct2 QmlSameStruct2Interface::prop1() const
{
    return m_obj->prop1();
}

void QmlSameStruct2Interface::setProp1(const Struct2& prop1)
{
    return m_obj->setProp1(prop1);
}

Struct2 QmlSameStruct2Interface::prop2() const
{
    return m_obj->prop2();
}

void QmlSameStruct2Interface::setProp2(const Struct2& prop2)
{
    return m_obj->setProp2(prop2);
}

Struct1 QmlSameStruct2Interface::func1(const Struct1& param1)
{
    return m_obj->func1(param1);
}

Struct1 QmlSameStruct2Interface::func2(const Struct1& param1, const Struct2& param2)
{
    return m_obj->func2(param1,param2);
}

} //namespace tb_same1
