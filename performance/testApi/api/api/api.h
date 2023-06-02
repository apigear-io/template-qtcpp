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

#if defined(API_API_LIBRARY)
#  define API_API_EXPORT Q_DECL_EXPORT
#else
#  define API_API_EXPORT Q_DECL_IMPORT
#endif

namespace api {

// ********************************************************************
/**
*
* AbstractTestApi0 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi0 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi0 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi0 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi0(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi1 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi1 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi1 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi1 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi1(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi2 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi2 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi2 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi2 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi2(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi3 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi3 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi3 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi3 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi3(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi4 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi4 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi4 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi4 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi4(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi5 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi5 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi5 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi5 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi5(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi6 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi6 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi6 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi6 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi6(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi7 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi7 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi7 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi7 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi7(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi8 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi8 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi8 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi8 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi8(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi9 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi9 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi9 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi9 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi9(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi10 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi10 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi10 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi10 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi10(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi11 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi11 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi11 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi11 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi11(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi12 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi12 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi12 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi12 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi12(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi13 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi13 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi13 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi13 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi13(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi14 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi14 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi14 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi14 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi14(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi15 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi15 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi15 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi15 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi15(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi16 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi16 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi16 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi16 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi16(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi17 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi17 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi17 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi17 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi17(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi18 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi18 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi18 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi18 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi18(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi19 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi19 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi19 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi19 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi19(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi20 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi20 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi20 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi20 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi20(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi21 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi21 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi21 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi21 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi21(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi22 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi22 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi22 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi22 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi22(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi23 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi23 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi23 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi23 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi23(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi24 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi24 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi24 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi24 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi24(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi25 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi25 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi25 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi25 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi25(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi26 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi26 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi26 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi26 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi26(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi27 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi27 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi27 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi27 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi27(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi28 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi28 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi28 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi28 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi28(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi29 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi29 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi29 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi29 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi29(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi30 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi30 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi30 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi30 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi30(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi31 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi31 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi31 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi31 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi31(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi32 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi32 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi32 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi32 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi32(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi33 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi33 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi33 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi33 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi33(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi34 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi34 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi34 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi34 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi34(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi35 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi35 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi35 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi35 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi35(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi36 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi36 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi36 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi36 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi36(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi37 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi37 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi37 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi37 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi37(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi38 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi38 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi38 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi38 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi38(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi39 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi39 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi39 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi39 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi39(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi40 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi40 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi40 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi40 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi40(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi41 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi41 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi41 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi41 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi41(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi42 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi42 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi42 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi42 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi42(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi43 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi43 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi43 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi43 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi43(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi44 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi44 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi44 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi44 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi44(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi45 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi45 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi45 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi45 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi45(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi46 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi46 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi46 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi46 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi46(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi47 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi47 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi47 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi47 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi47(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi48 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi48 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi48 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi48 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi48(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi49 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi49 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi49 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi49 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi49(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi50 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi50 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi50 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi50 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi50(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi51 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi51 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi51 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi51 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi51(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi52 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi52 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi52 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi52 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi52(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi53 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi53 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi53 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi53 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi53(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi54 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi54 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi54 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi54 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi54(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi55 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi55 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi55 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi55 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi55(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi56 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi56 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi56 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi56 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi56(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi57 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi57 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi57 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi57 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi57(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi58 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi58 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi58 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi58 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi58(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi59 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi59 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi59 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi59 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi59(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi60 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi60 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi60 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi60 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi60(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi61 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi61 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi61 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi61 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi61(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi62 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi62 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi62 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi62 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi62(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi63 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi63 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi63 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi63 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi63(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi64 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi64 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi64 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi64 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi64(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi65 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi65 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi65 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi65 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi65(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi66 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi66 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi66 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi66 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi66(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi67 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi67 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi67 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi67 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi67(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi68 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi68 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi68 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi68 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi68(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi69 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi69 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi69 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi69 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi69(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi70 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi70 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi70 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi70 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi70(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi71 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi71 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi71 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi71 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi71(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi72 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi72 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi72 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi72 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi72(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi73 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi73 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi73 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi73 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi73(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi74 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi74 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi74 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi74 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi74(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi75 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi75 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi75 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi75 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi75(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi76 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi76 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi76 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi76 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi76(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi77 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi77 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi77 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi77 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi77(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi78 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi78 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi78 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi78 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi78(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi79 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi79 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi79 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi79 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi79(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi80 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi80 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi80 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi80 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi80(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi81 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi81 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi81 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi81 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi81(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi82 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi82 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi82 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi82 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi82(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi83 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi83 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi83 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi83 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi83(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi84 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi84 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi84 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi84 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi84(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi85 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi85 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi85 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi85 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi85(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi86 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi86 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi86 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi86 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi86(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi87 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi87 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi87 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi87 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi87(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi88 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi88 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi88 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi88 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi88(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi89 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi89 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi89 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi89 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi89(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi90 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi90 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi90 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi90 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi90(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi91 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi91 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi91 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi91 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi91(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi92 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi92 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi92 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi92 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi92(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi93 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi93 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi93 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi93 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi93(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi94 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi94 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi94 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi94 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi94(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi95 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi95 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi95 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi95 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi95(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi96 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi96 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi96 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi96 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi96(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi97 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi97 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi97 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi97 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi97(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi98 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi98 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi98 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi98 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi98(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};

// ********************************************************************
/**
*
* AbstractTestApi99 is a pure interface QObject class.
* Declares:
*  - Methods defined for TestApi99 interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for TestApi99 interface.
*/
// ********************************************************************


class API_API_EXPORT AbstractTestApi99 : public QObject {
    Q_OBJECT
public:
    AbstractTestApi99(QObject * parent=nullptr);
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(int propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual int propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QString& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QString propString() const = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramInt 
    */
    void sigInt(int paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QString& paramString);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(int propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QString& propString);
};


} //namespace api

