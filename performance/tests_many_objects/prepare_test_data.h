#pragma once
#include "inspected_sink.h"
#include <memory>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <future>

#include "api/olink/olinktestapi0.h"
#include "api/olink/olinktestapi1.h"
#include "api/olink/olinktestapi2.h"
#include "api/olink/olinktestapi3.h"
#include "api/olink/olinktestapi4.h"
#include "api/olink/olinktestapi5.h"
#include "api/olink/olinktestapi6.h"
#include "api/olink/olinktestapi7.h"
#include "api/olink/olinktestapi8.h"
#include "api/olink/olinktestapi9.h"

#include "api/olink/olinktestapi10.h"
#include "api/olink/olinktestapi11.h"
#include "api/olink/olinktestapi12.h"
#include "api/olink/olinktestapi13.h"
#include "api/olink/olinktestapi14.h"
#include "api/olink/olinktestapi15.h"
#include "api/olink/olinktestapi16.h"
#include "api/olink/olinktestapi17.h"
#include "api/olink/olinktestapi18.h"
#include "api/olink/olinktestapi19.h"

#include "api/olink/olinktestapi20.h"
#include "api/olink/olinktestapi21.h"
#include "api/olink/olinktestapi22.h"
#include "api/olink/olinktestapi23.h"
#include "api/olink/olinktestapi24.h"
#include "api/olink/olinktestapi25.h"
#include "api/olink/olinktestapi26.h"
#include "api/olink/olinktestapi27.h"
#include "api/olink/olinktestapi28.h"
#include "api/olink/olinktestapi29.h"

#include "api/olink/olinktestapi30.h"
#include "api/olink/olinktestapi31.h"
#include "api/olink/olinktestapi32.h"
#include "api/olink/olinktestapi33.h"
#include "api/olink/olinktestapi34.h"
#include "api/olink/olinktestapi35.h"
#include "api/olink/olinktestapi36.h"
#include "api/olink/olinktestapi37.h"
#include "api/olink/olinktestapi38.h"
#include "api/olink/olinktestapi39.h"

#include "api/olink/olinktestapi40.h"
#include "api/olink/olinktestapi41.h"
#include "api/olink/olinktestapi42.h"
#include "api/olink/olinktestapi43.h"
#include "api/olink/olinktestapi44.h"
#include "api/olink/olinktestapi45.h"
#include "api/olink/olinktestapi46.h"
#include "api/olink/olinktestapi47.h"
#include "api/olink/olinktestapi48.h"
#include "api/olink/olinktestapi49.h"

#include "api/olink/olinktestapi50.h"
#include "api/olink/olinktestapi51.h"
#include "api/olink/olinktestapi52.h"
#include "api/olink/olinktestapi53.h"
#include "api/olink/olinktestapi54.h"
#include "api/olink/olinktestapi55.h"
#include "api/olink/olinktestapi56.h"
#include "api/olink/olinktestapi57.h"
#include "api/olink/olinktestapi58.h"
#include "api/olink/olinktestapi59.h"

#include "api/olink/olinktestapi60.h"
#include "api/olink/olinktestapi61.h"
#include "api/olink/olinktestapi62.h"
#include "api/olink/olinktestapi63.h"
#include "api/olink/olinktestapi64.h"
#include "api/olink/olinktestapi65.h"
#include "api/olink/olinktestapi66.h"
#include "api/olink/olinktestapi67.h"
#include "api/olink/olinktestapi68.h"
#include "api/olink/olinktestapi69.h"

#include "api/olink/olinktestapi70.h"
#include "api/olink/olinktestapi71.h"
#include "api/olink/olinktestapi72.h"
#include "api/olink/olinktestapi73.h"
#include "api/olink/olinktestapi74.h"
#include "api/olink/olinktestapi75.h"
#include "api/olink/olinktestapi76.h"
#include "api/olink/olinktestapi77.h"
#include "api/olink/olinktestapi78.h"
#include "api/olink/olinktestapi79.h"

#include "api/olink/olinktestapi80.h"
#include "api/olink/olinktestapi81.h"
#include "api/olink/olinktestapi82.h"
#include "api/olink/olinktestapi83.h"
#include "api/olink/olinktestapi84.h"
#include "api/olink/olinktestapi85.h"
#include "api/olink/olinktestapi86.h"
#include "api/olink/olinktestapi87.h"
#include "api/olink/olinktestapi88.h"
#include "api/olink/olinktestapi89.h"

#include "api/olink/olinktestapi90.h"
#include "api/olink/olinktestapi91.h"
#include "api/olink/olinktestapi92.h"
#include "api/olink/olinktestapi93.h"
#include "api/olink/olinktestapi94.h"
#include "api/olink/olinktestapi95.h"
#include "api/olink/olinktestapi96.h"
#include "api/olink/olinktestapi97.h"
#include "api/olink/olinktestapi98.h"
#include "api/olink/olinktestapi99.h"


template<class Interface, class TestData, class FunctionSetter>
void addTestData(std::shared_ptr<Interface> olinkClient, std::vector<TestData>& elements, FunctionSetter& setter)
{
    TestData element;
    element.sink = std::make_shared<InspectedSink>(olinkClient);
    element.testFunction = [olinkClient, &setter](const auto& value) {setter.testFunction(olinkClient, value); };
    elements.push_back(element);
}

template<class TestData, class FunctionSetter>
std::vector<TestData> getTestData(FunctionSetter& setter)
{
    std::vector<TestData> data;
    addTestData(std::make_shared<api::OLinkTestApi0>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi1>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi2>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi3>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi4>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi5>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi6>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi7>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi8>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi9>(), data, setter);

    addTestData(std::make_shared<api::OLinkTestApi10>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi11>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi12>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi13>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi14>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi15>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi16>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi17>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi18>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi19>(), data, setter);

    addTestData(std::make_shared<api::OLinkTestApi20>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi21>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi22>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi23>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi24>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi25>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi26>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi27>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi28>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi29>(), data, setter);

    addTestData(std::make_shared<api::OLinkTestApi30>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi31>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi32>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi33>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi34>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi35>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi36>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi37>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi38>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi39>(), data, setter);

    addTestData(std::make_shared<api::OLinkTestApi40>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi41>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi42>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi43>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi44>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi45>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi46>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi47>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi48>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi49>(), data, setter);

    addTestData(std::make_shared<api::OLinkTestApi50>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi51>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi52>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi53>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi54>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi55>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi56>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi57>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi58>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi59>(), data, setter);

    addTestData(std::make_shared<api::OLinkTestApi60>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi61>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi62>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi63>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi64>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi65>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi66>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi67>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi68>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi69>(), data, setter);

    addTestData(std::make_shared<api::OLinkTestApi70>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi71>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi72>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi73>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi74>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi75>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi76>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi77>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi78>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi79>(), data, setter);

    addTestData(std::make_shared<api::OLinkTestApi80>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi81>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi82>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi83>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi84>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi85>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi86>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi87>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi88>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi89>(), data, setter);

    addTestData(std::make_shared<api::OLinkTestApi90>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi91>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi92>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi93>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi94>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi95>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi96>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi97>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi98>(), data, setter);
    addTestData(std::make_shared<api::OLinkTestApi99>(), data, setter);


    return data;
}
