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

#include "testbed2/api/api.h"
#include "olink/iobjectsink.h"

#include <nlohmann/json.hpp>

namespace ApiGear {
namespace ObjectLink {
class IClientNode;
}}


using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace testbed2 {

/**
* Adapts the general OLink Client handler to a ManyParamInterface in a way it provides access 
* to remote specific for ManyParamInterface services (properties, signals, methods). 
* Sends and receives data over the network with ObjectLink protocol, through the communication node. 
* see https://objectlinkprotocol.net for ObjectLink details.
* see https://github.com/apigear-io/objectlink-core-cpp.git for olink client node - abstraction over the network.
* see Apigear::ObjectLink::OlinkClient for general Olink Client Handler implementation.
*     It provides a network implementation and tools to connect OLinkManyParamInterface to it.
* Use on client side to request changes of the ManyParamInterface on the server side 
* and to subscribe for the ManyParamInterface changes.
*/
class OLinkManyParamInterface : public AbstractManyParamInterface, public IObjectSink
{
    Q_OBJECT
public:
    /** ctor */
    explicit OLinkManyParamInterface(QObject *parent = nullptr);
    /** dtor */
    ~OLinkManyParamInterface() override = default;
    /**
    * Property getter
    * @return Locally stored recent value for Prop1.
    */
    int prop1() const override;
    /**
    * Request setting a property on the ManyParamInterface service.
    * @param The value to which set request is send for the Prop1.
    */
    void setProp1(int prop1) override;
    /**
    * Property getter
    * @return Locally stored recent value for Prop2.
    */
    int prop2() const override;
    /**
    * Request setting a property on the ManyParamInterface service.
    * @param The value to which set request is send for the Prop2.
    */
    void setProp2(int prop2) override;
    /**
    * Property getter
    * @return Locally stored recent value for Prop3.
    */
    int prop3() const override;
    /**
    * Request setting a property on the ManyParamInterface service.
    * @param The value to which set request is send for the Prop3.
    */
    void setProp3(int prop3) override;
    /**
    * Property getter
    * @return Locally stored recent value for Prop4.
    */
    int prop4() const override;
    /**
    * Request setting a property on the ManyParamInterface service.
    * @param The value to which set request is send for the Prop4.
    */
    void setProp4(int prop4) override;
    /**
    * Remote call of IManyParamInterface::func1 on the ManyParamInterface service.
    * Uses func1Async
    */
    int func1(int param1) override;
    /**
    * Remote call of IManyParamInterface::func1 on the ManyParamInterface service.
    */
    QtPromise::QPromise<int> func1Async(int param1);
    /**
    * Remote call of IManyParamInterface::func2 on the ManyParamInterface service.
    * Uses func2Async
    */
    int func2(int param1, int param2) override;
    /**
    * Remote call of IManyParamInterface::func2 on the ManyParamInterface service.
    */
    QtPromise::QPromise<int> func2Async(int param1, int param2);
    /**
    * Remote call of IManyParamInterface::func3 on the ManyParamInterface service.
    * Uses func3Async
    */
    int func3(int param1, int param2, int param3) override;
    /**
    * Remote call of IManyParamInterface::func3 on the ManyParamInterface service.
    */
    QtPromise::QPromise<int> func3Async(int param1, int param2, int param3);
    /**
    * Remote call of IManyParamInterface::func4 on the ManyParamInterface service.
    * Uses func4Async
    */
    int func4(int param1, int param2, int param3, int param4) override;
    /**
    * Remote call of IManyParamInterface::func4 on the ManyParamInterface service.
    */
    QtPromise::QPromise<int> func4Async(int param1, int param2, int param3, int param4);

signals:

    /**
    * Informs if the OLinkManyParamInterface is ready to send and receive messages.
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
    * @param props Initial values obtained from the ManyParamInterface service
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
    * @param the data received from ManyParamInterface service.
    */
    void applyState(const nlohmann::json& fields);

    /**
    * Applies received property value to local state and publishes changes to subscribers.
    * @param propertyName the name of property to be changed.
    * @param value The value for property.
    */
    void applyProperty(const std::string& propertyName, const nlohmann::json& value);
    /**  Updates local value for Prop1 and informs subscriber about the change with emit property changed signal. */
    void setProp1Local(int prop1);
    /** A local value for prop1 */
    int m_prop1;
    /**  Updates local value for Prop2 and informs subscriber about the change with emit property changed signal. */
    void setProp2Local(int prop2);
    /** A local value for prop2 */
    int m_prop2;
    /**  Updates local value for Prop3 and informs subscriber about the change with emit property changed signal. */
    void setProp3Local(int prop3);
    /** A local value for prop3 */
    int m_prop3;
    /**  Updates local value for Prop4 and informs subscriber about the change with emit property changed signal. */
    void setProp4Local(int prop4);
    /** A local value for prop4 */
    int m_prop4;
    /** An indicator if the object is linked with the service. */
    bool m_isReady;
    /** 
    * An abstraction layer over the connection with service for the OLinkManyParamInterface.
    * Handles incoming and outgoing messages.
    * Is given when object is linked with the service.
    */
    IClientNode *m_node;
};

} //namespace testbed2
