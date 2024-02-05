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

namespace tb_names {

/**
* A QML wrapper of the NamEs implementation.
* Uses a NamEs backend provided by an ApiFactory.
* Use this class to easily bind to properties and signals provided by NamEs backend or
* invoke operations on it. Have in mind that singals provided by NamEs backend should be
* emitted only by NamEs backend, emitting it on qml will not reach the NamEs backend.
* See ApiFactory and factories that implement the IApiFactory for other features.
*/
class TB_NAMES_API_EXPORT QmlNamEs : public AbstractNamEs
{
    Q_OBJECT

    /**
    * Exposes Switch property for qml.
    */
    Q_PROPERTY(bool Switch READ Switch WRITE setSwitch NOTIFY SwitchChanged)

    /**
    * Exposes SOME_PROPERTY property for qml.
    */
    Q_PROPERTY(int SOME_PROPERTY READ SOME_PROPERTY WRITE setSomeProperty NOTIFY SOME_PROPERTYChanged)

    /**
    * Exposes Some_Poperty2 property for qml.
    */
    Q_PROPERTY(int Some_Poperty2 READ Some_Poperty2 WRITE setSomePoperty2 NOTIFY Some_Poperty2Changed)
public:
    explicit QmlNamEs(QObject *parent = nullptr);
    ~QmlNamEs() override;
    /**
    * Getter for a Switch property
    * @return A value for Switch property provided by backend.
    */
    bool Switch() const override;
    /*
    * Setter for a Switch property, requests the backend to set the Switch property
    * @param bool Switch  Value to set for  Switch property.
    */
    void setSwitch(bool Switch) override;
    /**
    * Getter for a SOME_PROPERTY property
    * @return A value for SOME_PROPERTY property provided by backend.
    */
    int SOME_PROPERTY() const override;
    /*
    * Setter for a SOME_PROPERTY property, requests the backend to set the SOME_PROPERTY property
    * @param int SOME_PROPERTY  Value to set for  SOME_PROPERTY property.
    */
    void setSomeProperty(int SOME_PROPERTY) override;
    /**
    * Getter for a Some_Poperty2 property
    * @return A value for Some_Poperty2 property provided by backend.
    */
    int Some_Poperty2() const override;
    /*
    * Setter for a Some_Poperty2 property, requests the backend to set the Some_Poperty2 property
    * @param int Some_Poperty2  Value to set for  Some_Poperty2 property.
    */
    void setSomePoperty2(int Some_Poperty2) override;

    /**
    * Exposes someFunction of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE void someFunction(bool SOME_PARAM) override;

    /**
    * Exposes someFunction2 of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE void someFunction2(bool Some_Param) override;

Q_SIGNALS:
    /** Re-define singals for property changed notification, to make them are available for qml property */
    void SwitchChanged(bool Switch);
    void SOME_PROPERTYChanged(int SOME_PROPERTY);
    void Some_Poperty2Changed(int Some_Poperty2);
private:
    /**
    * Backend of AbstractNamEs type that provides properties on which methods will be invoked.
    * Produced by a ApiFactory factory. 
    */
	std::shared_ptr<AbstractNamEs> m_obj;
};

} //namespace tb_names
