{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $class := printf "OLink%sAdapter" .Interface.Name }}

#pragma once

#include <QtCore>
#include <nlohmann/json.hpp>

#include "{{snake .Module.Name}}/api/api.h"
#include "olink/iobjectsource.h"

namespace ApiGear {
namespace ObjectLink {
class RemoteRegistry;
class IRemoteNode;
}}

namespace {{snake  .Module.Name }} {

class {{$class}} : public QObject, public ApiGear::ObjectLink::IObjectSource
{
    Q_OBJECT
public:
    explicit {{$class}}(ApiGear::ObjectLink::RemoteRegistry& registry, Abstract{{.Interface.Name}}* impl, QObject *parent = nullptr);
    virtual ~{{$class}}() = default;
public:
    void publishState();
    nlohmann::json captureState();
    void applyState(const nlohmann::json& state);
    
public: // IObjectSource interface
    std::string olinkObjectName() override;
    nlohmann::json olinkInvoke(const std::string& methodId, const nlohmann::json& args) override;
    void olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) override;
    void olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode *node) override;
    void olinkUnlinked(const std::string& objectId) override;
    nlohmann::json olinkCollectProperties() override;

private:
    Abstract{{.Interface.Name}}* m_impl;
    ApiGear::ObjectLink::RemoteRegistry& m_registry;
    ApiGear::ObjectLink::IRemoteNode *m_node;
};

} // namespace {{snake  .Module.Name }}
