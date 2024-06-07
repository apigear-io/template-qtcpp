{{- $MODULE_ID := printf "%s_MQTT" (SNAKE .Module.Name) -}}
#pragma once

#include <QtCore>

#include "{{snake .Module.Name}}/api/iapifactory.h"
#include <apigear/mqtt/mqttclient.h>
#include "mqtt_common.h"

namespace {{qtNamespace .Module.Name }} {

/** 
* A Factory that creates a MqttClient version of interfaces in {{$.Module}}
* The created interfaces implementation connects to a broker to which a matching mqtt service objects should be connected.
* You can check the usage of IApiFactory in Qml versions of interface implementation.
* By default this factory is not used as IApiFactory.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/

class {{$MODULE_ID}}_LIBRARY_EXPORT MqttFactory : public QObject, public IApiFactory
{
public:
    MqttFactory(ApiGear::Mqtt::Client& client, QObject *parent = nullptr);
{{- range .Module.Interfaces }}
    /** @return Mqtt Client version of {{.Name}} */
    std::shared_ptr<Abstract{{Camel .Name}}> create{{Camel .Name}}(QObject *parent = nullptr) override;
{{- end }}
private:
    ApiGear::Mqtt::Client& m_client;
};

} //namespace {{qtNamespace .Module.Name }}
