#pragma once

#include <catch2/catch.hpp>

#include <catch2/trompeloeil.hpp>
#include "olink/iobjectsource.h"

namespace tests
{
    class SourceObjectMock : public trompeloeil::mock_interface<ApiGear::ObjectLink::IObjectSource>
    {
    public:
        IMPLEMENT_MOCK0(olinkObjectName);
        IMPLEMENT_MOCK2(olinkInvoke);
        IMPLEMENT_MOCK2(olinkSetProperty);
        IMPLEMENT_MOCK2(olinkLinked);
        IMPLEMENT_MOCK1(olinkUnlinked);
        IMPLEMENT_MOCK0(olinkCollectProperties);
    };
}

