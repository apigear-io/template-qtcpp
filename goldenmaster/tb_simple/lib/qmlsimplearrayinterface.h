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

#include "simplearrayinterface.h"
#include <memory>

namespace tb_simple {

/**
* A QML wrapper of the SimpleArrayInterface implementation.
* Uses a SimpleArrayInterface backend provided by an ApiFactory.
* Use this class to easily bind to properties and signals provided by SimpleArrayInterface backend or
* invoke operations on it. Have in mind that singals provided by SimpleArrayInterface backend should be
* emitted only by SimpleArrayInterface backend, emitting it on qml will not reach the SimpleArrayInterface backend.
* See ApiFactory and factories that implement the ApiFactoryInterface for other features.
*/
class TB_SIMPLE_LIB_EXPORT QmlSimpleArrayInterface : public AbstractSimpleArrayInterface
{
    Q_OBJECT

    /**
    * Exposes propBool property for qml.
    */
    Q_PROPERTY(QList<bool> propBool READ propBool WRITE setPropBool NOTIFY propBoolChanged)

    /**
    * Exposes propInt property for qml.
    */
    Q_PROPERTY(QList<int> propInt READ propInt WRITE setPropInt NOTIFY propIntChanged)

    /**
    * Exposes propFloat property for qml.
    */
    Q_PROPERTY(QList<qreal> propFloat READ propFloat WRITE setPropFloat NOTIFY propFloatChanged)

    /**
    * Exposes propString property for qml.
    */
    Q_PROPERTY(QList<QString> propString READ propString WRITE setPropString NOTIFY propStringChanged)
public:
    explicit QmlSimpleArrayInterface(QObject *parent = nullptr);
    ~QmlSimpleArrayInterface() override;
    /**
    * Getter for a propBool property
    * @return A value for propBool property provided by backend.
    */
    QList<bool> propBool() const override;
    /*
    * Setter for a propBool property, requests the backend to set the propBool property
    * @param const QList<bool>& propBool  Value to set for  propBool property.
    */
    void setPropBool(const QList<bool>& propBool) override;
    /**
    * Getter for a propInt property
    * @return A value for propInt property provided by backend.
    */
    QList<int> propInt() const override;
    /*
    * Setter for a propInt property, requests the backend to set the propInt property
    * @param const QList<int>& propInt  Value to set for  propInt property.
    */
    void setPropInt(const QList<int>& propInt) override;
    /**
    * Getter for a propFloat property
    * @return A value for propFloat property provided by backend.
    */
    QList<qreal> propFloat() const override;
    /*
    * Setter for a propFloat property, requests the backend to set the propFloat property
    * @param const QList<qreal>& propFloat  Value to set for  propFloat property.
    */
    void setPropFloat(const QList<qreal>& propFloat) override;
    /**
    * Getter for a propString property
    * @return A value for propString property provided by backend.
    */
    QList<QString> propString() const override;
    /*
    * Setter for a propString property, requests the backend to set the propString property
    * @param const QList<QString>& propString  Value to set for  propString property.
    */
    void setPropString(const QList<QString>& propString) override;

    /**
    * Exposes funcBool of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE QList<bool> funcBool(const QList<bool>& paramBool) override;

    /**
    * Exposes funcInt of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE QList<int> funcInt(const QList<int>& paramInt) override;

    /**
    * Exposes funcFloat of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE QList<qreal> funcFloat(const QList<qreal>& paramFloat) override;

    /**
    * Exposes funcString of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE QList<QString> funcString(const QList<QString>& paramString) override;

Q_SIGNALS:
    /** Re-define singals for property changed notification, to make them are available for qml property */
    void propBoolChanged(const QList<bool>& propBool);
    void propIntChanged(const QList<int>& propInt);
    void propFloatChanged(const QList<qreal>& propFloat);
    void propStringChanged(const QList<QString>& propString);
private:
    /**
    * Backend of AbstractSimpleArrayInterface type that provides properties on which methods will be invoked.
    * Produced by a ApiFactory factory. 
    */
	std::shared_ptr<AbstractSimpleArrayInterface> m_obj;
};

} //namespace tb_simple
