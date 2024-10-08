#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>
#include <condition_variable>


#include <QtCore>
#include <QTest>
#include <QThreadPool>
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/structarrayinterface.h"
#include "mqtt/mqttstructarrayinterface.h"
#include "mqtt/mqttstructarrayinterfaceadapter.h"


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

TEST_CASE("MQTT  testbed1 StructArrayInterface tests")
{
    /** A ThreadPool to handle blocking functions in separate thread. By default the thread pool size is set to one to keep order of messages guaranteed */
    QThreadPool m_handleCallsThreads;
    m_handleCallsThreads.setMaxThreadCount(1);
    ApiGear::Mqtt::ServiceAdapter service("ServiceUniqueNameInMqtt");
    service.connectToHost("localhost", 1883);

    ApiGear::Mqtt::Client client("UniqueClientName");
    client.connectToHost("localhost", 1883);

    auto clientStructArrayInterface = std::make_shared<testbed1::MqttStructArrayInterface >(client);
    auto implStructArrayInterface = std::make_shared<testbed1::StructArrayInterface>();
    auto serviceStructArrayInterface = std::make_shared<testbed1::MqttStructArrayInterfaceAdapter>(service, implStructArrayInterface);

    REQUIRE(QTest::qWaitFor([&client, &service]() {return client.isReady() && service.isReady(); }, timeout));
    REQUIRE(QTest::qWaitFor([&clientStructArrayInterface, &serviceStructArrayInterface]() {return clientStructArrayInterface->isReady() && serviceStructArrayInterface->isReady(); }, timeout));
    SECTION("Test setting propBool")
    {
        std::atomic<bool> ispropBoolChanged = false;
        clientStructArrayInterface->connect(clientStructArrayInterface.get(), &testbed1::AbstractStructArrayInterface::propBoolChanged, [&ispropBoolChanged ](auto value){ispropBoolChanged  = true;});
        auto test_value = QList<testbed1::StructBool>();
        auto element = testbed1::StructBool();
        testbed1::fillTestStructBool(element);
        test_value.append(element);
        clientStructArrayInterface->setPropBool(test_value);
        REQUIRE(QTest::qWaitFor([&ispropBoolChanged]() {return ispropBoolChanged  == true; }, timeout));
        REQUIRE(implStructArrayInterface->propBool() == test_value);
        REQUIRE(clientStructArrayInterface->propBool() == test_value);
    }
    SECTION("Test setting propInt")
    {
        std::atomic<bool> ispropIntChanged = false;
        clientStructArrayInterface->connect(clientStructArrayInterface.get(), &testbed1::AbstractStructArrayInterface::propIntChanged, [&ispropIntChanged ](auto value){ispropIntChanged  = true;});
        auto test_value = QList<testbed1::StructInt>();
        auto element = testbed1::StructInt();
        testbed1::fillTestStructInt(element);
        test_value.append(element);
        clientStructArrayInterface->setPropInt(test_value);
        REQUIRE(QTest::qWaitFor([&ispropIntChanged]() {return ispropIntChanged  == true; }, timeout));
        REQUIRE(implStructArrayInterface->propInt() == test_value);
        REQUIRE(clientStructArrayInterface->propInt() == test_value);
    }
    SECTION("Test setting propFloat")
    {
        std::atomic<bool> ispropFloatChanged = false;
        clientStructArrayInterface->connect(clientStructArrayInterface.get(), &testbed1::AbstractStructArrayInterface::propFloatChanged, [&ispropFloatChanged ](auto value){ispropFloatChanged  = true;});
        auto test_value = QList<testbed1::StructFloat>();
        auto element = testbed1::StructFloat();
        testbed1::fillTestStructFloat(element);
        test_value.append(element);
        clientStructArrayInterface->setPropFloat(test_value);
        REQUIRE(QTest::qWaitFor([&ispropFloatChanged]() {return ispropFloatChanged  == true; }, timeout));
        REQUIRE(implStructArrayInterface->propFloat() == test_value);
        REQUIRE(clientStructArrayInterface->propFloat() == test_value);
    }
    SECTION("Test setting propString")
    {
        std::atomic<bool> ispropStringChanged = false;
        clientStructArrayInterface->connect(clientStructArrayInterface.get(), &testbed1::AbstractStructArrayInterface::propStringChanged, [&ispropStringChanged ](auto value){ispropStringChanged  = true;});
        auto test_value = QList<testbed1::StructString>();
        auto element = testbed1::StructString();
        testbed1::fillTestStructString(element);
        test_value.append(element);
        clientStructArrayInterface->setPropString(test_value);
        REQUIRE(QTest::qWaitFor([&ispropStringChanged]() {return ispropStringChanged  == true; }, timeout));
        REQUIRE(implStructArrayInterface->propString() == test_value);
        REQUIRE(clientStructArrayInterface->propString() == test_value);
    }
    SECTION("Test emit sigBool")
    {
        std::atomic<bool> issigBoolEmitted = false;
        auto local_param_bool_array = QList<testbed1::StructBool>();
        auto element_paramBool = testbed1::StructBool();
        testbed1::fillTestStructBool(element_paramBool);
        local_param_bool_array .append(element_paramBool);

        clientStructArrayInterface->connect(clientStructArrayInterface.get(), &testbed1::AbstractStructArrayInterface::sigBool,
        [&issigBoolEmitted, &local_param_bool_array](const QList<testbed1::StructBool>& paramBool)
        {
            REQUIRE(paramBool == local_param_bool_array);
            issigBoolEmitted  = true;
        });

        emit implStructArrayInterface->sigBool(local_param_bool_array);
        REQUIRE(QTest::qWaitFor([&issigBoolEmitted ]() {return issigBoolEmitted   == true; }, timeout));
    }
    SECTION("Test emit sigInt")
    {
        std::atomic<bool> issigIntEmitted = false;
        auto local_param_int_array = QList<testbed1::StructInt>();
        auto element_paramInt = testbed1::StructInt();
        testbed1::fillTestStructInt(element_paramInt);
        local_param_int_array .append(element_paramInt);

        clientStructArrayInterface->connect(clientStructArrayInterface.get(), &testbed1::AbstractStructArrayInterface::sigInt,
        [&issigIntEmitted, &local_param_int_array](const QList<testbed1::StructInt>& paramInt)
        {
            REQUIRE(paramInt == local_param_int_array);
            issigIntEmitted  = true;
        });

        emit implStructArrayInterface->sigInt(local_param_int_array);
        REQUIRE(QTest::qWaitFor([&issigIntEmitted ]() {return issigIntEmitted   == true; }, timeout));
    }
    SECTION("Test emit sigFloat")
    {
        std::atomic<bool> issigFloatEmitted = false;
        auto local_param_float_array = QList<testbed1::StructFloat>();
        auto element_paramFloat = testbed1::StructFloat();
        testbed1::fillTestStructFloat(element_paramFloat);
        local_param_float_array .append(element_paramFloat);

        clientStructArrayInterface->connect(clientStructArrayInterface.get(), &testbed1::AbstractStructArrayInterface::sigFloat,
        [&issigFloatEmitted, &local_param_float_array](const QList<testbed1::StructFloat>& paramFloat)
        {
            REQUIRE(paramFloat == local_param_float_array);
            issigFloatEmitted  = true;
        });

        emit implStructArrayInterface->sigFloat(local_param_float_array);
        REQUIRE(QTest::qWaitFor([&issigFloatEmitted ]() {return issigFloatEmitted   == true; }, timeout));
    }
    SECTION("Test emit sigString")
    {
        std::atomic<bool> issigStringEmitted = false;
        auto local_param_string_array = QList<testbed1::StructString>();
        auto element_paramString = testbed1::StructString();
        testbed1::fillTestStructString(element_paramString);
        local_param_string_array .append(element_paramString);

        clientStructArrayInterface->connect(clientStructArrayInterface.get(), &testbed1::AbstractStructArrayInterface::sigString,
        [&issigStringEmitted, &local_param_string_array](const QList<testbed1::StructString>& paramString)
        {
            REQUIRE(paramString == local_param_string_array);
            issigStringEmitted  = true;
        });

        emit implStructArrayInterface->sigString(local_param_string_array);
        REQUIRE(QTest::qWaitFor([&issigStringEmitted ]() {return issigStringEmitted   == true; }, timeout));
    }
    SECTION("Test method funcBool")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientStructArrayInterface, &finished](){
            [[maybe_unused]] auto result = clientStructArrayInterface->funcBool(QList<testbed1::StructBool>());
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
        auto resultFuture = clientStructArrayInterface->funcBoolAsync(QList<testbed1::StructBool>());
        resultFuture.then([&finished](QList<testbed1::StructBool> /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<testbed1::StructBool>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcInt")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientStructArrayInterface, &finished](){
            [[maybe_unused]] auto result = clientStructArrayInterface->funcInt(QList<testbed1::StructInt>());
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
        auto resultFuture = clientStructArrayInterface->funcIntAsync(QList<testbed1::StructInt>());
        resultFuture.then([&finished](QList<testbed1::StructInt> /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<testbed1::StructInt>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcFloat")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientStructArrayInterface, &finished](){
            [[maybe_unused]] auto result = clientStructArrayInterface->funcFloat(QList<testbed1::StructFloat>());
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
        auto resultFuture = clientStructArrayInterface->funcFloatAsync(QList<testbed1::StructFloat>());
        resultFuture.then([&finished](QList<testbed1::StructFloat> /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<testbed1::StructFloat>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcString")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientStructArrayInterface, &finished](){
            [[maybe_unused]] auto result = clientStructArrayInterface->funcString(QList<testbed1::StructString>());
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
        auto resultFuture = clientStructArrayInterface->funcStringAsync(QList<testbed1::StructString>());
        resultFuture.then([&finished](QList<testbed1::StructString> /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<testbed1::StructString>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientStructArrayInterface.reset();
    serviceStructArrayInterface.reset();
    client.disconnect();
    service.disconnect();
}
