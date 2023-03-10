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
    // register enums structs and interfaces for testbed2
    qmlRegisterUncreatableType<testbed2::Enum1>(uri, 1, 0, "Testbed2Enum1", "An enum can not be created");
    qmlRegisterUncreatableType<testbed2::Enum2>(uri, 1, 0, "Testbed2Enum2", "An enum can not be created");
    qmlRegisterUncreatableType<testbed2::Enum3>(uri, 1, 0, "Testbed2Enum3", "An enum can not be created");
    qRegisterMetaType<testbed2::Struct1>();
    auto createTestbed2Struct1FactorySingleton = [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
         Q_UNUSED(engine)
         Q_UNUSED(scriptEngine)
         return new testbed2::Struct1Factory();
    };
    const std::string uriTestbed2Struct1Factory = uri + std::string(".Struct1FactorySingleton");
    qmlRegisterSingletonType<testbed2::Struct1Factory>(uriTestbed2Struct1Factory.c_str(), 1, 0, "Testbed2Struct1Factory", createTestbed2Struct1FactorySingleton);
    qRegisterMetaType<testbed2::Struct2>();
    auto createTestbed2Struct2FactorySingleton = [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
         Q_UNUSED(engine)
         Q_UNUSED(scriptEngine)
         return new testbed2::Struct2Factory();
    };
    const std::string uriTestbed2Struct2Factory = uri + std::string(".Struct2FactorySingleton");
    qmlRegisterSingletonType<testbed2::Struct2Factory>(uriTestbed2Struct2Factory.c_str(), 1, 0, "Testbed2Struct2Factory", createTestbed2Struct2FactorySingleton);
    qRegisterMetaType<testbed2::Struct3>();
    auto createTestbed2Struct3FactorySingleton = [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
         Q_UNUSED(engine)
         Q_UNUSED(scriptEngine)
         return new testbed2::Struct3Factory();
    };
    const std::string uriTestbed2Struct3Factory = uri + std::string(".Struct3FactorySingleton");
    qmlRegisterSingletonType<testbed2::Struct3Factory>(uriTestbed2Struct3Factory.c_str(), 1, 0, "Testbed2Struct3Factory", createTestbed2Struct3FactorySingleton);
    qRegisterMetaType<testbed2::Struct4>();
    auto createTestbed2Struct4FactorySingleton = [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
         Q_UNUSED(engine)
         Q_UNUSED(scriptEngine)
         return new testbed2::Struct4Factory();
    };
    const std::string uriTestbed2Struct4Factory = uri + std::string(".Struct4FactorySingleton");
    qmlRegisterSingletonType<testbed2::Struct4Factory>(uriTestbed2Struct4Factory.c_str(), 1, 0, "Testbed2Struct4Factory", createTestbed2Struct4FactorySingleton);
    qRegisterMetaType<testbed2::NestedStruct1>();
    auto createTestbed2NestedStruct1FactorySingleton = [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
         Q_UNUSED(engine)
         Q_UNUSED(scriptEngine)
         return new testbed2::NestedStruct1Factory();
    };
    const std::string uriTestbed2NestedStruct1Factory = uri + std::string(".NestedStruct1FactorySingleton");
    qmlRegisterSingletonType<testbed2::NestedStruct1Factory>(uriTestbed2NestedStruct1Factory.c_str(), 1, 0, "Testbed2NestedStruct1Factory", createTestbed2NestedStruct1FactorySingleton);
    qRegisterMetaType<testbed2::NestedStruct2>();
    auto createTestbed2NestedStruct2FactorySingleton = [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
         Q_UNUSED(engine)
         Q_UNUSED(scriptEngine)
         return new testbed2::NestedStruct2Factory();
    };
    const std::string uriTestbed2NestedStruct2Factory = uri + std::string(".NestedStruct2FactorySingleton");
    qmlRegisterSingletonType<testbed2::NestedStruct2Factory>(uriTestbed2NestedStruct2Factory.c_str(), 1, 0, "Testbed2NestedStruct2Factory", createTestbed2NestedStruct2FactorySingleton);
    qRegisterMetaType<testbed2::NestedStruct3>();
    auto createTestbed2NestedStruct3FactorySingleton = [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
         Q_UNUSED(engine)
         Q_UNUSED(scriptEngine)
         return new testbed2::NestedStruct3Factory();
    };
    const std::string uriTestbed2NestedStruct3Factory = uri + std::string(".NestedStruct3FactorySingleton");
    qmlRegisterSingletonType<testbed2::NestedStruct3Factory>(uriTestbed2NestedStruct3Factory.c_str(), 1, 0, "Testbed2NestedStruct3Factory", createTestbed2NestedStruct3FactorySingleton);
    qmlRegisterType<testbed2::QmlManyParamInterface>(uri, 1, 0, "Testbed2ManyParamInterface");
    qmlRegisterType<testbed2::QmlNestedStruct1Interface>(uri, 1, 0, "Testbed2NestedStruct1Interface");
    qmlRegisterType<testbed2::QmlNestedStruct2Interface>(uri, 1, 0, "Testbed2NestedStruct2Interface");
    qmlRegisterType<testbed2::QmlNestedStruct3Interface>(uri, 1, 0, "Testbed2NestedStruct3Interface");

}
