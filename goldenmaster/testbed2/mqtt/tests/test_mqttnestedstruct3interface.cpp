#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>
#include <condition_variable>


#include <QtCore>
#include <QTest>
#include <QThreadPool>
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/nestedstruct3interface.h"
#include "mqtt/mqttnestedstruct3interface.h"
#include "mqtt/mqttnestedstruct3interfaceadapter.h"


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

TEST_CASE("MQTT  testbed2 NestedStruct3Interface tests")
{
    /** A ThreadPool to handle blocking functions in separate thread. By default the thread pool size is set to one to keep order of messages guaranteed */
    QThreadPool m_handleCallsThreads;
    m_handleCallsThreads.setMaxThreadCount(1);
    ApiGear::Mqtt::ServiceAdapter service("ServiceUniqueNameInMqtt");
    service.connectToHost("localhost", 1883);

    ApiGear::Mqtt::Client client("UniqueClientName");
    client.connectToHost("localhost", 1883);

    auto clientNestedStruct3Interface = std::make_shared<testbed2::MqttNestedStruct3Interface >(client);
    auto implNestedStruct3Interface = std::make_shared<testbed2::NestedStruct3Interface>();
    auto serviceNestedStruct3Interface = std::make_shared<testbed2::MqttNestedStruct3InterfaceAdapter>(service, implNestedStruct3Interface);

    REQUIRE(QTest::qWaitFor([&client, &service]() {return client.isReady() && service.isReady(); }, timeout));
    REQUIRE(QTest::qWaitFor([&clientNestedStruct3Interface, &serviceNestedStruct3Interface]() {return clientNestedStruct3Interface->isReady() && serviceNestedStruct3Interface->isReady(); }, timeout));
    SECTION("Test setting prop1")
    {
        std::atomic<bool> isprop1Changed = false;
        clientNestedStruct3Interface->connect(clientNestedStruct3Interface.get(), &testbed2::AbstractNestedStruct3Interface::prop1Changed, [&isprop1Changed ](auto value){isprop1Changed  = true;});
        auto test_value = testbed2::NestedStruct1();
        testbed2::fillTestNestedStruct1(test_value);
        clientNestedStruct3Interface->setProp1(test_value);
        REQUIRE(QTest::qWaitFor([&isprop1Changed]() {return isprop1Changed  == true; }, timeout));
        REQUIRE(implNestedStruct3Interface->prop1() == test_value);
        REQUIRE(clientNestedStruct3Interface->prop1() == test_value);
    }
    SECTION("Test setting prop2")
    {
        std::atomic<bool> isprop2Changed = false;
        clientNestedStruct3Interface->connect(clientNestedStruct3Interface.get(), &testbed2::AbstractNestedStruct3Interface::prop2Changed, [&isprop2Changed ](auto value){isprop2Changed  = true;});
        auto test_value = testbed2::NestedStruct2();
        testbed2::fillTestNestedStruct2(test_value);
        clientNestedStruct3Interface->setProp2(test_value);
        REQUIRE(QTest::qWaitFor([&isprop2Changed]() {return isprop2Changed  == true; }, timeout));
        REQUIRE(implNestedStruct3Interface->prop2() == test_value);
        REQUIRE(clientNestedStruct3Interface->prop2() == test_value);
    }
    SECTION("Test setting prop3")
    {
        std::atomic<bool> isprop3Changed = false;
        clientNestedStruct3Interface->connect(clientNestedStruct3Interface.get(), &testbed2::AbstractNestedStruct3Interface::prop3Changed, [&isprop3Changed ](auto value){isprop3Changed  = true;});
        auto test_value = testbed2::NestedStruct3();
        testbed2::fillTestNestedStruct3(test_value);
        clientNestedStruct3Interface->setProp3(test_value);
        REQUIRE(QTest::qWaitFor([&isprop3Changed]() {return isprop3Changed  == true; }, timeout));
        REQUIRE(implNestedStruct3Interface->prop3() == test_value);
        REQUIRE(clientNestedStruct3Interface->prop3() == test_value);
    }
    SECTION("Test emit sig1")
    {
        std::atomic<bool> issig1Emitted = false;
        auto local_param1_struct = testbed2::NestedStruct1();
        testbed2::fillTestNestedStruct1(local_param1_struct);

        clientNestedStruct3Interface->connect(clientNestedStruct3Interface.get(), &testbed2::AbstractNestedStruct3Interface::sig1,
        [&issig1Emitted, &local_param1_struct](const testbed2::NestedStruct1& param1)
        {
            REQUIRE(param1 ==local_param1_struct);
            issig1Emitted  = true;
        });

        emit implNestedStruct3Interface->sig1(local_param1_struct);
        REQUIRE(QTest::qWaitFor([&issig1Emitted ]() {return issig1Emitted   == true; }, timeout));
    }
    SECTION("Test emit sig2")
    {
        std::atomic<bool> issig2Emitted = false;
        auto local_param1_struct = testbed2::NestedStruct1();
        testbed2::fillTestNestedStruct1(local_param1_struct);
        auto local_param2_struct = testbed2::NestedStruct2();
        testbed2::fillTestNestedStruct2(local_param2_struct);

        clientNestedStruct3Interface->connect(clientNestedStruct3Interface.get(), &testbed2::AbstractNestedStruct3Interface::sig2,
        [&issig2Emitted, &local_param1_struct, &local_param2_struct](const testbed2::NestedStruct1& param1, const testbed2::NestedStruct2& param2)
        {
            REQUIRE(param1 ==local_param1_struct);
            REQUIRE(param2 ==local_param2_struct);
            issig2Emitted  = true;
        });

        emit implNestedStruct3Interface->sig2(local_param1_struct, local_param2_struct);
        REQUIRE(QTest::qWaitFor([&issig2Emitted ]() {return issig2Emitted   == true; }, timeout));
    }
    SECTION("Test emit sig3")
    {
        std::atomic<bool> issig3Emitted = false;
        auto local_param1_struct = testbed2::NestedStruct1();
        testbed2::fillTestNestedStruct1(local_param1_struct);
        auto local_param2_struct = testbed2::NestedStruct2();
        testbed2::fillTestNestedStruct2(local_param2_struct);
        auto local_param3_struct = testbed2::NestedStruct3();
        testbed2::fillTestNestedStruct3(local_param3_struct);

        clientNestedStruct3Interface->connect(clientNestedStruct3Interface.get(), &testbed2::AbstractNestedStruct3Interface::sig3,
        [&issig3Emitted, &local_param1_struct, &local_param2_struct, &local_param3_struct](const testbed2::NestedStruct1& param1, const testbed2::NestedStruct2& param2, const testbed2::NestedStruct3& param3)
        {
            REQUIRE(param1 ==local_param1_struct);
            REQUIRE(param2 ==local_param2_struct);
            REQUIRE(param3 ==local_param3_struct);
            issig3Emitted  = true;
        });

        emit implNestedStruct3Interface->sig3(local_param1_struct, local_param2_struct, local_param3_struct);
        REQUIRE(QTest::qWaitFor([&issig3Emitted ]() {return issig3Emitted   == true; }, timeout));
    }
    SECTION("Test method func1")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientNestedStruct3Interface, &finished](){
            [[maybe_unused]] auto result = clientNestedStruct3Interface->func1(testbed2::NestedStruct1());
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method func1 async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = clientNestedStruct3Interface->func1Async(testbed2::NestedStruct1());
        resultFuture.then([&finished](testbed2::NestedStruct1 /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == testbed2::NestedStruct1());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method func2")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientNestedStruct3Interface, &finished](){
            [[maybe_unused]] auto result = clientNestedStruct3Interface->func2(testbed2::NestedStruct1(), testbed2::NestedStruct2());
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method func2 async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = clientNestedStruct3Interface->func2Async(testbed2::NestedStruct1(), testbed2::NestedStruct2());
        resultFuture.then([&finished](testbed2::NestedStruct1 /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == testbed2::NestedStruct1());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method func3")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientNestedStruct3Interface, &finished](){
            [[maybe_unused]] auto result = clientNestedStruct3Interface->func3(testbed2::NestedStruct1(), testbed2::NestedStruct2(), testbed2::NestedStruct3());
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method func3 async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = clientNestedStruct3Interface->func3Async(testbed2::NestedStruct1(), testbed2::NestedStruct2(), testbed2::NestedStruct3());
        resultFuture.then([&finished](testbed2::NestedStruct1 /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == testbed2::NestedStruct1());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientNestedStruct3Interface.reset();
    serviceNestedStruct3Interface.reset();
    client.disconnect();
    service.disconnect();
}
