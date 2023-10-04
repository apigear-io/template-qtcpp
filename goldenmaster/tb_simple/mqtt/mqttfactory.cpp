#include "mqttfactory.h"
#include "utilities/logger.h"
#include "mqttsimpleinterface.h"
#include "mqttsimplearrayinterface.h"

namespace tb_simple {

MqttFactory::MqttFactory(ApiGear::Mqtt::Client& client, QObject *parent)
    : QObject(parent),
      m_client(client)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

std::shared_ptr<AbstractSimpleInterface> MqttFactory::createSimpleInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    return std::make_shared<MqttSimpleInterface>(m_client);
}

std::shared_ptr<AbstractSimpleArrayInterface> MqttFactory::createSimpleArrayInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    return std::make_shared<MqttSimpleArrayInterface>(m_client);
}

} //namespace tb_simple
