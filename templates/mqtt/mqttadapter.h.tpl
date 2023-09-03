{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $class := printf "Mqtt%sAdapter" .Interface.Name }}
{{- $interface := .Interface.Name  }}
{{- $MODULE_ID := printf "%s_MQTT" (SNAKE .Module.Name) }}

#pragma once

#include <QtCore>
#include <nlohmann/json.hpp>

#include "{{snake .Module.Name}}/api/api.h"
#include "apigear/mqtt/mqttservice.h"
#include "mqtt_common.h"


namespace {{snake  .Module.Name }} {


/**
* Server side for {{.Interface.Name}} implements the {{.Interface.Name}} service.
* It is a source of data for {{.Interface.Name}} clients.
* Sends and receives data over the network with mqtt protocol.
*
* WARNING you should have only one {{.Interface.Name}} service in your network.
*/
class {{$MODULE_ID}}_LIBRARY_EXPORT {{$class}} : public QObject
{
    Q_OBJECT
public:
    /**
    * ctor
    * @param {{$interface}} The service source object, the actual {{$interface}} object which is exposed for remote clients with mqtt.
    * @param mqttServiceAdapter The mqtt client that exposes {{$interface}} to as a service in mqtt network.
    */
    explicit {{$class}}(ApiGear::Mqtt::ServiceAdapter& mqttServiceAdapter, std::shared_ptr<Abstract{{Camel .Interface.Name}}> impl, QObject *parent = nullptr);
    /*dtor*/
    virtual ~{{$class}}();
public:
    /**
    * The name of the object for which this service is created, object on client side has to have the same name.
    * It serves as an identifier for the source registry, it has to be unique for the pair source object - remote node.
    * Passed in the messages topics as an object identifier.
    */
    const QString& objectName();

private:
    {{- if (len .Interface.Properties) }}
    // Helper function, subscribes this adpater for property change requests from remote clients.
    void subscribeForPropertiesChanges();
    {{- end }}
    {{- if (len .Interface.Operations) }}
    // Helper function, subscribes this adpater for methods invoke requests from remote clients.
    void subscribeForInvokeRequests();
    {{- end }}
    {{- if (len .Interface.Properties) }}
    // Helper function, subscribes this adpater for property changes from the {{$interface}} implementation.
    void connectServicePropertiesChanges();
    {{- end }}
    {{- if (len .Interface.Signals) }}
    // Helper function, subscribes this adpater for signals emitted by the {{$interface}} implementation.
    void connectServiceSignals();
    {{- end }}
    /**
    * The actual implementation of a {{$interface}} that gets adapted to be a service in mqtt network.
    */
    std::shared_ptr<Abstract{{Camel .Interface.Name}}> m_impl;
    /**
    * The mqtt client which aligns this obejct to serve a service.
    */
    ApiGear::Mqtt::ServiceAdapter& m_mqttServiceAdapter;

    /** Ids of subscribed topics */
    std::vector<quint64> m_subscribedIds;
};

} // namespace {{snake  .Module.Name }}
