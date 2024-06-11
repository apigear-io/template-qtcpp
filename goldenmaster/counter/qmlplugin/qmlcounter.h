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
#include "counter/api/api.h"
#include <memory>

#if defined(COUNTER_QML_LIBRARY)
#  define COUNTER_QML_EXPORT Q_DECL_EXPORT
#else
#  define COUNTER_QML_EXPORT Q_DECL_IMPORT
#endif


namespace counter {

/**
* A QML wrapper of the Counter implementation.
* Uses a Counter backend provided by an ApiFactory.
* Use this class to easily bind to properties and signals provided by Counter backend or
* invoke operations on it. Have in mind that singals provided by Counter backend should be
* emitted only by Counter backend, emitting it on qml will not reach the Counter backend.
* See ApiFactory and factories that implement the IApiFactory for other features.
*/
class COUNTER_QML_EXPORT QmlCounter : public AbstractCounter
{
    Q_OBJECT
    QML_NAMED_ELEMENT(CounterCounter)

    /**
    * Exposes vector property for qml.
    */
    Q_PROPERTY(custom_types::Vector3D vector READ vector WRITE setVector NOTIFY vectorChanged)

    /**
    * Exposes extern_vector property for qml.
    */
    Q_PROPERTY(QVector3D extern_vector READ extern_vector WRITE setExternVector NOTIFY extern_vectorChanged)
public:
    explicit QmlCounter(QObject *parent = nullptr);
    ~QmlCounter() override;
    /**
    * Getter for a vector property
    * @return A value for vector property provided by backend.
    */
    custom_types::Vector3D vector() const override;
    /*
    * Setter for a vector property, requests the backend to set the vector property
    * @param const custom_types::Vector3D& vector  Value to set for  vector property.
    */
    void setVector(const custom_types::Vector3D& vector) override;
    /**
    * Getter for a extern_vector property
    * @return A value for extern_vector property provided by backend.
    */
    QVector3D extern_vector() const override;
    /*
    * Setter for a extern_vector property, requests the backend to set the extern_vector property
    * @param const QVector3D& extern_vector  Value to set for  extern_vector property.
    */
    void setExternVector(const QVector3D& extern_vector) override;

    /**
    * Exposes increment of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE QVector3D increment(const QVector3D& vec) override;

    /**
    * Exposes decrement of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE custom_types::Vector3D decrement(const custom_types::Vector3D& vec) override;

Q_SIGNALS:
    /** Re-define singals for property changed notification, to make them are available for qml property */
    void vectorChanged(const custom_types::Vector3D& vector);
    void extern_vectorChanged(const QVector3D& extern_vector);
private:
    /**
    * Backend of AbstractCounter type that provides properties on which methods will be invoked.
    * Produced by a ApiFactory factory. 
    */
	std::shared_ptr<AbstractCounter> m_obj;
};

} //namespace counter
