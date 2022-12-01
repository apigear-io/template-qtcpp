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

#include "tb_same1/api/api.h"
#include "olink/iobjectsource.h"

namespace ApiGear {
namespace ObjectLink {
class RemoteRegistry;
class IRemoteNode;
}}


class OLinkSameEnum2InterfaceAdapter : public QObject, public ApiGear::ObjectLink::IObjectSource
{
    Q_OBJECT
public:
    explicit OLinkSameEnum2InterfaceAdapter(ApiGear::ObjectLink::RemoteRegistry& registry, AbstractSameEnum2Interface* impl, QObject *parent = nullptr);
    virtual ~OLinkSameEnum2InterfaceAdapter() = default;
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
    AbstractSameEnum2Interface* m_impl;
    ApiGear::ObjectLink::RemoteRegistry& m_registry;
    ApiGear::ObjectLink::IRemoteNode *m_node;
};
