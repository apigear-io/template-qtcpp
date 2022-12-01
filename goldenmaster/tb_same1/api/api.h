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

#if defined(TB_SAME1_LIBRARY)
#  define TB_SAME1_EXPORT Q_DECL_EXPORT
#else
#  define TB_SAME1_EXPORT Q_DECL_IMPORT
#endif

namespace tb_same1 {

// ********************************************************************
// Enumeration Enum1
// ********************************************************************

class TB_SAME1_EXPORT Enum1 : public QObject {
    Q_OBJECT
public:
    Enum1(QObject *parent = nullptr)
        : QObject(parent)
        {}
    enum Enum1Enum {
        value1 = 1,
        value2 = 2,
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

class TB_SAME1_EXPORT Enum2 : public QObject {
    Q_OBJECT
public:
    Enum2(QObject *parent = nullptr)
        : QObject(parent)
        {}
    enum Enum2Enum {
        value1 = 1,
        value2 = 2,
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
// Struct1 struct
// ********************************************************************

class TB_SAME1_EXPORT Struct1
{
    Q_GADGET
    Q_PROPERTY(int field1 READ field1 WRITE setField1)
    Q_PROPERTY(int field2 READ field2 WRITE setField2)
    Q_PROPERTY(int field3 READ field3 WRITE setField3)

public:
    Struct1();
    void setField1(int field1);
    int field1() const;
    void setField2(int field2);
    int field2() const;
    void setField3(int field3);
    int field3() const;

    bool operator==(const Struct1 &other) const;
    bool operator!=(const Struct1 &other) const;

private:
    int m_field1;
    int m_field2;
    int m_field3;
};

QDataStream &operator<<(QDataStream &stream, const Struct1 &obj);
QDataStream &operator>>(QDataStream &stream, Struct1 &obj);

// ********************************************************************
// Struct1 struct factory
// ********************************************************************

class TB_SAME1_EXPORT Struct1Factory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE Struct1 create();
};
// ********************************************************************
// Struct2 struct
// ********************************************************************

class TB_SAME1_EXPORT Struct2
{
    Q_GADGET
    Q_PROPERTY(int field1 READ field1 WRITE setField1)
    Q_PROPERTY(int field2 READ field2 WRITE setField2)
    Q_PROPERTY(int field3 READ field3 WRITE setField3)

public:
    Struct2();
    void setField1(int field1);
    int field1() const;
    void setField2(int field2);
    int field2() const;
    void setField3(int field3);
    int field3() const;

    bool operator==(const Struct2 &other) const;
    bool operator!=(const Struct2 &other) const;

private:
    int m_field1;
    int m_field2;
    int m_field3;
};

QDataStream &operator<<(QDataStream &stream, const Struct2 &obj);
QDataStream &operator>>(QDataStream &stream, Struct2 &obj);

// ********************************************************************
// Struct2 struct factory
// ********************************************************************

class TB_SAME1_EXPORT Struct2Factory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE Struct2 create();
};

// ********************************************************************
// AbstractSameStruct1Interface pure interface
// ********************************************************************


class TB_SAME1_EXPORT AbstractSameStruct1Interface : public QObject {
    Q_OBJECT
public:
    AbstractSameStruct1Interface(QObject * parent=nullptr);
    virtual void setProp1(const Struct1& prop1) = 0;
    virtual Struct1 prop1() const = 0;
    virtual Struct1 func1(const Struct1& param1) = 0;
signals:
    void sig1(const Struct1& param1);
    void prop1Changed(const Struct1& prop1);
};

// ********************************************************************
// AbstractSameStruct2Interface pure interface
// ********************************************************************


class TB_SAME1_EXPORT AbstractSameStruct2Interface : public QObject {
    Q_OBJECT
public:
    AbstractSameStruct2Interface(QObject * parent=nullptr);
    virtual void setProp1(const Struct2& prop1) = 0;
    virtual Struct2 prop1() const = 0;
    virtual void setProp2(const Struct2& prop2) = 0;
    virtual Struct2 prop2() const = 0;
    virtual Struct1 func1(const Struct1& param1) = 0;
    virtual Struct1 func2(const Struct1& param1, const Struct2& param2) = 0;
signals:
    void sig1(const Struct1& param1);
    void sig2(const Struct1& param1, const Struct2& param2);
    void prop1Changed(const Struct2& prop1);
    void prop2Changed(const Struct2& prop2);
};

// ********************************************************************
// AbstractSameEnum1Interface pure interface
// ********************************************************************


class TB_SAME1_EXPORT AbstractSameEnum1Interface : public QObject {
    Q_OBJECT
public:
    AbstractSameEnum1Interface(QObject * parent=nullptr);
    virtual void setProp1(const Enum1::Enum1Enum prop1) = 0;
    virtual Enum1::Enum1Enum prop1() const = 0;
    virtual Enum1::Enum1Enum func1(const Enum1::Enum1Enum param1) = 0;
signals:
    void sig1(const Enum1::Enum1Enum param1);
    void prop1Changed(const Enum1::Enum1Enum prop1);
};

// ********************************************************************
// AbstractSameEnum2Interface pure interface
// ********************************************************************


class TB_SAME1_EXPORT AbstractSameEnum2Interface : public QObject {
    Q_OBJECT
public:
    AbstractSameEnum2Interface(QObject * parent=nullptr);
    virtual void setProp1(const Enum1::Enum1Enum prop1) = 0;
    virtual Enum1::Enum1Enum prop1() const = 0;
    virtual void setProp2(const Enum2::Enum2Enum prop2) = 0;
    virtual Enum2::Enum2Enum prop2() const = 0;
    virtual Enum1::Enum1Enum func1(const Enum1::Enum1Enum param1) = 0;
    virtual Enum1::Enum1Enum func2(const Enum1::Enum1Enum param1, const Enum2::Enum2Enum param2) = 0;
signals:
    void sig1(const Enum1::Enum1Enum param1);
    void sig2(const Enum1::Enum1Enum param1, const Enum2::Enum2Enum param2);
    void prop1Changed(const Enum1::Enum1Enum prop1);
    void prop2Changed(const Enum2::Enum2Enum prop2);
};


// ********************************************************************
// Interface Factory
// ********************************************************************

class TB_SAME1_EXPORT ApiFactoryInterface
{
public:
    virtual AbstractSameStruct1Interface* createSameStruct1Interface(QObject *parent) = 0;
    virtual AbstractSameStruct2Interface* createSameStruct2Interface(QObject *parent) = 0;
    virtual AbstractSameEnum1Interface* createSameEnum1Interface(QObject *parent) = 0;
    virtual AbstractSameEnum2Interface* createSameEnum2Interface(QObject *parent) = 0;
};

} //namespace tb_same1


Q_DECLARE_METATYPE(tb_same1::Enum1::Enum1Enum)
Q_DECLARE_METATYPE(tb_same1::Enum2::Enum2Enum)
Q_DECLARE_METATYPE(tb_same1::Struct1)
Q_DECLARE_METATYPE(tb_same1::Struct2)