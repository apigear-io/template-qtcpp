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

#if defined(TB_SAME1_API_LIBRARY)
#  define TB_SAME1_API_EXPORT Q_DECL_EXPORT
#else
#  define TB_SAME1_API_EXPORT Q_DECL_IMPORT
#endif

namespace tb_same1 {

// ********************************************************************
// Enumeration Enum1
// ********************************************************************
class TB_SAME1_API_EXPORT Enum1 : public QObject {
    Q_OBJECT
public:
    Enum1(QObject *parent = nullptr)
        : QObject(parent)
        {}
    enum Enum1Enum {
        Value1 = 1,
        Value2 = 2
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
class TB_SAME1_API_EXPORT Enum2 : public QObject {
    Q_OBJECT
public:
    Enum2(QObject *parent = nullptr)
        : QObject(parent)
        {}
    enum Enum2Enum {
        Value1 = 1,
        Value2 = 2
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
// Struct1 struct
// ********************************************************************
struct TB_SAME1_API_EXPORT Struct1
{
    Q_GADGET
    Q_PROPERTY(int field1 MEMBER m_field1 )
    Q_PROPERTY(int field2 MEMBER m_field2 )
    Q_PROPERTY(int field3 MEMBER m_field3 )

public:
    Struct1();
    bool operator==(const Struct1 &other) const;
    bool operator!=(const Struct1 &other) const;
    int m_field1;
    int m_field2;
    int m_field3;
};

/** ostream operator. Allows writing the Struct1 value to an text output*/
QDataStream &operator<<(QDataStream &stream, const Struct1 &obj);
/** istream operator. Allows reading to Struct1 value from input text*/
QDataStream &operator>>(QDataStream &stream, Struct1 &obj);

// ********************************************************************
// Struct1 struct factory
// Registered by plugin to allow creating this type of objects in qml. 
// ********************************************************************
class TB_SAME1_API_EXPORT Struct1Factory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE tb_same1::Struct1 create();
};
// ********************************************************************
// Struct2 struct
// ********************************************************************
struct TB_SAME1_API_EXPORT Struct2
{
    Q_GADGET
    Q_PROPERTY(int field1 MEMBER m_field1 )
    Q_PROPERTY(int field2 MEMBER m_field2 )
    Q_PROPERTY(int field3 MEMBER m_field3 )

public:
    Struct2();
    bool operator==(const Struct2 &other) const;
    bool operator!=(const Struct2 &other) const;
    int m_field1;
    int m_field2;
    int m_field3;
};

/** ostream operator. Allows writing the Struct2 value to an text output*/
QDataStream &operator<<(QDataStream &stream, const Struct2 &obj);
/** istream operator. Allows reading to Struct2 value from input text*/
QDataStream &operator>>(QDataStream &stream, Struct2 &obj);

// ********************************************************************
// Struct2 struct factory
// Registered by plugin to allow creating this type of objects in qml. 
// ********************************************************************
class TB_SAME1_API_EXPORT Struct2Factory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE tb_same1::Struct2 create();
};

// ********************************************************************
/**
*
* AbstractSameStruct1Interface is a pure interface QObject class.
* Declares:
*  - Methods defined for SameStruct1Interface interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for SameStruct1Interface interface.
*/
// ********************************************************************


class TB_SAME1_API_EXPORT AbstractSameStruct1Interface : public QObject {
    Q_OBJECT
public:
    AbstractSameStruct1Interface(QObject * parent=nullptr);
    /**
    * Sets the value of the prop1 property.
    */
    virtual void setProp1(const Struct1& prop1) = 0;
    /**
    * Gets the value of the prop1 property.
    */
    virtual Struct1 prop1() const = 0;

    virtual Struct1 func1(const Struct1& param1) = 0;
signals:
    /**
    * @param param1 
    */
    void sig1(const tb_same1::Struct1& param1);
    /**
    * Emitted when prop1 value has changed.
    */
    void prop1Changed(const Struct1& prop1);
};

// ********************************************************************
/**
*
* AbstractSameStruct2Interface is a pure interface QObject class.
* Declares:
*  - Methods defined for SameStruct2Interface interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for SameStruct2Interface interface.
*/
// ********************************************************************


class TB_SAME1_API_EXPORT AbstractSameStruct2Interface : public QObject {
    Q_OBJECT
public:
    AbstractSameStruct2Interface(QObject * parent=nullptr);
    /**
    * Sets the value of the prop1 property.
    */
    virtual void setProp1(const Struct2& prop1) = 0;
    /**
    * Gets the value of the prop1 property.
    */
    virtual Struct2 prop1() const = 0;
    /**
    * Sets the value of the prop2 property.
    */
    virtual void setProp2(const Struct2& prop2) = 0;
    /**
    * Gets the value of the prop2 property.
    */
    virtual Struct2 prop2() const = 0;

    virtual Struct1 func1(const Struct1& param1) = 0;

    virtual Struct1 func2(const Struct1& param1, const Struct2& param2) = 0;
signals:
    /**
    * @param param1 
    */
    void sig1(const tb_same1::Struct1& param1);
    /**
    * @param param1 
    * @param param2 
    */
    void sig2(const tb_same1::Struct1& param1, const tb_same1::Struct2& param2);
    /**
    * Emitted when prop1 value has changed.
    */
    void prop1Changed(const Struct2& prop1);
    /**
    * Emitted when prop2 value has changed.
    */
    void prop2Changed(const Struct2& prop2);
};

// ********************************************************************
/**
*
* AbstractSameEnum1Interface is a pure interface QObject class.
* Declares:
*  - Methods defined for SameEnum1Interface interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for SameEnum1Interface interface.
*/
// ********************************************************************


class TB_SAME1_API_EXPORT AbstractSameEnum1Interface : public QObject {
    Q_OBJECT
public:
    AbstractSameEnum1Interface(QObject * parent=nullptr);
    /**
    * Sets the value of the prop1 property.
    */
    virtual void setProp1(Enum1::Enum1Enum prop1) = 0;
    /**
    * Gets the value of the prop1 property.
    */
    virtual Enum1::Enum1Enum prop1() const = 0;

    virtual Enum1::Enum1Enum func1(Enum1::Enum1Enum param1) = 0;
signals:
    /**
    * @param param1 
    */
    void sig1(tb_same1::Enum1::Enum1Enum param1);
    /**
    * Emitted when prop1 value has changed.
    */
    void prop1Changed(Enum1::Enum1Enum prop1);
};

// ********************************************************************
/**
*
* AbstractSameEnum2Interface is a pure interface QObject class.
* Declares:
*  - Methods defined for SameEnum2Interface interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for SameEnum2Interface interface.
*/
// ********************************************************************


class TB_SAME1_API_EXPORT AbstractSameEnum2Interface : public QObject {
    Q_OBJECT
public:
    AbstractSameEnum2Interface(QObject * parent=nullptr);
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

    virtual Enum1::Enum1Enum func1(Enum1::Enum1Enum param1) = 0;

    virtual Enum1::Enum1Enum func2(Enum1::Enum1Enum param1, Enum2::Enum2Enum param2) = 0;
signals:
    /**
    * @param param1 
    */
    void sig1(tb_same1::Enum1::Enum1Enum param1);
    /**
    * @param param1 
    * @param param2 
    */
    void sig2(tb_same1::Enum1::Enum1Enum param1, tb_same1::Enum2::Enum2Enum param2);
    /**
    * Emitted when prop1 value has changed.
    */
    void prop1Changed(Enum1::Enum1Enum prop1);
    /**
    * Emitted when prop2 value has changed.
    */
    void prop2Changed(Enum2::Enum2Enum prop2);
};


} //namespace tb_same1


Q_DECLARE_METATYPE(tb_same1::Enum1::Enum1Enum)
Q_DECLARE_METATYPE(tb_same1::Enum2::Enum2Enum)
Q_DECLARE_METATYPE(tb_same1::Struct1)
Q_DECLARE_METATYPE(tb_same1::Struct2)