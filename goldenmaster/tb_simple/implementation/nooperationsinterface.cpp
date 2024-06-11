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


#include "nooperationsinterface.h"

namespace tb_simple {

NoOperationsInterface::NoOperationsInterface(QObject *parent)
    : AbstractNoOperationsInterface(parent)
    , m_propBool(false)
    , m_propInt(0)
{
}

NoOperationsInterface::~NoOperationsInterface()
{
}

void NoOperationsInterface::setPropBool(bool propBool)
{
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
    }
}

bool NoOperationsInterface::propBool() const
{
    return m_propBool;
}

void NoOperationsInterface::setPropInt(int propInt)
{
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
    }
}

int NoOperationsInterface::propInt() const
{
    return m_propInt;
}
} //namespace tb_simple
