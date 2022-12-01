{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $class := printf "OLink%sAdapter" .Interface.Name }}

#pragma once

#include <QtCore>
#include <nlohmann/json.hpp>

#include "{{snake .Module.Name}}/api/api.h"
#include "olink/remotenode.h"

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

class {{$class}} : public QObject, public IObjectSource
{
    Q_OBJECT
public:
    explicit {{$class}}(RemoteRegistry& registry, Abstract{{.Interface.Name}}* impl, QObject *parent = nullptr);
    virtual ~{{$class}}() override;
public:
    void publishState();
    nlohmann::json captureState();
    void applyState(const nlohmann::json& state);
    
public: // IObjectSource interface
    std::string olinkObjectName() override;
    nlohmann::json olinkInvoke(std::string name, nlohmann::json args) override;
    void olinkSetProperty(std::string name, nlohmann::json value) override;
    void olinkLinked(std::string name, IRemoteNode *node) override;
    void olinkUnlinked(std::string name) override;
    nlohmann::json olinkCollectProperties() override;

private:
    Abstract{{.Interface.Name}}* m_impl;
    RemoteRegistry& m_registry;
    IRemoteNode *m_node;
};
