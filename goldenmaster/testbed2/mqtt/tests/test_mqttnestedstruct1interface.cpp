#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>
#include <condition_variable>


#include <QtCore>
#include <QTest>
#include <QThreadPool>
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/nestedstruct1interface.h"
#include "mqtt/mqttnestedstruct1interface.h"
#include "mqtt/mqttnestedstruct1interfaceadapter.h"


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

TEST_CASE("MQTT  testbed2 NestedStruct1Interface tests")
{
    /** A ThreadPool to handle blocking functions in separate thread. By default the thread pool size is set to one to keep order of messages guaranteed */
    QThreadPool m_handleCallsThreads;
    m_handleCallsThreads.setMaxThreadCount(1);
    ApiGear::Mqtt::ServiceAdapter service("ServiceUniqueNameInMqtt");
    service.connectToHost("localhost", 1883);

    ApiGear::Mqtt::Client client("UniqueClientName");
    client.connectToHost("localhost", 1883);

    auto clientNestedStruct1Interface = std::make_shared<testbed2::MqttNestedStruct1Interface >(client);
    auto implNestedStruct1Interface = std::make_shared<testbed2::NestedStruct1Interface>();
    auto serviceNestedStruct1Interface = std::make_shared<testbed2::MqttNestedStruct1InterfaceAdapter>(service, implNestedStruct1Interface);

    REQUIRE(QTest::qWaitFor([&client, &service]() {return client.isReady() && service.isReady(); }, timeout));
    REQUIRE(QTest::qWaitFor([&clientNestedStruct1Interface, &serviceNestedStruct1Interface]() {return clientNestedStruct1Interface->isReady() && serviceNestedStruct1Interface->isReady(); }, timeout));
    SECTION("Test setting prop1")
    {
        std::atomic<bool> isprop1Changed = false;
        clientNestedStruct1Interface->connect(clientNestedStruct1Interface.get(), &testbed2::AbstractNestedStruct1Interface::prop1Changed, [&isprop1Changed ](auto value){isprop1Changed  = true;});
        auto test_value = testbed2::NestedStruct1();
        testbed2::fillTestNestedStruct1(test_value);
        clientNestedStruct1Interface->setProp1(test_value);
        REQUIRE(QTest::qWaitFor([&isprop1Changed]() {return isprop1Changed  == true; }, timeout));
        REQUIRE(implNestedStruct1Interface->prop1() == test_value);
        REQUIRE(clientNestedStruct1Interface->prop1() == test_value);
    }
    SECTION("Test emit sig1")
    {
        std::atomic<bool> issig1Emitted = false;
        auto local_param1_struct = testbed2::NestedStruct1();
        testbed2::fillTestNestedStruct1(local_param1_struct);

        clientNestedStruct1Interface->connect(clientNestedStruct1Interface.get(), &testbed2::AbstractNestedStruct1Interface::sig1,
        [&issig1Emitted, &local_param1_struct](const testbed2::NestedStruct1& param1)
        {
            REQUIRE(param1 ==local_param1_struct);
            issig1Emitted  = true;
        });

        emit implNestedStruct1Interface->sig1(local_param1_struct);
        REQUIRE(QTest::qWaitFor([&issig1Emitted ]() {return issig1Emitted   == true; }, timeout));
    }
    SECTION("Test method func1")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientNestedStruct1Interface, &finished](){
            [[maybe_unused]] auto result = clientNestedStruct1Interface->func1(testbed2::NestedStruct1());
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
        auto resultFuture = clientNestedStruct1Interface->func1Async(testbed2::NestedStruct1());
        resultFuture.then([&finished](testbed2::NestedStruct1 /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == testbed2::NestedStruct1());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientNestedStruct1Interface.reset();
    serviceNestedStruct1Interface.reset();
    client.disconnect();
    service.disconnect();
}
