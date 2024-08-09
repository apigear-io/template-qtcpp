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
#include <QFuture>

#include "counter/api/api.h"
#include "olink/iobjectsink.h"

#include <nlohmann/json.hpp>

namespace ApiGear {
namespace ObjectLink {
class IClientNode;
}}


using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace counter {

/**
* Adapts the general OLink Client handler to a Counter in a way it provides access 
* to remote specific for Counter services (properties, signals, methods). 
* Sends and receives data over the network with ObjectLink protocol, through the communication node. 
* see https://objectlinkprotocol.net for ObjectLink details.
* see https://github.com/apigear-io/objectlink-core-cpp.git for olink client node - abstraction over the network.
* see Apigear::ObjectLink::OlinkClient for general Olink Client Handler implementation.
*     It provides a network implementation and tools to connect OLinkCounter to it.
* Use on client side to request changes of the Counter on the server side 
* and to subscribe for the Counter changes.
*/
class OLinkCounter : public AbstractCounter, public IObjectSink
{
    Q_OBJECT
public:
    /** ctor */
    explicit OLinkCounter(QObject *parent = nullptr);
    /** dtor */
    ~OLinkCounter() override = default;
    /**
    * Property getter
    * @return Locally stored recent value for Vector.
    */
    custom_types::Vector3D vector() const override;
    /**
    * Request setting a property on the Counter service.
    * @param The value to which set request is send for the Vector.
    */
    void setVector(const custom_types::Vector3D& vector) override;
    /**
    * Property getter
    * @return Locally stored recent value for ExternVector.
    */
    QVector3D extern_vector() const override;
    /**
    * Request setting a property on the Counter service.
    * @param The value to which set request is send for the ExternVector.
    */
    void setExternVector(const QVector3D& extern_vector) override;
    /**
    * Remote call of ICounter::increment on the Counter service.
    * Uses incrementAsync
    */
    QVector3D increment(const QVector3D& vec) override;
    /**
    * Remote call of ICounter::increment on the Counter service.
    */
    QFuture<QVector3D> incrementAsync(const QVector3D& vec);
    /**
    * Remote call of ICounter::decrement on the Counter service.
    * Uses decrementAsync
    */
    custom_types::Vector3D decrement(const custom_types::Vector3D& vec) override;
    /**
    * Remote call of ICounter::decrement on the Counter service.
    */
    QFuture<custom_types::Vector3D> decrementAsync(const custom_types::Vector3D& vec);

signals:

    /**
    * Informs if the OLinkCounter is ready to send and receive messages.
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
    * @param props Initial values obtained from the Counter service
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
    * @param the data received from Counter service.
    */
    void applyState(const nlohmann::json& fields);

    /**
    * Applies received property value to local state and publishes changes to subscribers.
    * @param propertyName the name of property to be changed.
    * @param value The value for property.
    */
    void applyProperty(const std::string& propertyName, const nlohmann::json& value);
    /**  Updates local value for Vector and informs subscriber about the change with emit property changed signal. */
    void setVectorLocal(const custom_types::Vector3D& vector);
    /** A local value for vector */
    custom_types::Vector3D m_vector;
    /**  Updates local value for ExternVector and informs subscriber about the change with emit property changed signal. */
    void setExternVectorLocal(const QVector3D& extern_vector);
    /** A local value for extern_vector */
    QVector3D m_extern_vector;
    /** An indicator if the object is linked with the service. */
    bool m_isReady;
    /** 
    * An abstraction layer over the connection with service for the OLinkCounter.
    * Handles incoming and outgoing messages.
    * Is given when object is linked with the service.
    */
    IClientNode *m_node;
};

} //namespace counter
