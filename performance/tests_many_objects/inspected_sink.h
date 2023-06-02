#pragma once

#include "olink/iobjectsink.h"
#include "olink/iclientnode.h"
#include <memory>
#include <future>
#include <chrono>




/*
* A wrapper for tested object that adds counting of incoming messages.
*/
class InspectedSink : public ApiGear::ObjectLink::IObjectSink
{
public:
    InspectedSink(std::shared_ptr<ApiGear::ObjectLink::IObjectSink> sink)
        : m_sink(sink)
    {
    }
    std::string olinkObjectName() override
    {
        return m_sink->olinkObjectName();
    }

    void olinkOnSignal(const std::string& signalId, const nlohmann::json& args) override
    {
        signalEmittedTimes++;
        m_sink->olinkOnPropertyChanged(signalId, args);
    }

    void olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value) override
    {
        propertyChangedTimes++;
        m_sink->olinkOnPropertyChanged(propertyId, value);
    }

    void olinkOnInit(const std::string& objectId, const nlohmann::json& props, ApiGear::ObjectLink::IClientNode* node) override
    {
        m_sink->olinkOnInit(objectId, props, node);
        initReceived = true;
    }
    
    void olinkOnRelease()
    {
        released = true;
        m_sink->olinkOnRelease();
    }

    uint32_t propertyChangedTimes = 0;
    uint32_t signalEmittedTimes = 0;
    bool initReceived = false;
    bool released = false;
    std::shared_ptr<ApiGear::ObjectLink::IObjectSink> m_sink;
};
