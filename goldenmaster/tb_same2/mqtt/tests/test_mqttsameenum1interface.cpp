#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>
#include <condition_variable>


#include <QtCore>
#include <QTest>
#include <QThreadPool>
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/sameenum1interface.h"
#include "mqtt/mqttsameenum1interface.h"
#include "mqtt/mqttsameenum1interfaceadapter.h"


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

TEST_CASE("MQTT  tb.same2 SameEnum1Interface tests")
{
    /** A ThreadPool to handle blocking functions in separate thread. By default the thread pool size is set to one to keep order of messages guaranteed */
    QThreadPool m_handleCallsThreads;
    m_handleCallsThreads.setMaxThreadCount(1);
    ApiGear::Mqtt::ServiceAdapter service("ServiceUniqueNameInMqtt");
    service.connectToHost("localhost", 1883);

    ApiGear::Mqtt::Client client("UniqueClientName");
    client.connectToHost("localhost", 1883);

    auto clientSameEnum1Interface = std::make_shared<tb_same2::MqttSameEnum1Interface >(client);
    auto implSameEnum1Interface = std::make_shared<tb_same2::SameEnum1Interface>();
    auto serviceSameEnum1Interface = std::make_shared<tb_same2::MqttSameEnum1InterfaceAdapter>(service, implSameEnum1Interface);

    REQUIRE(QTest::qWaitFor([&client, &service]() {return client.isReady() && service.isReady(); }, timeout));
    REQUIRE(QTest::qWaitFor([&clientSameEnum1Interface, &serviceSameEnum1Interface]() {return clientSameEnum1Interface->isReady() && serviceSameEnum1Interface->isReady(); }, timeout));
    SECTION("Test setting prop1")
    {
        std::atomic<bool> isprop1Changed = false;
        clientSameEnum1Interface->connect(clientSameEnum1Interface.get(), &tb_same2::AbstractSameEnum1Interface::prop1Changed, [&isprop1Changed ](auto value){isprop1Changed  = true;});
        auto test_value = tb_same2::Enum1::Value2;
        clientSameEnum1Interface->setProp1(test_value);
        REQUIRE(QTest::qWaitFor([&isprop1Changed]() {return isprop1Changed  == true; }, timeout));
        REQUIRE(implSameEnum1Interface->prop1() == test_value);
        REQUIRE(clientSameEnum1Interface->prop1() == test_value);
    }
    SECTION("Test emit sig1")
    {
        std::atomic<bool> issig1Emitted = false;

        clientSameEnum1Interface->connect(clientSameEnum1Interface.get(), &tb_same2::AbstractSameEnum1Interface::sig1,
        [&issig1Emitted](tb_same2::Enum1::Enum1Enum param1)
        {
            REQUIRE(param1 == tb_same2::Enum1::Value2);
            issig1Emitted  = true;
        });

        emit implSameEnum1Interface->sig1(tb_same2::Enum1::Value2);
        REQUIRE(QTest::qWaitFor([&issig1Emitted ]() {return issig1Emitted   == true; }, timeout));
    }
    SECTION("Test method func1")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSameEnum1Interface, &finished](){
            [[maybe_unused]] auto result = clientSameEnum1Interface->func1(tb_same2::Enum1::Value1);
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
        auto resultFuture = clientSameEnum1Interface->func1Async(tb_same2::Enum1::Value1);
        resultFuture.then([&finished](tb_same2::Enum1::Enum1Enum /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == tb_same2::Enum1::Value1);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientSameEnum1Interface.reset();
    serviceSameEnum1Interface.reset();
    client.disconnect();
    service.disconnect();
}
