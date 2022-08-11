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


#include "qmlinterface2.h"
#include "../api/apifactory.h"
#include "../api/agent.h"

#include <QtQml>

QmlInterface2::QmlInterface2(QObject *parent)
    : AbstractInterface2(parent)
{
    m_obj = ApiFactory::get()->createInterface2(this);
    connect(m_obj, &AbstractInterface2::prop200Changed, this, &QmlInterface2::prop200Changed);
    connect(m_obj, &AbstractInterface2::prop200Changed, this, &AbstractInterface2::prop200Changed);
    connect(m_obj, &AbstractInterface2::prop201Changed, this, &QmlInterface2::prop201Changed);
    connect(m_obj, &AbstractInterface2::prop201Changed, this, &AbstractInterface2::prop201Changed);
    connect(m_obj, &AbstractInterface2::prop202Changed, this, &QmlInterface2::prop202Changed);
    connect(m_obj, &AbstractInterface2::prop202Changed, this, &AbstractInterface2::prop202Changed);
    connect(m_obj, &AbstractInterface2::prop203Changed, this, &QmlInterface2::prop203Changed);
    connect(m_obj, &AbstractInterface2::prop203Changed, this, &AbstractInterface2::prop203Changed);
    connect(m_obj, &AbstractInterface2::prop204Changed, this, &QmlInterface2::prop204Changed);
    connect(m_obj, &AbstractInterface2::prop204Changed, this, &AbstractInterface2::prop204Changed);
    connect(m_obj, &AbstractInterface2::prop205Changed, this, &QmlInterface2::prop205Changed);
    connect(m_obj, &AbstractInterface2::prop205Changed, this, &AbstractInterface2::prop205Changed);
}

QmlInterface2::~QmlInterface2()
{
}

int QmlInterface2::prop200() const
{
    return m_obj->prop200();
}

void QmlInterface2::setProp200(int prop200)
{
    Interface2Agent::capture_state(this);
    return m_obj->setProp200(prop200);
}

int QmlInterface2::prop201() const
{
    return m_obj->prop201();
}

void QmlInterface2::setProp201(int prop201)
{
    Interface2Agent::capture_state(this);
    return m_obj->setProp201(prop201);
}

int QmlInterface2::prop202() const
{
    return m_obj->prop202();
}

void QmlInterface2::setProp202(int prop202)
{
    Interface2Agent::capture_state(this);
    return m_obj->setProp202(prop202);
}

qreal QmlInterface2::prop203() const
{
    return m_obj->prop203();
}

void QmlInterface2::setProp203(qreal prop203)
{
    Interface2Agent::capture_state(this);
    return m_obj->setProp203(prop203);
}

qreal QmlInterface2::prop204() const
{
    return m_obj->prop204();
}

void QmlInterface2::setProp204(qreal prop204)
{
    Interface2Agent::capture_state(this);
    return m_obj->setProp204(prop204);
}

QString QmlInterface2::prop205() const
{
    return m_obj->prop205();
}

void QmlInterface2::setProp205(const QString& prop205)
{
    Interface2Agent::capture_state(this);
    return m_obj->setProp205(prop205);
}
