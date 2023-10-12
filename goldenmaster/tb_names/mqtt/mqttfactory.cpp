#include "mqttfactory.h"
#include "utilities/logger.h"
#include "mqttnam_es.h"

namespace tb_names {

MqttFactory::MqttFactory(ApiGear::Mqtt::Client& client, QObject *parent)
    : QObject(parent),
      m_client(client)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

std::shared_ptr<AbstractNamEs> MqttFactory::createNamEs(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    return std::make_shared<MqttNam_Es>(m_client);
}

} //namespace tb_names
