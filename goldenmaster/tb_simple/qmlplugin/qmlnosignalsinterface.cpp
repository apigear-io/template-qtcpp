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


#include "qmlnosignalsinterface.h"
#include "apifactory.h"

#include <QtQml>

namespace tb_simple {

QmlNoSignalsInterface::QmlNoSignalsInterface(QObject *parent)
    : AbstractNoSignalsInterface(parent)
{
    m_obj = ApiFactory::get()->createNoSignalsInterface();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlNoSignalsInterface::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractNoSignalsInterface::Property Changed signal
    // for usage, where QmlNoSignalsInterface is used by the AbstractTuner interface and for connections with AbstractNoSignalsInterface::Property Changed signal
    connect(m_obj.get(), &AbstractNoSignalsInterface::propBoolChanged, this, &QmlNoSignalsInterface::propBoolChanged);
    connect(m_obj.get(), &AbstractNoSignalsInterface::propBoolChanged, this, &AbstractNoSignalsInterface::propBoolChanged);
    connect(m_obj.get(), &AbstractNoSignalsInterface::propIntChanged, this, &QmlNoSignalsInterface::propIntChanged);
    connect(m_obj.get(), &AbstractNoSignalsInterface::propIntChanged, this, &AbstractNoSignalsInterface::propIntChanged);

    // Forward the singals emitted by backend implementation to QmlNoSignalsInterface wrapper.
    //  Have in mind that there is no forwarding from the QmlNoSignalsInterface wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
}

QmlNoSignalsInterface::~QmlNoSignalsInterface()
{
}

bool QmlNoSignalsInterface::propBool() const
{
    return m_obj->propBool();
}

void QmlNoSignalsInterface::setPropBool(bool propBool)
{
    return m_obj->setPropBool(propBool);
}

int QmlNoSignalsInterface::propInt() const
{
    return m_obj->propInt();
}

void QmlNoSignalsInterface::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

void QmlNoSignalsInterface::funcVoid()
{
    return m_obj->funcVoid();
}

bool QmlNoSignalsInterface::funcBool(bool paramBool)
{
    return m_obj->funcBool(paramBool);
}

} //namespace tb_simple
