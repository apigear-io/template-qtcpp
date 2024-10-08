#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>
#include <condition_variable>


#include <QtCore>
#include <QTest>
#include <QThreadPool>
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/enuminterface.h"
#include "mqtt/mqttenuminterface.h"
#include "mqtt/mqttenuminterfaceadapter.h"


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

TEST_CASE("MQTT  tb.enum EnumInterface tests")
{
    /** A ThreadPool to handle blocking functions in separate thread. By default the thread pool size is set to one to keep order of messages guaranteed */
    QThreadPool m_handleCallsThreads;
    m_handleCallsThreads.setMaxThreadCount(1);
    ApiGear::Mqtt::ServiceAdapter service("ServiceUniqueNameInMqtt");
    service.connectToHost("localhost", 1883);

    ApiGear::Mqtt::Client client("UniqueClientName");
    client.connectToHost("localhost", 1883);

    auto clientEnumInterface = std::make_shared<tb_enum::MqttEnumInterface >(client);
    auto implEnumInterface = std::make_shared<tb_enum::EnumInterface>();
    auto serviceEnumInterface = std::make_shared<tb_enum::MqttEnumInterfaceAdapter>(service, implEnumInterface);

    REQUIRE(QTest::qWaitFor([&client, &service]() {return client.isReady() && service.isReady(); }, timeout));
    REQUIRE(QTest::qWaitFor([&clientEnumInterface, &serviceEnumInterface]() {return clientEnumInterface->isReady() && serviceEnumInterface->isReady(); }, timeout));
    SECTION("Test setting prop0")
    {
        std::atomic<bool> isprop0Changed = false;
        clientEnumInterface->connect(clientEnumInterface.get(), &tb_enum::AbstractEnumInterface::prop0Changed, [&isprop0Changed ](auto value){isprop0Changed  = true;});
        auto test_value = tb_enum::Enum0::Value1;
        clientEnumInterface->setProp0(test_value);
        REQUIRE(QTest::qWaitFor([&isprop0Changed]() {return isprop0Changed  == true; }, timeout));
        REQUIRE(implEnumInterface->prop0() == test_value);
        REQUIRE(clientEnumInterface->prop0() == test_value);
    }
    SECTION("Test setting prop1")
    {
        std::atomic<bool> isprop1Changed = false;
        clientEnumInterface->connect(clientEnumInterface.get(), &tb_enum::AbstractEnumInterface::prop1Changed, [&isprop1Changed ](auto value){isprop1Changed  = true;});
        auto test_value = tb_enum::Enum1::Value2;
        clientEnumInterface->setProp1(test_value);
        REQUIRE(QTest::qWaitFor([&isprop1Changed]() {return isprop1Changed  == true; }, timeout));
        REQUIRE(implEnumInterface->prop1() == test_value);
        REQUIRE(clientEnumInterface->prop1() == test_value);
    }
    SECTION("Test setting prop2")
    {
        std::atomic<bool> isprop2Changed = false;
        clientEnumInterface->connect(clientEnumInterface.get(), &tb_enum::AbstractEnumInterface::prop2Changed, [&isprop2Changed ](auto value){isprop2Changed  = true;});
        auto test_value = tb_enum::Enum2::Value1;
        clientEnumInterface->setProp2(test_value);
        REQUIRE(QTest::qWaitFor([&isprop2Changed]() {return isprop2Changed  == true; }, timeout));
        REQUIRE(implEnumInterface->prop2() == test_value);
        REQUIRE(clientEnumInterface->prop2() == test_value);
    }
    SECTION("Test setting prop3")
    {
        std::atomic<bool> isprop3Changed = false;
        clientEnumInterface->connect(clientEnumInterface.get(), &tb_enum::AbstractEnumInterface::prop3Changed, [&isprop3Changed ](auto value){isprop3Changed  = true;});
        auto test_value = tb_enum::Enum3::Value2;
        clientEnumInterface->setProp3(test_value);
        REQUIRE(QTest::qWaitFor([&isprop3Changed]() {return isprop3Changed  == true; }, timeout));
        REQUIRE(implEnumInterface->prop3() == test_value);
        REQUIRE(clientEnumInterface->prop3() == test_value);
    }
    SECTION("Test emit sig0")
    {
        std::atomic<bool> issig0Emitted = false;

        clientEnumInterface->connect(clientEnumInterface.get(), &tb_enum::AbstractEnumInterface::sig0,
        [&issig0Emitted](tb_enum::Enum0::Enum0Enum param0)
        {
            REQUIRE(param0 == tb_enum::Enum0::Value1);
            issig0Emitted  = true;
        });

        emit implEnumInterface->sig0(tb_enum::Enum0::Value1);
        REQUIRE(QTest::qWaitFor([&issig0Emitted ]() {return issig0Emitted   == true; }, timeout));
    }
    SECTION("Test emit sig1")
    {
        std::atomic<bool> issig1Emitted = false;

        clientEnumInterface->connect(clientEnumInterface.get(), &tb_enum::AbstractEnumInterface::sig1,
        [&issig1Emitted](tb_enum::Enum1::Enum1Enum param1)
        {
            REQUIRE(param1 == tb_enum::Enum1::Value2);
            issig1Emitted  = true;
        });

        emit implEnumInterface->sig1(tb_enum::Enum1::Value2);
        REQUIRE(QTest::qWaitFor([&issig1Emitted ]() {return issig1Emitted   == true; }, timeout));
    }
    SECTION("Test emit sig2")
    {
        std::atomic<bool> issig2Emitted = false;

        clientEnumInterface->connect(clientEnumInterface.get(), &tb_enum::AbstractEnumInterface::sig2,
        [&issig2Emitted](tb_enum::Enum2::Enum2Enum param2)
        {
            REQUIRE(param2 == tb_enum::Enum2::Value1);
            issig2Emitted  = true;
        });

        emit implEnumInterface->sig2(tb_enum::Enum2::Value1);
        REQUIRE(QTest::qWaitFor([&issig2Emitted ]() {return issig2Emitted   == true; }, timeout));
    }
    SECTION("Test emit sig3")
    {
        std::atomic<bool> issig3Emitted = false;

        clientEnumInterface->connect(clientEnumInterface.get(), &tb_enum::AbstractEnumInterface::sig3,
        [&issig3Emitted](tb_enum::Enum3::Enum3Enum param3)
        {
            REQUIRE(param3 == tb_enum::Enum3::Value2);
            issig3Emitted  = true;
        });

        emit implEnumInterface->sig3(tb_enum::Enum3::Value2);
        REQUIRE(QTest::qWaitFor([&issig3Emitted ]() {return issig3Emitted   == true; }, timeout));
    }
    SECTION("Test method func0")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientEnumInterface, &finished](){
            [[maybe_unused]] auto result = clientEnumInterface->func0(tb_enum::Enum0::Value0);
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method func0 async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = clientEnumInterface->func0Async(tb_enum::Enum0::Value0);
        resultFuture.then([&finished](tb_enum::Enum0::Enum0Enum /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == tb_enum::Enum0::Value0);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method func1")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientEnumInterface, &finished](){
            [[maybe_unused]] auto result = clientEnumInterface->func1(tb_enum::Enum1::Value1);
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
        auto resultFuture = clientEnumInterface->func1Async(tb_enum::Enum1::Value1);
        resultFuture.then([&finished](tb_enum::Enum1::Enum1Enum /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == tb_enum::Enum1::Value1);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method func2")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientEnumInterface, &finished](){
            [[maybe_unused]] auto result = clientEnumInterface->func2(tb_enum::Enum2::Value2);
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
        auto resultFuture = clientEnumInterface->func2Async(tb_enum::Enum2::Value2);
        resultFuture.then([&finished](tb_enum::Enum2::Enum2Enum /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == tb_enum::Enum2::Value2);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method func3")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientEnumInterface, &finished](){
            [[maybe_unused]] auto result = clientEnumInterface->func3(tb_enum::Enum3::Value3);
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
        auto resultFuture = clientEnumInterface->func3Async(tb_enum::Enum3::Value3);
        resultFuture.then([&finished](tb_enum::Enum3::Enum3Enum /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == tb_enum::Enum3::Value3);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientEnumInterface.reset();
    serviceEnumInterface.reset();
    client.disconnect();
    service.disconnect();
}
