{% comment %} // Copyright (c) ApiGear UG 2020 {% endcomment -%}
{{ cppGpl .Module }}
{% capture class%}Wamp{{.Name}}Adapter{% endcapture %}


#include "{{lower $class}}.h"

#include <nlohmann/json.hpp>
#include "../api/agent.h"
#include "../api/json.adapter.h"

#include <QtCore>

using namespace ApiGear::WAMP;
using json = nlohmann::json;

{{$class}}::{{$class}}(Abstract{{interface}}* impl, QObject *parent)
    : QObject(parent)
    , m_impl(impl)
{    
    // setup state handling
    WampClient::instance()->doRegister("{{module}}.{{interface}}._get", [this](ProcedureArg arg) {
        this->handleGetState(arg);
    });
    WampClient::instance()->doRegister("{{module}}.{{interface}}._set", [this](ProcedureArg arg) {
        this->handleSetState(arg);
    });

    // setup operations
{{- range .Operations }}
    WampClient::instance()->doRegister("{{module}}.{{interface}}.{{.Name}}", [this](ProcedureArg arg) {
        this->handle{{Camel .Name}}(arg);
    });
{{- end }}

    // setup properties
{{- range .Properties }}
    connect(impl, &Abstract{{interface}}::{{.Name}}Changed, this, &{{$class}}::publishState);
{{- end }}    

    // setup signals
{{- range .Signals }}
    connect(impl, &Abstract{{interface}}::{{.Name}}, this, &{{$class}}::publish{{signalCamel .Name}});
{{- end }}
}

{{$class}}::~{{$class}}()
{
}

json {{$class}}::captureState()
{
    return json::object({
{{- range .Properties }}
        { "{{.Name}}", m_impl->{{.Name}}() }{% unless forloop.last %},{% endunless %}
{{- end }}
    });
}

void {{$class}}::applyState(const json& state)
{
{{- range .Properties }}
    if(state.contains("{{.Name}}")) {
        m_impl->set{{propertyCamel .Name}}(state["{{.Name}}"]);
    }    
{{- end }}
}

void {{$class}}::publishState()
{
    qDebug() << Q_FUNC_INFO;
    const json& fields = captureState();
    WampClient::instance()->doPublish("{{module}}.{{interface}}", json::array(), fields);
}

void {{$class}}::handleGetState(ProcedureArg arg) 
{
    WampClient::instance()->doYield(arg.requestId, json::array(), this->captureState());
}

void {{$class}}::handleSetState(ProcedureArg arg)
{
    this->applyState(arg.kwargs);
    WampClient::instance()->doYield(arg.requestId, json::array(), json::object());
}

{{- range .Operations }}

void {{$class}}::handle{{Camel .Name}}(ProcedureArg arg)
{    
    qDebug() << Q_FUNC_INFO;
{{- range  .Params }}
    const {{qtReturn "" .}}& {{.Name}} = arg.args.at({{ forloop.index0 }});        
{{- end }}        
{% if operation.type == 'void' %}
    m_impl->{{.Name}}({{ operation.params | map: 'name' | join: ', ' }});
    WampClient::instance()->doYield(arg.requestId, json::array(), json::object());
{% else %}
    const {{qtReturn "" .Return}}& result = m_impl->{{.Name}}({{ operation.params | map: 'name' | join: ', ' }});
    const json& args = json::array({ result });
    WampClient::instance()->doYield(arg.requestId, args, json::object());
{% endif %}
}
{{- end }}


{{- range .Signals }}
void {{$class}}::publish{{signalCamel .Name}}({{signal|qtParams}})
{
    qDebug() << Q_FUNC_INFO;
    json args = json::array({
{% for param in signal.params %}
      {{.Name}}{% unless forloop.last %},{% endunless %}
{{- end }}
    });
    WampClient::instance()->doPublish("{{module}}.{{interface}}.{{.Name}}", args, json::object());
}
{{- end }}



