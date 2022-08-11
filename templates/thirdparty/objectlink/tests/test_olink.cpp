#include <catch2/catch.hpp>

#include "olink/core/protocol.h"
#include "olink/core/types.h"
#include "olink/consolelogger.h"
#include "olink/clientnode.h"
#include "olink/remotenode.h"


#include "nlohmann/json.hpp"

#include <list>
#include <string>

#include "sinkobject.hpp"
#include "sourceobject.hpp"

using json = nlohmann::json;
using namespace ApiGear::ObjectLink;


TEST_CASE("link")
{
    RemoteRegistry::get().onLog(ConsoleLogger::logFunc());
    ClientRegistry::get().onLog(ConsoleLogger::logFunc());
    // setup service
    RemoteNode remote;

    CalcSource source;

    // setup client
    ClientNode client;
    client.onLog(ConsoleLogger::logFunc());
    CalcSink sink;

    WriteMessageFunc clientWriteFunc = [&remote](std::string msg) {
        remote.handleMessage(msg);
    };
    client.onWrite(clientWriteFunc);

    WriteMessageFunc sourceWriteFunc = [&client](std::string msg) {
        client.handleMessage(msg);
    };
    remote.onWrite(sourceWriteFunc);


    // register source object
    remote.addObjectSource(&source);
    // register sink object
    client.addObjectSink(&sink);

    SECTION("link ->, <- init") {
        // not initalized sink, with total=0
        REQUIRE( sink.isReady() == false );
        REQUIRE( sink.total() == 0);
        // link sink with source
        client.linkRemote("demo.Calc");
        // initalized sink with total=1
        REQUIRE( sink.isReady() == true );
        REQUIRE( sink.total() == 1);
    }
//    remote.removeObjectSource(&source);
//    client.removeObjectSink(&sink);
}

TEST_CASE("setProperty")
{
    ConsoleLogger log;
    // setup service
    RemoteNode remote;
    remote.onLog(log.logFunc());
    CalcSource source;

    // setup client
//    ObjectSinkRegistry clientRegistry("client1");
    ClientNode client;
    client.onLog(log.logFunc());
    CalcSink sink;

    WriteMessageFunc sinkWriteFunc = [&remote](std::string msg) {
        remote.handleMessage(msg);
    };
    client.onWrite(sinkWriteFunc);

    WriteMessageFunc sourceWriteFunc = [&client](std::string msg) {
        client.handleMessage(msg);
    };
    remote.onWrite(sourceWriteFunc);

    // register source object
    remote.addObjectSource(&source);
    client.addObjectSink(&sink);
    client.linkRemote("demo.Calc");

    REQUIRE( sink.isReady() == true );
    SECTION("set property") {
        REQUIRE( sink.total() == 1);
        sink.setTotal(2);
        REQUIRE( sink.total() == 2);
        sink.setTotal(3);
        REQUIRE( sink.total() == 3);
    }
//    remote.removeObjectSource(&source);
//    client.removeObjectSink(&sink);
}

TEST_CASE("signal")
{
    ConsoleLogger log;
    // setup service
    RemoteNode remote;
    remote.onLog(log.logFunc());
    CalcSource source;

    // setup client
//    ObjectSinkRegistry clientRegistry("client1");
    ClientNode client;
    client.onLog(log.logFunc());
    CalcSink sink;

    WriteMessageFunc sinkWriteFunc = [&remote](std::string msg) {
        remote.handleMessage(msg);
    };
    client.onWrite(sinkWriteFunc);

    WriteMessageFunc sourceWriteFunc = [&client](std::string msg) {
        client.handleMessage(msg);
    };
    remote.onWrite(sourceWriteFunc);

    // register source object
    remote.addObjectSource(&source);
    client.addObjectSink(&sink);
    client.linkRemote("demo.Calc");
    REQUIRE( sink.isReady() == true );

    SECTION("signal") {
        REQUIRE( sink.events.size() == 0);
        source.notifyShutdown(10);
        REQUIRE( sink.events.size() == 1);
    }
//    remote.removeObjectSource(&source);
//    client.removeObjectSink(&sink);
}


TEST_CASE("invoke")
{
    ConsoleLogger log;
    // setup service
//    ObjectSourceRegistry sourceRegistry("host1");
    RemoteNode remote;
    remote.onLog(log.logFunc());
    CalcSource source;

    // setup client
//    ObjectSinkRegistry sinkRegistry("client1");
    ClientNode client;
    client.onLog(log.logFunc());
    CalcSink sink;

    WriteMessageFunc clientWriteFunc = [&remote](std::string msg) {
        remote.handleMessage(msg);
    };
    client.onWrite(clientWriteFunc);

    WriteMessageFunc serviceWriteFunc = [&client](std::string msg) {
        client.handleMessage(msg);
    };
    remote.onWrite(serviceWriteFunc);


    // register source object
    remote.addObjectSource(&source);
    client.addObjectSink(&sink);
    client.linkRemote("demo.Calc");
    REQUIRE( sink.isReady() == true );

    SECTION("invoke") {
        REQUIRE( sink.total() == 1);
        sink.add(5);
        REQUIRE( sink.total() == 6);
    }
//    remote.removeObjectSource(&source);
//    client.removeObjectSink(&sink);
}
