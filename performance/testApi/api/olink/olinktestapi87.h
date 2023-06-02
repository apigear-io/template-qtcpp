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
#include <QtPromise>

#include "api/api/api.h"
#include "olink/iobjectsink.h"

#include <nlohmann/json.hpp>

namespace ApiGear {
namespace ObjectLink {
class IClientNode;
}}


using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace api {

/**
* Adapts the general OLink Client handler to a TestApi87 in a way it provides access 
* to remote specific for TestApi87 services (properties, signals, methods). 
* Sends and receives data over the network with ObjectLink protocol, through the communication node. 
* see https://objectlinkprotocol.net for ObjectLink details.
* see https://github.com/apigear-io/objectlink-core-cpp.git for olink client node - abstraction over the network.
* see Apigear::ObjectLink::OlinkClient for general Olink Client Handler implementation.
*     It provides a network implementation and tools to connect OLinkTestApi87 to it.
* Use on client side to request changes of the TestApi87 on the server side 
* and to subscribe for the TestApi87 changes.
*/
class OLinkTestApi87 : public AbstractTestApi87, public IObjectSink
{
    Q_OBJECT
public:
    /** ctor */
    explicit OLinkTestApi87(QObject *parent = nullptr);
    /** dtor */
    ~OLinkTestApi87() override = default;
    /**
    * Property getter
    * @return Locally stored recent value for PropInt.
    */
    int propInt() const override;
    /**
    * Request setting a property on the TestApi87 service.
    * @param The value to which set request is send for the PropInt.
    */
    void setPropInt(int propInt) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropFloat.
    */
    qreal propFloat() const override;
    /**
    * Request setting a property on the TestApi87 service.
    * @param The value to which set request is send for the PropFloat.
    */
    void setPropFloat(qreal propFloat) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropString.
    */
    QString propString() const override;
    /**
    * Request setting a property on the TestApi87 service.
    * @param The value to which set request is send for the PropString.
    */
    void setPropString(const QString& propString) override;
    /**
    * Remote call of ITestApi87::funcInt on the TestApi87 service.
    * Uses funcIntAsync
    */
    int funcInt(int paramInt) override;
    /**
    * Remote call of ITestApi87::funcInt on the TestApi87 service.
    */
    QtPromise::QPromise<int> funcIntAsync(int paramInt);
    /**
    * Remote call of ITestApi87::funcFloat on the TestApi87 service.
    * Uses funcFloatAsync
    */
    qreal funcFloat(qreal paramFloat) override;
    /**
    * Remote call of ITestApi87::funcFloat on the TestApi87 service.
    */
    QtPromise::QPromise<qreal> funcFloatAsync(qreal paramFloat);
    /**
    * Remote call of ITestApi87::funcString on the TestApi87 service.
    * Uses funcStringAsync
    */
    QString funcString(const QString& paramString) override;
    /**
    * Remote call of ITestApi87::funcString on the TestApi87 service.
    */
    QtPromise::QPromise<QString> funcStringAsync(const QString& paramString);

signals:

    /**
    * Informs if the OLinkTestApi87 is ready to send and receive messages.
    */
    void isReady();
public:

    /**
    * The name of the object for which this sink is created, object on server side has to have the same name.
    * It serves as an identifier for the client registry, it has to be unique for the pair sink object - client node.
    * Passed in the olink messages as an object identifier.
    */
    std::string olinkObjectName() override;

    /**
    * Information about signal emission on a server side to all subscribers.
    * @param signalId Unique identifier for the signal emitted from object.
    * @param args The arguments for the signal.
    */
    void olinkOnSignal(const std::string& signalId, const nlohmann::json& args) override;

    /**
    * Applies the information about the property changed on server side.
    * @param propertyId Unique identifier of a changed property in object .
    * @param value The value of the property.
    */
    void olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value) override;

    /** Informs this object sink that connection was is established.
    * @param interfaceId The name of the object for which link was established.
    * @param props Initial values obtained from the TestApi87 service
    * @param the initialized link endpoint for this sink.
    */
    void olinkOnInit(const std::string& objectId, const nlohmann::json& props, ::ApiGear::ObjectLink::IClientNode *node) override;
    /**
    * Informs this object sink that the link was disconnected and cannot be used anymore.
    */
    void olinkOnRelease() override;
private:
    /**
    * Applies received data to local state and publishes changes to subscribers.
    * @param the data received from TestApi87 service.
    */
    void applyState(const nlohmann::json& fields);
    /**  Updates local value for PropInt and informs subscriber about the change with emit property changed signal. */
    void setPropIntLocal(int propInt);
    /** A local value for propInt */
    int m_propInt;
    /**  Updates local value for PropFloat and informs subscriber about the change with emit property changed signal. */
    void setPropFloatLocal(qreal propFloat);
    /** A local value for propFloat */
    qreal m_propFloat;
    /**  Updates local value for PropString and informs subscriber about the change with emit property changed signal. */
    void setPropStringLocal(const QString& propString);
    /** A local value for propString */
    QString m_propString;
    /** An indicator if the object is linked with the service. */
    bool m_isReady;
    /** 
    * An abstraction layer over the connection with service for the OLinkTestApi87.
    * Handles incoming and outgoing messages.
    * Is given when object is linked with the service.
    */
    IClientNode *m_node;
};

} //namespace api
