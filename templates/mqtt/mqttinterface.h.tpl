{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $module_id := (snake .Module.Name)}}
{{- $class := printf "Mqtt%s" .Interface.Name }}
{{- $module := .Module.Name }}
{{- $interfaceName := Camel .Interface.Name  }}
{{- $interfaceNameOriginal := .Interface.Name  }}
{{- $interfaceClass := printf "I%s" $interfaceName }}
{{- $MODULE_ID := printf "%s_MQTT" (SNAKE .Module.Name) }}

{{- $hasNonVoidOperations := 0 -}}
{{- range .Interface.Operations }}
    {{- if not (.Return.IsVoid) }}
        {{- $hasNonVoidOperations = 1}}
    {{- end -}}
{{- end -}}

#pragma once

#include <QtCore>
#include <QtPromise>

#include "{{snake .Module.Name}}/api/api.h"
#include "mqtt_common.h"

#include <apigear/mqtt/mqttclient.h>
#include <nlohmann/json.hpp>
#include <map>

namespace {{snake  .Module.Name }} {

/**
* Adapts the general Mqtt Client handler to a {{$interfaceNameOriginal}} in a way it provides access
* to remote specific for {{$interfaceNameOriginal}} services (properties, signals, methods). 
* Serves as a sink of data provided by the remote service.
* Sends and receives data over the network with Mqtt protocol.
* see Apigear::Mqtt::Client for general Mqtt Client Handler implementation.
*     It provides a network implementation and tools to connect and exchange information with
*     a Mqtt Service adapter (which is source of data for this client) connected to same broker.
* Use on client side to request changes of the {{$interfaceNameOriginal}} on the server side 
* and to subscribe for the {{$interfaceNameOriginal}} changes.
*/
class {{$MODULE_ID}}_LIBRARY_EXPORT {{$class}} : public Abstract{{Camel .Interface.Name}}
{
    Q_OBJECT
public:
    /** ctor */
    explicit {{$class}}(ApiGear::Mqtt::Client& client, QObject *parent = nullptr);
    /** dtor */
    ~{{$class}}() override;

{{- range .Interface.Properties }}
{{- $property := . }}
    /**
    * Property getter
    * @return Locally stored recent value for {{Camel $property.Name}}.
    */
    {{qtReturn "" .}} {{.Name}}() const override;
    /**
    * Request setting a property on the {{$interfaceNameOriginal}} service.
    * @param The value to which set request is send for the {{Camel $property.Name}}.
    */
    void set{{Camel .Name}}({{qtParam "" .}}) override;
{{- end }}

{{- range .Interface.Operations }}
{{- $operation := . }}
    /**
    * Remote call of {{$interfaceClass}}::{{$operation.Name}} on the {{$interfaceNameOriginal}} service.
    * Uses {{$operation.Name}}Async
    */
    {{qtReturn "" .Return}} {{camel .Name}}({{qtParams "" .Params}}) override;
    /**
    * Remote call of {{$interfaceClass}}::{{$operation.Name}} on the {{$interfaceNameOriginal}} service.
    */
    QtPromise::QPromise<{{qtReturn "" .Return}}> {{camel .Name}}Async({{qtParams "" .Params}});
{{- end }}

signals:
    /**
    * Informs if the {{$class}} is ready to send and receive messages.
    */
    void isReady();

public:
    /**
    * The name of the interface for which this mqtt client adapter is created.
    * It is used in subscriptions messages as an object identifier, to create topics for this interface, 
    * so adapter for an interface on server side has to have the same name.
    */
    const QString& interfaceName();

private:
    {{- if (len .Interface.Properties) }}
    // Helper function, subscribes for property changes from the remote {{$interfaceNameOriginal}} service.
    void subscribeForPropertiesChanges();
    {{- end }}
    {{- if (len .Interface.Signals) }}
    // Helper function, subscribes for signals emitted by the remote {{$interfaceNameOriginal}} service.
    void subscribeForSignals();
    {{- end }}
    {{- if $hasNonVoidOperations }}
    // Helper function, subscribes for result of invoke on remote {{$interfaceNameOriginal}} service.
    void subscribeForInvokeResponses();
    {{- end }}

{{- range .Interface.Properties }}
{{- $property := . }}
    /**  Updates local value for {{Camel $property.Name}} and informs subscriber about the change with emit property changed signal. */
    void set{{Camel .Name}}Local(const nlohmann::json& input);
    /** A local value for {{$property.Name}} */
    {{qtReturn "" .}} m_{{$property.Name}};
{{- end }}

    // Helper function for removing all subscriptions. 
    void unsubscribeAll();
    //Helper function for handling invoke responses.
    void findAndExecuteCall(const nlohmann::json& value, quint64 callId, QString topic);

    /** An indicator if the object is linked with the service. */
    bool m_isReady;
    /** 
    * An abstraction layer over the connection with service for the {{$class}}.
    * Handles incoming and outgoing messages.
    */
    ApiGear::Mqtt::Client& m_client;
    /**
    * identifiers for all subscribed pair topic - callback for one direction messages without responses (or that are not a response).
    */
    std::vector<quint64> m_subscribedIds;

    // Typdef for below m_InvokeCallsInfo members.
    using InvokeRespTopic = QString;
    // Typdef for below m_InvokeCallsInfo members.
    using InvokeTopic = QString;
    // Typdef for below m_InvokeCallsInfo members.
    using InvokeRespSubscriptionId = quint64;
    /**
    * Identifiers for all subscribed pair topic - topic response,  kept by "topic".
    * Keeps and helps accessing relevant information for invoke messages.
    */
    std::map<InvokeTopic, std::pair<InvokeRespTopic, InvokeRespSubscriptionId>> m_InvokeCallsInfo;
    /**
     * Invoke response handlers associated with the call Id.
     */
    std::map<quint64, std::pair<QString, std::function<void(const nlohmann::json&)>>> m_pendingCallsInfo;
    /* Pending calls mutex */
    std::mutex m_pendingCallMutex;
};

} //namespace {{snake  .Module.Name }}
