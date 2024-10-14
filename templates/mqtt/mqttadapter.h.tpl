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


namespace {{qtNamespace .Module.Name }} {


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
    * The name of the interface for which this mqtt service adapter is created.
    * It is used in subscriptions messages as an object identifier, to create topics for this interface, 
    * so adapter for an interface on client side has to have the same name.
    */
    const QString& interfaceName();
    /**
    * Use to check if the {{$class}} is ready to send and receive messages.
    */
    bool isReady() const;

signals:
    /**
    * Informs if the {{$class}} is ready to send and receive messages.
    */
    void ready();
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

    // Helper function for removing all subscriptions. 
    void unsubscribeAll();
    // Helper function for handling subsbscriptions
    void handleOnSubscribed(QString topic, quint64 id,  bool hasSucceed);

    /**
    * The actual implementation of a {{$interface}} that gets adapted to be a service in mqtt network.
    */
    std::shared_ptr<Abstract{{Camel .Interface.Name}}> m_impl;
    /**
    * The mqtt client which aligns this obejct to serve a service.
    */
    ApiGear::Mqtt::ServiceAdapter& m_mqttServiceAdapter;

    /** An indicator if the object has fisnished initialization. */
    bool m_finishedInitialization;

    /** Ids of subscribed topics */
    std::vector<quint64> m_subscribedIds;
    /* Storage for tracking pending subscriptions */
    std::vector<QString> m_pendingSubscriptions;
};

} // namespace {{qtNamespace .Module.Name }}
