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
#pragma once

#include <QQmlEngine>
#include <QtCore>
#include <QtCore/QtGlobal>
#include <QDataStream>

#include "tb_same1/api/api.h"

#if defined(TB_SAME1_QML_LIBRARY)
#  define TB_SAME1_QML_EXPORT Q_DECL_EXPORT
#else
#  define TB_SAME1_QML_EXPORT Q_DECL_IMPORT
#endif

namespace tb_same1 {

struct ForeignEnum1 : public QObject
{
    Q_OBJECT
    QML_FOREIGN(Enum1)
    QML_NAMED_ELEMENT(TbSame1Enum1)
    QML_UNCREATABLE("This is enum class")
    QML_ADDED_IN_VERSION(1,0)
};

struct ForeignEnum2 : public QObject
{
    Q_OBJECT
    QML_FOREIGN(Enum2)
    QML_NAMED_ELEMENT(TbSame1Enum2)
    QML_UNCREATABLE("This is enum class")
    QML_ADDED_IN_VERSION(1,0)
};

// ********************************************************************
// Struct1 struct factory
// Registered by plugin to allow creating this type of objects in qml. 
// ********************************************************************
class TB_SAME1_QML_EXPORT Struct1Factory : public QObject {
    Q_OBJECT
    QML_ADDED_IN_VERSION(1,0)
    QML_NAMED_ELEMENT(TbSame1Struct1Factory)
    QML_SINGLETON
public:
    Q_INVOKABLE tb_same1::Struct1 create(int in_field1 ,int in_field2 ,int in_field3);
};

// ********************************************************************
// Struct2 struct factory
// Registered by plugin to allow creating this type of objects in qml. 
// ********************************************************************
class TB_SAME1_QML_EXPORT Struct2Factory : public QObject {
    Q_OBJECT
    QML_ADDED_IN_VERSION(1,0)
    QML_NAMED_ELEMENT(TbSame1Struct2Factory)
    QML_SINGLETON
public:
    Q_INVOKABLE tb_same1::Struct2 create(int in_field1 ,int in_field2 ,int in_field3);
};


} //namespace tb_same1
