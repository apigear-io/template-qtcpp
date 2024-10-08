#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>
#include <condition_variable>


#include <QtCore>
#include <QTest>
#include <QThreadPool>
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/samestruct1interface.h"
#include "mqtt/mqttsamestruct1interface.h"
#include "mqtt/mqttsamestruct1interfaceadapter.h"


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

TEST_CASE("MQTT  tb.same2 SameStruct1Interface tests")
{
    /** A ThreadPool to handle blocking functions in separate thread. By default the thread pool size is set to one to keep order of messages guaranteed */
    QThreadPool m_handleCallsThreads;
    m_handleCallsThreads.setMaxThreadCount(1);
    ApiGear::Mqtt::ServiceAdapter service("ServiceUniqueNameInMqtt");
    service.connectToHost("localhost", 1883);

    ApiGear::Mqtt::Client client("UniqueClientName");
    client.connectToHost("localhost", 1883);

    auto clientSameStruct1Interface = std::make_shared<tb_same2::MqttSameStruct1Interface >(client);
    auto implSameStruct1Interface = std::make_shared<tb_same2::SameStruct1Interface>();
    auto serviceSameStruct1Interface = std::make_shared<tb_same2::MqttSameStruct1InterfaceAdapter>(service, implSameStruct1Interface);

    REQUIRE(QTest::qWaitFor([&client, &service]() {return client.isReady() && service.isReady(); }, timeout));
    REQUIRE(QTest::qWaitFor([&clientSameStruct1Interface, &serviceSameStruct1Interface]() {return clientSameStruct1Interface->isReady() && serviceSameStruct1Interface->isReady(); }, timeout));
    SECTION("Test setting prop1")
    {
        std::atomic<bool> isprop1Changed = false;
        clientSameStruct1Interface->connect(clientSameStruct1Interface.get(), &tb_same2::AbstractSameStruct1Interface::prop1Changed, [&isprop1Changed ](auto value){isprop1Changed  = true;});
        auto test_value = tb_same2::Struct1();
        tb_same2::fillTestStruct1(test_value);
        clientSameStruct1Interface->setProp1(test_value);
        REQUIRE(QTest::qWaitFor([&isprop1Changed]() {return isprop1Changed  == true; }, timeout));
        REQUIRE(implSameStruct1Interface->prop1() == test_value);
        REQUIRE(clientSameStruct1Interface->prop1() == test_value);
    }
    SECTION("Test emit sig1")
    {
        std::atomic<bool> issig1Emitted = false;
        auto local_param1_struct = tb_same2::Struct1();
        tb_same2::fillTestStruct1(local_param1_struct);

        clientSameStruct1Interface->connect(clientSameStruct1Interface.get(), &tb_same2::AbstractSameStruct1Interface::sig1,
        [&issig1Emitted, &local_param1_struct](const tb_same2::Struct1& param1)
        {
            REQUIRE(param1 ==local_param1_struct);
            issig1Emitted  = true;
        });

        emit implSameStruct1Interface->sig1(local_param1_struct);
        REQUIRE(QTest::qWaitFor([&issig1Emitted ]() {return issig1Emitted   == true; }, timeout));
    }
    SECTION("Test method func1")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSameStruct1Interface, &finished](){
            [[maybe_unused]] auto result = clientSameStruct1Interface->func1(tb_same2::Struct1());
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
        auto resultFuture = clientSameStruct1Interface->func1Async(tb_same2::Struct1());
        resultFuture.then([&finished](tb_same2::Struct1 /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == tb_same2::Struct1());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientSameStruct1Interface.reset();
    serviceSameStruct1Interface.reset();
    client.disconnect();
    service.disconnect();
}
