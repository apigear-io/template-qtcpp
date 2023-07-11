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
#include <QQmlEngine>
#include "testbed2/api/api.h"
#include <memory>

#if defined(TESTBED2_QML_LIBRARY)
#  define TESTBED2_QML_EXPORT Q_DECL_EXPORT
#else
#  define TESTBED2_QML_EXPORT Q_DECL_IMPORT
#endif


namespace testbed2 {

/**
* A QML wrapper of the NestedStruct1Interface implementation.
* Uses a NestedStruct1Interface backend provided by an ApiFactory.
* Use this class to easily bind to properties and signals provided by NestedStruct1Interface backend or
* invoke operations on it. Have in mind that singals provided by NestedStruct1Interface backend should be
* emitted only by NestedStruct1Interface backend, emitting it on qml will not reach the NestedStruct1Interface backend.
* See ApiFactory and factories that implement the IApiFactory for other features.
*/
class TESTBED2_QML_EXPORT QmlNestedStruct1Interface : public AbstractNestedStruct1Interface
{
    Q_OBJECT
    QML_NAMED_ELEMENT(Testbed2NestedStruct1Interface)

    /**
    * Exposes prop1 property for qml.
    */
    Q_PROPERTY(testbed2::NestedStruct1 prop1 READ prop1 WRITE setProp1 NOTIFY prop1Changed)
public:
    explicit QmlNestedStruct1Interface(QObject *parent = nullptr);
    ~QmlNestedStruct1Interface() override;
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
    * Exposes func1 of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE testbed2::NestedStruct1 func1(const testbed2::NestedStruct1& param1) override;

Q_SIGNALS:
    /** Re-define singals for property changed notification, to make them are available for qml property */
    void prop1Changed(const testbed2::NestedStruct1& prop1);
private:
    /**
    * Backend of AbstractNestedStruct1Interface type that provides properties on which methods will be invoked.
    * Produced by a ApiFactory factory. 
    */
	std::shared_ptr<AbstractNestedStruct1Interface> m_obj;
};

} //namespace testbed2
