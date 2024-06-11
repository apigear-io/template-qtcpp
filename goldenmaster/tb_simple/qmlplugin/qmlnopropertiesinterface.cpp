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


#include "qmlnopropertiesinterface.h"
#include "apifactory.h"

#include <QtQml>

namespace tb_simple {

QmlNoPropertiesInterface::QmlNoPropertiesInterface(QObject *parent)
    : AbstractNoPropertiesInterface(parent)
{
    m_obj = ApiFactory::get()->createNoPropertiesInterface();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlNoPropertiesInterface::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractNoPropertiesInterface::Property Changed signal
    // for usage, where QmlNoPropertiesInterface is used by the AbstractTuner interface and for connections with AbstractNoPropertiesInterface::Property Changed signal

    // Forward the singals emitted by backend implementation to QmlNoPropertiesInterface wrapper.
    //  Have in mind that there is no forwarding from the QmlNoPropertiesInterface wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractNoPropertiesInterface::sigVoid, this, &AbstractNoPropertiesInterface::sigVoid);
    connect(m_obj.get(), &AbstractNoPropertiesInterface::sigBool, this, &AbstractNoPropertiesInterface::sigBool);
}

QmlNoPropertiesInterface::~QmlNoPropertiesInterface()
{
}

void QmlNoPropertiesInterface::funcVoid()
{
    return m_obj->funcVoid();
}

bool QmlNoPropertiesInterface::funcBool(bool paramBool)
{
    return m_obj->funcBool(paramBool);
}

} //namespace tb_simple
