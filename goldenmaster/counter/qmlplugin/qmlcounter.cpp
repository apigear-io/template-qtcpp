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


#include "qmlcounter.h"
#include "apifactory.h"

#include <QtQml>

namespace counter {

QmlCounter::QmlCounter(QObject *parent)
    : AbstractCounter(parent)
{
    m_obj = ApiFactory::get()->createCounter();
    // Connection to forward backend implementation singal to wrapper:
    // - Forward the Property Changed singal emitted by backend implementation, as QmlCounter::Property Changed signal for qml property changed notification.
    // - Forward the  Property Changed singal emitted by backend implementation, as AbstractCounter::Property Changed signal
    // for usage, where QmlCounter is used by the AbstractTuner interface and for connections with AbstractCounter::Property Changed signal
    connect(m_obj.get(), &AbstractCounter::vectorChanged, this, &QmlCounter::vectorChanged);
    connect(m_obj.get(), &AbstractCounter::vectorChanged, this, &AbstractCounter::vectorChanged);
    connect(m_obj.get(), &AbstractCounter::extern_vectorChanged, this, &QmlCounter::extern_vectorChanged);
    connect(m_obj.get(), &AbstractCounter::extern_vectorChanged, this, &AbstractCounter::extern_vectorChanged);

    // Forward the singals emitted by backend implementation to QmlCounter wrapper.
    //  Have in mind that there is no forwarding from the QmlCounter wrapper to backend implementation.
    //  This signal is designed to be emitted from backend only.
}

QmlCounter::~QmlCounter()
{
}

custom_types::Vector3D QmlCounter::vector() const
{
    return m_obj->vector();
}

void QmlCounter::setVector(const custom_types::Vector3D& vector)
{
    return m_obj->setVector(vector);
}

QVector3D QmlCounter::extern_vector() const
{
    return m_obj->extern_vector();
}

void QmlCounter::setExternVector(const QVector3D& extern_vector)
{
    return m_obj->setExternVector(extern_vector);
}

QVector3D QmlCounter::increment(const QVector3D& vec)
{
    return m_obj->increment(vec);
}

custom_types::Vector3D QmlCounter::decrement(const custom_types::Vector3D& vec)
{
    return m_obj->decrement(vec);
}

} //namespace counter
