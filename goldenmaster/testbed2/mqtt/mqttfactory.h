#pragma once

#include <QtCore>

#include "testbed2/api/iapifactory.h"
#include <apigear/mqtt/mqttclient.h>
#include "mqtt_common.h"

namespace testbed2 {

/** 
* A Factory that creates a MqttClient version of interfaces in testbed2
* The created interfaces implementation connects to a broker to which a matching mqtt service objects should be connected.
* You can check the usage of IApiFactory in Qml versions of interface implementation.
* By default this factory is not used as IApiFactory.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/

class TESTBED2_MQTT_LIBRARY_EXPORT MqttFactory : public QObject, public IApiFactory
{
public:
    MqttFactory(ApiGear::Mqtt::Client& client, QObject *parent = nullptr);
    /** @return Mqtt Client version of ManyParamInterface */
    std::shared_ptr<AbstractManyParamInterface> createManyParamInterface(QObject *parent = nullptr) override;
    /** @return Mqtt Client version of NestedStruct1Interface */
    std::shared_ptr<AbstractNestedStruct1Interface> createNestedStruct1Interface(QObject *parent = nullptr) override;
    /** @return Mqtt Client version of NestedStruct2Interface */
    std::shared_ptr<AbstractNestedStruct2Interface> createNestedStruct2Interface(QObject *parent = nullptr) override;
    /** @return Mqtt Client version of NestedStruct3Interface */
    std::shared_ptr<AbstractNestedStruct3Interface> createNestedStruct3Interface(QObject *parent = nullptr) override;
private:
    ApiGear::Mqtt::Client& m_client;
};

} //namespace testbed2
