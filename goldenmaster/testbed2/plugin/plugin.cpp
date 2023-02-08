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
#include "testbed2/api/qmlmanyparaminterface.h"
#include "testbed2/api/qmlnestedstruct1interface.h"
#include "testbed2/api/qmlnestedstruct2interface.h"
#include "testbed2/api/qmlnestedstruct3interface.h"

void Plugin::registerTypes(const char *uri)
{
    // @uri testbed2
    // register enum
    qmlRegisterUncreatableType<testbed2::Enum1>(uri, 1, 0, "Enum1", "An enum can not be created");
    qmlRegisterUncreatableType<testbed2::Enum2>(uri, 1, 0, "Enum2", "An enum can not be created");
    qmlRegisterUncreatableType<testbed2::Enum3>(uri, 1, 0, "Enum3", "An enum can not be created");

    // register structs
    qRegisterMetaType<testbed2::Struct1>();
    qmlRegisterUncreatableType<testbed2::Struct1Factory>(uri, 1, 0, "Struct1Factory", "A struct factory can not be created");
    qRegisterMetaType<testbed2::Struct2>();
    qmlRegisterUncreatableType<testbed2::Struct2Factory>(uri, 1, 0, "Struct2Factory", "A struct factory can not be created");
    qRegisterMetaType<testbed2::Struct3>();
    qmlRegisterUncreatableType<testbed2::Struct3Factory>(uri, 1, 0, "Struct3Factory", "A struct factory can not be created");
    qRegisterMetaType<testbed2::Struct4>();
    qmlRegisterUncreatableType<testbed2::Struct4Factory>(uri, 1, 0, "Struct4Factory", "A struct factory can not be created");
    qRegisterMetaType<testbed2::NestedStruct1>();
    qmlRegisterUncreatableType<testbed2::NestedStruct1Factory>(uri, 1, 0, "NestedStruct1Factory", "A struct factory can not be created");
    qRegisterMetaType<testbed2::NestedStruct2>();
    qmlRegisterUncreatableType<testbed2::NestedStruct2Factory>(uri, 1, 0, "NestedStruct2Factory", "A struct factory can not be created");
    qRegisterMetaType<testbed2::NestedStruct3>();
    qmlRegisterUncreatableType<testbed2::NestedStruct3Factory>(uri, 1, 0, "NestedStruct3Factory", "A struct factory can not be created");

    // register interfaces
    qmlRegisterType<testbed2::QmlManyParamInterface>(uri, 1, 0, "ManyParamInterface");
    qmlRegisterType<testbed2::QmlNestedStruct1Interface>(uri, 1, 0, "NestedStruct1Interface");
    qmlRegisterType<testbed2::QmlNestedStruct2Interface>(uri, 1, 0, "NestedStruct2Interface");
    qmlRegisterType<testbed2::QmlNestedStruct3Interface>(uri, 1, 0, "NestedStruct3Interface");



}
