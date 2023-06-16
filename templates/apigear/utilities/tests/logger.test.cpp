#pragma warning (disable: 4251) 
#pragma warning (disable: 4099) 

#include <catch2/catch.hpp>
#include <iostream>
#include <sstream>

#include "../logger.h"

namespace {
    struct strTuple {
        std::string cout;
        std::string clog;
        std::string cerr;
    };

    // we need to capture the strings and restore the buffers
    // otherwise catch2 REQUIRE etc. checks cause seg faults
    strTuple captureStdStreams(std::function<void()> testFunction)
    {
        using namespace std;
        strTuple output;

        // redirect std streams to be read by us
        streambuf* oldCoutBuffer = cout.rdbuf();
        ostringstream newCout;
        cout.rdbuf(newCout.rdbuf());

        streambuf* oldClogBuffer = clog.rdbuf();
        ostringstream newClog;
        clog.rdbuf(newClog.rdbuf());

        streambuf* oldCerrBuffer = cerr.rdbuf();
        ostringstream newCerr;
        cerr.rdbuf(newCerr.rdbuf());

        // run function under test
        testFunction();

        // save stream content
        output.cout = newCout.str();
        output.clog = newClog.str();
        output.cerr = newCerr.str();

        // reset streams
        cout.rdbuf(oldCoutBuffer);
        clog.rdbuf(oldClogBuffer);
        cerr.rdbuf(oldCerrBuffer);

        return output;
    };

    auto logAll = [](){
        ApiGear::Utilities::logDebug("test loglevel debug");
        ApiGear::Utilities::logInfo("test loglevel info");
        ApiGear::Utilities::logWarning("test loglevel warning");
        ApiGear::Utilities::logError("test loglevel error");
    };

}

SCENARIO("Test console log", "[console][log]")
{
    GIVEN("Default settings") {
        THEN("Warning and Error should be logged") {
            strTuple output = captureStdStreams(logAll);
            REQUIRE(output.cout.empty());
            REQUIRE(output.clog.empty());
            REQUIRE(output.cerr == "[warning] test loglevel warning\n[error  ] test loglevel error\n");
        }
    }

    GIVEN("Set minimum log level to debug") {
        ApiGear::Utilities::setLogger(ApiGear::Utilities::getDefaultCharLogFunc(ApiGear::Utilities::LogLevel::Debug));

        THEN("Everything should be logged") {
            strTuple output = captureStdStreams(logAll);
            REQUIRE(output.cout== "[info   ] test loglevel info\n");
            REQUIRE(output.clog=="[debug  ] test loglevel debug\n");
            REQUIRE(output.cerr=="[warning] test loglevel warning\n[error  ] test loglevel error\n");
        }
    }

    GIVEN("Set minimum log level to info") {
        ApiGear::Utilities::setLogger(ApiGear::Utilities::getDefaultCharLogFunc(ApiGear::Utilities::LogLevel::Info));

        THEN("Info, Warning and Error should be logged") {
            strTuple output = captureStdStreams(logAll);
            REQUIRE(output.cout== "[info   ] test loglevel info\n");
            REQUIRE(output.clog.empty());
            REQUIRE(output.cerr=="[warning] test loglevel warning\n[error  ] test loglevel error\n");
        }
    }

    GIVEN("Set minimum log level to warning") {
        ApiGear::Utilities::setLogger(ApiGear::Utilities::getDefaultCharLogFunc(ApiGear::Utilities::LogLevel::Warning));

        THEN("Warning and Error should be logged") {
            strTuple output = captureStdStreams(logAll);
            REQUIRE(output.cout.empty());
            REQUIRE(output.clog.empty());
            REQUIRE(output.cerr=="[warning] test loglevel warning\n[error  ] test loglevel error\n");
        }
    }

    GIVEN("Set minimum log level to error") {
        ApiGear::Utilities::setLogger(ApiGear::Utilities::getDefaultCharLogFunc(ApiGear::Utilities::LogLevel::Error));

        THEN("Error should be logged") {
            strTuple output = captureStdStreams(logAll);
            REQUIRE(output.cout.empty());
            REQUIRE(output.clog.empty());
            REQUIRE(output.cerr=="[error  ] test loglevel error\n");
        }
    }
}

SCENARIO("Test disabled log", "[log]")
{
    GIVEN("No log function defined") {
        ApiGear::Utilities::WriteLogFuncCharPtr noFunc = nullptr;
        ApiGear::Utilities::setLogger(noFunc);

        THEN("Nothing should be logged") {
            strTuple output = captureStdStreams(logAll);
            REQUIRE(output.cout.empty());
            REQUIRE(output.clog.empty());
            REQUIRE(output.cerr.empty());
        }
    }
}