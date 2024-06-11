#include "mqttfactory.h"
#include "utilities/logger.h"

namespace extern_types {

MqttFactory::MqttFactory(ApiGear::Mqtt::Client& client, QObject *parent)
    : QObject(parent),
      m_client(client)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

} //namespace extern_types
