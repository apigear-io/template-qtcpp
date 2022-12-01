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

#include "testbed1/api/api.h"
#include "testbed1/lib/qmlstructinterface.h"
#include "testbed1/lib/qmlstructarrayinterface.h"

void Plugin::registerTypes(const char *uri)
{
    // @uri testbed1
    // register enum

    // register structs
    qRegisterMetaType<testbed1::StructBool>();
    qmlRegisterUncreatableType<testbed1::StructBoolFactory>(uri, 1, 0, "StructBoolFactory", "A struct factory can not be created");
    qRegisterMetaType<testbed1::StructInt>();
    qmlRegisterUncreatableType<testbed1::StructIntFactory>(uri, 1, 0, "StructIntFactory", "A struct factory can not be created");
    qRegisterMetaType<testbed1::StructFloat>();
    qmlRegisterUncreatableType<testbed1::StructFloatFactory>(uri, 1, 0, "StructFloatFactory", "A struct factory can not be created");
    qRegisterMetaType<testbed1::StructString>();
    qmlRegisterUncreatableType<testbed1::StructStringFactory>(uri, 1, 0, "StructStringFactory", "A struct factory can not be created");

    // register interfaces
    qmlRegisterType<testbed1::QmlStructInterface>(uri, 1, 0, "StructInterface");
    qmlRegisterType<testbed1::QmlStructArrayInterface>(uri, 1, 0, "StructArrayInterface");



}
