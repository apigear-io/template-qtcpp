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

#if defined(TB_SIMPLE_LIBRARY)
#  define TB_SIMPLE_EXPORT Q_DECL_EXPORT
#else
#  define TB_SIMPLE_EXPORT Q_DECL_IMPORT
#endif

namespace tb_simple {

// ********************************************************************
/**
*
* AbstractSimpleInterface is a pure interface QObject class.
* Declares:
*  - Methods defined for SimpleInterface interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for SimpleInterface interface.
*/
// ********************************************************************


class TB_SIMPLE_EXPORT AbstractSimpleInterface : public QObject {
    Q_OBJECT
public:
    AbstractSimpleInterface(QObject * parent=nullptr);
    /**
    * Sets the value of the propBool property.
    */
    virtual void setPropBool(bool propBool) = 0;
    /**
    * Gets the value of the propBool property.
    */
    virtual bool propBool() const = 0;
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

    virtual bool funcBool(bool paramBool) = 0;

    virtual int funcInt(int paramInt) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual QString funcString(const QString& paramString) = 0;
signals:
    /**
    * @param paramBool 
    */
    void sigBool(bool paramBool);
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
    * Emitted when propBool value has changed.
    */
    void propBoolChanged(bool propBool);
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
* AbstractSimpleArrayInterface is a pure interface QObject class.
* Declares:
*  - Methods defined for SimpleArrayInterface interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for SimpleArrayInterface interface.
*/
// ********************************************************************


class TB_SIMPLE_EXPORT AbstractSimpleArrayInterface : public QObject {
    Q_OBJECT
public:
    AbstractSimpleArrayInterface(QObject * parent=nullptr);
    /**
    * Sets the value of the propBool property.
    */
    virtual void setPropBool(const QList<bool>& propBool) = 0;
    /**
    * Gets the value of the propBool property.
    */
    virtual QList<bool> propBool() const = 0;
    /**
    * Sets the value of the propInt property.
    */
    virtual void setPropInt(const QList<int>& propInt) = 0;
    /**
    * Gets the value of the propInt property.
    */
    virtual QList<int> propInt() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(const QList<qreal>& propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual QList<qreal> propFloat() const = 0;
    /**
    * Sets the value of the propString property.
    */
    virtual void setPropString(const QList<QString>& propString) = 0;
    /**
    * Gets the value of the propString property.
    */
    virtual QList<QString> propString() const = 0;

    virtual QList<bool> funcBool(const QList<bool>& paramBool) = 0;

    virtual QList<int> funcInt(const QList<int>& paramInt) = 0;

    virtual QList<qreal> funcFloat(const QList<qreal>& paramFloat) = 0;

    virtual QList<QString> funcString(const QList<QString>& paramString) = 0;
signals:
    /**
    * @param paramBool 
    */
    void sigBool(const QList<bool>& paramBool);
    /**
    * @param paramInt 
    */
    void sigInt(const QList<int>& paramInt);
    /**
    * @param paramFloat 
    */
    void sigFloat(const QList<qreal>& paramFloat);
    /**
    * @param paramString 
    */
    void sigString(const QList<QString>& paramString);
    /**
    * Emitted when propBool value has changed.
    */
    void propBoolChanged(const QList<bool>& propBool);
    /**
    * Emitted when propInt value has changed.
    */
    void propIntChanged(const QList<int>& propInt);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(const QList<qreal>& propFloat);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QList<QString>& propString);
};


// ********************************************************************
// Interface Factory
// ********************************************************************

/**
* An interface for a Factory of interfaces in tb.simple
* May be used to provide different implementations of your interfaces.
* Check the usage of ApiFactoryInterface in Qml versions of interface implementation.
* See also the ApiFactory, where you can set this factory as an ApiFactoryInterface implementation.
*/
class TB_SIMPLE_EXPORT ApiFactoryInterface
{
public:
/** Create an instance of SimpleInterface
* @return The implementation of a AbstractSimpleInterface, of which user should take ownership.
*/
    virtual AbstractSimpleInterface* createSimpleInterface(QObject *parent) = 0;
/** Create an instance of SimpleArrayInterface
* @return The implementation of a AbstractSimpleArrayInterface, of which user should take ownership.
*/
    virtual AbstractSimpleArrayInterface* createSimpleArrayInterface(QObject *parent) = 0;
};

} //namespace tb_simple

