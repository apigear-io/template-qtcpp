#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>
#include <condition_variable>


#include <QtCore>
#include <QTest>
#include <QThreadPool>
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/nosignalsinterface.h"
#include "mqtt/mqttnosignalsinterface.h"
#include "mqtt/mqttnosignalsinterfaceadapter.h"


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

TEST_CASE("MQTT  tb.simple NoSignalsInterface tests")
{
    /** A ThreadPool to handle blocking functions in separate thread. By default the thread pool size is set to one to keep order of messages guaranteed */
    QThreadPool m_handleCallsThreads;
    m_handleCallsThreads.setMaxThreadCount(1);
    ApiGear::Mqtt::ServiceAdapter service("ServiceUniqueNameInMqtt");
    service.connectToHost("localhost", 1883);

    ApiGear::Mqtt::Client client("UniqueClientName");
    client.connectToHost("localhost", 1883);

    auto clientNoSignalsInterface = std::make_shared<tb_simple::MqttNoSignalsInterface >(client);
    auto implNoSignalsInterface = std::make_shared<tb_simple::NoSignalsInterface>();
    auto serviceNoSignalsInterface = std::make_shared<tb_simple::MqttNoSignalsInterfaceAdapter>(service, implNoSignalsInterface);

    REQUIRE(QTest::qWaitFor([&client, &service]() {return client.isReady() && service.isReady(); }, timeout));
    REQUIRE(QTest::qWaitFor([&clientNoSignalsInterface, &serviceNoSignalsInterface]() {return clientNoSignalsInterface->isReady() && serviceNoSignalsInterface->isReady(); }, timeout));
    SECTION("Test setting propBool")
    {
        std::atomic<bool> ispropBoolChanged = false;
        clientNoSignalsInterface->connect(clientNoSignalsInterface.get(), &tb_simple::AbstractNoSignalsInterface::propBoolChanged, [&ispropBoolChanged ](auto value){ispropBoolChanged  = true;});
        auto test_value = true;
        clientNoSignalsInterface->setPropBool(test_value);
        REQUIRE(QTest::qWaitFor([&ispropBoolChanged]() {return ispropBoolChanged  == true; }, timeout));
        REQUIRE(implNoSignalsInterface->propBool() == test_value);
        REQUIRE(clientNoSignalsInterface->propBool() == test_value);
    }
    SECTION("Test setting propInt")
    {
        std::atomic<bool> ispropIntChanged = false;
        clientNoSignalsInterface->connect(clientNoSignalsInterface.get(), &tb_simple::AbstractNoSignalsInterface::propIntChanged, [&ispropIntChanged ](auto value){ispropIntChanged  = true;});
        auto test_value = 1;
        clientNoSignalsInterface->setPropInt(test_value);
        REQUIRE(QTest::qWaitFor([&ispropIntChanged]() {return ispropIntChanged  == true; }, timeout));
        REQUIRE(implNoSignalsInterface->propInt() == test_value);
        REQUIRE(clientNoSignalsInterface->propInt() == test_value);
    }
    SECTION("Test method funcVoid")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientNoSignalsInterface, &finished](){
            clientNoSignalsInterface->funcVoid();
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method funcVoid async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = clientNoSignalsInterface->funcVoidAsync();
        resultFuture.then([&finished](){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcBool")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientNoSignalsInterface, &finished](){
            [[maybe_unused]] auto result = clientNoSignalsInterface->funcBool(false);
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
        auto resultFuture = clientNoSignalsInterface->funcBoolAsync(false);
        resultFuture.then([&finished](bool /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == false);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientNoSignalsInterface.reset();
    serviceNoSignalsInterface.reset();
    client.disconnect();
    service.disconnect();
}
