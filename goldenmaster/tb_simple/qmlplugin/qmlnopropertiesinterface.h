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
#include "tb_simple/api/api.h"
#include <memory>

#if defined(TB_SIMPLE_QML_LIBRARY)
#  define TB_SIMPLE_QML_EXPORT Q_DECL_EXPORT
#else
#  define TB_SIMPLE_QML_EXPORT Q_DECL_IMPORT
#endif


namespace tb_simple {

/**
* A QML wrapper of the NoPropertiesInterface implementation.
* Uses a NoPropertiesInterface backend provided by an ApiFactory.
* Use this class to easily bind to properties and signals provided by NoPropertiesInterface backend or
* invoke operations on it. Have in mind that singals provided by NoPropertiesInterface backend should be
* emitted only by NoPropertiesInterface backend, emitting it on qml will not reach the NoPropertiesInterface backend.
* See ApiFactory and factories that implement the IApiFactory for other features.
*/
class TB_SIMPLE_QML_EXPORT QmlNoPropertiesInterface : public AbstractNoPropertiesInterface
{
    Q_OBJECT
    QML_NAMED_ELEMENT(TbSimpleNoPropertiesInterface)
public:
    explicit QmlNoPropertiesInterface(QObject *parent = nullptr);
    ~QmlNoPropertiesInterface() override;

    /**
    * Exposes funcVoid of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE void funcVoid() override;

    /**
    * Exposes funcBool of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE bool funcBool(bool paramBool) override;

Q_SIGNALS:
    /** Re-define singals for property changed notification, to make them are available for qml property */
private:
    /**
    * Backend of AbstractNoPropertiesInterface type that provides properties on which methods will be invoked.
    * Produced by a ApiFactory factory. 
    */
	std::shared_ptr<AbstractNoPropertiesInterface> m_obj;
};

} //namespace tb_simple
