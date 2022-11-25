{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $class := printf "OLink%sAdapter" .Interface.Name }}

#pragma once

#include <QtCore>
#include <nlohmann/json.hpp>

#include "../api/api.h"
#include "objectlink/olink/remotenode.h"

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

class {{$class}} : public QObject, public IObjectSource
{
    Q_OBJECT
public:
    explicit {{$class}}(Abstract{{.Interface.Name}}* impl, QObject *parent = nullptr);
    virtual ~{{$class}}() override;
public:
    void publishState();
    json captureState();
    void applyState(const json& state);
    
public: // IObjectSource interface
    std::string olinkObjectName() override;
    json olinkInvoke(std::string name, json args) override;
    void olinkSetProperty(std::string name, json value) override;
    void olinkLinked(std::string name, IRemoteNode *node) override;
    void olinkUnlinked(std::string name) override;
    json olinkCollectProperties() override;

private:
    Abstract{{.Interface.Name}}* m_impl;
    IRemoteNode *m_node;
};
