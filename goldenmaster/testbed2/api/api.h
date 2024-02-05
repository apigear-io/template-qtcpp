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

#if defined(TESTBED2_API_LIBRARY)
#  define TESTBED2_API_EXPORT Q_DECL_EXPORT
#else
#  define TESTBED2_API_EXPORT Q_DECL_IMPORT
#endif

namespace testbed2 {

// ********************************************************************
// Enumeration Enum1
// ********************************************************************
class TESTBED2_API_EXPORT Enum1 : public QObject {
    Q_OBJECT
public:
    Enum1(QObject *parent = nullptr)
        : QObject(parent)
        {}
    enum Enum1Enum {
        Value1 = 1,
        Value2 = 2,
        Value3 = 3,
        Value4 = 4
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
class TESTBED2_API_EXPORT Enum2 : public QObject {
    Q_OBJECT
public:
    Enum2(QObject *parent = nullptr)
        : QObject(parent)
        {}
    enum Enum2Enum {
        Value1 = 1,
        Value2 = 2,
        Value3 = 3,
        Value4 = 4
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
class TESTBED2_API_EXPORT Enum3 : public QObject {
    Q_OBJECT
public:
    Enum3(QObject *parent = nullptr)
        : QObject(parent)
        {}
    enum Enum3Enum {
        Value1 = 1,
        Value2 = 2,
        Value3 = 3,
        Value4 = 4
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
// Struct1 struct
// ********************************************************************
struct TESTBED2_API_EXPORT Struct1
{
    Q_GADGET
    Q_PROPERTY(int field1 MEMBER m_field1 )

public:
    Struct1();
    bool operator==(const Struct1 &other) const;
    bool operator!=(const Struct1 &other) const;
    int m_field1;
};

/** ostream operator. Allows writing the Struct1 value to an text output*/
QDataStream &operator<<(QDataStream &stream, const Struct1 &obj);
/** istream operator. Allows reading to Struct1 value from input text*/
QDataStream &operator>>(QDataStream &stream, Struct1 &obj);

// ********************************************************************
// Struct1 struct factory
// Registered by plugin to allow creating this type of objects in qml. 
// ********************************************************************
class TESTBED2_API_EXPORT Struct1Factory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE testbed2::Struct1 create();
};
// ********************************************************************
// Struct2 struct
// ********************************************************************
struct TESTBED2_API_EXPORT Struct2
{
    Q_GADGET
    Q_PROPERTY(int field1 MEMBER m_field1 )
    Q_PROPERTY(int field2 MEMBER m_field2 )

public:
    Struct2();
    bool operator==(const Struct2 &other) const;
    bool operator!=(const Struct2 &other) const;
    int m_field1;
    int m_field2;
};

/** ostream operator. Allows writing the Struct2 value to an text output*/
QDataStream &operator<<(QDataStream &stream, const Struct2 &obj);
/** istream operator. Allows reading to Struct2 value from input text*/
QDataStream &operator>>(QDataStream &stream, Struct2 &obj);

// ********************************************************************
// Struct2 struct factory
// Registered by plugin to allow creating this type of objects in qml. 
// ********************************************************************
class TESTBED2_API_EXPORT Struct2Factory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE testbed2::Struct2 create();
};
// ********************************************************************
// Struct3 struct
// ********************************************************************
struct TESTBED2_API_EXPORT Struct3
{
    Q_GADGET
    Q_PROPERTY(int field1 MEMBER m_field1 )
    Q_PROPERTY(int field2 MEMBER m_field2 )
    Q_PROPERTY(int field3 MEMBER m_field3 )

public:
    Struct3();
    bool operator==(const Struct3 &other) const;
    bool operator!=(const Struct3 &other) const;
    int m_field1;
    int m_field2;
    int m_field3;
};

/** ostream operator. Allows writing the Struct3 value to an text output*/
QDataStream &operator<<(QDataStream &stream, const Struct3 &obj);
/** istream operator. Allows reading to Struct3 value from input text*/
QDataStream &operator>>(QDataStream &stream, Struct3 &obj);

// ********************************************************************
// Struct3 struct factory
// Registered by plugin to allow creating this type of objects in qml. 
// ********************************************************************
class TESTBED2_API_EXPORT Struct3Factory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE testbed2::Struct3 create();
};
// ********************************************************************
// Struct4 struct
// ********************************************************************
struct TESTBED2_API_EXPORT Struct4
{
    Q_GADGET
    Q_PROPERTY(int field1 MEMBER m_field1 )
    Q_PROPERTY(int field2 MEMBER m_field2 )
    Q_PROPERTY(int field3 MEMBER m_field3 )
    Q_PROPERTY(int field4 MEMBER m_field4 )

public:
    Struct4();
    bool operator==(const Struct4 &other) const;
    bool operator!=(const Struct4 &other) const;
    int m_field1;
    int m_field2;
    int m_field3;
    int m_field4;
};

/** ostream operator. Allows writing the Struct4 value to an text output*/
QDataStream &operator<<(QDataStream &stream, const Struct4 &obj);
/** istream operator. Allows reading to Struct4 value from input text*/
QDataStream &operator>>(QDataStream &stream, Struct4 &obj);

// ********************************************************************
// Struct4 struct factory
// Registered by plugin to allow creating this type of objects in qml. 
// ********************************************************************
class TESTBED2_API_EXPORT Struct4Factory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE testbed2::Struct4 create();
};
// ********************************************************************
// NestedStruct1 struct
// ********************************************************************
struct TESTBED2_API_EXPORT NestedStruct1
{
    Q_GADGET
    Q_PROPERTY(testbed2::Struct1 field1 MEMBER m_field1 )

public:
    NestedStruct1();
    bool operator==(const NestedStruct1 &other) const;
    bool operator!=(const NestedStruct1 &other) const;
    Struct1 m_field1;
};

/** ostream operator. Allows writing the NestedStruct1 value to an text output*/
QDataStream &operator<<(QDataStream &stream, const NestedStruct1 &obj);
/** istream operator. Allows reading to NestedStruct1 value from input text*/
QDataStream &operator>>(QDataStream &stream, NestedStruct1 &obj);

// ********************************************************************
// NestedStruct1 struct factory
// Registered by plugin to allow creating this type of objects in qml. 
// ********************************************************************
class TESTBED2_API_EXPORT NestedStruct1Factory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE testbed2::NestedStruct1 create();
};
// ********************************************************************
// NestedStruct2 struct
// ********************************************************************
struct TESTBED2_API_EXPORT NestedStruct2
{
    Q_GADGET
    Q_PROPERTY(testbed2::Struct1 field1 MEMBER m_field1 )
    Q_PROPERTY(testbed2::Struct2 field2 MEMBER m_field2 )

public:
    NestedStruct2();
    bool operator==(const NestedStruct2 &other) const;
    bool operator!=(const NestedStruct2 &other) const;
    Struct1 m_field1;
    Struct2 m_field2;
};

/** ostream operator. Allows writing the NestedStruct2 value to an text output*/
QDataStream &operator<<(QDataStream &stream, const NestedStruct2 &obj);
/** istream operator. Allows reading to NestedStruct2 value from input text*/
QDataStream &operator>>(QDataStream &stream, NestedStruct2 &obj);

// ********************************************************************
// NestedStruct2 struct factory
// Registered by plugin to allow creating this type of objects in qml. 
// ********************************************************************
class TESTBED2_API_EXPORT NestedStruct2Factory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE testbed2::NestedStruct2 create();
};
// ********************************************************************
// NestedStruct3 struct
// ********************************************************************
struct TESTBED2_API_EXPORT NestedStruct3
{
    Q_GADGET
    Q_PROPERTY(testbed2::Struct1 field1 MEMBER m_field1 )
    Q_PROPERTY(testbed2::Struct2 field2 MEMBER m_field2 )
    Q_PROPERTY(testbed2::Struct3 field3 MEMBER m_field3 )

public:
    NestedStruct3();
    bool operator==(const NestedStruct3 &other) const;
    bool operator!=(const NestedStruct3 &other) const;
    Struct1 m_field1;
    Struct2 m_field2;
    Struct3 m_field3;
};

/** ostream operator. Allows writing the NestedStruct3 value to an text output*/
QDataStream &operator<<(QDataStream &stream, const NestedStruct3 &obj);
/** istream operator. Allows reading to NestedStruct3 value from input text*/
QDataStream &operator>>(QDataStream &stream, NestedStruct3 &obj);

// ********************************************************************
// NestedStruct3 struct factory
// Registered by plugin to allow creating this type of objects in qml. 
// ********************************************************************
class TESTBED2_API_EXPORT NestedStruct3Factory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE testbed2::NestedStruct3 create();
};

// ********************************************************************
/**
*
* AbstractManyParamInterface is a pure interface QObject class.
* Declares:
*  - Methods defined for ManyParamInterface interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for ManyParamInterface interface.
*/
// ********************************************************************


class TESTBED2_API_EXPORT AbstractManyParamInterface : public QObject {
    Q_OBJECT
public:
    AbstractManyParamInterface(QObject * parent=nullptr);
    /**
    * Sets the value of the prop1 property.
    */
    virtual void setProp1(int prop1) = 0;
    /**
    * Gets the value of the prop1 property.
    */
    virtual int prop1() const = 0;
    /**
    * Sets the value of the prop2 property.
    */
    virtual void setProp2(int prop2) = 0;
    /**
    * Gets the value of the prop2 property.
    */
    virtual int prop2() const = 0;
    /**
    * Sets the value of the prop3 property.
    */
    virtual void setProp3(int prop3) = 0;
    /**
    * Gets the value of the prop3 property.
    */
    virtual int prop3() const = 0;
    /**
    * Sets the value of the prop4 property.
    */
    virtual void setProp4(int prop4) = 0;
    /**
    * Gets the value of the prop4 property.
    */
    virtual int prop4() const = 0;

    virtual int func1(int param1) = 0;

    virtual int func2(int param1, int param2) = 0;

    virtual int func3(int param1, int param2, int param3) = 0;

    virtual int func4(int param1, int param2, int param3, int param4) = 0;
signals:
    /**
    * @param param1 
    */
    void sig1(int param1);
    /**
    * @param param1 
    * @param param2 
    */
    void sig2(int param1, int param2);
    /**
    * @param param1 
    * @param param2 
    * @param param3 
    */
    void sig3(int param1, int param2, int param3);
    /**
    * @param param1 
    * @param param2 
    * @param param3 
    * @param param4 
    */
    void sig4(int param1, int param2, int param3, int param4);
    /**
    * Emitted when prop1 value has changed.
    */
    void prop1Changed(int prop1);
    /**
    * Emitted when prop2 value has changed.
    */
    void prop2Changed(int prop2);
    /**
    * Emitted when prop3 value has changed.
    */
    void prop3Changed(int prop3);
    /**
    * Emitted when prop4 value has changed.
    */
    void prop4Changed(int prop4);
};

// ********************************************************************
/**
*
* AbstractNestedStruct1Interface is a pure interface QObject class.
* Declares:
*  - Methods defined for NestedStruct1Interface interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for NestedStruct1Interface interface.
*/
// ********************************************************************


class TESTBED2_API_EXPORT AbstractNestedStruct1Interface : public QObject {
    Q_OBJECT
public:
    AbstractNestedStruct1Interface(QObject * parent=nullptr);
    /**
    * Sets the value of the prop1 property.
    */
    virtual void setProp1(const NestedStruct1& prop1) = 0;
    /**
    * Gets the value of the prop1 property.
    */
    virtual NestedStruct1 prop1() const = 0;

    virtual NestedStruct1 func1(const NestedStruct1& param1) = 0;
signals:
    /**
    * @param param1 
    */
    void sig1(const testbed2::NestedStruct1& param1);
    /**
    * Emitted when prop1 value has changed.
    */
    void prop1Changed(const NestedStruct1& prop1);
};

// ********************************************************************
/**
*
* AbstractNestedStruct2Interface is a pure interface QObject class.
* Declares:
*  - Methods defined for NestedStruct2Interface interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for NestedStruct2Interface interface.
*/
// ********************************************************************


class TESTBED2_API_EXPORT AbstractNestedStruct2Interface : public QObject {
    Q_OBJECT
public:
    AbstractNestedStruct2Interface(QObject * parent=nullptr);
    /**
    * Sets the value of the prop1 property.
    */
    virtual void setProp1(const NestedStruct1& prop1) = 0;
    /**
    * Gets the value of the prop1 property.
    */
    virtual NestedStruct1 prop1() const = 0;
    /**
    * Sets the value of the prop2 property.
    */
    virtual void setProp2(const NestedStruct2& prop2) = 0;
    /**
    * Gets the value of the prop2 property.
    */
    virtual NestedStruct2 prop2() const = 0;

    virtual NestedStruct1 func1(const NestedStruct1& param1) = 0;

    virtual NestedStruct1 func2(const NestedStruct1& param1, const NestedStruct2& param2) = 0;
signals:
    /**
    * @param param1 
    */
    void sig1(const testbed2::NestedStruct1& param1);
    /**
    * @param param1 
    * @param param2 
    */
    void sig2(const testbed2::NestedStruct1& param1, const testbed2::NestedStruct2& param2);
    /**
    * Emitted when prop1 value has changed.
    */
    void prop1Changed(const NestedStruct1& prop1);
    /**
    * Emitted when prop2 value has changed.
    */
    void prop2Changed(const NestedStruct2& prop2);
};

// ********************************************************************
/**
*
* AbstractNestedStruct3Interface is a pure interface QObject class.
* Declares:
*  - Methods defined for NestedStruct3Interface interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for NestedStruct3Interface interface.
*/
// ********************************************************************


class TESTBED2_API_EXPORT AbstractNestedStruct3Interface : public QObject {
    Q_OBJECT
public:
    AbstractNestedStruct3Interface(QObject * parent=nullptr);
    /**
    * Sets the value of the prop1 property.
    */
    virtual void setProp1(const NestedStruct1& prop1) = 0;
    /**
    * Gets the value of the prop1 property.
    */
    virtual NestedStruct1 prop1() const = 0;
    /**
    * Sets the value of the prop2 property.
    */
    virtual void setProp2(const NestedStruct2& prop2) = 0;
    /**
    * Gets the value of the prop2 property.
    */
    virtual NestedStruct2 prop2() const = 0;
    /**
    * Sets the value of the prop3 property.
    */
    virtual void setProp3(const NestedStruct3& prop3) = 0;
    /**
    * Gets the value of the prop3 property.
    */
    virtual NestedStruct3 prop3() const = 0;

    virtual NestedStruct1 func1(const NestedStruct1& param1) = 0;

    virtual NestedStruct1 func2(const NestedStruct1& param1, const NestedStruct2& param2) = 0;

    virtual NestedStruct1 func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) = 0;
signals:
    /**
    * @param param1 
    */
    void sig1(const testbed2::NestedStruct1& param1);
    /**
    * @param param1 
    * @param param2 
    */
    void sig2(const testbed2::NestedStruct1& param1, const testbed2::NestedStruct2& param2);
    /**
    * @param param1 
    * @param param2 
    * @param param3 
    */
    void sig3(const testbed2::NestedStruct1& param1, const testbed2::NestedStruct2& param2, const testbed2::NestedStruct3& param3);
    /**
    * Emitted when prop1 value has changed.
    */
    void prop1Changed(const NestedStruct1& prop1);
    /**
    * Emitted when prop2 value has changed.
    */
    void prop2Changed(const NestedStruct2& prop2);
    /**
    * Emitted when prop3 value has changed.
    */
    void prop3Changed(const NestedStruct3& prop3);
};


} //namespace testbed2


Q_DECLARE_METATYPE(testbed2::Enum1::Enum1Enum)
Q_DECLARE_METATYPE(testbed2::Enum2::Enum2Enum)
Q_DECLARE_METATYPE(testbed2::Enum3::Enum3Enum)
Q_DECLARE_METATYPE(testbed2::Struct1)
Q_DECLARE_METATYPE(testbed2::Struct2)
Q_DECLARE_METATYPE(testbed2::Struct3)
Q_DECLARE_METATYPE(testbed2::Struct4)
Q_DECLARE_METATYPE(testbed2::NestedStruct1)
Q_DECLARE_METATYPE(testbed2::NestedStruct2)
Q_DECLARE_METATYPE(testbed2::NestedStruct3)