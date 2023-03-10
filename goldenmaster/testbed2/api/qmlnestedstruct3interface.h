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

namespace testbed2 {

/**
* A QML wrapper of the NestedStruct3Interface implementation.
* Uses a NestedStruct3Interface backend provided by an ApiFactory.
* Use this class to easily bind to properties and signals provided by NestedStruct3Interface backend or
* invoke operations on it. Have in mind that singals provided by NestedStruct3Interface backend should be
* emitted only by NestedStruct3Interface backend, emitting it on qml will not reach the NestedStruct3Interface backend.
* See ApiFactory and factories that implement the IApiFactory for other features.
*/
class TESTBED2_API_EXPORT QmlNestedStruct3Interface : public AbstractNestedStruct3Interface
{
    Q_OBJECT

    /**
    * Exposes prop1 property for qml.
    */
    Q_PROPERTY(testbed2::NestedStruct1 prop1 READ prop1 WRITE setProp1 NOTIFY prop1Changed)

    /**
    * Exposes prop2 property for qml.
    */
    Q_PROPERTY(testbed2::NestedStruct2 prop2 READ prop2 WRITE setProp2 NOTIFY prop2Changed)

    /**
    * Exposes prop3 property for qml.
    */
    Q_PROPERTY(testbed2::NestedStruct3 prop3 READ prop3 WRITE setProp3 NOTIFY prop3Changed)
public:
    explicit QmlNestedStruct3Interface(QObject *parent = nullptr);
    ~QmlNestedStruct3Interface() override;
    /**
    * Getter for a prop1 property
    * @return A value for prop1 property provided by backend.
    */
    testbed2::NestedStruct1 prop1() const override;
    /*
    * Setter for a prop1 property, requests the backend to set the prop1 property
    * @param const NestedStruct1& prop1  Value to set for  prop1 property.
    */
    void setProp1(const testbed2::NestedStruct1& prop1) override;
    /**
    * Getter for a prop2 property
    * @return A value for prop2 property provided by backend.
    */
    testbed2::NestedStruct2 prop2() const override;
    /*
    * Setter for a prop2 property, requests the backend to set the prop2 property
    * @param const NestedStruct2& prop2  Value to set for  prop2 property.
    */
    void setProp2(const testbed2::NestedStruct2& prop2) override;
    /**
    * Getter for a prop3 property
    * @return A value for prop3 property provided by backend.
    */
    testbed2::NestedStruct3 prop3() const override;
    /*
    * Setter for a prop3 property, requests the backend to set the prop3 property
    * @param const NestedStruct3& prop3  Value to set for  prop3 property.
    */
    void setProp3(const testbed2::NestedStruct3& prop3) override;

    /**
    * Exposes func1 of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE testbed2::NestedStruct1 func1(const testbed2::NestedStruct1& param1) override;

    /**
    * Exposes func2 of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE testbed2::NestedStruct1 func2(const testbed2::NestedStruct1& param1, const testbed2::NestedStruct2& param2) override;

    /**
    * Exposes func3 of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE testbed2::NestedStruct1 func3(const testbed2::NestedStruct1& param1, const testbed2::NestedStruct2& param2, const testbed2::NestedStruct3& param3) override;

Q_SIGNALS:
    /** Re-define singals for property changed notification, to make them are available for qml property */
    void prop1Changed(const testbed2::NestedStruct1& prop1);
    void prop2Changed(const testbed2::NestedStruct2& prop2);
    void prop3Changed(const testbed2::NestedStruct3& prop3);
private:
    /**
    * Backend of AbstractNestedStruct3Interface type that provides properties on which methods will be invoked.
    * Produced by a ApiFactory factory. 
    */
	std::shared_ptr<AbstractNestedStruct3Interface> m_obj;
};

} //namespace testbed2
