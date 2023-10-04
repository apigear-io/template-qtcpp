#include "mqttfactory.h"
#include "utilities/logger.h"

{{- range .Module.Interfaces }}
#include "mqtt{{.Name|lower}}.h"
{{- end }}

namespace {{snake  .Module.Name }} {

MqttFactory::MqttFactory(ApiGear::Mqtt::Client& client, QObject *parent)
    : QObject(parent),
      m_client(client)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

{{- range .Module.Interfaces }}

std::shared_ptr<Abstract{{Camel .Name}}> MqttFactory::create{{Camel .Name}}(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    return std::make_shared<Mqtt{{.Name}}>(m_client);
}

{{- end }}

} //namespace {{snake  .Module.Name }}
