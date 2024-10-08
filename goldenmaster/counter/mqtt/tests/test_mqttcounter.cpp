#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>
#include <condition_variable>


#include <QtCore>
#include <QTest>
#include <QThreadPool>
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/counter.h"
#include "mqtt/mqttcounter.h"
#include "mqtt/mqttcounteradapter.h"

#include "custom_types/api/test_struct_helper.h"
#include "extern_types/api/test_struct_helper.h"

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

TEST_CASE("MQTT  counter Counter tests")
{
    /** A ThreadPool to handle blocking functions in separate thread. By default the thread pool size is set to one to keep order of messages guaranteed */
    QThreadPool m_handleCallsThreads;
    m_handleCallsThreads.setMaxThreadCount(1);
    ApiGear::Mqtt::ServiceAdapter service("ServiceUniqueNameInMqtt");
    service.connectToHost("localhost", 1883);

    ApiGear::Mqtt::Client client("UniqueClientName");
    client.connectToHost("localhost", 1883);

    auto clientCounter = std::make_shared<counter::MqttCounter >(client);
    auto implCounter = std::make_shared<counter::Counter>();
    auto serviceCounter = std::make_shared<counter::MqttCounterAdapter>(service, implCounter);

    REQUIRE(QTest::qWaitFor([&client, &service]() {return client.isReady() && service.isReady(); }, timeout));
    REQUIRE(QTest::qWaitFor([&clientCounter, &serviceCounter]() {return clientCounter->isReady() && serviceCounter->isReady(); }, timeout));
    SECTION("Test setting vector")
    {
        std::atomic<bool> isvectorChanged = false;
        clientCounter->connect(clientCounter.get(), &counter::AbstractCounter::vectorChanged, [&isvectorChanged ](auto value){isvectorChanged  = true;});
        auto test_value = custom_types::Vector3D();
        custom_types::fillTestVector3D(test_value);
        clientCounter->setVector(test_value);
        REQUIRE(QTest::qWaitFor([&isvectorChanged]() {return isvectorChanged  == true; }, timeout));
        REQUIRE(implCounter->vector() == test_value);
        REQUIRE(clientCounter->vector() == test_value);
    }
    SECTION("Test method increment")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientCounter, &finished](){
            [[maybe_unused]] auto result = clientCounter->increment(QVector3D());
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method increment async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = clientCounter->incrementAsync(QVector3D());
        resultFuture.then([&finished](QVector3D /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QVector3D());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method decrement")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientCounter, &finished](){
            [[maybe_unused]] auto result = clientCounter->decrement(custom_types::Vector3D());
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method decrement async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = clientCounter->decrementAsync(custom_types::Vector3D());
        resultFuture.then([&finished](custom_types::Vector3D /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == custom_types::Vector3D());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientCounter.reset();
    serviceCounter.reset();
    client.disconnect();
    service.disconnect();
}
