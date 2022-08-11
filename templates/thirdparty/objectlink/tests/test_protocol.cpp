#include <catch2/catch.hpp>

#include "olink/core/types.h"
#include "olink/core/protocol.h"
#include "nlohmann/json.hpp"

#include <list>
#include <string>
#include "mocksink.hpp"
#include "mocksource.hpp"
#include "olink/consolelogger.h"

using json = nlohmann::json;
using namespace ApiGear::ObjectLink;


TEST_CASE("protocol")
{
    std::string name = "demo.Calc";
    json props = {{ "count", 0 }};
    int value = 1;
    json args = {1, 2};
    int requestId = 1;
    MsgType msgType = MsgType::Invoke;
    std::string error = "failed";

    ConsoleLogger log;
    MockSink sink;
    MockSource source;
    ClientNode client;
    client.onLog(log.logFunc());
    RemoteNode remote;
    remote.onLog(log.logFunc());
    SECTION("link") {
        json msg = Protocol::linkMessage(name);
        REQUIRE(msg[0] == MsgType::Link);
        REQUIRE(msg[1] == name);
    }
    SECTION("unlink") {
        json msg = Protocol::unlinkMessage(name);
        REQUIRE(msg[0] == MsgType::Unlink);
        REQUIRE(msg[1] == name);
    }
    SECTION("init") {
        json msg = Protocol::initMessage(name, props);
        REQUIRE(msg[0] == MsgType::Init);
        REQUIRE(msg[1] == name);
        REQUIRE(msg[2] == props);
    }
    SECTION("setProperty") {
        json msg = Protocol::setPropertyMessage(name, value);
        REQUIRE(msg[0] == MsgType::SetProperty);
        REQUIRE(msg[1] == name);
        REQUIRE(msg[2] == value);
    }
    SECTION("propertyChange") {
        json msg = Protocol::propertyChangeMessage(name, value);
        REQUIRE(msg[0] == MsgType::PropertyChange);
        REQUIRE(msg[1] == name);
        REQUIRE(msg[2] == value);
    }
    SECTION("invoke") {
        json msg = Protocol::invokeMessage(requestId, name, args);
        REQUIRE(msg[0] == MsgType::Invoke);
        REQUIRE(msg[1] == requestId);
        REQUIRE(msg[2] == name);
        REQUIRE(msg[3] == args);
    }
    SECTION("invokeReply") {
        json msg = Protocol::invokeReplyMessage(requestId, name, value);
        REQUIRE(msg[0] == MsgType::InvokeReply);
        REQUIRE(msg[1] == requestId);
        REQUIRE(msg[2] == name);
        REQUIRE(msg[3] == value);
    }
    SECTION("signal") {
        json msg = Protocol::signalMessage(name, args);
        REQUIRE(msg[0] == MsgType::Signal);
        REQUIRE(msg[1] == name);
        REQUIRE(msg[2] == args);
    }
    SECTION("error") {
        json msg = Protocol::errorMessage(msgType, requestId, error);
        REQUIRE(msg[0] == MsgType::Error);
        REQUIRE(msg[1] == msgType);
        REQUIRE(msg[2] == requestId);
        REQUIRE(msg[3] == error);
    }
}
