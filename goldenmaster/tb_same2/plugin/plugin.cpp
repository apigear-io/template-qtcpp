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

#include "../api/api.h"
#include "../lib/qmlsamestruct1interface.h"
#include "../lib/qmlsamestruct2interface.h"
#include "../lib/qmlsameenum1interface.h"
#include "../lib/qmlsameenum2interface.h"

void Plugin::registerTypes(const char *uri)
{
    // @uri tb.same2
    // register enum
    qmlRegisterUncreatableType<Enum1>(uri, 1, 0, "Enum1", "An enum can not be created");
    qmlRegisterUncreatableType<Enum2>(uri, 1, 0, "Enum2", "An enum can not be created");

    // register structs
    qRegisterMetaType<Struct1>();
    qmlRegisterUncreatableType<Struct1Factory>(uri, 1, 0, "Struct1Factory", "A struct factory can not be created");
    qRegisterMetaType<Struct2>();
    qmlRegisterUncreatableType<Struct2Factory>(uri, 1, 0, "Struct2Factory", "A struct factory can not be created");

    // register interfaces
    qmlRegisterType<QmlSameStruct1Interface>(uri, 1, 0, "SameStruct1Interface");
    qmlRegisterType<QmlSameStruct2Interface>(uri, 1, 0, "SameStruct2Interface");
    qmlRegisterType<QmlSameEnum1Interface>(uri, 1, 0, "SameEnum1Interface");
    qmlRegisterType<QmlSameEnum2Interface>(uri, 1, 0, "SameEnum2Interface");



}
