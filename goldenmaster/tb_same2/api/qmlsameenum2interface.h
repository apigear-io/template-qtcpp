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
* A QML wrapper of the SameEnum2Interface implementation.
* Uses a SameEnum2Interface backend provided by an ApiFactory.
* Use this class to easily bind to properties and signals provided by SameEnum2Interface backend or
* invoke operations on it. Have in mind that singals provided by SameEnum2Interface backend should be
* emitted only by SameEnum2Interface backend, emitting it on qml will not reach the SameEnum2Interface backend.
* See ApiFactory and factories that implement the IApiFactory for other features.
*/
class TB_SAME2_API_EXPORT QmlSameEnum2Interface : public AbstractSameEnum2Interface
{
    Q_OBJECT

    /**
    * Exposes prop1 property for qml.
    */
    Q_PROPERTY(Enum1::Enum1Enum prop1 READ prop1 WRITE setProp1 NOTIFY prop1Changed)

    /**
    * Exposes prop2 property for qml.
    */
    Q_PROPERTY(Enum2::Enum2Enum prop2 READ prop2 WRITE setProp2 NOTIFY prop2Changed)
public:
    explicit QmlSameEnum2Interface(QObject *parent = nullptr);
    ~QmlSameEnum2Interface() override;
    /**
    * Getter for a prop1 property
    * @return A value for prop1 property provided by backend.
    */
    Enum1::Enum1Enum prop1() const override;
    /*
    * Setter for a prop1 property, requests the backend to set the prop1 property
    * @param Enum1::Enum1Enum prop1  Value to set for  prop1 property.
    */
    void setProp1(Enum1::Enum1Enum prop1) override;
    /**
    * Getter for a prop2 property
    * @return A value for prop2 property provided by backend.
    */
    Enum2::Enum2Enum prop2() const override;
    /*
    * Setter for a prop2 property, requests the backend to set the prop2 property
    * @param Enum2::Enum2Enum prop2  Value to set for  prop2 property.
    */
    void setProp2(Enum2::Enum2Enum prop2) override;

    /**
    * Exposes func1 of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE Enum1::Enum1Enum func1(Enum1::Enum1Enum param1) override;

    /**
    * Exposes func2 of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE Enum1::Enum1Enum func2(Enum1::Enum1Enum param1, Enum2::Enum2Enum param2) override;

Q_SIGNALS:
    /** Re-define singals for property changed notification, to make them are available for qml property */
    void prop1Changed(Enum1::Enum1Enum prop1);
    void prop2Changed(Enum2::Enum2Enum prop2);
private:
    /**
    * Backend of AbstractSameEnum2Interface type that provides properties on which methods will be invoked.
    * Produced by a ApiFactory factory. 
    */
	std::shared_ptr<AbstractSameEnum2Interface> m_obj;
};

} //namespace tb_same2
