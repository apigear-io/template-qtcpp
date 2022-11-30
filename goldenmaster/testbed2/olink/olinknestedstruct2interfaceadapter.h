/**
NO TITLE
Copyright (C) 2020 ApiGear UG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <QtCore>
#include <nlohmann/json.hpp>

#include "../api/api.h"
#include "olink/remotenode.h"

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

class OLinkNestedStruct2InterfaceAdapter : public QObject, public IObjectSource
{
    Q_OBJECT
public:
    explicit OLinkNestedStruct2InterfaceAdapter(RemoteRegistry& registry, AbstractNestedStruct2Interface* impl, QObject *parent = nullptr);
    virtual ~OLinkNestedStruct2InterfaceAdapter() override;
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
    AbstractNestedStruct2Interface* m_impl;
    RemoteRegistry& m_registry;
    IRemoteNode *m_node;
};
