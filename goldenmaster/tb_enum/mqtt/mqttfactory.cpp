#include "mqttfactory.h"
#include "utilities/logger.h"
#include "mqttenuminterface.h"

namespace tb_enum {

MqttFactory::MqttFactory(ApiGear::Mqtt::Client& client, QObject *parent)
    : QObject(parent),
      m_client(client)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

std::shared_ptr<AbstractEnumInterface> MqttFactory::createEnumInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    return std::make_shared<MqttEnumInterface>(m_client);
}

} //namespace tb_enum
