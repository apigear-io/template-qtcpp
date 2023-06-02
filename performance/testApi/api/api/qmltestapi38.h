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

namespace api {

/**
* A QML wrapper of the TestApi38 implementation.
* Uses a TestApi38 backend provided by an ApiFactory.
* Use this class to easily bind to properties and signals provided by TestApi38 backend or
* invoke operations on it. Have in mind that singals provided by TestApi38 backend should be
* emitted only by TestApi38 backend, emitting it on qml will not reach the TestApi38 backend.
* See ApiFactory and factories that implement the IApiFactory for other features.
*/
class API_API_EXPORT QmlTestApi38 : public AbstractTestApi38
{
    Q_OBJECT

    /**
    * Exposes propInt property for qml.
    */
    Q_PROPERTY(int propInt READ propInt WRITE setPropInt NOTIFY propIntChanged)

    /**
    * Exposes propFloat property for qml.
    */
    Q_PROPERTY(qreal propFloat READ propFloat WRITE setPropFloat NOTIFY propFloatChanged)

    /**
    * Exposes propString property for qml.
    */
    Q_PROPERTY(QString propString READ propString WRITE setPropString NOTIFY propStringChanged)
public:
    explicit QmlTestApi38(QObject *parent = nullptr);
    ~QmlTestApi38() override;
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
    /**
    * Getter for a propFloat property
    * @return A value for propFloat property provided by backend.
    */
    qreal propFloat() const override;
    /*
    * Setter for a propFloat property, requests the backend to set the propFloat property
    * @param qreal propFloat  Value to set for  propFloat property.
    */
    void setPropFloat(qreal propFloat) override;
    /**
    * Getter for a propString property
    * @return A value for propString property provided by backend.
    */
    QString propString() const override;
    /*
    * Setter for a propString property, requests the backend to set the propString property
    * @param const QString& propString  Value to set for  propString property.
    */
    void setPropString(const QString& propString) override;

    /**
    * Exposes funcInt of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE int funcInt(int paramInt) override;

    /**
    * Exposes funcFloat of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE qreal funcFloat(qreal paramFloat) override;

    /**
    * Exposes funcString of backend implementation to a qml.
    *   
    */
    Q_INVOKABLE QString funcString(const QString& paramString) override;

Q_SIGNALS:
    /** Re-define singals for property changed notification, to make them are available for qml property */
    void propIntChanged(int propInt);
    void propFloatChanged(qreal propFloat);
    void propStringChanged(const QString& propString);
private:
    /**
    * Backend of AbstractTestApi38 type that provides properties on which methods will be invoked.
    * Produced by a ApiFactory factory. 
    */
	std::shared_ptr<AbstractTestApi38> m_obj;
};

} //namespace api
