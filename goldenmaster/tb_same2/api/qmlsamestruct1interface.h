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

namespace tb_same2 {

/**
* A QML wrapper of the SameStruct1Interface implementation.
* Uses a SameStruct1Interface backend provided by an ApiFactory.
* Use this class to easily bind to properties and signals provided by SameStruct1Interface backend or
* invoke operations on it. Have in mind that singals provided by SameStruct1Interface backend should be
* emitted only by SameStruct1Interface backend, emitting it on qml will not reach the SameStruct1Interface backend.
* See ApiFactory and factories that implement the IApiFactory for other features.
*/
class TB_SAME2_API_EXPORT QmlSameStruct1Interface : public AbstractSameStruct1Interface
{
    Q_OBJECT

    /**
    * Exposes prop1 property for qml.
    */
    Q_PROPERTY(Struct1 prop1 READ prop1 WRITE setProp1 NOTIFY prop1Changed)
public:
    explicit QmlSameStruct1Interface(QObject *parent = nullptr);
    ~QmlSameStruct1Interface() override;
    /**
    * Getter for a prop1 property
    * @return A value for prop1 property provided by backend.
    */
    Struct1 prop1() const override;
    /*
    * Setter for a prop1 property, requests the backend to set the prop1 property
    * @param const Struct1& prop1  Value to set for  prop1 property.
    */
    void setProp1(const Struct1& prop1) override;

    /**
    * Exposes func1 of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE Struct1 func1(const Struct1& param1) override;

Q_SIGNALS:
    /** Re-define singals for property changed notification, to make them are available for qml property */
    void prop1Changed(const Struct1& prop1);
private:
    /**
    * Backend of AbstractSameStruct1Interface type that provides properties on which methods will be invoked.
    * Produced by a ApiFactory factory. 
    */
	std::shared_ptr<AbstractSameStruct1Interface> m_obj;
};

} //namespace tb_same2
