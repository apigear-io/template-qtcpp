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

#include "api.h"
#include <memory>

namespace testbed1 {

/**
* A QML wrapper of the StructInterface implementation.
* Uses a StructInterface backend provided by an ApiFactory.
* Use this class to easily bind to properties and signals provided by StructInterface backend or
* invoke operations on it. Have in mind that singals provided by StructInterface backend should be
* emitted only by StructInterface backend, emitting it on qml will not reach the StructInterface backend.
* See ApiFactory and factories that implement the IApiFactory for other features.
*/
class TESTBED1_API_EXPORT QmlStructInterface : public AbstractStructInterface
{
    Q_OBJECT

    /**
    * Exposes propBool property for qml.
    */
    Q_PROPERTY(StructBool propBool READ propBool WRITE setPropBool NOTIFY propBoolChanged)

    /**
    * Exposes propInt property for qml.
    */
    Q_PROPERTY(StructInt propInt READ propInt WRITE setPropInt NOTIFY propIntChanged)

    /**
    * Exposes propFloat property for qml.
    */
    Q_PROPERTY(StructFloat propFloat READ propFloat WRITE setPropFloat NOTIFY propFloatChanged)

    /**
    * Exposes propString property for qml.
    */
    Q_PROPERTY(StructString propString READ propString WRITE setPropString NOTIFY propStringChanged)
public:
    explicit QmlStructInterface(QObject *parent = nullptr);
    ~QmlStructInterface() override;
    /**
    * Getter for a propBool property
    * @return A value for propBool property provided by backend.
    */
    StructBool propBool() const override;
    /*
    * Setter for a propBool property, requests the backend to set the propBool property
    * @param const StructBool& propBool  Value to set for  propBool property.
    */
    void setPropBool(const StructBool& propBool) override;
    /**
    * Getter for a propInt property
    * @return A value for propInt property provided by backend.
    */
    StructInt propInt() const override;
    /*
    * Setter for a propInt property, requests the backend to set the propInt property
    * @param const StructInt& propInt  Value to set for  propInt property.
    */
    void setPropInt(const StructInt& propInt) override;
    /**
    * Getter for a propFloat property
    * @return A value for propFloat property provided by backend.
    */
    StructFloat propFloat() const override;
    /*
    * Setter for a propFloat property, requests the backend to set the propFloat property
    * @param const StructFloat& propFloat  Value to set for  propFloat property.
    */
    void setPropFloat(const StructFloat& propFloat) override;
    /**
    * Getter for a propString property
    * @return A value for propString property provided by backend.
    */
    StructString propString() const override;
    /*
    * Setter for a propString property, requests the backend to set the propString property
    * @param const StructString& propString  Value to set for  propString property.
    */
    void setPropString(const StructString& propString) override;

    /**
    * Exposes funcBool of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE StructBool funcBool(const StructBool& paramBool) override;

    /**
    * Exposes funcInt of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE StructBool funcInt(const StructInt& paramInt) override;

    /**
    * Exposes funcFloat of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE StructFloat funcFloat(const StructFloat& paramFloat) override;

    /**
    * Exposes funcString of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE StructString funcString(const StructString& paramString) override;

Q_SIGNALS:
    /** Re-define singals for property changed notification, to make them are available for qml property */
    void propBoolChanged(const StructBool& propBool);
    void propIntChanged(const StructInt& propInt);
    void propFloatChanged(const StructFloat& propFloat);
    void propStringChanged(const StructString& propString);
private:
    /**
    * Backend of AbstractStructInterface type that provides properties on which methods will be invoked.
    * Produced by a ApiFactory factory. 
    */
	std::shared_ptr<AbstractStructInterface> m_obj;
};

} //namespace testbed1
