#pragma once
#include "api/olink/olinktestapi0.h"

/*
* A wrapper for tested object that adds counting of incoming messages.
*/
class TestSink : public api::OLinkTestApi0
{
public:
    void olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value) override {
        propertyChangedTimes++;
        api::OLinkTestApi0::olinkOnPropertyChanged(propertyId, value);
    }
    uint32_t propertyChangedTimes = 0;
};
