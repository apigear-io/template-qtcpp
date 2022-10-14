{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $module_id := (snake .Module.Name)}}
{{- $class := printf "OLink%s" .Interface.Name }}
{{- $module := .Module.Name }}
{{- $iface := .Interface.Name }}
#pragma once

#include <QtCore>
#include <QtPromise>

#include "../api/api.h"
#include "objectlink/olink/clientnode.h"

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

class {{$class}} : public Abstract{{.Interface.Name}}, public IObjectSink
{
    Q_OBJECT
public:
    explicit {{$class}}(QObject *parent = nullptr);
    virtual ~{{$class}}() override;

    void applyState(const json& fields);

{{- range .Interface.Properties }}
    {{qtReturn "" .}} {{.Name}}() const override;
    void set{{Camel .Name}}({{qtParam "" .}}) override;
    void set{{Camel .Name}}Local({{qtParam "" .}});
{{- end }}

{{- range .Interface.Operations }}
    {{qtReturn "" .Return}} {{.Name}}({{qtParams "" .Params}}) override;
    QtPromise::QPromise<{{qtReturn "" .Return}}> {{.Name}}Async({{qtParams "" .Params}});
{{- end }}
signals:
    void isReady();
public:
    virtual std::string olinkObjectName() override;
    virtual void olinkOnSignal(std::string name, json args) override;
    virtual void olinkOnPropertyChanged(std::string name, json value) override;
    virtual void olinkOnInit(std::string name, json props, IClientNode *node) override;
    virtual void olinkOnRelease() override;
private:
{{- range .Interface.Properties }}
    {{qtReturn "" .}} m_{{.Name}};
{{- end }}
    bool m_isReady;
    IClientNode *m_node;
};
