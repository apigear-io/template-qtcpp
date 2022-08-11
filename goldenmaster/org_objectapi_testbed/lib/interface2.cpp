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


#include "interface2.h"

#include <QtQml>

#include "../api/agent.h"

Interface2::Interface2(QObject *parent)
    : AbstractInterface2(parent)
    , m_prop200(0)
    , m_prop201(0)
    , m_prop202(0)
    , m_prop203(0.0)
    , m_prop204(0.0)
    , m_prop205(QString())
{
}

Interface2::~Interface2()
{
}

void Interface2::setProp200(int prop200)
{
    if (m_prop200 != prop200) {
        m_prop200 = prop200;
        emit prop200Changed(prop200);
        Interface2Agent::trace_state(this);
    }
}

int Interface2::prop200() const
{
    return m_prop200;
}

void Interface2::setProp201(int prop201)
{
    if (m_prop201 != prop201) {
        m_prop201 = prop201;
        emit prop201Changed(prop201);
        Interface2Agent::trace_state(this);
    }
}

int Interface2::prop201() const
{
    return m_prop201;
}

void Interface2::setProp202(int prop202)
{
    if (m_prop202 != prop202) {
        m_prop202 = prop202;
        emit prop202Changed(prop202);
        Interface2Agent::trace_state(this);
    }
}

int Interface2::prop202() const
{
    return m_prop202;
}

void Interface2::setProp203(qreal prop203)
{
    if (m_prop203 != prop203) {
        m_prop203 = prop203;
        emit prop203Changed(prop203);
        Interface2Agent::trace_state(this);
    }
}

qreal Interface2::prop203() const
{
    return m_prop203;
}

void Interface2::setProp204(qreal prop204)
{
    if (m_prop204 != prop204) {
        m_prop204 = prop204;
        emit prop204Changed(prop204);
        Interface2Agent::trace_state(this);
    }
}

qreal Interface2::prop204() const
{
    return m_prop204;
}

void Interface2::setProp205(const QString& prop205)
{
    if (m_prop205 != prop205) {
        m_prop205 = prop205;
        emit prop205Changed(prop205);
        Interface2Agent::trace_state(this);
    }
}

QString Interface2::prop205() const
{
    return m_prop205;
}
