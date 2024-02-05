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


#include "nam_es.h"

#include <QtQml>

namespace tb_names {

NamEs::NamEs(QObject *parent)
    : AbstractNamEs(parent)
    , m_Switch(false)
    , m_SOME_PROPERTY(0)
    , m_Some_Poperty2(0)
{
}

NamEs::~NamEs()
{
}

void NamEs::setSwitch(bool Switch)
{
    if (m_Switch != Switch) {
        m_Switch = Switch;
        emit SwitchChanged(Switch);
    }
}

bool NamEs::Switch() const
{
    return m_Switch;
}

void NamEs::setSomeProperty(int SOME_PROPERTY)
{
    if (m_SOME_PROPERTY != SOME_PROPERTY) {
        m_SOME_PROPERTY = SOME_PROPERTY;
        emit SOME_PROPERTYChanged(SOME_PROPERTY);
    }
}

int NamEs::SOME_PROPERTY() const
{
    return m_SOME_PROPERTY;
}

void NamEs::setSomePoperty2(int Some_Poperty2)
{
    if (m_Some_Poperty2 != Some_Poperty2) {
        m_Some_Poperty2 = Some_Poperty2;
        emit Some_Poperty2Changed(Some_Poperty2);
    }
}

int NamEs::Some_Poperty2() const
{
    return m_Some_Poperty2;
}

void NamEs::someFunction(bool SOME_PARAM)
{
    return;
}

void NamEs::someFunction2(bool Some_Param)
{
    return;
}
} //namespace tb_names
