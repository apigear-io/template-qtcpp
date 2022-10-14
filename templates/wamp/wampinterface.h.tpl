{% comment %} // Copyright (c) ApiGear UG 2020 {% endcomment -%}
{{ cppGpl .Module }}
{% assign class = .Name |prepend:"Wamp"-%}
#pragma once

#include <QtCore>
#include <QtPromise>

#include "../api/api.h"
#include "../shared/wampclient.h"

using namespace ApiGear;

class {{$class}} : public Abstract{{.Name}}
{
    Q_OBJECT
public:
    explicit {{$class}}(QObject *parent = nullptr);
    virtual ~{{$class}}() override;

    void applyState(const json& fields);

{{- range .Properties }}
    {{qtReturn "" .}} {{.Name}}() const override;
    void set{{property.Camel .Name}}({{qtParam "" .}}) override;
    void set{{property.Camel .Name}}Local({{qtParam "" .}});
{{- end }}

{{- range .Operations }}
    {{qtReturn "" .Return}} {{.Name}}({{qtParams "" .Params}}) override;
    QtPromise::QPromise<{{qtReturn "" .Return}}> {{.Name}}Async({{qtParams "" .Params}});
{{- end }}

{{- range .Signals }}
void notify{{signalCamel .Name}}(WAMP::EventArg arg);
{{- end }}

private:
{{- range .Properties }}
    {{qtReturn "" .}} m_{{.Name}};
{{- end }}
};
