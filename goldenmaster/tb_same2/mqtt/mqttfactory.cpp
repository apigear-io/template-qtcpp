#include "mqttfactory.h"
#include "utilities/logger.h"
#include "mqttsamestruct1interface.h"
#include "mqttsamestruct2interface.h"
#include "mqttsameenum1interface.h"
#include "mqttsameenum2interface.h"

namespace tb_same2 {

MqttFactory::MqttFactory(ApiGear::Mqtt::Client& client, QObject *parent)
    : QObject(parent),
      m_client(client)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

std::shared_ptr<AbstractSameStruct1Interface> MqttFactory::createSameStruct1Interface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    return std::make_shared<MqttSameStruct1Interface>(m_client);
}

std::shared_ptr<AbstractSameStruct2Interface> MqttFactory::createSameStruct2Interface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    return std::make_shared<MqttSameStruct2Interface>(m_client);
}

std::shared_ptr<AbstractSameEnum1Interface> MqttFactory::createSameEnum1Interface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    return std::make_shared<MqttSameEnum1Interface>(m_client);
}

std::shared_ptr<AbstractSameEnum2Interface> MqttFactory::createSameEnum2Interface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    return std::make_shared<MqttSameEnum2Interface>(m_client);
}

} //namespace tb_same2
