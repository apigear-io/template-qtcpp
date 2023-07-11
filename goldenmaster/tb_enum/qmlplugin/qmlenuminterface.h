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
#include "tb_enum/api/api.h"
#include <memory>

#if defined(TB_ENUM_QML_LIBRARY)
#  define TB_ENUM_QML_EXPORT Q_DECL_EXPORT
#else
#  define TB_ENUM_QML_EXPORT Q_DECL_IMPORT
#endif


namespace tb_enum {

/**
* A QML wrapper of the EnumInterface implementation.
* Uses a EnumInterface backend provided by an ApiFactory.
* Use this class to easily bind to properties and signals provided by EnumInterface backend or
* invoke operations on it. Have in mind that singals provided by EnumInterface backend should be
* emitted only by EnumInterface backend, emitting it on qml will not reach the EnumInterface backend.
* See ApiFactory and factories that implement the IApiFactory for other features.
*/
class TB_ENUM_QML_EXPORT QmlEnumInterface : public AbstractEnumInterface
{
    Q_OBJECT
    QML_NAMED_ELEMENT(TbEnumEnumInterface)

    /**
    * Exposes prop0 property for qml.
    */
    Q_PROPERTY(tb_enum::Enum0::Enum0Enum prop0 READ prop0 WRITE setProp0 NOTIFY prop0Changed)

    /**
    * Exposes prop1 property for qml.
    */
    Q_PROPERTY(tb_enum::Enum1::Enum1Enum prop1 READ prop1 WRITE setProp1 NOTIFY prop1Changed)

    /**
    * Exposes prop2 property for qml.
    */
    Q_PROPERTY(tb_enum::Enum2::Enum2Enum prop2 READ prop2 WRITE setProp2 NOTIFY prop2Changed)

    /**
    * Exposes prop3 property for qml.
    */
    Q_PROPERTY(tb_enum::Enum3::Enum3Enum prop3 READ prop3 WRITE setProp3 NOTIFY prop3Changed)
public:
    explicit QmlEnumInterface(QObject *parent = nullptr);
    ~QmlEnumInterface() override;
    /**
    * Getter for a prop0 property
    * @return A value for prop0 property provided by backend.
    */
    tb_enum::Enum0::Enum0Enum prop0() const override;
    /*
    * Setter for a prop0 property, requests the backend to set the prop0 property
    * @param Enum0::Enum0Enum prop0  Value to set for  prop0 property.
    */
    void setProp0(tb_enum::Enum0::Enum0Enum prop0) override;
    /**
    * Getter for a prop1 property
    * @return A value for prop1 property provided by backend.
    */
    tb_enum::Enum1::Enum1Enum prop1() const override;
    /*
    * Setter for a prop1 property, requests the backend to set the prop1 property
    * @param Enum1::Enum1Enum prop1  Value to set for  prop1 property.
    */
    void setProp1(tb_enum::Enum1::Enum1Enum prop1) override;
    /**
    * Getter for a prop2 property
    * @return A value for prop2 property provided by backend.
    */
    tb_enum::Enum2::Enum2Enum prop2() const override;
    /*
    * Setter for a prop2 property, requests the backend to set the prop2 property
    * @param Enum2::Enum2Enum prop2  Value to set for  prop2 property.
    */
    void setProp2(tb_enum::Enum2::Enum2Enum prop2) override;
    /**
    * Getter for a prop3 property
    * @return A value for prop3 property provided by backend.
    */
    tb_enum::Enum3::Enum3Enum prop3() const override;
    /*
    * Setter for a prop3 property, requests the backend to set the prop3 property
    * @param Enum3::Enum3Enum prop3  Value to set for  prop3 property.
    */
    void setProp3(tb_enum::Enum3::Enum3Enum prop3) override;

    /**
    * Exposes func0 of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE tb_enum::Enum0::Enum0Enum func0(tb_enum::Enum0::Enum0Enum param0) override;

    /**
    * Exposes func1 of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE tb_enum::Enum1::Enum1Enum func1(tb_enum::Enum1::Enum1Enum param1) override;

    /**
    * Exposes func2 of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE tb_enum::Enum2::Enum2Enum func2(tb_enum::Enum2::Enum2Enum param2) override;

    /**
    * Exposes func3 of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE tb_enum::Enum3::Enum3Enum func3(tb_enum::Enum3::Enum3Enum param3) override;

Q_SIGNALS:
    /** Re-define singals for property changed notification, to make them are available for qml property */
    void prop0Changed(tb_enum::Enum0::Enum0Enum prop0);
    void prop1Changed(tb_enum::Enum1::Enum1Enum prop1);
    void prop2Changed(tb_enum::Enum2::Enum2Enum prop2);
    void prop3Changed(tb_enum::Enum3::Enum3Enum prop3);
private:
    /**
    * Backend of AbstractEnumInterface type that provides properties on which methods will be invoked.
    * Produced by a ApiFactory factory. 
    */
	std::shared_ptr<AbstractEnumInterface> m_obj;
};

} //namespace tb_enum
