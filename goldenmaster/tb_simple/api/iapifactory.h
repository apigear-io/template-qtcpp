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


namespace tb_simple {
    class AbstractVoidInterface;
    class AbstractSimpleInterface;
    class AbstractSimpleArrayInterface;
    class AbstractNoPropertiesInterface;
    class AbstractNoOperationsInterface;
    class AbstractNoSignalsInterface;

/**
* An interface for a Factory of interfaces in tb.simple
* May be used to provide different implementations of your interfaces.
* Check the usage of IApiFactory in Qml versions of interface implementation.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/
class IApiFactory
{
public:
    virtual ~IApiFactory() = default;
    /** 
    * Create an instance of VoidInterface
    * @return The implementation of a AbstractVoidInterface.
    */
    virtual std::shared_ptr<AbstractVoidInterface> createVoidInterface(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of SimpleInterface
    * @return The implementation of a AbstractSimpleInterface.
    */
    virtual std::shared_ptr<AbstractSimpleInterface> createSimpleInterface(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of SimpleArrayInterface
    * @return The implementation of a AbstractSimpleArrayInterface.
    */
    virtual std::shared_ptr<AbstractSimpleArrayInterface> createSimpleArrayInterface(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of NoPropertiesInterface
    * @return The implementation of a AbstractNoPropertiesInterface.
    */
    virtual std::shared_ptr<AbstractNoPropertiesInterface> createNoPropertiesInterface(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of NoOperationsInterface
    * @return The implementation of a AbstractNoOperationsInterface.
    */
    virtual std::shared_ptr<AbstractNoOperationsInterface> createNoOperationsInterface(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of NoSignalsInterface
    * @return The implementation of a AbstractNoSignalsInterface.
    */
    virtual std::shared_ptr<AbstractNoSignalsInterface> createNoSignalsInterface(QObject *parent = nullptr) = 0;
};

} //namespace tb_simple
