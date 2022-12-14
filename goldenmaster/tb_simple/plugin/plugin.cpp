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

#include "plugin.h"

#include <QtQml>

#include "tb_simple/api/api.h"
#include "tb_simple/lib/qmlsimpleinterface.h"
#include "tb_simple/lib/qmlsimplearrayinterface.h"

void Plugin::registerTypes(const char *uri)
{
    // @uri tb.simple
    // register enum

    // register structs

    // register interfaces
    qmlRegisterType<tb_simple::QmlSimpleInterface>(uri, 1, 0, "SimpleInterface");
    qmlRegisterType<tb_simple::QmlSimpleArrayInterface>(uri, 1, 0, "SimpleArrayInterface");



}
