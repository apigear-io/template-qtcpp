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
#include <QtCore/QtGlobal>

#if defined(TB_NAMES_API_LIBRARY)
#  define TB_NAMES_API_EXPORT Q_DECL_EXPORT
#else
#  define TB_NAMES_API_EXPORT Q_DECL_IMPORT
#endif

namespace tb_names {

// ********************************************************************
/**
*
* AbstractNamEs is a pure interface QObject class.
* Declares:
*  - Methods defined for Nam_Es interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for Nam_Es interface.
*/
// ********************************************************************


class TB_NAMES_API_EXPORT AbstractNamEs : public QObject {
    Q_OBJECT
public:
    AbstractNamEs(QObject * parent=nullptr);
    /**
    * Sets the value of the Switch property.
    */
    virtual void setSwitch(bool Switch) = 0;
    /**
    * Gets the value of the Switch property.
    */
    virtual bool Switch() const = 0;
    /**
    * Sets the value of the SOME_PROPERTY property.
    */
    virtual void setSomeProperty(int SOME_PROPERTY) = 0;
    /**
    * Gets the value of the SOME_PROPERTY property.
    */
    virtual int SOME_PROPERTY() const = 0;
    /**
    * Sets the value of the Some_Poperty2 property.
    */
    virtual void setSomePoperty2(int Some_Poperty2) = 0;
    /**
    * Gets the value of the Some_Poperty2 property.
    */
    virtual int Some_Poperty2() const = 0;

    virtual void someFunction(bool SOME_PARAM) = 0;

    virtual void someFunction2(bool Some_Param) = 0;
signals:
    /**
    * @param SOME_PARAM 
    */
    void someSignal(bool SOME_PARAM);
    /**
    * @param Some_Param 
    */
    void someSignal2(bool Some_Param);
    /**
    * Emitted when Switch value has changed.
    */
    void SwitchChanged(bool Switch);
    /**
    * Emitted when SOME_PROPERTY value has changed.
    */
    void SOME_PROPERTYChanged(int SOME_PROPERTY);
    /**
    * Emitted when Some_Poperty2 value has changed.
    */
    void Some_Poperty2Changed(int Some_Poperty2);
};


} //namespace tb_names

