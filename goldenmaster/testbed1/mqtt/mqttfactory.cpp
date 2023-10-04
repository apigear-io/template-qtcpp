#include "mqttfactory.h"
#include "utilities/logger.h"
#include "mqttstructinterface.h"
#include "mqttstructarrayinterface.h"

namespace testbed1 {

MqttFactory::MqttFactory(ApiGear::Mqtt::Client& client, QObject *parent)
    : QObject(parent),
      m_client(client)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

std::shared_ptr<AbstractStructInterface> MqttFactory::createStructInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    return std::make_shared<MqttStructInterface>(m_client);
}

std::shared_ptr<AbstractStructArrayInterface> MqttFactory::createStructArrayInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    return std::make_shared<MqttStructArrayInterface>(m_client);
}

} //namespace testbed1
