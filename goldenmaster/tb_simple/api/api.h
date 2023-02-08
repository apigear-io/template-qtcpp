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

#if defined(TB_SIMPLE_API_LIBRARY)
#  define TB_SIMPLE_API_EXPORT Q_DECL_EXPORT
#else
#  define TB_SIMPLE_API_EXPORT Q_DECL_IMPORT
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


class TB_SIMPLE_API_EXPORT AbstractSimpleInterface : public QObject {
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
    * Sets the value of the propInt32 property.
    */
    virtual void setPropInt32(qint32 propInt32) = 0;
    /**
    * Gets the value of the propInt32 property.
    */
    virtual qint32 propInt32() const = 0;
    /**
    * Sets the value of the propInt64 property.
    */
    virtual void setPropInt64(qint64 propInt64) = 0;
    /**
    * Gets the value of the propInt64 property.
    */
    virtual qint64 propInt64() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(qreal propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual qreal propFloat() const = 0;
    /**
    * Sets the value of the propFloat32 property.
    */
    virtual void setPropFloat32(float propFloat32) = 0;
    /**
    * Gets the value of the propFloat32 property.
    */
    virtual float propFloat32() const = 0;
    /**
    * Sets the value of the propFloat64 property.
    */
    virtual void setPropFloat64(double propFloat64) = 0;
    /**
    * Gets the value of the propFloat64 property.
    */
    virtual double propFloat64() const = 0;
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

    virtual qint32 funcInt32(qint32 paramInt32) = 0;

    virtual qint64 funcInt64(qint64 paramInt64) = 0;

    virtual qreal funcFloat(qreal paramFloat) = 0;

    virtual float funcFloat32(float paramFloat32) = 0;

    virtual double funcFloat64(double paramFloat) = 0;

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
    * @param paramInt32 
    */
    void sigInt32(qint32 paramInt32);
    /**
    * @param paramInt64 
    */
    void sigInt64(qint64 paramInt64);
    /**
    * @param paramFloat 
    */
    void sigFloat(qreal paramFloat);
    /**
    * @param paramFloa32 
    */
    void sigFloat32(float paramFloa32);
    /**
    * @param paramFloat64 
    */
    void sigFloat64(double paramFloat64);
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
    * Emitted when propInt32 value has changed.
    */
    void propInt32Changed(qint32 propInt32);
    /**
    * Emitted when propInt64 value has changed.
    */
    void propInt64Changed(qint64 propInt64);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(qreal propFloat);
    /**
    * Emitted when propFloat32 value has changed.
    */
    void propFloat32Changed(float propFloat32);
    /**
    * Emitted when propFloat64 value has changed.
    */
    void propFloat64Changed(double propFloat64);
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


class TB_SIMPLE_API_EXPORT AbstractSimpleArrayInterface : public QObject {
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
    * Sets the value of the propInt32 property.
    */
    virtual void setPropInt32(const QList<qint32>& propInt32) = 0;
    /**
    * Gets the value of the propInt32 property.
    */
    virtual QList<qint32> propInt32() const = 0;
    /**
    * Sets the value of the propInt64 property.
    */
    virtual void setPropInt64(const QList<qint64>& propInt64) = 0;
    /**
    * Gets the value of the propInt64 property.
    */
    virtual QList<qint64> propInt64() const = 0;
    /**
    * Sets the value of the propFloat property.
    */
    virtual void setPropFloat(const QList<qreal>& propFloat) = 0;
    /**
    * Gets the value of the propFloat property.
    */
    virtual QList<qreal> propFloat() const = 0;
    /**
    * Sets the value of the propFloat32 property.
    */
    virtual void setPropFloat32(const QList<float>& propFloat32) = 0;
    /**
    * Gets the value of the propFloat32 property.
    */
    virtual QList<float> propFloat32() const = 0;
    /**
    * Sets the value of the propFloat64 property.
    */
    virtual void setPropFloat64(const QList<double>& propFloat64) = 0;
    /**
    * Gets the value of the propFloat64 property.
    */
    virtual QList<double> propFloat64() const = 0;
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

    virtual QList<qint32> funcInt32(const QList<qint32>& paramInt32) = 0;

    virtual QList<qint64> funcInt64(const QList<qint64>& paramInt64) = 0;

    virtual QList<qreal> funcFloat(const QList<qreal>& paramFloat) = 0;

    virtual QList<float> funcFloat32(const QList<float>& paramFloat32) = 0;

    virtual QList<double> funcFloat64(const QList<double>& paramFloat) = 0;

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
    * @param paramInt32 
    */
    void sigInt32(const QList<qint32>& paramInt32);
    /**
    * @param paramInt64 
    */
    void sigInt64(const QList<qint64>& paramInt64);
    /**
    * @param paramFloat 
    */
    void sigFloat(const QList<qreal>& paramFloat);
    /**
    * @param paramFloa32 
    */
    void sigFloat32(const QList<float>& paramFloa32);
    /**
    * @param paramFloat64 
    */
    void sigFloat64(const QList<double>& paramFloat64);
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
    * Emitted when propInt32 value has changed.
    */
    void propInt32Changed(const QList<qint32>& propInt32);
    /**
    * Emitted when propInt64 value has changed.
    */
    void propInt64Changed(const QList<qint64>& propInt64);
    /**
    * Emitted when propFloat value has changed.
    */
    void propFloatChanged(const QList<qreal>& propFloat);
    /**
    * Emitted when propFloat32 value has changed.
    */
    void propFloat32Changed(const QList<float>& propFloat32);
    /**
    * Emitted when propFloat64 value has changed.
    */
    void propFloat64Changed(const QList<double>& propFloat64);
    /**
    * Emitted when propString value has changed.
    */
    void propStringChanged(const QList<QString>& propString);
};


} //namespace tb_simple

