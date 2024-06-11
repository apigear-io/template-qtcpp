#include "mqttfactory.h"
#include "utilities/logger.h"
#include "mqttcounter.h"

namespace counter {

MqttFactory::MqttFactory(ApiGear::Mqtt::Client& client, QObject *parent)
    : QObject(parent),
      m_client(client)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

std::shared_ptr<AbstractCounter> MqttFactory::createCounter(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    return std::make_shared<MqttCounter>(m_client);
}

} //namespace counter
