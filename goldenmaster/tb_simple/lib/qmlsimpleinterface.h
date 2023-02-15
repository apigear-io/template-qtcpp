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

#include "simpleinterface.h"
#include <memory>

namespace tb_simple {

/**
* A QML wrapper of the SimpleInterface implementation.
* Uses a SimpleInterface backend provided by an ApiFactory.
* Use this class to easily bind to properties and signals provided by SimpleInterface backend or
* invoke operations on it. Have in mind that singals provided by SimpleInterface backend should be
* emitted only by SimpleInterface backend, emitting it on qml will not reach the SimpleInterface backend.
* See ApiFactory and factories that implement the ApiFactoryInterface for other features.
*/
class TB_SIMPLE_LIB_EXPORT QmlSimpleInterface : public AbstractSimpleInterface
{
    Q_OBJECT

    /**
    * Exposes propBool property for qml.
    */
    Q_PROPERTY(bool propBool READ propBool WRITE setPropBool NOTIFY propBoolChanged)

    /**
    * Exposes propInt property for qml.
    */
    Q_PROPERTY(int propInt READ propInt WRITE setPropInt NOTIFY propIntChanged)

    /**
    * Exposes propInt32 property for qml.
    */
    Q_PROPERTY(qint32 propInt32 READ propInt32 WRITE setPropInt32 NOTIFY propInt32Changed)

    /**
    * Exposes propInt64 property for qml.
    */
    Q_PROPERTY(qint64 propInt64 READ propInt64 WRITE setPropInt64 NOTIFY propInt64Changed)

    /**
    * Exposes propFloat property for qml.
    */
    Q_PROPERTY(qreal propFloat READ propFloat WRITE setPropFloat NOTIFY propFloatChanged)

    /**
    * Exposes propFloat32 property for qml.
    */
    Q_PROPERTY(float propFloat32 READ propFloat32 WRITE setPropFloat32 NOTIFY propFloat32Changed)

    /**
    * Exposes propFloat64 property for qml.
    */
    Q_PROPERTY(double propFloat64 READ propFloat64 WRITE setPropFloat64 NOTIFY propFloat64Changed)

    /**
    * Exposes propString property for qml.
    */
    Q_PROPERTY(QString propString READ propString WRITE setPropString NOTIFY propStringChanged)
public:
    explicit QmlSimpleInterface(QObject *parent = nullptr);
    ~QmlSimpleInterface() override;
    /**
    * Getter for a propBool property
    * @return A value for propBool property provided by backend.
    */
    bool propBool() const override;
    /*
    * Setter for a propBool property, requests the backend to set the propBool property
    * @param bool propBool  Value to set for  propBool property.
    */
    void setPropBool(bool propBool) override;
    /**
    * Getter for a propInt property
    * @return A value for propInt property provided by backend.
    */
    int propInt() const override;
    /*
    * Setter for a propInt property, requests the backend to set the propInt property
    * @param int propInt  Value to set for  propInt property.
    */
    void setPropInt(int propInt) override;
    /**
    * Getter for a propInt32 property
    * @return A value for propInt32 property provided by backend.
    */
    qint32 propInt32() const override;
    /*
    * Setter for a propInt32 property, requests the backend to set the propInt32 property
    * @param qint32 propInt32  Value to set for  propInt32 property.
    */
    void setPropInt32(qint32 propInt32) override;
    /**
    * Getter for a propInt64 property
    * @return A value for propInt64 property provided by backend.
    */
    qint64 propInt64() const override;
    /*
    * Setter for a propInt64 property, requests the backend to set the propInt64 property
    * @param qint64 propInt64  Value to set for  propInt64 property.
    */
    void setPropInt64(qint64 propInt64) override;
    /**
    * Getter for a propFloat property
    * @return A value for propFloat property provided by backend.
    */
    qreal propFloat() const override;
    /*
    * Setter for a propFloat property, requests the backend to set the propFloat property
    * @param qreal propFloat  Value to set for  propFloat property.
    */
    void setPropFloat(qreal propFloat) override;
    /**
    * Getter for a propFloat32 property
    * @return A value for propFloat32 property provided by backend.
    */
    float propFloat32() const override;
    /*
    * Setter for a propFloat32 property, requests the backend to set the propFloat32 property
    * @param float propFloat32  Value to set for  propFloat32 property.
    */
    void setPropFloat32(float propFloat32) override;
    /**
    * Getter for a propFloat64 property
    * @return A value for propFloat64 property provided by backend.
    */
    double propFloat64() const override;
    /*
    * Setter for a propFloat64 property, requests the backend to set the propFloat64 property
    * @param double propFloat64  Value to set for  propFloat64 property.
    */
    void setPropFloat64(double propFloat64) override;
    /**
    * Getter for a propString property
    * @return A value for propString property provided by backend.
    */
    QString propString() const override;
    /*
    * Setter for a propString property, requests the backend to set the propString property
    * @param const QString& propString  Value to set for  propString property.
    */
    void setPropString(const QString& propString) override;

    /**
    * Exposes funcBool of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE bool funcBool(bool paramBool) override;

    /**
    * Exposes funcInt of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE int funcInt(int paramInt) override;

    /**
    * Exposes funcInt32 of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE qint32 funcInt32(qint32 paramInt32) override;

    /**
    * Exposes funcInt64 of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE qint64 funcInt64(qint64 paramInt64) override;

    /**
    * Exposes funcFloat of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE qreal funcFloat(qreal paramFloat) override;

    /**
    * Exposes funcFloat32 of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE float funcFloat32(float paramFloat32) override;

    /**
    * Exposes funcFloat64 of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE double funcFloat64(double paramFloat) override;

    /**
    * Exposes funcString of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE QString funcString(const QString& paramString) override;

Q_SIGNALS:
    /** Re-define singals for property changed notification, to make them are available for qml property */
    void propBoolChanged(bool propBool);
    void propIntChanged(int propInt);
    void propInt32Changed(qint32 propInt32);
    void propInt64Changed(qint64 propInt64);
    void propFloatChanged(qreal propFloat);
    void propFloat32Changed(float propFloat32);
    void propFloat64Changed(double propFloat64);
    void propStringChanged(const QString& propString);
private:
    /**
    * Backend of AbstractSimpleInterface type that provides properties on which methods will be invoked.
    * Produced by a ApiFactory factory. 
    */
	std::shared_ptr<AbstractSimpleInterface> m_obj;
};

} //namespace tb_simple
