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

#if defined(TESTBED2_LIBRARY)
#  define TESTBED2_EXPORT Q_DECL_EXPORT
#else
#  define TESTBED2_EXPORT Q_DECL_IMPORT
#endif

// ********************************************************************
// Enumeration Enum1
// ********************************************************************

class TESTBED2_EXPORT Enum1 : public QObject {
    Q_OBJECT
public:
    Enum1(QObject *parent = nullptr)
        : QObject(parent)
        {}
    enum Enum1Enum {
        value1 = 1,
        value2 = 2,
        value3 = 3,
        value4 = 4,
    };
    Q_ENUM(Enum1Enum)

    static Enum1Enum toEnum(quint8 v, bool *ok);
};
Q_DECLARE_METATYPE(Enum1::Enum1Enum)

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

class TESTBED2_EXPORT Enum2 : public QObject {
    Q_OBJECT
public:
    Enum2(QObject *parent = nullptr)
        : QObject(parent)
        {}
    enum Enum2Enum {
        value1 = 1,
        value2 = 2,
        value3 = 3,
        value4 = 4,
    };
    Q_ENUM(Enum2Enum)

    static Enum2Enum toEnum(quint8 v, bool *ok);
};
Q_DECLARE_METATYPE(Enum2::Enum2Enum)

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

class TESTBED2_EXPORT Enum3 : public QObject {
    Q_OBJECT
public:
    Enum3(QObject *parent = nullptr)
        : QObject(parent)
        {}
    enum Enum3Enum {
        value1 = 1,
        value2 = 2,
        value3 = 3,
        value4 = 4,
    };
    Q_ENUM(Enum3Enum)

    static Enum3Enum toEnum(quint8 v, bool *ok);
};
Q_DECLARE_METATYPE(Enum3::Enum3Enum)

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
// Struct1 struct
// ********************************************************************

class TESTBED2_EXPORT Struct1
{
    Q_GADGET
    Q_PROPERTY(int field1 READ field1 WRITE setField1)

public:
    Struct1();
    void setField1(int field1);
    int field1() const;

    bool operator==(const Struct1 &other) const;
    bool operator!=(const Struct1 &other) const;

private:
    int m_field1;
};

Q_DECLARE_METATYPE(Struct1)

QDataStream &operator<<(QDataStream &stream, const Struct1 &obj);
QDataStream &operator>>(QDataStream &stream, Struct1 &obj);

// ********************************************************************
// Struct1 struct factory
// ********************************************************************

class TESTBED2_EXPORT Struct1Factory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE Struct1 create();
};
// ********************************************************************
// Struct2 struct
// ********************************************************************

class TESTBED2_EXPORT Struct2
{
    Q_GADGET
    Q_PROPERTY(int field1 READ field1 WRITE setField1)
    Q_PROPERTY(int field2 READ field2 WRITE setField2)

public:
    Struct2();
    void setField1(int field1);
    int field1() const;
    void setField2(int field2);
    int field2() const;

    bool operator==(const Struct2 &other) const;
    bool operator!=(const Struct2 &other) const;

private:
    int m_field1;
    int m_field2;
};

Q_DECLARE_METATYPE(Struct2)

QDataStream &operator<<(QDataStream &stream, const Struct2 &obj);
QDataStream &operator>>(QDataStream &stream, Struct2 &obj);

// ********************************************************************
// Struct2 struct factory
// ********************************************************************

class TESTBED2_EXPORT Struct2Factory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE Struct2 create();
};
// ********************************************************************
// Struct3 struct
// ********************************************************************

class TESTBED2_EXPORT Struct3
{
    Q_GADGET
    Q_PROPERTY(int field1 READ field1 WRITE setField1)
    Q_PROPERTY(int field2 READ field2 WRITE setField2)
    Q_PROPERTY(int field3 READ field3 WRITE setField3)

public:
    Struct3();
    void setField1(int field1);
    int field1() const;
    void setField2(int field2);
    int field2() const;
    void setField3(int field3);
    int field3() const;

    bool operator==(const Struct3 &other) const;
    bool operator!=(const Struct3 &other) const;

private:
    int m_field1;
    int m_field2;
    int m_field3;
};

Q_DECLARE_METATYPE(Struct3)

QDataStream &operator<<(QDataStream &stream, const Struct3 &obj);
QDataStream &operator>>(QDataStream &stream, Struct3 &obj);

// ********************************************************************
// Struct3 struct factory
// ********************************************************************

class TESTBED2_EXPORT Struct3Factory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE Struct3 create();
};
// ********************************************************************
// Struct4 struct
// ********************************************************************

class TESTBED2_EXPORT Struct4
{
    Q_GADGET
    Q_PROPERTY(int field1 READ field1 WRITE setField1)
    Q_PROPERTY(int field2 READ field2 WRITE setField2)
    Q_PROPERTY(int field3 READ field3 WRITE setField3)
    Q_PROPERTY(int field4 READ field4 WRITE setField4)

public:
    Struct4();
    void setField1(int field1);
    int field1() const;
    void setField2(int field2);
    int field2() const;
    void setField3(int field3);
    int field3() const;
    void setField4(int field4);
    int field4() const;

    bool operator==(const Struct4 &other) const;
    bool operator!=(const Struct4 &other) const;

private:
    int m_field1;
    int m_field2;
    int m_field3;
    int m_field4;
};

Q_DECLARE_METATYPE(Struct4)

QDataStream &operator<<(QDataStream &stream, const Struct4 &obj);
QDataStream &operator>>(QDataStream &stream, Struct4 &obj);

// ********************************************************************
// Struct4 struct factory
// ********************************************************************

class TESTBED2_EXPORT Struct4Factory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE Struct4 create();
};
// ********************************************************************
// NestedStruct1 struct
// ********************************************************************

class TESTBED2_EXPORT NestedStruct1
{
    Q_GADGET
    Q_PROPERTY(Struct1 field1 READ field1 WRITE setField1)

public:
    NestedStruct1();
    void setField1(const Struct1& field1);
    Struct1 field1() const;

    bool operator==(const NestedStruct1 &other) const;
    bool operator!=(const NestedStruct1 &other) const;

private:
    Struct1 m_field1;
};

Q_DECLARE_METATYPE(NestedStruct1)

QDataStream &operator<<(QDataStream &stream, const NestedStruct1 &obj);
QDataStream &operator>>(QDataStream &stream, NestedStruct1 &obj);

// ********************************************************************
// NestedStruct1 struct factory
// ********************************************************************

class TESTBED2_EXPORT NestedStruct1Factory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE NestedStruct1 create();
};
// ********************************************************************
// NestedStruct2 struct
// ********************************************************************

class TESTBED2_EXPORT NestedStruct2
{
    Q_GADGET
    Q_PROPERTY(Struct1 field1 READ field1 WRITE setField1)
    Q_PROPERTY(Struct2 field2 READ field2 WRITE setField2)

public:
    NestedStruct2();
    void setField1(const Struct1& field1);
    Struct1 field1() const;
    void setField2(const Struct2& field2);
    Struct2 field2() const;

    bool operator==(const NestedStruct2 &other) const;
    bool operator!=(const NestedStruct2 &other) const;

private:
    Struct1 m_field1;
    Struct2 m_field2;
};

Q_DECLARE_METATYPE(NestedStruct2)

QDataStream &operator<<(QDataStream &stream, const NestedStruct2 &obj);
QDataStream &operator>>(QDataStream &stream, NestedStruct2 &obj);

// ********************************************************************
// NestedStruct2 struct factory
// ********************************************************************

class TESTBED2_EXPORT NestedStruct2Factory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE NestedStruct2 create();
};
// ********************************************************************
// NestedStruct3 struct
// ********************************************************************

class TESTBED2_EXPORT NestedStruct3
{
    Q_GADGET
    Q_PROPERTY(Struct1 field1 READ field1 WRITE setField1)
    Q_PROPERTY(Struct2 field2 READ field2 WRITE setField2)
    Q_PROPERTY(Struct3 field3 READ field3 WRITE setField3)

public:
    NestedStruct3();
    void setField1(const Struct1& field1);
    Struct1 field1() const;
    void setField2(const Struct2& field2);
    Struct2 field2() const;
    void setField3(const Struct3& field3);
    Struct3 field3() const;

    bool operator==(const NestedStruct3 &other) const;
    bool operator!=(const NestedStruct3 &other) const;

private:
    Struct1 m_field1;
    Struct2 m_field2;
    Struct3 m_field3;
};

Q_DECLARE_METATYPE(NestedStruct3)

QDataStream &operator<<(QDataStream &stream, const NestedStruct3 &obj);
QDataStream &operator>>(QDataStream &stream, NestedStruct3 &obj);

// ********************************************************************
// NestedStruct3 struct factory
// ********************************************************************

class TESTBED2_EXPORT NestedStruct3Factory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE NestedStruct3 create();
};

// ********************************************************************
// AbstractManyParamInterface pure interface
// ********************************************************************


class TESTBED2_EXPORT AbstractManyParamInterface : public QObject {
    Q_OBJECT
public:
    AbstractManyParamInterface(QObject * parent=nullptr);
    virtual void setProp1(int prop1) = 0;
    virtual int prop1() const = 0;
    virtual void setProp2(int prop2) = 0;
    virtual int prop2() const = 0;
    virtual void setProp3(int prop3) = 0;
    virtual int prop3() const = 0;
    virtual void setProp4(int prop4) = 0;
    virtual int prop4() const = 0;
    virtual int func1(int param1) = 0;
    virtual int func2(int param1, int param2) = 0;
    virtual int func3(int param1, int param2, int param3) = 0;
    virtual int func4(int param1, int param2, int param3, int param4) = 0;
signals:
    void sig1(int param1);
    void sig2(int param1, int param2);
    void sig3(int param1, int param2, int param3);
    void sig4(int param1, int param2, int param3, int param4);
    void prop1Changed(int prop1);
    void prop2Changed(int prop2);
    void prop3Changed(int prop3);
    void prop4Changed(int prop4);
};

// ********************************************************************
// AbstractNestedStruct1Interface pure interface
// ********************************************************************


class TESTBED2_EXPORT AbstractNestedStruct1Interface : public QObject {
    Q_OBJECT
public:
    AbstractNestedStruct1Interface(QObject * parent=nullptr);
    virtual void setProp1(const NestedStruct1& prop1) = 0;
    virtual NestedStruct1 prop1() const = 0;
    virtual NestedStruct1 func1(const NestedStruct1& param1) = 0;
signals:
    void sig1(const NestedStruct1& param1);
    void prop1Changed(const NestedStruct1& prop1);
};

// ********************************************************************
// AbstractNestedStruct2Interface pure interface
// ********************************************************************


class TESTBED2_EXPORT AbstractNestedStruct2Interface : public QObject {
    Q_OBJECT
public:
    AbstractNestedStruct2Interface(QObject * parent=nullptr);
    virtual void setProp1(const NestedStruct1& prop1) = 0;
    virtual NestedStruct1 prop1() const = 0;
    virtual void setProp2(const NestedStruct2& prop2) = 0;
    virtual NestedStruct2 prop2() const = 0;
    virtual NestedStruct1 func1(const NestedStruct1& param1) = 0;
    virtual NestedStruct1 func2(const NestedStruct1& param1, const NestedStruct2& param2) = 0;
signals:
    void sig1(const NestedStruct1& param1);
    void sig2(const NestedStruct1& param1, const NestedStruct2& param2);
    void prop1Changed(const NestedStruct1& prop1);
    void prop2Changed(const NestedStruct2& prop2);
};

// ********************************************************************
// AbstractNestedStruct3Interface pure interface
// ********************************************************************


class TESTBED2_EXPORT AbstractNestedStruct3Interface : public QObject {
    Q_OBJECT
public:
    AbstractNestedStruct3Interface(QObject * parent=nullptr);
    virtual void setProp1(const NestedStruct1& prop1) = 0;
    virtual NestedStruct1 prop1() const = 0;
    virtual void setProp2(const NestedStruct2& prop2) = 0;
    virtual NestedStruct2 prop2() const = 0;
    virtual void setProp3(const NestedStruct3& prop3) = 0;
    virtual NestedStruct3 prop3() const = 0;
    virtual NestedStruct1 func1(const NestedStruct1& param1) = 0;
    virtual NestedStruct1 func2(const NestedStruct1& param1, const NestedStruct2& param2) = 0;
    virtual NestedStruct1 func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) = 0;
signals:
    void sig1(const NestedStruct1& param1);
    void sig2(const NestedStruct1& param1, const NestedStruct2& param2);
    void sig3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3);
    void prop1Changed(const NestedStruct1& prop1);
    void prop2Changed(const NestedStruct2& prop2);
    void prop3Changed(const NestedStruct3& prop3);
};


// ********************************************************************
// Interface Factory
// ********************************************************************

class TESTBED2_EXPORT ApiFactoryInterface
{
public:
    virtual AbstractManyParamInterface* createManyParamInterface(QObject *parent) = 0;
    virtual AbstractNestedStruct1Interface* createNestedStruct1Interface(QObject *parent) = 0;
    virtual AbstractNestedStruct2Interface* createNestedStruct2Interface(QObject *parent) = 0;
    virtual AbstractNestedStruct3Interface* createNestedStruct3Interface(QObject *parent) = 0;
};

