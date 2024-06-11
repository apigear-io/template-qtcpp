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


#include "qmlnooperationsinterface.h"
#include "apifactory.h"

#include <QtQml>

namespace tb_simple {

QmlNoOperationsInterface::QmlNoOperationsInterface(QObject *parent)
    : AbstractNoOperationsInterface(parent)
{
    m_obj = ApiFactory::get()->createNoOperationsInterface();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlNoOperationsInterface::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractNoOperationsInterface::Property Changed signal
    // for usage, where QmlNoOperationsInterface is used by the AbstractTuner interface and for connections with AbstractNoOperationsInterface::Property Changed signal
    connect(m_obj.get(), &AbstractNoOperationsInterface::propBoolChanged, this, &QmlNoOperationsInterface::propBoolChanged);
    connect(m_obj.get(), &AbstractNoOperationsInterface::propBoolChanged, this, &AbstractNoOperationsInterface::propBoolChanged);
    connect(m_obj.get(), &AbstractNoOperationsInterface::propIntChanged, this, &QmlNoOperationsInterface::propIntChanged);
    connect(m_obj.get(), &AbstractNoOperationsInterface::propIntChanged, this, &AbstractNoOperationsInterface::propIntChanged);

    // Forward the singals emitted by backend implementation to QmlNoOperationsInterface wrapper.
    //  Have in mind that there is no forwarding from the QmlNoOperationsInterface wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
    connect(m_obj.get(), &AbstractNoOperationsInterface::sigVoid, this, &AbstractNoOperationsInterface::sigVoid);
    connect(m_obj.get(), &AbstractNoOperationsInterface::sigBool, this, &AbstractNoOperationsInterface::sigBool);
}

QmlNoOperationsInterface::~QmlNoOperationsInterface()
{
}

bool QmlNoOperationsInterface::propBool() const
{
    return m_obj->propBool();
}

void QmlNoOperationsInterface::setPropBool(bool propBool)
{
    return m_obj->setPropBool(propBool);
}

int QmlNoOperationsInterface::propInt() const
{
    return m_obj->propInt();
}

void QmlNoOperationsInterface::setPropInt(int propInt)
{
    return m_obj->setPropInt(propInt);
}

} //namespace tb_simple
