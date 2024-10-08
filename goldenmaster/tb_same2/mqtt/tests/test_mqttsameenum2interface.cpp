#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>
#include <condition_variable>


#include <QtCore>
#include <QTest>
#include <QThreadPool>
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/sameenum2interface.h"
#include "mqtt/mqttsameenum2interface.h"
#include "mqtt/mqttsameenum2interfaceadapter.h"


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

TEST_CASE("MQTT  tb.same2 SameEnum2Interface tests")
{
    /** A ThreadPool to handle blocking functions in separate thread. By default the thread pool size is set to one to keep order of messages guaranteed */
    QThreadPool m_handleCallsThreads;
    m_handleCallsThreads.setMaxThreadCount(1);
    ApiGear::Mqtt::ServiceAdapter service("ServiceUniqueNameInMqtt");
    service.connectToHost("localhost", 1883);

    ApiGear::Mqtt::Client client("UniqueClientName");
    client.connectToHost("localhost", 1883);

    auto clientSameEnum2Interface = std::make_shared<tb_same2::MqttSameEnum2Interface >(client);
    auto implSameEnum2Interface = std::make_shared<tb_same2::SameEnum2Interface>();
    auto serviceSameEnum2Interface = std::make_shared<tb_same2::MqttSameEnum2InterfaceAdapter>(service, implSameEnum2Interface);

    REQUIRE(QTest::qWaitFor([&client, &service]() {return client.isReady() && service.isReady(); }, timeout));
    REQUIRE(QTest::qWaitFor([&clientSameEnum2Interface, &serviceSameEnum2Interface]() {return clientSameEnum2Interface->isReady() && serviceSameEnum2Interface->isReady(); }, timeout));
    SECTION("Test setting prop1")
    {
        std::atomic<bool> isprop1Changed = false;
        clientSameEnum2Interface->connect(clientSameEnum2Interface.get(), &tb_same2::AbstractSameEnum2Interface::prop1Changed, [&isprop1Changed ](auto value){isprop1Changed  = true;});
        auto test_value = tb_same2::Enum1::Value2;
        clientSameEnum2Interface->setProp1(test_value);
        REQUIRE(QTest::qWaitFor([&isprop1Changed]() {return isprop1Changed  == true; }, timeout));
        REQUIRE(implSameEnum2Interface->prop1() == test_value);
        REQUIRE(clientSameEnum2Interface->prop1() == test_value);
    }
    SECTION("Test setting prop2")
    {
        std::atomic<bool> isprop2Changed = false;
        clientSameEnum2Interface->connect(clientSameEnum2Interface.get(), &tb_same2::AbstractSameEnum2Interface::prop2Changed, [&isprop2Changed ](auto value){isprop2Changed  = true;});
        auto test_value = tb_same2::Enum2::Value2;
        clientSameEnum2Interface->setProp2(test_value);
        REQUIRE(QTest::qWaitFor([&isprop2Changed]() {return isprop2Changed  == true; }, timeout));
        REQUIRE(implSameEnum2Interface->prop2() == test_value);
        REQUIRE(clientSameEnum2Interface->prop2() == test_value);
    }
    SECTION("Test emit sig1")
    {
        std::atomic<bool> issig1Emitted = false;

        clientSameEnum2Interface->connect(clientSameEnum2Interface.get(), &tb_same2::AbstractSameEnum2Interface::sig1,
        [&issig1Emitted](tb_same2::Enum1::Enum1Enum param1)
        {
            REQUIRE(param1 == tb_same2::Enum1::Value2);
            issig1Emitted  = true;
        });

        emit implSameEnum2Interface->sig1(tb_same2::Enum1::Value2);
        REQUIRE(QTest::qWaitFor([&issig1Emitted ]() {return issig1Emitted   == true; }, timeout));
    }
    SECTION("Test emit sig2")
    {
        std::atomic<bool> issig2Emitted = false;

        clientSameEnum2Interface->connect(clientSameEnum2Interface.get(), &tb_same2::AbstractSameEnum2Interface::sig2,
        [&issig2Emitted](tb_same2::Enum1::Enum1Enum param1, tb_same2::Enum2::Enum2Enum param2)
        {
            REQUIRE(param1 == tb_same2::Enum1::Value2);
            REQUIRE(param2 == tb_same2::Enum2::Value2);
            issig2Emitted  = true;
        });

        emit implSameEnum2Interface->sig2(tb_same2::Enum1::Value2, tb_same2::Enum2::Value2);
        REQUIRE(QTest::qWaitFor([&issig2Emitted ]() {return issig2Emitted   == true; }, timeout));
    }
    SECTION("Test method func1")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSameEnum2Interface, &finished](){
            [[maybe_unused]] auto result = clientSameEnum2Interface->func1(tb_same2::Enum1::Value1);
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
        auto resultFuture = clientSameEnum2Interface->func1Async(tb_same2::Enum1::Value1);
        resultFuture.then([&finished](tb_same2::Enum1::Enum1Enum /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == tb_same2::Enum1::Value1);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method func2")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSameEnum2Interface, &finished](){
            [[maybe_unused]] auto result = clientSameEnum2Interface->func2(tb_same2::Enum1::Value1, tb_same2::Enum2::Value1);
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
        auto resultFuture = clientSameEnum2Interface->func2Async(tb_same2::Enum1::Value1, tb_same2::Enum2::Value1);
        resultFuture.then([&finished](tb_same2::Enum1::Enum1Enum /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == tb_same2::Enum1::Value1);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientSameEnum2Interface.reset();
    serviceSameEnum2Interface.reset();
    client.disconnect();
    service.disconnect();
}
