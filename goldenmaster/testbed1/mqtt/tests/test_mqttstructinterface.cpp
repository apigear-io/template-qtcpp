#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>
#include <condition_variable>


#include <QtCore>
#include <QTest>
#include <QThreadPool>
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/structinterface.h"
#include "mqtt/mqttstructinterface.h"
#include "mqtt/mqttstructinterfaceadapter.h"


#include "apigear/mqtt/mqttclient.h"
#include "apigear/mqtt/mqttservice.h"

// Those tests require an external mqtt broker, which is not provided here with  the mqtt feature.
// Before running tests make sure that the broker of your choice is running.

namespace{

    int timeout = 1000;//in ms
    
    class HandleCallTask : public QRunnable
    {
    public:
        HandleCallTask(std::function<void()> func)
            :execute(func)
        {
        }

        void run() override
        {
            execute();
        }

    private:
        std::function<void()> execute;
    };

}

TEST_CASE("MQTT  testbed1 StructInterface tests")
{
    /** A ThreadPool to handle blocking functions in separate thread. By default the thread pool size is set to one to keep order of messages guaranteed */
    QThreadPool m_handleCallsThreads;
    m_handleCallsThreads.setMaxThreadCount(1);
    ApiGear::Mqtt::ServiceAdapter service("ServiceUniqueNameInMqtt");
    service.connectToHost("localhost", 1883);

    ApiGear::Mqtt::Client client("UniqueClientName");
    client.connectToHost("localhost", 1883);

    auto clientStructInterface = std::make_shared<testbed1::MqttStructInterface >(client);
    auto implStructInterface = std::make_shared<testbed1::StructInterface>();
    auto serviceStructInterface = std::make_shared<testbed1::MqttStructInterfaceAdapter>(service, implStructInterface);

    REQUIRE(QTest::qWaitFor([&client, &service]() {return client.isReady() && service.isReady(); }, timeout));
    REQUIRE(QTest::qWaitFor([&clientStructInterface, &serviceStructInterface]() {return clientStructInterface->isReady() && serviceStructInterface->isReady(); }, timeout));
    SECTION("Test setting propBool")
    {
        std::atomic<bool> ispropBoolChanged = false;
        clientStructInterface->connect(clientStructInterface.get(), &testbed1::AbstractStructInterface::propBoolChanged, [&ispropBoolChanged ](auto value){ispropBoolChanged  = true;});
        auto test_value = testbed1::StructBool();
        testbed1::fillTestStructBool(test_value);
        clientStructInterface->setPropBool(test_value);
        REQUIRE(QTest::qWaitFor([&ispropBoolChanged]() {return ispropBoolChanged  == true; }, timeout));
        REQUIRE(implStructInterface->propBool() == test_value);
        REQUIRE(clientStructInterface->propBool() == test_value);
    }
    SECTION("Test setting propInt")
    {
        std::atomic<bool> ispropIntChanged = false;
        clientStructInterface->connect(clientStructInterface.get(), &testbed1::AbstractStructInterface::propIntChanged, [&ispropIntChanged ](auto value){ispropIntChanged  = true;});
        auto test_value = testbed1::StructInt();
        testbed1::fillTestStructInt(test_value);
        clientStructInterface->setPropInt(test_value);
        REQUIRE(QTest::qWaitFor([&ispropIntChanged]() {return ispropIntChanged  == true; }, timeout));
        REQUIRE(implStructInterface->propInt() == test_value);
        REQUIRE(clientStructInterface->propInt() == test_value);
    }
    SECTION("Test setting propFloat")
    {
        std::atomic<bool> ispropFloatChanged = false;
        clientStructInterface->connect(clientStructInterface.get(), &testbed1::AbstractStructInterface::propFloatChanged, [&ispropFloatChanged ](auto value){ispropFloatChanged  = true;});
        auto test_value = testbed1::StructFloat();
        testbed1::fillTestStructFloat(test_value);
        clientStructInterface->setPropFloat(test_value);
        REQUIRE(QTest::qWaitFor([&ispropFloatChanged]() {return ispropFloatChanged  == true; }, timeout));
        REQUIRE(implStructInterface->propFloat() == test_value);
        REQUIRE(clientStructInterface->propFloat() == test_value);
    }
    SECTION("Test setting propString")
    {
        std::atomic<bool> ispropStringChanged = false;
        clientStructInterface->connect(clientStructInterface.get(), &testbed1::AbstractStructInterface::propStringChanged, [&ispropStringChanged ](auto value){ispropStringChanged  = true;});
        auto test_value = testbed1::StructString();
        testbed1::fillTestStructString(test_value);
        clientStructInterface->setPropString(test_value);
        REQUIRE(QTest::qWaitFor([&ispropStringChanged]() {return ispropStringChanged  == true; }, timeout));
        REQUIRE(implStructInterface->propString() == test_value);
        REQUIRE(clientStructInterface->propString() == test_value);
    }
    SECTION("Test emit sigBool")
    {
        std::atomic<bool> issigBoolEmitted = false;
        auto local_param_bool_struct = testbed1::StructBool();
        testbed1::fillTestStructBool(local_param_bool_struct);

        clientStructInterface->connect(clientStructInterface.get(), &testbed1::AbstractStructInterface::sigBool,
        [&issigBoolEmitted, &local_param_bool_struct](const testbed1::StructBool& paramBool)
        {
            REQUIRE(paramBool ==local_param_bool_struct);
            issigBoolEmitted  = true;
        });

        emit implStructInterface->sigBool(local_param_bool_struct);
        REQUIRE(QTest::qWaitFor([&issigBoolEmitted ]() {return issigBoolEmitted   == true; }, timeout));
    }
    SECTION("Test emit sigInt")
    {
        std::atomic<bool> issigIntEmitted = false;
        auto local_param_int_struct = testbed1::StructInt();
        testbed1::fillTestStructInt(local_param_int_struct);

        clientStructInterface->connect(clientStructInterface.get(), &testbed1::AbstractStructInterface::sigInt,
        [&issigIntEmitted, &local_param_int_struct](const testbed1::StructInt& paramInt)
        {
            REQUIRE(paramInt ==local_param_int_struct);
            issigIntEmitted  = true;
        });

        emit implStructInterface->sigInt(local_param_int_struct);
        REQUIRE(QTest::qWaitFor([&issigIntEmitted ]() {return issigIntEmitted   == true; }, timeout));
    }
    SECTION("Test emit sigFloat")
    {
        std::atomic<bool> issigFloatEmitted = false;
        auto local_param_float_struct = testbed1::StructFloat();
        testbed1::fillTestStructFloat(local_param_float_struct);

        clientStructInterface->connect(clientStructInterface.get(), &testbed1::AbstractStructInterface::sigFloat,
        [&issigFloatEmitted, &local_param_float_struct](const testbed1::StructFloat& paramFloat)
        {
            REQUIRE(paramFloat ==local_param_float_struct);
            issigFloatEmitted  = true;
        });

        emit implStructInterface->sigFloat(local_param_float_struct);
        REQUIRE(QTest::qWaitFor([&issigFloatEmitted ]() {return issigFloatEmitted   == true; }, timeout));
    }
    SECTION("Test emit sigString")
    {
        std::atomic<bool> issigStringEmitted = false;
        auto local_param_string_struct = testbed1::StructString();
        testbed1::fillTestStructString(local_param_string_struct);

        clientStructInterface->connect(clientStructInterface.get(), &testbed1::AbstractStructInterface::sigString,
        [&issigStringEmitted, &local_param_string_struct](const testbed1::StructString& paramString)
        {
            REQUIRE(paramString ==local_param_string_struct);
            issigStringEmitted  = true;
        });

        emit implStructInterface->sigString(local_param_string_struct);
        REQUIRE(QTest::qWaitFor([&issigStringEmitted ]() {return issigStringEmitted   == true; }, timeout));
    }
    SECTION("Test method funcBool")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientStructInterface, &finished](){
            [[maybe_unused]] auto result = clientStructInterface->funcBool(testbed1::StructBool());
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method funcBool async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = clientStructInterface->funcBoolAsync(testbed1::StructBool());
        resultFuture.then([&finished](testbed1::StructBool /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == testbed1::StructBool());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcInt")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientStructInterface, &finished](){
            [[maybe_unused]] auto result = clientStructInterface->funcInt(testbed1::StructInt());
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method funcInt async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = clientStructInterface->funcIntAsync(testbed1::StructInt());
        resultFuture.then([&finished](testbed1::StructInt /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == testbed1::StructInt());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcFloat")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientStructInterface, &finished](){
            [[maybe_unused]] auto result = clientStructInterface->funcFloat(testbed1::StructFloat());
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method funcFloat async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = clientStructInterface->funcFloatAsync(testbed1::StructFloat());
        resultFuture.then([&finished](testbed1::StructFloat /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == testbed1::StructFloat());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcString")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientStructInterface, &finished](){
            [[maybe_unused]] auto result = clientStructInterface->funcString(testbed1::StructString());
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method funcString async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = clientStructInterface->funcStringAsync(testbed1::StructString());
        resultFuture.then([&finished](testbed1::StructString /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == testbed1::StructString());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientStructInterface.reset();
    serviceStructInterface.reset();
    client.disconnect();
    service.disconnect();
}
