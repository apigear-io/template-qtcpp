#pragma once

#include <QtCore>

#include "testbed1/api/iapifactory.h"
#include <apigear/mqtt/mqttclient.h>
#include "mqtt_common.h"

namespace testbed1 {

/** 
* A Factory that creates a MqttClient version of interfaces in testbed1
* The created interfaces implementation connects to a broker to which a matching mqtt service objects should be connected.
* You can check the usage of IApiFactory in Qml versions of interface implementation.
* By default this factory is not used as IApiFactory.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/

class TESTBED1_MQTT_LIBRARY_EXPORT MqttFactory : public QObject, public IApiFactory
{
public:
    MqttFactory(ApiGear::Mqtt::Client& client, QObject *parent = nullptr);
    /** @return Mqtt Client version of StructInterface */
    std::shared_ptr<AbstractStructInterface> createStructInterface(QObject *parent = nullptr) override;
    /** @return Mqtt Client version of StructArrayInterface */
    std::shared_ptr<AbstractStructArrayInterface> createStructArrayInterface(QObject *parent = nullptr) override;
private:
    ApiGear::Mqtt::Client& m_client;
};

} //namespace testbed1
