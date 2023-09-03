#pragma once

#include <QtCore>

#include "tb_same1/api/iapifactory.h"
#include <apigear/mqtt/mqttclient.h>
#include "mqtt_common.h"

namespace tb_same1 {

/** 
* A Factory that creates a MqttClient version of interfaces in tb.same1
* The created interfaces implementation connects to a broker to which a matching mqtt service objects should be connected.
* You can check the usage of IApiFactory in Qml versions of interface implementation.
* By default this factory is not used as IApiFactory.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/

class TB_SAME1_MQTT_LIBRARY_EXPORT MqttFactory : public QObject, public IApiFactory
{
public:
    MqttFactory(ApiGear::Mqtt::Client& client, QObject *parent = nullptr);
    /** @return Mqtt Client version of SameStruct1Interface */
    std::shared_ptr<AbstractSameStruct1Interface> createSameStruct1Interface(QObject *parent = nullptr) override;
    /** @return Mqtt Client version of SameStruct2Interface */
    std::shared_ptr<AbstractSameStruct2Interface> createSameStruct2Interface(QObject *parent = nullptr) override;
    /** @return Mqtt Client version of SameEnum1Interface */
    std::shared_ptr<AbstractSameEnum1Interface> createSameEnum1Interface(QObject *parent = nullptr) override;
    /** @return Mqtt Client version of SameEnum2Interface */
    std::shared_ptr<AbstractSameEnum2Interface> createSameEnum2Interface(QObject *parent = nullptr) override;
private:
    ApiGear::Mqtt::Client& m_client;
};

} //namespace tb_same1
