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

#include "testbed1/api/api.h"

#if defined(TESTBED1_QML_LIBRARY)
#  define TESTBED1_QML_EXPORT Q_DECL_EXPORT
#else
#  define TESTBED1_QML_EXPORT Q_DECL_IMPORT
#endif

namespace testbed1 {

// ********************************************************************
// StructBool struct factory
// Registered by plugin to allow creating this type of objects in qml. 
// ********************************************************************
class TESTBED1_QML_EXPORT StructBoolFactory : public QObject {
    Q_OBJECT
    QML_ADDED_IN_VERSION(1,0)
    QML_NAMED_ELEMENT(Testbed1StructBoolFactory)
    QML_SINGLETON
public:
    Q_INVOKABLE testbed1::StructBool create(bool in_fieldBool);
};

// ********************************************************************
// StructInt struct factory
// Registered by plugin to allow creating this type of objects in qml. 
// ********************************************************************
class TESTBED1_QML_EXPORT StructIntFactory : public QObject {
    Q_OBJECT
    QML_ADDED_IN_VERSION(1,0)
    QML_NAMED_ELEMENT(Testbed1StructIntFactory)
    QML_SINGLETON
public:
    Q_INVOKABLE testbed1::StructInt create(int in_fieldInt);
};

// ********************************************************************
// StructFloat struct factory
// Registered by plugin to allow creating this type of objects in qml. 
// ********************************************************************
class TESTBED1_QML_EXPORT StructFloatFactory : public QObject {
    Q_OBJECT
    QML_ADDED_IN_VERSION(1,0)
    QML_NAMED_ELEMENT(Testbed1StructFloatFactory)
    QML_SINGLETON
public:
    Q_INVOKABLE testbed1::StructFloat create(qreal in_fieldFloat);
};

// ********************************************************************
// StructString struct factory
// Registered by plugin to allow creating this type of objects in qml. 
// ********************************************************************
class TESTBED1_QML_EXPORT StructStringFactory : public QObject {
    Q_OBJECT
    QML_ADDED_IN_VERSION(1,0)
    QML_NAMED_ELEMENT(Testbed1StructStringFactory)
    QML_SINGLETON
public:
    Q_INVOKABLE testbed1::StructString create(QString in_fieldString);
};


} //namespace testbed1
