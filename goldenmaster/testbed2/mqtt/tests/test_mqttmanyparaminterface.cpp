#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>
#include <condition_variable>


#include <QtCore>
#include <QTest>
#include <QThreadPool>
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/manyparaminterface.h"
#include "mqtt/mqttmanyparaminterface.h"
#include "mqtt/mqttmanyparaminterfaceadapter.h"


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

TEST_CASE("MQTT  testbed2 ManyParamInterface tests")
{
    /** A ThreadPool to handle blocking functions in separate thread. By default the thread pool size is set to one to keep order of messages guaranteed */
    QThreadPool m_handleCallsThreads;
    m_handleCallsThreads.setMaxThreadCount(1);
    ApiGear::Mqtt::ServiceAdapter service("ServiceUniqueNameInMqtt");
    service.connectToHost("localhost", 1883);

    ApiGear::Mqtt::Client client("UniqueClientName");
    client.connectToHost("localhost", 1883);

    auto clientManyParamInterface = std::make_shared<testbed2::MqttManyParamInterface >(client);
    auto implManyParamInterface = std::make_shared<testbed2::ManyParamInterface>();
    auto serviceManyParamInterface = std::make_shared<testbed2::MqttManyParamInterfaceAdapter>(service, implManyParamInterface);

    REQUIRE(QTest::qWaitFor([&client, &service]() {return client.isReady() && service.isReady(); }, timeout));
    REQUIRE(QTest::qWaitFor([&clientManyParamInterface, &serviceManyParamInterface]() {return clientManyParamInterface->isReady() && serviceManyParamInterface->isReady(); }, timeout));
    SECTION("Test setting prop1")
    {
        std::atomic<bool> isprop1Changed = false;
        clientManyParamInterface->connect(clientManyParamInterface.get(), &testbed2::AbstractManyParamInterface::prop1Changed, [&isprop1Changed ](auto value){isprop1Changed  = true;});
        auto test_value = 1;
        clientManyParamInterface->setProp1(test_value);
        REQUIRE(QTest::qWaitFor([&isprop1Changed]() {return isprop1Changed  == true; }, timeout));
        REQUIRE(implManyParamInterface->prop1() == test_value);
        REQUIRE(clientManyParamInterface->prop1() == test_value);
    }
    SECTION("Test setting prop2")
    {
        std::atomic<bool> isprop2Changed = false;
        clientManyParamInterface->connect(clientManyParamInterface.get(), &testbed2::AbstractManyParamInterface::prop2Changed, [&isprop2Changed ](auto value){isprop2Changed  = true;});
        auto test_value = 1;
        clientManyParamInterface->setProp2(test_value);
        REQUIRE(QTest::qWaitFor([&isprop2Changed]() {return isprop2Changed  == true; }, timeout));
        REQUIRE(implManyParamInterface->prop2() == test_value);
        REQUIRE(clientManyParamInterface->prop2() == test_value);
    }
    SECTION("Test setting prop3")
    {
        std::atomic<bool> isprop3Changed = false;
        clientManyParamInterface->connect(clientManyParamInterface.get(), &testbed2::AbstractManyParamInterface::prop3Changed, [&isprop3Changed ](auto value){isprop3Changed  = true;});
        auto test_value = 1;
        clientManyParamInterface->setProp3(test_value);
        REQUIRE(QTest::qWaitFor([&isprop3Changed]() {return isprop3Changed  == true; }, timeout));
        REQUIRE(implManyParamInterface->prop3() == test_value);
        REQUIRE(clientManyParamInterface->prop3() == test_value);
    }
    SECTION("Test setting prop4")
    {
        std::atomic<bool> isprop4Changed = false;
        clientManyParamInterface->connect(clientManyParamInterface.get(), &testbed2::AbstractManyParamInterface::prop4Changed, [&isprop4Changed ](auto value){isprop4Changed  = true;});
        auto test_value = 1;
        clientManyParamInterface->setProp4(test_value);
        REQUIRE(QTest::qWaitFor([&isprop4Changed]() {return isprop4Changed  == true; }, timeout));
        REQUIRE(implManyParamInterface->prop4() == test_value);
        REQUIRE(clientManyParamInterface->prop4() == test_value);
    }
    SECTION("Test emit sig1")
    {
        std::atomic<bool> issig1Emitted = false;

        clientManyParamInterface->connect(clientManyParamInterface.get(), &testbed2::AbstractManyParamInterface::sig1,
        [&issig1Emitted](int param1)
        {
            REQUIRE(param1 == 1);
            issig1Emitted  = true;
        });

        emit implManyParamInterface->sig1(1);
        REQUIRE(QTest::qWaitFor([&issig1Emitted ]() {return issig1Emitted   == true; }, timeout));
    }
    SECTION("Test emit sig2")
    {
        std::atomic<bool> issig2Emitted = false;

        clientManyParamInterface->connect(clientManyParamInterface.get(), &testbed2::AbstractManyParamInterface::sig2,
        [&issig2Emitted](int param1, int param2)
        {
            REQUIRE(param1 == 1);
            REQUIRE(param2 == 1);
            issig2Emitted  = true;
        });

        emit implManyParamInterface->sig2(1, 1);
        REQUIRE(QTest::qWaitFor([&issig2Emitted ]() {return issig2Emitted   == true; }, timeout));
    }
    SECTION("Test emit sig3")
    {
        std::atomic<bool> issig3Emitted = false;

        clientManyParamInterface->connect(clientManyParamInterface.get(), &testbed2::AbstractManyParamInterface::sig3,
        [&issig3Emitted](int param1, int param2, int param3)
        {
            REQUIRE(param1 == 1);
            REQUIRE(param2 == 1);
            REQUIRE(param3 == 1);
            issig3Emitted  = true;
        });

        emit implManyParamInterface->sig3(1, 1, 1);
        REQUIRE(QTest::qWaitFor([&issig3Emitted ]() {return issig3Emitted   == true; }, timeout));
    }
    SECTION("Test emit sig4")
    {
        std::atomic<bool> issig4Emitted = false;

        clientManyParamInterface->connect(clientManyParamInterface.get(), &testbed2::AbstractManyParamInterface::sig4,
        [&issig4Emitted](int param1, int param2, int param3, int param4)
        {
            REQUIRE(param1 == 1);
            REQUIRE(param2 == 1);
            REQUIRE(param3 == 1);
            REQUIRE(param4 == 1);
            issig4Emitted  = true;
        });

        emit implManyParamInterface->sig4(1, 1, 1, 1);
        REQUIRE(QTest::qWaitFor([&issig4Emitted ]() {return issig4Emitted   == true; }, timeout));
    }
    SECTION("Test method func1")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientManyParamInterface, &finished](){
            [[maybe_unused]] auto result = clientManyParamInterface->func1(0);
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
        auto resultFuture = clientManyParamInterface->func1Async(0);
        resultFuture.then([&finished](int /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == 0);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method func2")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientManyParamInterface, &finished](){
            [[maybe_unused]] auto result = clientManyParamInterface->func2(0, 0);
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
        auto resultFuture = clientManyParamInterface->func2Async(0, 0);
        resultFuture.then([&finished](int /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == 0);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method func3")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientManyParamInterface, &finished](){
            [[maybe_unused]] auto result = clientManyParamInterface->func3(0, 0, 0);
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
        auto resultFuture = clientManyParamInterface->func3Async(0, 0, 0);
        resultFuture.then([&finished](int /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == 0);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method func4")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientManyParamInterface, &finished](){
            [[maybe_unused]] auto result = clientManyParamInterface->func4(0, 0, 0, 0);
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method func4 async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = clientManyParamInterface->func4Async(0, 0, 0, 0);
        resultFuture.then([&finished](int /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == 0);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientManyParamInterface.reset();
    serviceManyParamInterface.reset();
    client.disconnect();
    service.disconnect();
}
