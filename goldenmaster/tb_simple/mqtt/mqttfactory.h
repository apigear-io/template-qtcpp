#pragma once

#include <QtCore>

#include "tb_simple/api/iapifactory.h"
#include <apigear/mqtt/mqttclient.h>
#include "mqtt_common.h"

namespace tb_simple {

/** 
* A Factory that creates a MqttClient version of interfaces in tb.simple
* The created interfaces implementation connects to a broker to which a matching mqtt service objects should be connected.
* You can check the usage of IApiFactory in Qml versions of interface implementation.
* By default this factory is not used as IApiFactory.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/

class TB_SIMPLE_MQTT_LIBRARY_EXPORT MqttFactory : public QObject, public IApiFactory
{
public:
    MqttFactory(ApiGear::Mqtt::Client& client, QObject *parent = nullptr);
    /** @return Mqtt Client version of VoidInterface */
    std::shared_ptr<AbstractVoidInterface> createVoidInterface(QObject *parent = nullptr) override;
    /** @return Mqtt Client version of SimpleInterface */
    std::shared_ptr<AbstractSimpleInterface> createSimpleInterface(QObject *parent = nullptr) override;
    /** @return Mqtt Client version of SimpleArrayInterface */
    std::shared_ptr<AbstractSimpleArrayInterface> createSimpleArrayInterface(QObject *parent = nullptr) override;
    /** @return Mqtt Client version of NoPropertiesInterface */
    std::shared_ptr<AbstractNoPropertiesInterface> createNoPropertiesInterface(QObject *parent = nullptr) override;
    /** @return Mqtt Client version of NoOperationsInterface */
    std::shared_ptr<AbstractNoOperationsInterface> createNoOperationsInterface(QObject *parent = nullptr) override;
    /** @return Mqtt Client version of NoSignalsInterface */
    std::shared_ptr<AbstractNoSignalsInterface> createNoSignalsInterface(QObject *parent = nullptr) override;
private:
    ApiGear::Mqtt::Client& m_client;
};

} //namespace tb_simple
