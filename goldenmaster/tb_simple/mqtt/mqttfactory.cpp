#include "mqttfactory.h"
#include "utilities/logger.h"
#include "mqttvoidinterface.h"
#include "mqttsimpleinterface.h"
#include "mqttsimplearrayinterface.h"
#include "mqttnopropertiesinterface.h"
#include "mqttnooperationsinterface.h"
#include "mqttnosignalsinterface.h"

namespace tb_simple {

MqttFactory::MqttFactory(ApiGear::Mqtt::Client& client, QObject *parent)
    : QObject(parent),
      m_client(client)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

std::shared_ptr<AbstractVoidInterface> MqttFactory::createVoidInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    return std::make_shared<MqttVoidInterface>(m_client);
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

std::shared_ptr<AbstractNoPropertiesInterface> MqttFactory::createNoPropertiesInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    return std::make_shared<MqttNoPropertiesInterface>(m_client);
}

std::shared_ptr<AbstractNoOperationsInterface> MqttFactory::createNoOperationsInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    return std::make_shared<MqttNoOperationsInterface>(m_client);
}

std::shared_ptr<AbstractNoSignalsInterface> MqttFactory::createNoSignalsInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    return std::make_shared<MqttNoSignalsInterface>(m_client);
}

} //namespace tb_simple
