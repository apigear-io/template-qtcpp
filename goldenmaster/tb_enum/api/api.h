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

#if defined(TB_ENUM_API_LIBRARY)
#  define TB_ENUM_API_EXPORT Q_DECL_EXPORT
#else
#  define TB_ENUM_API_EXPORT Q_DECL_IMPORT
#endif

namespace tb_enum {

// ********************************************************************
// Enumeration Enum0
// ********************************************************************
class TB_ENUM_API_EXPORT Enum0 : public QObject {
    Q_OBJECT
public:
    Enum0(QObject *parent = nullptr)
        : QObject(parent)
        {}
    enum Enum0Enum {
        Value0 = 0,
        Value1 = 1,
        Value2 = 2
    };
    Q_ENUM(Enum0Enum)

    /**
    * Converter for Enum0Enum
    * @param v Value in quint8 format.
    * @param ok. Write parameter, will be set to true if conversion was successful, false otherwise.
    * @return An enum value for given quint8 or default value if in parameter is out of the enums range.
    */
    static Enum0Enum toEnum(quint8 v, bool *ok);
};

/** ostream operator. Allows writing the Enum0Enum value to an text output*/
inline QDataStream &operator<<(QDataStream &ds, const Enum0::Enum0Enum &obj)
{
    quint8 val = obj;
    ds << val;
    return ds;
}
/** istream operator. Allows reading to Enum0Enum value from input text*/
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
class TB_ENUM_API_EXPORT Enum1 : public QObject {
    Q_OBJECT
public:
    Enum1(QObject *parent = nullptr)
        : QObject(parent)
        {}
    enum Enum1Enum {
        Value1 = 1,
        Value2 = 2,
        Value3 = 3
    };
    Q_ENUM(Enum1Enum)

    /**
    * Converter for Enum1Enum
    * @param v Value in quint8 format.
    * @param ok. Write parameter, will be set to true if conversion was successful, false otherwise.
    * @return An enum value for given quint8 or default value if in parameter is out of the enums range.
    */
    static Enum1Enum toEnum(quint8 v, bool *ok);
};

/** ostream operator. Allows writing the Enum1Enum value to an text output*/
inline QDataStream &operator<<(QDataStream &ds, const Enum1::Enum1Enum &obj)
{
    quint8 val = obj;
    ds << val;
    return ds;
}
/** istream operator. Allows reading to Enum1Enum value from input text*/
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
class TB_ENUM_API_EXPORT Enum2 : public QObject {
    Q_OBJECT
public:
    Enum2(QObject *parent = nullptr)
        : QObject(parent)
        {}
    enum Enum2Enum {
        Value2 = 2,
        Value1 = 1,
        Value0 = 0
    };
    Q_ENUM(Enum2Enum)

    /**
    * Converter for Enum2Enum
    * @param v Value in quint8 format.
    * @param ok. Write parameter, will be set to true if conversion was successful, false otherwise.
    * @return An enum value for given quint8 or default value if in parameter is out of the enums range.
    */
    static Enum2Enum toEnum(quint8 v, bool *ok);
};

/** ostream operator. Allows writing the Enum2Enum value to an text output*/
inline QDataStream &operator<<(QDataStream &ds, const Enum2::Enum2Enum &obj)
{
    quint8 val = obj;
    ds << val;
    return ds;
}
/** istream operator. Allows reading to Enum2Enum value from input text*/
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
class TB_ENUM_API_EXPORT Enum3 : public QObject {
    Q_OBJECT
public:
    Enum3(QObject *parent = nullptr)
        : QObject(parent)
        {}
    enum Enum3Enum {
        Value3 = 3,
        Value2 = 2,
        Value1 = 1
    };
    Q_ENUM(Enum3Enum)

    /**
    * Converter for Enum3Enum
    * @param v Value in quint8 format.
    * @param ok. Write parameter, will be set to true if conversion was successful, false otherwise.
    * @return An enum value for given quint8 or default value if in parameter is out of the enums range.
    */
    static Enum3Enum toEnum(quint8 v, bool *ok);
};

/** ostream operator. Allows writing the Enum3Enum value to an text output*/
inline QDataStream &operator<<(QDataStream &ds, const Enum3::Enum3Enum &obj)
{
    quint8 val = obj;
    ds << val;
    return ds;
}
/** istream operator. Allows reading to Enum3Enum value from input text*/
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
/**
*
* AbstractEnumInterface is a pure interface QObject class.
* Declares:
*  - Methods defined for EnumInterface interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for EnumInterface interface.
*/
// ********************************************************************


class TB_ENUM_API_EXPORT AbstractEnumInterface : public QObject {
    Q_OBJECT
public:
    AbstractEnumInterface(QObject * parent=nullptr);
    /**
    * Sets the value of the prop0 property.
    */
    virtual void setProp0(Enum0::Enum0Enum prop0) = 0;
    /**
    * Gets the value of the prop0 property.
    */
    virtual Enum0::Enum0Enum prop0() const = 0;
    /**
    * Sets the value of the prop1 property.
    */
    virtual void setProp1(Enum1::Enum1Enum prop1) = 0;
    /**
    * Gets the value of the prop1 property.
    */
    virtual Enum1::Enum1Enum prop1() const = 0;
    /**
    * Sets the value of the prop2 property.
    */
    virtual void setProp2(Enum2::Enum2Enum prop2) = 0;
    /**
    * Gets the value of the prop2 property.
    */
    virtual Enum2::Enum2Enum prop2() const = 0;
    /**
    * Sets the value of the prop3 property.
    */
    virtual void setProp3(Enum3::Enum3Enum prop3) = 0;
    /**
    * Gets the value of the prop3 property.
    */
    virtual Enum3::Enum3Enum prop3() const = 0;

    virtual Enum0::Enum0Enum func0(Enum0::Enum0Enum param0) = 0;

    virtual Enum1::Enum1Enum func1(Enum1::Enum1Enum param1) = 0;

    virtual Enum2::Enum2Enum func2(Enum2::Enum2Enum param2) = 0;

    virtual Enum3::Enum3Enum func3(Enum3::Enum3Enum param3) = 0;
signals:
    /**
    * @param param0 
    */
    void sig0(tb_enum::Enum0::Enum0Enum param0);
    /**
    * @param param1 
    */
    void sig1(tb_enum::Enum1::Enum1Enum param1);
    /**
    * @param param2 
    */
    void sig2(tb_enum::Enum2::Enum2Enum param2);
    /**
    * @param param3 
    */
    void sig3(tb_enum::Enum3::Enum3Enum param3);
    /**
    * Emitted when prop0 value has changed.
    */
    void prop0Changed(Enum0::Enum0Enum prop0);
    /**
    * Emitted when prop1 value has changed.
    */
    void prop1Changed(Enum1::Enum1Enum prop1);
    /**
    * Emitted when prop2 value has changed.
    */
    void prop2Changed(Enum2::Enum2Enum prop2);
    /**
    * Emitted when prop3 value has changed.
    */
    void prop3Changed(Enum3::Enum3Enum prop3);
};


} //namespace tb_enum


Q_DECLARE_METATYPE(tb_enum::Enum0::Enum0Enum)
Q_DECLARE_METATYPE(tb_enum::Enum1::Enum1Enum)
Q_DECLARE_METATYPE(tb_enum::Enum2::Enum2Enum)
Q_DECLARE_METATYPE(tb_enum::Enum3::Enum3Enum)