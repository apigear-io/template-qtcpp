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

#include <QtCore>
#include <QtCore/QtGlobal>

#if defined(TB_ENUM_LIBRARY)
#  define TB_ENUM_EXPORT Q_DECL_EXPORT
#else
#  define TB_ENUM_EXPORT Q_DECL_IMPORT
#endif

namespace tb_enum {

// ********************************************************************
// Enumeration Enum0
// ********************************************************************

class TB_ENUM_EXPORT Enum0 : public QObject {
    Q_OBJECT
public:
    Enum0(QObject *parent = nullptr)
        : QObject(parent)
        {}
    enum Enum0Enum {
        value0 = 0,
        value1 = 1,
        value2 = 2,
    };
    Q_ENUM(Enum0Enum)

    static Enum0Enum toEnum(quint8 v, bool *ok);
};


inline QDataStream &operator<<(QDataStream &ds, const Enum0::Enum0Enum &obj)
{
    quint8 val = obj;
    ds << val;
    return ds;
}

inline QDataStream &operator>>(QDataStream &ds, Enum0::Enum0Enum &obj) {
    bool ok;
    quint8 val;
    ds >> val;
    obj = Enum0::toEnum(val, &ok);
    if (!ok) {
        qWarning() << "received an invalid enum value for typeState, value =" << val;
    }
    return ds;
}

// ********************************************************************
// Enumeration Enum1
// ********************************************************************

class TB_ENUM_EXPORT Enum1 : public QObject {
    Q_OBJECT
public:
    Enum1(QObject *parent = nullptr)
        : QObject(parent)
        {}
    enum Enum1Enum {
        value1 = 1,
        value2 = 2,
        value3 = 3,
    };
    Q_ENUM(Enum1Enum)

    static Enum1Enum toEnum(quint8 v, bool *ok);
};


inline QDataStream &operator<<(QDataStream &ds, const Enum1::Enum1Enum &obj)
{
    quint8 val = obj;
    ds << val;
    return ds;
}

inline QDataStream &operator>>(QDataStream &ds, Enum1::Enum1Enum &obj) {
    bool ok;
    quint8 val;
    ds >> val;
    obj = Enum1::toEnum(val, &ok);
    if (!ok) {
        qWarning() << "received an invalid enum value for typeState, value =" << val;
    }
    return ds;
}

// ********************************************************************
// Enumeration Enum2
// ********************************************************************

class TB_ENUM_EXPORT Enum2 : public QObject {
    Q_OBJECT
public:
    Enum2(QObject *parent = nullptr)
        : QObject(parent)
        {}
    enum Enum2Enum {
        value2 = 2,
        value1 = 1,
        value0 = 0,
    };
    Q_ENUM(Enum2Enum)

    static Enum2Enum toEnum(quint8 v, bool *ok);
};


inline QDataStream &operator<<(QDataStream &ds, const Enum2::Enum2Enum &obj)
{
    quint8 val = obj;
    ds << val;
    return ds;
}

inline QDataStream &operator>>(QDataStream &ds, Enum2::Enum2Enum &obj) {
    bool ok;
    quint8 val;
    ds >> val;
    obj = Enum2::toEnum(val, &ok);
    if (!ok) {
        qWarning() << "received an invalid enum value for typeState, value =" << val;
    }
    return ds;
}

// ********************************************************************
// Enumeration Enum3
// ********************************************************************

class TB_ENUM_EXPORT Enum3 : public QObject {
    Q_OBJECT
public:
    Enum3(QObject *parent = nullptr)
        : QObject(parent)
        {}
    enum Enum3Enum {
        value3 = 3,
        value2 = 2,
        value1 = 1,
    };
    Q_ENUM(Enum3Enum)

    static Enum3Enum toEnum(quint8 v, bool *ok);
};


inline QDataStream &operator<<(QDataStream &ds, const Enum3::Enum3Enum &obj)
{
    quint8 val = obj;
    ds << val;
    return ds;
}

inline QDataStream &operator>>(QDataStream &ds, Enum3::Enum3Enum &obj) {
    bool ok;
    quint8 val;
    ds >> val;
    obj = Enum3::toEnum(val, &ok);
    if (!ok) {
        qWarning() << "received an invalid enum value for typeState, value =" << val;
    }
    return ds;
}

// ********************************************************************
// AbstractEnumInterface pure interface
// ********************************************************************


class TB_ENUM_EXPORT AbstractEnumInterface : public QObject {
    Q_OBJECT
public:
    AbstractEnumInterface(QObject * parent=nullptr);
    virtual void setProp0(const Enum0::Enum0Enum prop0) = 0;
    virtual Enum0::Enum0Enum prop0() const = 0;
    virtual void setProp1(const Enum1::Enum1Enum prop1) = 0;
    virtual Enum1::Enum1Enum prop1() const = 0;
    virtual void setProp2(const Enum2::Enum2Enum prop2) = 0;
    virtual Enum2::Enum2Enum prop2() const = 0;
    virtual void setProp3(const Enum3::Enum3Enum prop3) = 0;
    virtual Enum3::Enum3Enum prop3() const = 0;
    virtual Enum0::Enum0Enum func0(const Enum0::Enum0Enum param0) = 0;
    virtual Enum1::Enum1Enum func1(const Enum1::Enum1Enum param1) = 0;
    virtual Enum2::Enum2Enum func2(const Enum2::Enum2Enum param2) = 0;
    virtual Enum3::Enum3Enum func3(const Enum3::Enum3Enum param3) = 0;
signals:
    void sig0(const Enum0::Enum0Enum param0);
    void sig1(const Enum1::Enum1Enum param1);
    void sig2(const Enum2::Enum2Enum param2);
    void sig3(const Enum3::Enum3Enum param3);
    void prop0Changed(const Enum0::Enum0Enum prop0);
    void prop1Changed(const Enum1::Enum1Enum prop1);
    void prop2Changed(const Enum2::Enum2Enum prop2);
    void prop3Changed(const Enum3::Enum3Enum prop3);
};


// ********************************************************************
// Interface Factory
// ********************************************************************

class TB_ENUM_EXPORT ApiFactoryInterface
{
public:
    virtual AbstractEnumInterface* createEnumInterface(QObject *parent) = 0;
};

} //namespace tb_enum


Q_DECLARE_METATYPE(tb_enum::Enum0::Enum0Enum)
Q_DECLARE_METATYPE(tb_enum::Enum1::Enum1Enum)
Q_DECLARE_METATYPE(tb_enum::Enum2::Enum2Enum)
Q_DECLARE_METATYPE(tb_enum::Enum3::Enum3Enum)