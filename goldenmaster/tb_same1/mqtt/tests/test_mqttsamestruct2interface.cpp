#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>
#include <condition_variable>


#include <QtCore>
#include <QTest>
#include <QThreadPool>
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/samestruct2interface.h"
#include "mqtt/mqttsamestruct2interface.h"
#include "mqtt/mqttsamestruct2interfaceadapter.h"


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

TEST_CASE("MQTT  tb.same1 SameStruct2Interface tests")
{
    /** A ThreadPool to handle blocking functions in separate thread. By default the thread pool size is set to one to keep order of messages guaranteed */
    QThreadPool m_handleCallsThreads;
    m_handleCallsThreads.setMaxThreadCount(1);
    ApiGear::Mqtt::ServiceAdapter service("ServiceUniqueNameInMqtt");
    service.connectToHost("localhost", 1883);

    ApiGear::Mqtt::Client client("UniqueClientName");
    client.connectToHost("localhost", 1883);

    auto clientSameStruct2Interface = std::make_shared<tb_same1::MqttSameStruct2Interface >(client);
    auto implSameStruct2Interface = std::make_shared<tb_same1::SameStruct2Interface>();
    auto serviceSameStruct2Interface = std::make_shared<tb_same1::MqttSameStruct2InterfaceAdapter>(service, implSameStruct2Interface);

    REQUIRE(QTest::qWaitFor([&client, &service]() {return client.isReady() && service.isReady(); }, timeout));
    REQUIRE(QTest::qWaitFor([&clientSameStruct2Interface, &serviceSameStruct2Interface]() {return clientSameStruct2Interface->isReady() && serviceSameStruct2Interface->isReady(); }, timeout));
    SECTION("Test setting prop1")
    {
        std::atomic<bool> isprop1Changed = false;
        clientSameStruct2Interface->connect(clientSameStruct2Interface.get(), &tb_same1::AbstractSameStruct2Interface::prop1Changed, [&isprop1Changed ](auto value){isprop1Changed  = true;});
        auto test_value = tb_same1::Struct2();
        tb_same1::fillTestStruct2(test_value);
        clientSameStruct2Interface->setProp1(test_value);
        REQUIRE(QTest::qWaitFor([&isprop1Changed]() {return isprop1Changed  == true; }, timeout));
        REQUIRE(implSameStruct2Interface->prop1() == test_value);
        REQUIRE(clientSameStruct2Interface->prop1() == test_value);
    }
    SECTION("Test setting prop2")
    {
        std::atomic<bool> isprop2Changed = false;
        clientSameStruct2Interface->connect(clientSameStruct2Interface.get(), &tb_same1::AbstractSameStruct2Interface::prop2Changed, [&isprop2Changed ](auto value){isprop2Changed  = true;});
        auto test_value = tb_same1::Struct2();
        tb_same1::fillTestStruct2(test_value);
        clientSameStruct2Interface->setProp2(test_value);
        REQUIRE(QTest::qWaitFor([&isprop2Changed]() {return isprop2Changed  == true; }, timeout));
        REQUIRE(implSameStruct2Interface->prop2() == test_value);
        REQUIRE(clientSameStruct2Interface->prop2() == test_value);
    }
    SECTION("Test emit sig1")
    {
        std::atomic<bool> issig1Emitted = false;
        auto local_param1_struct = tb_same1::Struct1();
        tb_same1::fillTestStruct1(local_param1_struct);

        clientSameStruct2Interface->connect(clientSameStruct2Interface.get(), &tb_same1::AbstractSameStruct2Interface::sig1,
        [&issig1Emitted, &local_param1_struct](const tb_same1::Struct1& param1)
        {
            REQUIRE(param1 ==local_param1_struct);
            issig1Emitted  = true;
        });

        emit implSameStruct2Interface->sig1(local_param1_struct);
        REQUIRE(QTest::qWaitFor([&issig1Emitted ]() {return issig1Emitted   == true; }, timeout));
    }
    SECTION("Test emit sig2")
    {
        std::atomic<bool> issig2Emitted = false;
        auto local_param1_struct = tb_same1::Struct1();
        tb_same1::fillTestStruct1(local_param1_struct);
        auto local_param2_struct = tb_same1::Struct2();
        tb_same1::fillTestStruct2(local_param2_struct);

        clientSameStruct2Interface->connect(clientSameStruct2Interface.get(), &tb_same1::AbstractSameStruct2Interface::sig2,
        [&issig2Emitted, &local_param1_struct, &local_param2_struct](const tb_same1::Struct1& param1, const tb_same1::Struct2& param2)
        {
            REQUIRE(param1 ==local_param1_struct);
            REQUIRE(param2 ==local_param2_struct);
            issig2Emitted  = true;
        });

        emit implSameStruct2Interface->sig2(local_param1_struct, local_param2_struct);
        REQUIRE(QTest::qWaitFor([&issig2Emitted ]() {return issig2Emitted   == true; }, timeout));
    }
    SECTION("Test method func1")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSameStruct2Interface, &finished](){
            [[maybe_unused]] auto result = clientSameStruct2Interface->func1(tb_same1::Struct1());
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
        auto resultFuture = clientSameStruct2Interface->func1Async(tb_same1::Struct1());
        resultFuture.then([&finished](tb_same1::Struct1 /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == tb_same1::Struct1());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method func2")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSameStruct2Interface, &finished](){
            [[maybe_unused]] auto result = clientSameStruct2Interface->func2(tb_same1::Struct1(), tb_same1::Struct2());
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
        auto resultFuture = clientSameStruct2Interface->func2Async(tb_same1::Struct1(), tb_same1::Struct2());
        resultFuture.then([&finished](tb_same1::Struct1 /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == tb_same1::Struct1());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientSameStruct2Interface.reset();
    serviceSameStruct2Interface.reset();
    client.disconnect();
    service.disconnect();
}