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

#if defined(TESTBED1_API_LIBRARY)
#  define TESTBED1_API_EXPORT Q_DECL_EXPORT
#else
#  define TESTBED1_API_EXPORT Q_DECL_IMPORT
#endif

namespace testbed1 {
// ********************************************************************
// StructBool struct
// ********************************************************************
struct TESTBED1_API_EXPORT StructBool
{
    Q_GADGET
    Q_PROPERTY(bool fieldBool MEMBER m_fieldBool )

public:
    StructBool();
    bool operator==(const StructBool &other) const;
    bool operator!=(const StructBool &other) const;
    bool m_fieldBool;
};

/** ostream operator. Allows writing the StructBool value to an text output*/
QDataStream &operator<<(QDataStream &stream, const StructBool &obj);
/** istream operator. Allows reading to StructBool value from input text*/
QDataStream &operator>>(QDataStream &stream, StructBool &obj);

// ********************************************************************
// StructBool struct factory
// Registered by plugin to allow creating this type of objects in qml. 
// ********************************************************************
class TESTBED1_API_EXPORT StructBoolFactory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE testbed1::StructBool create();
};
// ********************************************************************
// StructInt struct
// ********************************************************************
struct TESTBED1_API_EXPORT StructInt
{
    Q_GADGET
    Q_PROPERTY(int fieldInt MEMBER m_fieldInt )

public:
    StructInt();
    bool operator==(const StructInt &other) const;
    bool operator!=(const StructInt &other) const;
    int m_fieldInt;
};

/** ostream operator. Allows writing the StructInt value to an text output*/
QDataStream &operator<<(QDataStream &stream, const StructInt &obj);
/** istream operator. Allows reading to StructInt value from input text*/
QDataStream &operator>>(QDataStream &stream, StructInt &obj);

// ********************************************************************
// StructInt struct factory
// Registered by plugin to allow creating this type of objects in qml. 
// ********************************************************************
class TESTBED1_API_EXPORT StructIntFactory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE testbed1::StructInt create();
};
// ********************************************************************
// StructFloat struct
// ********************************************************************
struct TESTBED1_API_EXPORT StructFloat
{
    Q_GADGET
    Q_PROPERTY(qreal fieldFloat MEMBER m_fieldFloat )

public:
    StructFloat();
    bool operator==(const StructFloat &other) const;
    bool operator!=(const StructFloat &other) const;
    qreal m_fieldFloat;
};

/** ostream operator. Allows writing the StructFloat value to an text output*/
QDataStream &operator<<(QDataStream &stream, const StructFloat &obj);
/** istream operator. Allows reading to StructFloat value from input text*/
QDataStream &operator>>(QDataStream &stream, StructFloat &obj);

// ********************************************************************
// StructFloat struct factory
// Registered by plugin to allow creating this type of objects in qml. 
// ********************************************************************
class TESTBED1_API_EXPORT StructFloatFactory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE testbed1::StructFloat create();
};
// ********************************************************************
// StructString struct
// ********************************************************************
struct TESTBED1_API_EXPORT StructString
{
    Q_GADGET
    Q_PROPERTY(QString fieldString MEMBER m_fieldString )

public:
    StructString();
    bool operator==(const StructString &other) const;
    bool operator!=(const StructString &other) const;
    QString m_fieldString;
};

/** ostream operator. Allows writing the StructString value to an text output*/
QDataStream &operator<<(QDataStream &stream, const StructString &obj);
/** istream operator. Allows reading to StructString value from input text*/
QDataStream &operator>>(QDataStream &stream, StructString &obj);

// ********************************************************************
// StructString struct factory
// Registered by plugin to allow creating this type of objects in qml. 
// ********************************************************************
class TESTBED1_API_EXPORT StructStringFactory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE testbed1::StructString create();
};

// ********************************************************************
/**
*
* AbstractStructInterface is a pure interface QObject class.
* Declares:
*  - Methods defined for StructInterface interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for StructInterface interface.
*/
// ********************************************************************


class TESTBED1_API_EXPORT AbstractStructInterface : public QObject {
    Q_OBJECT
public:
    AbstractStructInterface(QObject * parent=nullptr);
    /**
    * Sets the value of the propBool property.
    */
    virtual void setPropBool(const StructBool& propBool) = 0;
    /**
    * Gets the value of the propBool property.
    */
    virtual StructBool propBool() const = 0;
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(const StructInt& propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual StructInt propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(const StructFloat& propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual StructFloat propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const StructString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual StructString propString() const = 0;

    virtual StructBool funcBool(const StructBool& paramBool) = 0;

    virtual StructBool funcInt(const StructInt& paramInt) = 0;

    virtual StructFloat funcFloat(const StructFloat& paramFloat) = 0;

    virtual StructString funcString(const StructString& paramString) = 0;
signals:
    /**
    * @param paramBool 
    */
    void sigBool(const testbed1::StructBool& paramBool);
    /**
    * @param paramInt 
    */
    void sigInt(const testbed1::StructInt& paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(const testbed1::StructFloat& paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const testbed1::StructString& paramString);
    /**
    * Emitted when propBool value has changed.
    */
    void propBoolChanged(const StructBool& propBool);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(const StructInt& propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(const StructFloat& propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const StructString& propString);
};

// ********************************************************************
/**
*
* AbstractStructArrayInterface is a pure interface QObject class.
* Declares:
*  - Methods defined for StructArrayInterface interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for StructArrayInterface interface.
*/
// ********************************************************************


class TESTBED1_API_EXPORT AbstractStructArrayInterface : public QObject {
    Q_OBJECT
public:
    AbstractStructArrayInterface(QObject * parent=nullptr);
    /**
    * Sets the value of the propBool property.
    */
    virtual void setPropBool(const QList<StructBool>& propBool) = 0;
    /**
    * Gets the value of the propBool property.
    */
    virtual QList<StructBool> propBool() const = 0;
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(const QList<StructInt>& propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual QList<StructInt> propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(const QList<StructFloat>& propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual QList<StructFloat> propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QList<StructString>& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QList<StructString> propString() const = 0;

    virtual StructBool funcBool(const QList<StructBool>& paramBool) = 0;

    virtual StructBool funcInt(const QList<StructInt>& paramInt) = 0;

    virtual StructBool funcFloat(const QList<StructFloat>& paramFloat) = 0;

    virtual StructBool funcString(const QList<StructString>& paramString) = 0;
signals:
    /**
    * @param paramBool 
    */
    void sigBool(const QList<testbed1::StructBool>& paramBool);
    /**
    * @param paramInt 
    */
    void sigInt(const QList<testbed1::StructInt>& paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(const QList<testbed1::StructFloat>& paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QList<testbed1::StructString>& paramString);
    /**
    * Emitted when propBool value has changed.
    */
    void propBoolChanged(const QList<StructBool>& propBool);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(const QList<StructInt>& propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(const QList<StructFloat>& propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QList<StructString>& propString);
};


} //namespace testbed1


Q_DECLARE_METATYPE(testbed1::StructBool)
Q_DECLARE_METATYPE(testbed1::StructInt)
Q_DECLARE_METATYPE(testbed1::StructFloat)
Q_DECLARE_METATYPE(testbed1::StructString)