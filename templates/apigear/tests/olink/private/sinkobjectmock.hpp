#pragma once

#include <catch2/catch.hpp>

#include <catch2/trompeloeil.hpp>
#include "olink/iobjectsink.h"

namespace tests
{
class SinkObjectMock : public trompeloeil::mock_interface<ApiGear::ObjectLink::IObjectSink>
{
public:
    IMPLEMENT_MOCK0(olinkObjectName);
    IMPLEMENT_MOCK2(olinkOnSignal);
    IMPLEMENT_MOCK2(olinkOnPropertyChanged);
    IMPLEMENT_MOCK3(olinkOnInit);
    IMPLEMENT_MOCK0(olinkOnRelease);
};
}
