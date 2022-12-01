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

#include "testbed2/api/api.h"
#include "testbed2/lib/qmlmanyparaminterface.h"
#include "testbed2/lib/qmlnestedstruct1interface.h"
#include "testbed2/lib/qmlnestedstruct2interface.h"
#include "testbed2/lib/qmlnestedstruct3interface.h"

void Plugin::registerTypes(const char *uri)
{
    // @uri testbed2
    // register enum
    qmlRegisterUncreatableType<Enum1>(uri, 1, 0, "Enum1", "An enum can not be created");
    qmlRegisterUncreatableType<Enum2>(uri, 1, 0, "Enum2", "An enum can not be created");
    qmlRegisterUncreatableType<Enum3>(uri, 1, 0, "Enum3", "An enum can not be created");

    // register structs
    qRegisterMetaType<Struct1>();
    qmlRegisterUncreatableType<Struct1Factory>(uri, 1, 0, "Struct1Factory", "A struct factory can not be created");
    qRegisterMetaType<Struct2>();
    qmlRegisterUncreatableType<Struct2Factory>(uri, 1, 0, "Struct2Factory", "A struct factory can not be created");
    qRegisterMetaType<Struct3>();
    qmlRegisterUncreatableType<Struct3Factory>(uri, 1, 0, "Struct3Factory", "A struct factory can not be created");
    qRegisterMetaType<Struct4>();
    qmlRegisterUncreatableType<Struct4Factory>(uri, 1, 0, "Struct4Factory", "A struct factory can not be created");
    qRegisterMetaType<NestedStruct1>();
    qmlRegisterUncreatableType<NestedStruct1Factory>(uri, 1, 0, "NestedStruct1Factory", "A struct factory can not be created");
    qRegisterMetaType<NestedStruct2>();
    qmlRegisterUncreatableType<NestedStruct2Factory>(uri, 1, 0, "NestedStruct2Factory", "A struct factory can not be created");
    qRegisterMetaType<NestedStruct3>();
    qmlRegisterUncreatableType<NestedStruct3Factory>(uri, 1, 0, "NestedStruct3Factory", "A struct factory can not be created");

    // register interfaces
    qmlRegisterType<QmlManyParamInterface>(uri, 1, 0, "ManyParamInterface");
    qmlRegisterType<QmlNestedStruct1Interface>(uri, 1, 0, "NestedStruct1Interface");
    qmlRegisterType<QmlNestedStruct2Interface>(uri, 1, 0, "NestedStruct2Interface");
    qmlRegisterType<QmlNestedStruct3Interface>(uri, 1, 0, "NestedStruct3Interface");



}
