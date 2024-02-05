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
#include "olinknam_es.h"

#include "tb_names/api/json.adapter.h"

#include "olink/iclientnode.h"
#include "utilities/logger.h"

#include <QtCore>

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace tb_names {

OLinkNam_Es::OLinkNam_Es(QObject *parent)
    : AbstractNamEs(parent)
    , m_Switch(false)
    , m_SOME_PROPERTY(0)
    , m_Some_Poperty2(0)
    , m_isReady(false)
    , m_node(nullptr)
{        
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

void OLinkNam_Es::applyState(const nlohmann::json& fields) 
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(fields.contains("Switch")) {
        setSwitchLocal(fields["Switch"].get<bool>());
    }
    if(fields.contains("SOME_PROPERTY")) {
        setSomePropertyLocal(fields["SOME_PROPERTY"].get<int>());
    }
    if(fields.contains("Some_Poperty2")) {
        setSomePoperty2Local(fields["Some_Poperty2"].get<int>());
    }
}

void OLinkNam_Es::setSwitch(bool Switch)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.names.Nam_Es/Switch", Switch);
}

void OLinkNam_Es::setSwitchLocal(bool Switch)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_Switch != Switch) {
        m_Switch = Switch;
        emit SwitchChanged(Switch);
    }
}

bool OLinkNam_Es::Switch() const
{
    return m_Switch;
}

void OLinkNam_Es::setSomeProperty(int SOME_PROPERTY)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.names.Nam_Es/SOME_PROPERTY", SOME_PROPERTY);
}

void OLinkNam_Es::setSomePropertyLocal(int SOME_PROPERTY)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_SOME_PROPERTY != SOME_PROPERTY) {
        m_SOME_PROPERTY = SOME_PROPERTY;
        emit SOME_PROPERTYChanged(SOME_PROPERTY);
    }
}

int OLinkNam_Es::SOME_PROPERTY() const
{
    return m_SOME_PROPERTY;
}

void OLinkNam_Es::setSomePoperty2(int Some_Poperty2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.names.Nam_Es/Some_Poperty2", Some_Poperty2);
}

void OLinkNam_Es::setSomePoperty2Local(int Some_Poperty2)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if (m_Some_Poperty2 != Some_Poperty2) {
        m_Some_Poperty2 = Some_Poperty2;
        emit Some_Poperty2Changed(Some_Poperty2);
    }
}

int OLinkNam_Es::Some_Poperty2() const
{
    return m_Some_Poperty2;
}

void OLinkNam_Es::someFunction(bool SOME_PARAM)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    InvokeReplyFunc func = [this](InvokeReplyArg arg) {};
    const nlohmann::json &args = nlohmann::json::array({
        SOME_PARAM
    });
    const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "SOME_FUNCTION");
    m_node->invokeRemote(operationId, args, func);
}

QtPromise::QPromise<void> OLinkNam_Es::someFunctionAsync(bool SOME_PARAM)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return QtPromise::QPromise<void>::reject("not initialized");
    }
    m_node->invokeRemote("tb.names.Nam_Es/SOME_FUNCTION", nlohmann::json::array({
            
                SOME_PARAM}));
    return QtPromise::QPromise<void>::resolve();
}

void OLinkNam_Es::someFunction2(bool Some_Param)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return;
    }
    InvokeReplyFunc func = [this](InvokeReplyArg arg) {};
    const nlohmann::json &args = nlohmann::json::array({
        Some_Param
    });
    const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "Some_Function2");
    m_node->invokeRemote(operationId, args, func);
}

QtPromise::QPromise<void> OLinkNam_Es::someFunction2Async(bool Some_Param)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    if(!m_node) {
        return QtPromise::QPromise<void>::reject("not initialized");
    }
    m_node->invokeRemote("tb.names.Nam_Es/Some_Function2", nlohmann::json::array({
            
                Some_Param}));
    return QtPromise::QPromise<void>::resolve();
}


std::string OLinkNam_Es::olinkObjectName()
{
    return "tb.names.Nam_Es";
}

void OLinkNam_Es::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(signalId);
    auto signalName = Name::getMemberName(signalId);
    if(signalName == "SOME_SIGNAL") {
        emit someSignal(args[0].get<bool>());   
        return;
    }
    if(signalName == "Some_Signal2") {
        emit someSignal2(args[0].get<bool>());   
        return;
    }
}

void OLinkNam_Es::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    AG_LOG_DEBUG(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyState({ {propertyName, value} });
}
void OLinkNam_Es::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    AG_LOG_INFO(Q_FUNC_INFO);
    AG_LOG_INFO(objectId);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkNam_Es::olinkOnRelease()
{
    AG_LOG_INFO(Q_FUNC_INFO);
    m_isReady = false;
    m_node = nullptr;
}

} //namespace tb_names
