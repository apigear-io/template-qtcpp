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

#include "tb_enum/api/api.h"
#include "tb_enum/api/qmlenuminterface.h"

void Plugin::registerTypes(const char *uri)
{
    // @uri tb.enum
    // register enum
    qmlRegisterUncreatableType<tb_enum::Enum0>(uri, 1, 0, "Enum0", "An enum can not be created");
    qmlRegisterUncreatableType<tb_enum::Enum1>(uri, 1, 0, "Enum1", "An enum can not be created");
    qmlRegisterUncreatableType<tb_enum::Enum2>(uri, 1, 0, "Enum2", "An enum can not be created");
    qmlRegisterUncreatableType<tb_enum::Enum3>(uri, 1, 0, "Enum3", "An enum can not be created");

    // register structs

    // register interfaces
    qmlRegisterType<tb_enum::QmlEnumInterface>(uri, 1, 0, "EnumInterface");



}
