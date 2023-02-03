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


#include "qmlsameenum1interface.h"
#include "tb_same2/api/apifactory.h"
#include "tb_same2/api/agent.h"

#include <QtQml>

namespace tb_same2 {

QmlSameEnum1Interface::QmlSameEnum1Interface(QObject *parent)
    : AbstractSameEnum1Interface(parent)
{
    m_obj = ApiFactory::get()->createSameEnum1Interface();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlSameEnum1Interface::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractSameEnum1Interface::Property Changed signal
    // for usage, where QmlSameEnum1Interface is used by the AbstractTuner interface and for connections with AbstractSameEnum1Interface::Property Changed signal
    connect(m_obj.get(), &AbstractSameEnum1Interface::prop1Changed, this, &QmlSameEnum1Interface::prop1Changed);
    connect(m_obj.get(), &AbstractSameEnum1Interface::prop1Changed, this, &AbstractSameEnum1Interface::prop1Changed);

    // Forward the singals emitted by backend implementation to QmlSameEnum1Interface wrapper.
    //  Have in mind that there is no forwarding from the QmlSameEnum1Interface wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractSameEnum1Interface::sig1, this, &AbstractSameEnum1Interface::sig1);
}

QmlSameEnum1Interface::~QmlSameEnum1Interface()
{
}

Enum1::Enum1Enum QmlSameEnum1Interface::prop1() const
{
    return m_obj->prop1();
}

void QmlSameEnum1Interface::setProp1(Enum1::Enum1Enum prop1)
{
    SameEnum1InterfaceAgent::capture_state(this);
    return m_obj->setProp1(prop1);
}

Enum1::Enum1Enum QmlSameEnum1Interface::func1(Enum1::Enum1Enum param1)
{
    SameEnum1InterfaceAgent::trace_func1(this, param1);
	
    return m_obj->func1(param1);
}

} //namespace tb_same2
