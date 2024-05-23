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

#include "tb_simple/api/api.h"
#include "olink/iobjectsink.h"

#include <nlohmann/json.hpp>

namespace ApiGear {
namespace ObjectLink {
class IClientNode;
}}


using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace tb_simple {

/**
* Adapts the general OLink Client handler to a SimpleArrayInterface in a way it provides access 
* to remote specific for SimpleArrayInterface services (properties, signals, methods). 
* Sends and receives data over the network with ObjectLink protocol, through the communication node. 
* see https://objectlinkprotocol.net for ObjectLink details.
* see https://github.com/apigear-io/objectlink-core-cpp.git for olink client node - abstraction over the network.
* see Apigear::ObjectLink::OlinkClient for general Olink Client Handler implementation.
*     It provides a network implementation and tools to connect OLinkSimpleArrayInterface to it.
* Use on client side to request changes of the SimpleArrayInterface on the server side 
* and to subscribe for the SimpleArrayInterface changes.
*/
class OLinkSimpleArrayInterface : public AbstractSimpleArrayInterface, public IObjectSink
{
    Q_OBJECT
public:
    /** ctor */
    explicit OLinkSimpleArrayInterface(QObject *parent = nullptr);
    /** dtor */
    ~OLinkSimpleArrayInterface() override = default;
    /**
    * Property getter
    * @return Locally stored recent value for PropBool.
    */
    QList<bool> propBool() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the PropBool.
    */
    void setPropBool(const QList<bool>& propBool) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropInt.
    */
    QList<int> propInt() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the PropInt.
    */
    void setPropInt(const QList<int>& propInt) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropInt32.
    */
    QList<qint32> propInt32() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the PropInt32.
    */
    void setPropInt32(const QList<qint32>& propInt32) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropInt64.
    */
    QList<qint64> propInt64() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the PropInt64.
    */
    void setPropInt64(const QList<qint64>& propInt64) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropFloat.
    */
    QList<qreal> propFloat() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the PropFloat.
    */
    void setPropFloat(const QList<qreal>& propFloat) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropFloat32.
    */
    QList<float> propFloat32() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the PropFloat32.
    */
    void setPropFloat32(const QList<float>& propFloat32) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropFloat64.
    */
    QList<double> propFloat64() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the PropFloat64.
    */
    void setPropFloat64(const QList<double>& propFloat64) override;
    /**
    * Property getter
    * @return Locally stored recent value for PropString.
    */
    QList<QString> propString() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the PropString.
    */
    void setPropString(const QList<QString>& propString) override;
    /**
    * Remote call of ISimpleArrayInterface::funcBool on the SimpleArrayInterface service.
    * Uses funcBoolAsync
    */
    QList<bool> funcBool(const QList<bool>& paramBool) override;
    /**
    * Remote call of ISimpleArrayInterface::funcBool on the SimpleArrayInterface service.
    */
    QFuture<QList<bool>> funcBoolAsync(const QList<bool>& paramBool);
    /**
    * Remote call of ISimpleArrayInterface::funcInt on the SimpleArrayInterface service.
    * Uses funcIntAsync
    */
    QList<int> funcInt(const QList<int>& paramInt) override;
    /**
    * Remote call of ISimpleArrayInterface::funcInt on the SimpleArrayInterface service.
    */
    QFuture<QList<int>> funcIntAsync(const QList<int>& paramInt);
    /**
    * Remote call of ISimpleArrayInterface::funcInt32 on the SimpleArrayInterface service.
    * Uses funcInt32Async
    */
    QList<qint32> funcInt32(const QList<qint32>& paramInt32) override;
    /**
    * Remote call of ISimpleArrayInterface::funcInt32 on the SimpleArrayInterface service.
    */
    QFuture<QList<qint32>> funcInt32Async(const QList<qint32>& paramInt32);
    /**
    * Remote call of ISimpleArrayInterface::funcInt64 on the SimpleArrayInterface service.
    * Uses funcInt64Async
    */
    QList<qint64> funcInt64(const QList<qint64>& paramInt64) override;
    /**
    * Remote call of ISimpleArrayInterface::funcInt64 on the SimpleArrayInterface service.
    */
    QFuture<QList<qint64>> funcInt64Async(const QList<qint64>& paramInt64);
    /**
    * Remote call of ISimpleArrayInterface::funcFloat on the SimpleArrayInterface service.
    * Uses funcFloatAsync
    */
    QList<qreal> funcFloat(const QList<qreal>& paramFloat) override;
    /**
    * Remote call of ISimpleArrayInterface::funcFloat on the SimpleArrayInterface service.
    */
    QFuture<QList<qreal>> funcFloatAsync(const QList<qreal>& paramFloat);
    /**
    * Remote call of ISimpleArrayInterface::funcFloat32 on the SimpleArrayInterface service.
    * Uses funcFloat32Async
    */
    QList<float> funcFloat32(const QList<float>& paramFloat32) override;
    /**
    * Remote call of ISimpleArrayInterface::funcFloat32 on the SimpleArrayInterface service.
    */
    QFuture<QList<float>> funcFloat32Async(const QList<float>& paramFloat32);
    /**
    * Remote call of ISimpleArrayInterface::funcFloat64 on the SimpleArrayInterface service.
    * Uses funcFloat64Async
    */
    QList<double> funcFloat64(const QList<double>& paramFloat) override;
    /**
    * Remote call of ISimpleArrayInterface::funcFloat64 on the SimpleArrayInterface service.
    */
    QFuture<QList<double>> funcFloat64Async(const QList<double>& paramFloat);
    /**
    * Remote call of ISimpleArrayInterface::funcString on the SimpleArrayInterface service.
    * Uses funcStringAsync
    */
    QList<QString> funcString(const QList<QString>& paramString) override;
    /**
    * Remote call of ISimpleArrayInterface::funcString on the SimpleArrayInterface service.
    */
    QFuture<QList<QString>> funcStringAsync(const QList<QString>& paramString);

signals:

    /**
    * Informs if the OLinkSimpleArrayInterface is ready to send and receive messages.
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
    * @param props Initial values obtained from the SimpleArrayInterface service
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
    * @param the data received from SimpleArrayInterface service.
    */
    void applyState(const nlohmann::json& fields);

    /**
    * Applies received property value to local state and publishes changes to subscribers.
    * @param propertyName the name of property to be changed.
    * @param value The value for property.
    */
    void applyProperty(const std::string& propertyName, const nlohmann::json& value);
    /**  Updates local value for PropBool and informs subscriber about the change with emit property changed signal. */
    void setPropBoolLocal(const QList<bool>& propBool);
    /** A local value for propBool */
    QList<bool> m_propBool;
    /**  Updates local value for PropInt and informs subscriber about the change with emit property changed signal. */
    void setPropIntLocal(const QList<int>& propInt);
    /** A local value for propInt */
    QList<int> m_propInt;
    /**  Updates local value for PropInt32 and informs subscriber about the change with emit property changed signal. */
    void setPropInt32Local(const QList<qint32>& propInt32);
    /** A local value for propInt32 */
    QList<qint32> m_propInt32;
    /**  Updates local value for PropInt64 and informs subscriber about the change with emit property changed signal. */
    void setPropInt64Local(const QList<qint64>& propInt64);
    /** A local value for propInt64 */
    QList<qint64> m_propInt64;
    /**  Updates local value for PropFloat and informs subscriber about the change with emit property changed signal. */
    void setPropFloatLocal(const QList<qreal>& propFloat);
    /** A local value for propFloat */
    QList<qreal> m_propFloat;
    /**  Updates local value for PropFloat32 and informs subscriber about the change with emit property changed signal. */
    void setPropFloat32Local(const QList<float>& propFloat32);
    /** A local value for propFloat32 */
    QList<float> m_propFloat32;
    /**  Updates local value for PropFloat64 and informs subscriber about the change with emit property changed signal. */
    void setPropFloat64Local(const QList<double>& propFloat64);
    /** A local value for propFloat64 */
    QList<double> m_propFloat64;
    /**  Updates local value for PropString and informs subscriber about the change with emit property changed signal. */
    void setPropStringLocal(const QList<QString>& propString);
    /** A local value for propString */
    QList<QString> m_propString;
    /** An indicator if the object is linked with the service. */
    bool m_isReady;
    /** 
    * An abstraction layer over the connection with service for the OLinkSimpleArrayInterface.
    * Handles incoming and outgoing messages.
    * Is given when object is linked with the service.
    */
    IClientNode *m_node;
};

} //namespace tb_simple
