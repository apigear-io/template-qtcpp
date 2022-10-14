{% comment %} // Copyright (c) ApiGear UG 2020 {% endcomment -%}
{{ cppGpl .Module }}
{% capture class%}Wamp{{.Name}}Adapter{% endcapture %}
#pragma once

#include <QtCore>
#include <nlohmann/json.hpp>

#include "../api/api.h"
#include "../shared/wampclient.h"

using namespace ApiGear;

class {{$class}} : public QObject
{
    Q_OBJECT
public:
    explicit {{$class}}(Abstract{{interface}}* impl, QObject *parent = nullptr);
    virtual ~{{$class}}() override;
public:
    void publishState();
    nlohmann::json captureState();
    void applyState(const nlohmann::json& state);
    // handler functions
    void handleGetState(WAMP::ProcedureArg arg);
    void handleSetState(WAMP::ProcedureArg arg);
{{- range .Operations }}
    void handle{{Camel .Name}}(WAMP::ProcedureArg arg);
{{- end }}
{{- range .Signals }}
    void publish{{signalCamel .Name}}({{signal|qtParams}});
{{- end }}
private:
    Abstract{{interface}}* m_impl;
};
