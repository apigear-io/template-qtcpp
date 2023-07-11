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
* A QML wrapper of the ManyParamInterface implementation.
* Uses a ManyParamInterface backend provided by an ApiFactory.
* Use this class to easily bind to properties and signals provided by ManyParamInterface backend or
* invoke operations on it. Have in mind that singals provided by ManyParamInterface backend should be
* emitted only by ManyParamInterface backend, emitting it on qml will not reach the ManyParamInterface backend.
* See ApiFactory and factories that implement the IApiFactory for other features.
*/
class TESTBED2_QML_EXPORT QmlManyParamInterface : public AbstractManyParamInterface
{
    Q_OBJECT
    QML_NAMED_ELEMENT(Testbed2ManyParamInterface)

    /**
    * Exposes prop1 property for qml.
    */
    Q_PROPERTY(int prop1 READ prop1 WRITE setProp1 NOTIFY prop1Changed)

    /**
    * Exposes prop2 property for qml.
    */
    Q_PROPERTY(int prop2 READ prop2 WRITE setProp2 NOTIFY prop2Changed)

    /**
    * Exposes prop3 property for qml.
    */
    Q_PROPERTY(int prop3 READ prop3 WRITE setProp3 NOTIFY prop3Changed)

    /**
    * Exposes prop4 property for qml.
    */
    Q_PROPERTY(int prop4 READ prop4 WRITE setProp4 NOTIFY prop4Changed)
public:
    explicit QmlManyParamInterface(QObject *parent = nullptr);
    ~QmlManyParamInterface() override;
    /**
    * Getter for a prop1 property
    * @return A value for prop1 property provided by backend.
    */
    int prop1() const override;
    /*
    * Setter for a prop1 property, requests the backend to set the prop1 property
    * @param int prop1  Value to set for  prop1 property.
    */
    void setProp1(int prop1) override;
    /**
    * Getter for a prop2 property
    * @return A value for prop2 property provided by backend.
    */
    int prop2() const override;
    /*
    * Setter for a prop2 property, requests the backend to set the prop2 property
    * @param int prop2  Value to set for  prop2 property.
    */
    void setProp2(int prop2) override;
    /**
    * Getter for a prop3 property
    * @return A value for prop3 property provided by backend.
    */
    int prop3() const override;
    /*
    * Setter for a prop3 property, requests the backend to set the prop3 property
    * @param int prop3  Value to set for  prop3 property.
    */
    void setProp3(int prop3) override;
    /**
    * Getter for a prop4 property
    * @return A value for prop4 property provided by backend.
    */
    int prop4() const override;
    /*
    * Setter for a prop4 property, requests the backend to set the prop4 property
    * @param int prop4  Value to set for  prop4 property.
    */
    void setProp4(int prop4) override;

    /**
    * Exposes func1 of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE int func1(int param1) override;

    /**
    * Exposes func2 of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE int func2(int param1, int param2) override;

    /**
    * Exposes func3 of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE int func3(int param1, int param2, int param3) override;

    /**
    * Exposes func4 of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE int func4(int param1, int param2, int param3, int param4) override;

Q_SIGNALS:
    /** Re-define singals for property changed notification, to make them are available for qml property */
    void prop1Changed(int prop1);
    void prop2Changed(int prop2);
    void prop3Changed(int prop3);
    void prop4Changed(int prop4);
private:
    /**
    * Backend of AbstractManyParamInterface type that provides properties on which methods will be invoked.
    * Produced by a ApiFactory factory. 
    */
	std::shared_ptr<AbstractManyParamInterface> m_obj;
};

} //namespace testbed2
