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

#include <memory>


namespace testbed2 {
    class AbstractManyParamInterface;
    class AbstractNestedStruct1Interface;
    class AbstractNestedStruct2Interface;
    class AbstractNestedStruct3Interface;

/**
* An interface for a Factory of interfaces in testbed2
* May be used to provide different implementations of your interfaces.
* Check the usage of IApiFactory in Qml versions of interface implementation.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/
class IApiFactory
{
public:
    virtual ~IApiFactory() = default;
    /** 
    * Create an instance of ManyParamInterface
    * @return The implementation of a AbstractManyParamInterface.
    */
    virtual std::shared_ptr<AbstractManyParamInterface> createManyParamInterface(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of NestedStruct1Interface
    * @return The implementation of a AbstractNestedStruct1Interface.
    */
    virtual std::shared_ptr<AbstractNestedStruct1Interface> createNestedStruct1Interface(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of NestedStruct2Interface
    * @return The implementation of a AbstractNestedStruct2Interface.
    */
    virtual std::shared_ptr<AbstractNestedStruct2Interface> createNestedStruct2Interface(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of NestedStruct3Interface
    * @return The implementation of a AbstractNestedStruct3Interface.
    */
    virtual std::shared_ptr<AbstractNestedStruct3Interface> createNestedStruct3Interface(QObject *parent = nullptr) = 0;
};

} //namespace testbed2
