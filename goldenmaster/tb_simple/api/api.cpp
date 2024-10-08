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
#include "api.h"
// use json.adapter.h to compile the file with this module and export all the necessary symbols in the library
#include "json.adapter.h"

namespace tb_simple {

// ********************************************************************
// AbstractVoidInterface abstract interface
// ********************************************************************

AbstractVoidInterface::AbstractVoidInterface(QObject *parent)
    : QObject(parent)
{
}

// ********************************************************************
// AbstractSimpleInterface abstract interface
// ********************************************************************

AbstractSimpleInterface::AbstractSimpleInterface(QObject *parent)
    : QObject(parent)
{
}

// ********************************************************************
// AbstractSimpleArrayInterface abstract interface
// ********************************************************************

AbstractSimpleArrayInterface::AbstractSimpleArrayInterface(QObject *parent)
    : QObject(parent)
{
}

// ********************************************************************
// AbstractNoPropertiesInterface abstract interface
// ********************************************************************

AbstractNoPropertiesInterface::AbstractNoPropertiesInterface(QObject *parent)
    : QObject(parent)
{
}

// ********************************************************************
// AbstractNoOperationsInterface abstract interface
// ********************************************************************

AbstractNoOperationsInterface::AbstractNoOperationsInterface(QObject *parent)
    : QObject(parent)
{
}

// ********************************************************************
// AbstractNoSignalsInterface abstract interface
// ********************************************************************

AbstractNoSignalsInterface::AbstractNoSignalsInterface(QObject *parent)
    : QObject(parent)
{
}

} // namespace tb_simple
