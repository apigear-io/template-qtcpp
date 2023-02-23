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

#if defined(TB_SIMPLE_API_LIBRARY)
#  define TB_SIMPLE_API_EXPORT Q_DECL_EXPORT
#else
#  define TB_SIMPLE_API_EXPORT Q_DECL_IMPORT
#endif

namespace tb_simple {
    class AbstractSimpleInterface;
    class AbstractSimpleArrayInterface;

/**
* An interface for a Factory of interfaces in tb.simple
* May be used to provide different implementations of your interfaces.
* Check the usage of IApiFactory in Qml versions of interface implementation.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/
class TB_SIMPLE_API_EXPORT IApiFactory
{
public:
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
};

} //namespace tb_simple
