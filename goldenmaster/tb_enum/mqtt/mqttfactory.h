#pragma once

#include <QtCore>

#include "tb_enum/api/iapifactory.h"
#include <apigear/mqtt/mqttclient.h>
#include "mqtt_common.h"

namespace tb_enum {

/** 
* A Factory that creates a MqttClient version of interfaces in tb.enum
* The created interfaces implementation connects to a broker to which a matching mqtt service objects should be connected.
* You can check the usage of IApiFactory in Qml versions of interface implementation.
* By default this factory is not used as IApiFactory.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/

class TB_ENUM_MQTT_LIBRARY_EXPORT MqttFactory : public QObject, public IApiFactory
{
public:
    MqttFactory(ApiGear::Mqtt::Client& client, QObject *parent = nullptr);
    /** @return Mqtt Client version of EnumInterface */
    std::shared_ptr<AbstractEnumInterface> createEnumInterface(QObject *parent = nullptr) override;
private:
    ApiGear::Mqtt::Client& m_client;
};

} //namespace tb_enum
