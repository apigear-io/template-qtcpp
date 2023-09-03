#include "mqttfactory.h"
#include "utilities/logger.h"
#include "mqttmanyparaminterface.h"
#include "mqttnestedstruct1interface.h"
#include "mqttnestedstruct2interface.h"
#include "mqttnestedstruct3interface.h"

namespace testbed2 {

MqttFactory::MqttFactory(ApiGear::Mqtt::Client& client, QObject *parent)
    : QObject(parent),
      m_client(client)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

std::shared_ptr<AbstractManyParamInterface> MqttFactory::createManyParamInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    return std::make_shared<MqttManyParamInterface>(m_client);
}

std::shared_ptr<AbstractNestedStruct1Interface> MqttFactory::createNestedStruct1Interface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    return std::make_shared<MqttNestedStruct1Interface>(m_client);
}

std::shared_ptr<AbstractNestedStruct2Interface> MqttFactory::createNestedStruct2Interface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    return std::make_shared<MqttNestedStruct2Interface>(m_client);
}

std::shared_ptr<AbstractNestedStruct3Interface> MqttFactory::createNestedStruct3Interface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    return std::make_shared<MqttNestedStruct3Interface>(m_client);
}

} //namespace testbed2