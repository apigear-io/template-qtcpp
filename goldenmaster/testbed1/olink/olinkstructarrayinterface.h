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

#include "testbed1/api/api.h"
#include "olink/iobjectsink.h"

#include <nlohmann/json.hpp>

namespace ApiGear {
namespace ObjectLink {
class IClientNode;
}}


using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace testbed1 {

/**
* Adapts the general OLink Client handler to a StructArrayInterface in a way it provides access 
* to remote specific for StructArrayInterface services (properties, signals, methods). 
* Sends and receives data over the network with ObjectLink protocol, through the communication node. 
* see https://objectlinkprotocol.net for ObjectLink details.
* see https://github.com/apigear-io/objectlink-core-cpp.git for olink client node - abstraction over the network.
* see Apigear::ObjectLink::OlinkClient for general Olink Client Handler implementation.
*     It provides a network implementation and tools to connect OLinkStructArrayInterface to it.
* Use on client side to request changes of the StructArrayInterface on the server side 
* and to subscribe for the StructArrayInterface changes.
*/
class OLinkStructArrayInterface : public AbstractStructArrayInterface, public IObjectSink
{
    Q_OBJECT
public:
    /** ctor */
    explicit OLinkStructArrayInterface(QObject *parent = nullptr);
    /** dtor */
    ~OLinkStructArrayInterface() override = default;
    /**
    * Property getter
    * @return Locally stored recent value for PropBool.
    */
    QList<StructBool> propBool() const override;
    /**
    * Request setting a property on the StructArrayInterface service.
    * @param The value to which set request is send for the PropBool.
    */
    void setPropBool(const QList<StructBool>& propBool) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropInt.
    */
    QList<StructInt> propInt() const override;
    /**
    * Request setting a property on the StructArrayInterface service.
    * @param The value to which set request is send for the PropInt.
    */
    void setPropInt(const QList<StructInt>& propInt) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropFloat.
    */
    QList<StructFloat> propFloat() const override;
    /**
    * Request setting a property on the StructArrayInterface service.
    * @param The value to which set request is send for the PropFloat.
    */
    void setPropFloat(const QList<StructFloat>& propFloat) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropString.
    */
    QList<StructString> propString() const override;
    /**
    * Request setting a property on the StructArrayInterface service.
    * @param The value to which set request is send for the PropString.
    */
    void setPropString(const QList<StructString>& propString) override;
    /**
    * Remote call of IStructArrayInterface::funcBool on the StructArrayInterface service.
    * Uses funcBoolAsync
    */
    StructBool funcBool(const QList<StructBool>& paramBool) override;
    /**
    * Remote call of IStructArrayInterface::funcBool on the StructArrayInterface service.
    */
    QtPromise::QPromise<StructBool> funcBoolAsync(const QList<StructBool>& paramBool);
    /**
    * Remote call of IStructArrayInterface::funcInt on the StructArrayInterface service.
    * Uses funcIntAsync
    */
    StructBool funcInt(const QList<StructInt>& paramInt) override;
    /**
    * Remote call of IStructArrayInterface::funcInt on the StructArrayInterface service.
    */
    QtPromise::QPromise<StructBool> funcIntAsync(const QList<StructInt>& paramInt);
    /**
    * Remote call of IStructArrayInterface::funcFloat on the StructArrayInterface service.
    * Uses funcFloatAsync
    */
    StructBool funcFloat(const QList<StructFloat>& paramFloat) override;
    /**
    * Remote call of IStructArrayInterface::funcFloat on the StructArrayInterface service.
    */
    QtPromise::QPromise<StructBool> funcFloatAsync(const QList<StructFloat>& paramFloat);
    /**
    * Remote call of IStructArrayInterface::funcString on the StructArrayInterface service.
    * Uses funcStringAsync
    */
    StructBool funcString(const QList<StructString>& paramString) override;
    /**
    * Remote call of IStructArrayInterface::funcString on the StructArrayInterface service.
    */
    QtPromise::QPromise<StructBool> funcStringAsync(const QList<StructString>& paramString);

signals:

    /**
    * Informs if the OLinkStructArrayInterface is ready to send and receive messages.
    * @return true if StructArrayInterface is operable, false otherwise.
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
    * @param props Initial values obtained from the StructArrayInterface service
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
    * @param the data received from StructArrayInterface service.
    */
    void applyState(const nlohmann::json& fields);
    /**  Updates local value for PropBool and informs subscriber about the change with emit property changed signal. */
    void setPropBoolLocal(const QList<StructBool>& propBool);
    /** A local value for propBool */
    QList<StructBool> m_propBool;
    /**  Updates local value for PropInt and informs subscriber about the change with emit property changed signal. */
    void setPropIntLocal(const QList<StructInt>& propInt);
    /** A local value for propInt */
    QList<StructInt> m_propInt;
    /**  Updates local value for PropFloat and informs subscriber about the change with emit property changed signal. */
    void setPropFloatLocal(const QList<StructFloat>& propFloat);
    /** A local value for propFloat */
    QList<StructFloat> m_propFloat;
    /**  Updates local value for PropString and informs subscriber about the change with emit property changed signal. */
    void setPropStringLocal(const QList<StructString>& propString);
    /** A local value for propString */
    QList<StructString> m_propString;
    /** An indicator if the object is linked with the service. */
    bool m_isReady;
    /** 
    * An abstraction layer over the connection with service for the OLinkStructArrayInterface.
    * Handles incoming and outgoing messages.
    * Is given when object is linked with the service.
    */
    IClientNode *m_node;
};

} //namespace testbed1
