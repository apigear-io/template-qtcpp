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
* A QML wrapper of the NoOperationsInterface implementation.
* Uses a NoOperationsInterface backend provided by an ApiFactory.
* Use this class to easily bind to properties and signals provided by NoOperationsInterface backend or
* invoke operations on it. Have in mind that singals provided by NoOperationsInterface backend should be
* emitted only by NoOperationsInterface backend, emitting it on qml will not reach the NoOperationsInterface backend.
* See ApiFactory and factories that implement the IApiFactory for other features.
*/
class TB_SIMPLE_QML_EXPORT QmlNoOperationsInterface : public AbstractNoOperationsInterface
{
    Q_OBJECT
    QML_NAMED_ELEMENT(TbSimpleNoOperationsInterface)

    /**
    * Exposes propBool property for qml.
    */
    Q_PROPERTY(bool propBool READ propBool WRITE setPropBool NOTIFY propBoolChanged)

    /**
    * Exposes propInt property for qml.
    */
    Q_PROPERTY(int propInt READ propInt WRITE setPropInt NOTIFY propIntChanged)
public:
    explicit QmlNoOperationsInterface(QObject *parent = nullptr);
    ~QmlNoOperationsInterface() override;
    /**
    * Getter for a propBool property
    * @return A value for propBool property provided by backend.
    */
    bool propBool() const override;
    /*
    * Setter for a propBool property, requests the backend to set the propBool property
    * @param bool propBool  Value to set for  propBool property.
    */
    void setPropBool(bool propBool) override;
    /**
    * Getter for a propInt property
    * @return A value for propInt property provided by backend.
    */
    int propInt() const override;
    /*
    * Setter for a propInt property, requests the backend to set the propInt property
    * @param int propInt  Value to set for  propInt property.
    */
    void setPropInt(int propInt) override;

Q_SIGNALS:
    /** Re-define singals for property changed notification, to make them are available for qml property */
    void propBoolChanged(bool propBool);
    void propIntChanged(int propInt);
private:
    /**
    * Backend of AbstractNoOperationsInterface type that provides properties on which methods will be invoked.
    * Produced by a ApiFactory factory. 
    */
	std::shared_ptr<AbstractNoOperationsInterface> m_obj;
};

} //namespace tb_simple
