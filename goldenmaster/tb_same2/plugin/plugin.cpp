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

#include "tb_same2/api/api.h"
#include "tb_same2/api/qmlsamestruct1interface.h"
#include "tb_same2/api/qmlsamestruct2interface.h"
#include "tb_same2/api/qmlsameenum1interface.h"
#include "tb_same2/api/qmlsameenum2interface.h"

void Plugin::registerTypes(const char *uri)
{
    // register enums structs and interfaces for tb_same2
    qmlRegisterUncreatableType<tb_same2::Enum1>(uri, 1, 0, "TbSame2Enum1", "An enum can not be created");
    qmlRegisterUncreatableType<tb_same2::Enum2>(uri, 1, 0, "TbSame2Enum2", "An enum can not be created");
    qRegisterMetaType<tb_same2::Struct1>();
    auto createTbSame2Struct1FactorySingleton = [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
         Q_UNUSED(engine)
         Q_UNUSED(scriptEngine)
         return new tb_same2::Struct1Factory();
    };
    const std::string uriTbSame2Struct1Factory = uri + std::string(".Struct1FactorySingleton");
    qmlRegisterSingletonType<tb_same2::Struct1Factory>(uriTbSame2Struct1Factory.c_str(), 1, 0, "TbSame2Struct1Factory", createTbSame2Struct1FactorySingleton);
    qRegisterMetaType<tb_same2::Struct2>();
    auto createTbSame2Struct2FactorySingleton = [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
         Q_UNUSED(engine)
         Q_UNUSED(scriptEngine)
         return new tb_same2::Struct2Factory();
    };
    const std::string uriTbSame2Struct2Factory = uri + std::string(".Struct2FactorySingleton");
    qmlRegisterSingletonType<tb_same2::Struct2Factory>(uriTbSame2Struct2Factory.c_str(), 1, 0, "TbSame2Struct2Factory", createTbSame2Struct2FactorySingleton);
    qmlRegisterType<tb_same2::QmlSameStruct1Interface>(uri, 1, 0, "TbSame2SameStruct1Interface");
    qmlRegisterType<tb_same2::QmlSameStruct2Interface>(uri, 1, 0, "TbSame2SameStruct2Interface");
    qmlRegisterType<tb_same2::QmlSameEnum1Interface>(uri, 1, 0, "TbSame2SameEnum1Interface");
    qmlRegisterType<tb_same2::QmlSameEnum2Interface>(uri, 1, 0, "TbSame2SameEnum2Interface");

}
