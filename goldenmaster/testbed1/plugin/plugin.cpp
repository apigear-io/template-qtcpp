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
#include "testbed1/api/qmlstructinterface.h"
#include "testbed1/api/qmlstructarrayinterface.h"

void Plugin::registerTypes(const char *uri)
{
    // register enums structs and interfaces for testbed1
    qRegisterMetaType<testbed1::StructBool>();
    auto createTestbed1StructBoolFactorySingleton = [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
         Q_UNUSED(engine)
         Q_UNUSED(scriptEngine)
         return new testbed1::StructBoolFactory();
    };
    const std::string uriTestbed1StructBoolFactory = uri + std::string(".StructBoolFactorySingleton");
    qmlRegisterSingletonType<testbed1::StructBoolFactory>(uriTestbed1StructBoolFactory.c_str(), 1, 0, "Testbed1StructBoolFactory", createTestbed1StructBoolFactorySingleton);
    qRegisterMetaType<testbed1::StructInt>();
    auto createTestbed1StructIntFactorySingleton = [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
         Q_UNUSED(engine)
         Q_UNUSED(scriptEngine)
         return new testbed1::StructIntFactory();
    };
    const std::string uriTestbed1StructIntFactory = uri + std::string(".StructIntFactorySingleton");
    qmlRegisterSingletonType<testbed1::StructIntFactory>(uriTestbed1StructIntFactory.c_str(), 1, 0, "Testbed1StructIntFactory", createTestbed1StructIntFactorySingleton);
    qRegisterMetaType<testbed1::StructFloat>();
    auto createTestbed1StructFloatFactorySingleton = [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
         Q_UNUSED(engine)
         Q_UNUSED(scriptEngine)
         return new testbed1::StructFloatFactory();
    };
    const std::string uriTestbed1StructFloatFactory = uri + std::string(".StructFloatFactorySingleton");
    qmlRegisterSingletonType<testbed1::StructFloatFactory>(uriTestbed1StructFloatFactory.c_str(), 1, 0, "Testbed1StructFloatFactory", createTestbed1StructFloatFactorySingleton);
    qRegisterMetaType<testbed1::StructString>();
    auto createTestbed1StructStringFactorySingleton = [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
         Q_UNUSED(engine)
         Q_UNUSED(scriptEngine)
         return new testbed1::StructStringFactory();
    };
    const std::string uriTestbed1StructStringFactory = uri + std::string(".StructStringFactorySingleton");
    qmlRegisterSingletonType<testbed1::StructStringFactory>(uriTestbed1StructStringFactory.c_str(), 1, 0, "Testbed1StructStringFactory", createTestbed1StructStringFactorySingleton);
    qmlRegisterType<testbed1::QmlStructInterface>(uri, 1, 0, "Testbed1StructInterface");
    qmlRegisterType<testbed1::QmlStructArrayInterface>(uri, 1, 0, "Testbed1StructArrayInterface");

}
