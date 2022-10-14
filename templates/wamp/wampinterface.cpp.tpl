{% comment %} // Copyright (c) ApiGear UG 2020 {% endcomment -%}
{{ cppGpl .Module }}
{% assign class = .Name |prepend:"Wamp"-%}


#include "{{lower $class}}.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

{{$class}}::{{$class}}(QObject *parent)
    : Abstract{{.Name}}(parent)
{{- range .Properties }}
    , m_{{.Name}}({{qtDefault "" .}})
{{- end }}
{    
    // get initial state from service
    WampClient::instance()->doCall("{{module.name}}.{{.Name}}._get", json::array(), json::object(), [this](WAMP::ResponseArg arg) {
        this->applyState(arg.kwargs);
    });

    // subscribe to state changes
    WampClient::instance()->doSubscribe("{{module.name}}.{{.Name}}", [this](WAMP::EventArg arg) {
        this->applyState(arg.kwargs);
    });

{{- range .Signals }}
    // subscribe to signal {{.Name}}
    WampClient::instance()->doSubscribe("{{module.name}}.{{.Name}}.{{.Name}}", [this](WAMP::EventArg arg) {
        this->notify{{signalCamel .Name}}(arg);
    });
{{- end }}
}

{{$class}}::~{{$class}}()
{
}

void {{$class}}::applyState(const json& fields) 
{
{{- range .Properties }}
    if(fields.contains("{{.Name}}")) {
        set{{property.Camel .Name}}Local(fields["{{.Name}}"].get<{{property | qtReturn}}>());
    }
{{- end }}
}

{{- range .Properties }}
{% assign name = property.name %}

void {{$class}}::set{{Camel .Name}}({{qtParam "" .}})
{
    const json &fields = json::object({
        { "{{.Name}}", {{.Name}} }
    });
    WampClient::instance()->doCall("{{module.name}}.{{.Name}}._set", json::array(), fields);
}

void {{$class}}::set{{Camel .Name}}Local({{qtParam "" .}})
{
    if (m_{{.Name}} != {{.Name}}) {
        m_{{.Name}} = {{.Name}};
        emit {{.Name}}Changed({{.Name}});
        {{.Name}}Agent::trace_state(this);
    }
}


{{qtReturn "" .}} {{$class}}::{{.Name}}() const
{
    return m_{{.Name}};
}

{{- end }}


{{- range .Operations }}
{% capture returnType %}{{qtReturn "" .Return}}{% endcapture %}

{{returnType}} {{$class}}::{{.Name}}({{qtParams "" .Params}})
{
    qDebug() << Q_FUNC_INFO;
    {% if operation.type == 'void' %}
    WampClient::instance()->doCall("{{module.name}}.{{.Name}}.{{.Name}}", json::array({
            {%- for param in operation.params -%}
                {{.Name}}{% unless forloop.last %},{% endunless -%}
            {{- end }}}), json::object());
    {% else %}
    {{returnType}} value{ {{qtDefault "" .Return}} };
    {{.Name}}Async({{ operation.params | map: 'name' | join: ', ' }})
        .then([&]({{returnType}} result) {
            value = result;
        })
        .wait();
    return value;
    {% endif %}
}

QtPromise::QPromise<{{returnType}}> {{$class}}::{{.Name}}Async({{qtParams "" .Params}})
{
    {% if operation.type == 'void' %}
    WampClient::instance()->doCall("{{module.name}}.{{.Name}}.{{.Name}}", json::array({
            {%- for param in operation.params -%}
                {{.Name}}{% unless forloop.last %},{% endunless -%}
            {{- end }}}), json::object());
    return QtPromise::QPromise<void>::resolve();
    {% else %}
    return QtPromise::QPromise<{{returnType}}>{[&](
        const QtPromise::QPromiseResolve<{{returnType}}>& resolve) {
            WampClient::instance()->doCall("{{module.name}}.{{.Name}}.{{.Name}}", json::array({
            {%- for param in operation.params -%}
                {{.Name}}{% unless forloop.last %},{% endunless -%}
            {{- end }}}), json::object(), [resolve](WAMP::ResponseArg arg) {                
                const {{returnType}}& result = arg.args[0].get<{{returnType}}>();
                resolve(result);
            });
        }
    };
    {% endif %}
}

{{- end }}

{{- range .Signals }}

void {{$class}}::notify{{signalCamel .Name}}(WAMP::EventArg arg)
{
    emit {{signal}}(
{{- range .Params }}
        arg.args[{{forloop.index0}}].get<{{qtReturn "" .}}>(){% unless forloop.last %},{% endunless -%}
{{- end }}
    );
}
{{- end }}

