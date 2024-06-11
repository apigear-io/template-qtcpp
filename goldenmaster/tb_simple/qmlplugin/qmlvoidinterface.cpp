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


#include "qmlvoidinterface.h"
#include "apifactory.h"

#include <QtQml>

namespace tb_simple {

QmlVoidInterface::QmlVoidInterface(QObject *parent)
    : AbstractVoidInterface(parent)
{
    m_obj = ApiFactory::get()->createVoidInterface();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlVoidInterface::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractVoidInterface::Property Changed signal
    // for usage, where QmlVoidInterface is used by the AbstractTuner interface and for connections with AbstractVoidInterface::Property Changed signal

    // Forward the singals emitted by backend implementation to QmlVoidInterface wrapper.
    //  Have in mind that there is no forwarding from the QmlVoidInterface wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractVoidInterface::sigVoid, this, &AbstractVoidInterface::sigVoid);
}

QmlVoidInterface::~QmlVoidInterface()
{
}

void QmlVoidInterface::funcVoid()
{
    return m_obj->funcVoid();
}

} //namespace tb_simple
