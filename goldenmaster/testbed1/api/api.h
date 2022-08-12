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

#if defined(TESTBED1_LIBRARY)
#  define TESTBED1_EXPORT Q_DECL_EXPORT
#else
#  define TESTBED1_EXPORT Q_DECL_IMPORT
#endif
// ********************************************************************
// StructBool struct
// ********************************************************************

class TESTBED1_EXPORT StructBool
{
    Q_GADGET
    Q_PROPERTY(bool fieldBool READ fieldBool WRITE setFieldBool)

public:
    StructBool();
    void setFieldBool(bool fieldBool);
    bool fieldBool() const;

    bool operator==(const StructBool &other) const;
    bool operator!=(const StructBool &other) const;

private:
    bool m_fieldBool;
};

Q_DECLARE_METATYPE(StructBool)

QDataStream &operator<<(QDataStream &stream, const StructBool &obj);
QDataStream &operator>>(QDataStream &stream, StructBool &obj);

// ********************************************************************
// StructBool struct factory
// ********************************************************************

class TESTBED1_EXPORT StructBoolFactory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE StructBool create();
};
// ********************************************************************
// StructInt struct
// ********************************************************************

class TESTBED1_EXPORT StructInt
{
    Q_GADGET
    Q_PROPERTY(int fieldInt READ fieldInt WRITE setFieldInt)

public:
    StructInt();
    void setFieldInt(int fieldInt);
    int fieldInt() const;

    bool operator==(const StructInt &other) const;
    bool operator!=(const StructInt &other) const;

private:
    int m_fieldInt;
};

Q_DECLARE_METATYPE(StructInt)

QDataStream &operator<<(QDataStream &stream, const StructInt &obj);
QDataStream &operator>>(QDataStream &stream, StructInt &obj);

// ********************************************************************
// StructInt struct factory
// ********************************************************************

class TESTBED1_EXPORT StructIntFactory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE StructInt create();
};
// ********************************************************************
// StructFloat struct
// ********************************************************************

class TESTBED1_EXPORT StructFloat
{
    Q_GADGET
    Q_PROPERTY(qreal fieldFloat READ fieldFloat WRITE setFieldFloat)

public:
    StructFloat();
    void setFieldFloat(qreal fieldFloat);
    qreal fieldFloat() const;

    bool operator==(const StructFloat &other) const;
    bool operator!=(const StructFloat &other) const;

private:
    qreal m_fieldFloat;
};

Q_DECLARE_METATYPE(StructFloat)

QDataStream &operator<<(QDataStream &stream, const StructFloat &obj);
QDataStream &operator>>(QDataStream &stream, StructFloat &obj);

// ********************************************************************
// StructFloat struct factory
// ********************************************************************

class TESTBED1_EXPORT StructFloatFactory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE StructFloat create();
};
// ********************************************************************
// StructString struct
// ********************************************************************

class TESTBED1_EXPORT StructString
{
    Q_GADGET
    Q_PROPERTY(QString fieldString READ fieldString WRITE setFieldString)

public:
    StructString();
    void setFieldString(const QString& fieldString);
    QString fieldString() const;

    bool operator==(const StructString &other) const;
    bool operator!=(const StructString &other) const;

private:
    QString m_fieldString;
};

Q_DECLARE_METATYPE(StructString)

QDataStream &operator<<(QDataStream &stream, const StructString &obj);
QDataStream &operator>>(QDataStream &stream, StructString &obj);

// ********************************************************************
// StructString struct factory
// ********************************************************************

class TESTBED1_EXPORT StructStringFactory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE StructString create();
};

// ********************************************************************
// AbstractStructInterface pure interface
// ********************************************************************


class TESTBED1_EXPORT AbstractStructInterface : public QObject {
    Q_OBJECT
public:
    AbstractStructInterface(QObject * parent=nullptr);
    virtual void setPropBool(const StructBool& propBool) = 0;
    virtual StructBool propBool() const = 0;
    virtual void setPropInt(const StructInt& propInt) = 0;
    virtual StructInt propInt() const = 0;
    virtual void setPropFloat(const StructFloat& propFloat) = 0;
    virtual StructFloat propFloat() const = 0;
    virtual void setPropString(const StructString& propString) = 0;
    virtual StructString propString() const = 0;
    virtual StructBool funcBool(const StructBool& paramBool) = 0;
    virtual StructBool funcInt(const StructInt& paramInt) = 0;
    virtual StructFloat funcFloat(const StructFloat& paramFloat) = 0;
    virtual StructString funcString(const StructString& paramString) = 0;
signals:
    void sigBool(const StructBool& paramBool);
    void sigInt(const StructInt& paramInt);
    void sigFloat(const StructFloat& paramFloat);
    void sigString(const StructString& paramString);
    void propBoolChanged(const StructBool& propBool);
    void propIntChanged(const StructInt& propInt);
    void propFloatChanged(const StructFloat& propFloat);
    void propStringChanged(const StructString& propString);
};

// ********************************************************************
// AbstractStructArrayInterface pure interface
// ********************************************************************


class TESTBED1_EXPORT AbstractStructArrayInterface : public QObject {
    Q_OBJECT
public:
    AbstractStructArrayInterface(QObject * parent=nullptr);
    virtual void setPropBool(const QList<StructBool>& propBool) = 0;
    virtual QList<StructBool> propBool() const = 0;
    virtual void setPropInt(const QList<StructInt>& propInt) = 0;
    virtual QList<StructInt> propInt() const = 0;
    virtual void setPropFloat(const QList<StructFloat>& propFloat) = 0;
    virtual QList<StructFloat> propFloat() const = 0;
    virtual void setPropString(const QList<StructString>& propString) = 0;
    virtual QList<StructString> propString() const = 0;
    virtual StructBool funcBool(const QList<StructBool>& paramBool) = 0;
    virtual StructBool funcInt(const QList<StructInt>& paramInt) = 0;
    virtual StructBool funcFloat(const QList<StructFloat>& paramFloat) = 0;
    virtual StructBool funcString(const QList<StructString>& paramString) = 0;
signals:
    void sigBool(const QList<StructBool>& paramBool);
    void sigInt(const QList<StructInt>& paramInt);
    void sigFloat(const QList<StructFloat>& paramFloat);
    void sigString(const QList<StructString>& paramString);
    void propBoolChanged(const QList<StructBool>& propBool);
    void propIntChanged(const QList<StructInt>& propInt);
    void propFloatChanged(const QList<StructFloat>& propFloat);
    void propStringChanged(const QList<StructString>& propString);
};


// ********************************************************************
// Interface Factory
// ********************************************************************

class TESTBED1_EXPORT ApiFactoryInterface
{
public:
    virtual AbstractStructInterface* createStructInterface(QObject *parent) = 0;
    virtual AbstractStructArrayInterface* createStructArrayInterface(QObject *parent) = 0;
};

