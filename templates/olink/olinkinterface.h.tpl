{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $module_id := (snake .Module.Name)}}
{{- $class := printf "OLink%s" .Interface.Name }}
{{- $module := .Module.Name }}
{{- $iface := .Interface.Name }}
#pragma once

#include <QtCore>
#include <QtPromise>

#include "{{snake .Module.Name}}/api/api.h"
#include "olink/iobjectsink.h"

#include <nlohmann/json.hpp>

namespace ApiGear {
namespace ObjectLink {
class IClientNode;
}}


using namespace ApiGear;
using namespace ApiGear::ObjectLink;

class {{$class}} : public Abstract{{.Interface.Name}}, public IObjectSink
{
    Q_OBJECT
public:
    explicit {{$class}}(QObject *parent = nullptr);
    virtual ~{{$class}}() = default;

    void applyState(const nlohmann::json& fields);

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
    virtual void olinkOnSignal(const std::string& signalId, const nlohmann::json& args) override;
    virtual void olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value) override;
    virtual void olinkOnInit(const std::string& objectId, const nlohmann::json& props, ::ApiGear::ObjectLink::IClientNode *node) override;
    virtual void olinkOnRelease() override;
private:
{{- range .Interface.Properties }}
    {{qtReturn "" .}} m_{{.Name}};
{{- end }}
    bool m_isReady;
    IClientNode *m_node;
};
