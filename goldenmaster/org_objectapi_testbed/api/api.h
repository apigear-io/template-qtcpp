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

#if defined(ORG_OBJECTAPI_TESTBED_LIBRARY)
#  define ORG_OBJECTAPI_TESTBED_EXPORT Q_DECL_EXPORT
#else
#  define ORG_OBJECTAPI_TESTBED_EXPORT Q_DECL_IMPORT
#endif

// ********************************************************************
// Enumeration Enum1
// ********************************************************************

class ORG_OBJECTAPI_TESTBED_EXPORT Enum1 : public QObject {
    Q_OBJECT
public:
    Enum1(QObject *parent = nullptr)
        : QObject(parent)
        {}
    enum Enum1Enum {
        Member1 = 0,
        Member2 = 1,
        Member3 = 2,
        Member4 = 3,
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

class ORG_OBJECTAPI_TESTBED_EXPORT Enum2 : public QObject {
    Q_OBJECT
public:
    Enum2(QObject *parent = nullptr)
        : QObject(parent)
        {}
    enum Enum2Enum {
        Member1 = 0,
        Member2 = 1,
        Member3 = 2,
        Member4 = 3,
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
// Struct1 struct
// ********************************************************************

class ORG_OBJECTAPI_TESTBED_EXPORT Struct1
{
    Q_GADGET
    Q_PROPERTY(bool field1 READ field1 WRITE setField1)
    Q_PROPERTY(int field2 READ field2 WRITE setField2)
    Q_PROPERTY(qreal field3 READ field3 WRITE setField3)
    Q_PROPERTY(QString field4 READ field4 WRITE setField4)

public:
    Struct1();
    void setField1(bool field1);
    bool field1() const;
    void setField2(int field2);
    int field2() const;
    void setField3(qreal field3);
    qreal field3() const;
    void setField4(const QString& field4);
    QString field4() const;

    bool operator==(const Struct1 &other) const;
    bool operator!=(const Struct1 &other) const;

private:
    bool m_field1;
    int m_field2;
    qreal m_field3;
    QString m_field4;
};

Q_DECLARE_METATYPE(Struct1)

QDataStream &operator<<(QDataStream &stream, const Struct1 &obj);
QDataStream &operator>>(QDataStream &stream, Struct1 &obj);

// ********************************************************************
// Struct1 struct factory
// ********************************************************************

class ORG_OBJECTAPI_TESTBED_EXPORT Struct1Factory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE Struct1 create();
};

// ********************************************************************
// AbstractInterface1 pure interface
// ********************************************************************


class ORG_OBJECTAPI_TESTBED_EXPORT AbstractInterface1 : public QObject {
    Q_OBJECT
public:
    AbstractInterface1(QObject * parent=nullptr);
    virtual void setProp1(bool prop1) = 0;
    virtual bool prop1() const = 0;
    virtual void setProp2(int prop2) = 0;
    virtual int prop2() const = 0;
    virtual void setProp3(qreal prop3) = 0;
    virtual qreal prop3() const = 0;
    virtual void setProp4(const QString& prop4) = 0;
    virtual QString prop4() const = 0;
    virtual void setProp5(const QList<int>& prop5) = 0;
    virtual QList<int> prop5() const = 0;
    virtual void setProp6(const Struct1& prop6) = 0;
    virtual Struct1 prop6() const = 0;
    virtual void setProp7(int prop7) = 0;
    virtual int prop7() const = 0;
    virtual void setProp10(const QList<int>& prop10) = 0;
    virtual QList<int> prop10() const = 0;
    virtual void setProp11(const QList<Struct1>& prop11) = 0;
    virtual QList<Struct1> prop11() const = 0;
    virtual void setProp12(const QList<Enum1::Enum1Enum>& prop12) = 0;
    virtual QList<Enum1::Enum1Enum> prop12() const = 0;
    virtual void setProp14(const QList<Struct1>& prop14) = 0;
    virtual QList<Struct1> prop14() const = 0;
    virtual void op1() = 0;
    virtual void op2(int step) = 0;
    virtual int op3() = 0;
signals:
    void sig1();
    void sig2(int step);
    void sig3();
    void prop1Changed(bool prop1);
    void prop2Changed(int prop2);
    void prop3Changed(qreal prop3);
    void prop4Changed(const QString& prop4);
    void prop5Changed(const QList<int>& prop5);
    void prop6Changed(const Struct1& prop6);
    void prop7Changed(int prop7);
    void prop10Changed(const QList<int>& prop10);
    void prop11Changed(const QList<Struct1>& prop11);
    void prop12Changed(const QList<Enum1::Enum1Enum>& prop12);
    void prop14Changed(const QList<Struct1>& prop14);
};

// ********************************************************************
// AbstractInterface2 pure interface
// ********************************************************************


class ORG_OBJECTAPI_TESTBED_EXPORT AbstractInterface2 : public QObject {
    Q_OBJECT
public:
    AbstractInterface2(QObject * parent=nullptr);
    virtual void setProp200(int prop200) = 0;
    virtual int prop200() const = 0;
    virtual void setProp201(int prop201) = 0;
    virtual int prop201() const = 0;
    virtual void setProp202(int prop202) = 0;
    virtual int prop202() const = 0;
    virtual void setProp203(qreal prop203) = 0;
    virtual qreal prop203() const = 0;
    virtual void setProp204(qreal prop204) = 0;
    virtual qreal prop204() const = 0;
    virtual void setProp205(const QString& prop205) = 0;
    virtual QString prop205() const = 0;
signals:
    void prop200Changed(int prop200);
    void prop201Changed(int prop201);
    void prop202Changed(int prop202);
    void prop203Changed(qreal prop203);
    void prop204Changed(qreal prop204);
    void prop205Changed(const QString& prop205);
};


// ********************************************************************
// Interface Factory
// ********************************************************************

class ORG_OBJECTAPI_TESTBED_EXPORT ApiFactoryInterface
{
public:
    virtual AbstractInterface1* createInterface1(QObject *parent) = 0;
    virtual AbstractInterface2* createInterface2(QObject *parent) = 0;
};

