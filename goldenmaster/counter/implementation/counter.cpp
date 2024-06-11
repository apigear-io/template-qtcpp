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


#include "counter.h"

namespace counter {

Counter::Counter(QObject *parent)
    : AbstractCounter(parent)
    , m_vector(custom_types::Vector3D())
    , m_extern_vector(QVector3D())
{
}

Counter::~Counter()
{
}

void Counter::setVector(const custom_types::Vector3D& vector)
{
    if (m_vector != vector) {
        m_vector = vector;
        emit vectorChanged(vector);
    }
}

custom_types::Vector3D Counter::vector() const
{
    return m_vector;
}

void Counter::setExternVector(const QVector3D& extern_vector)
{
    if (m_extern_vector != extern_vector) {
        m_extern_vector = extern_vector;
        emit extern_vectorChanged(extern_vector);
    }
}

QVector3D Counter::extern_vector() const
{
    return m_extern_vector;
}

QVector3D Counter::increment(const QVector3D& vec)
{
    return QVector3D();
}

custom_types::Vector3D Counter::decrement(const custom_types::Vector3D& vec)
{
    return custom_types::Vector3D();
}
} //namespace counter
