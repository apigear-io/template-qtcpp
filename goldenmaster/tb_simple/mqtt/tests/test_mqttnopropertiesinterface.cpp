#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>
#include <condition_variable>


#include <QtCore>
#include <QTest>
#include <QThreadPool>
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/nopropertiesinterface.h"
#include "mqtt/mqttnopropertiesinterface.h"
#include "mqtt/mqttnopropertiesinterfaceadapter.h"


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

TEST_CASE("MQTT  tb.simple NoPropertiesInterface tests")
{
    /** A ThreadPool to handle blocking functions in separate thread. By default the thread pool size is set to one to keep order of messages guaranteed */
    QThreadPool m_handleCallsThreads;
    m_handleCallsThreads.setMaxThreadCount(1);
    ApiGear::Mqtt::ServiceAdapter service("ServiceUniqueNameInMqtt");
    service.connectToHost("localhost", 1883);

    ApiGear::Mqtt::Client client("UniqueClientName");
    client.connectToHost("localhost", 1883);

    auto clientNoPropertiesInterface = std::make_shared<tb_simple::MqttNoPropertiesInterface >(client);
    auto implNoPropertiesInterface = std::make_shared<tb_simple::NoPropertiesInterface>();
    auto serviceNoPropertiesInterface = std::make_shared<tb_simple::MqttNoPropertiesInterfaceAdapter>(service, implNoPropertiesInterface);

    REQUIRE(QTest::qWaitFor([&client, &service]() {return client.isReady() && service.isReady(); }, timeout));
    REQUIRE(QTest::qWaitFor([&clientNoPropertiesInterface, &serviceNoPropertiesInterface]() {return clientNoPropertiesInterface->isReady() && serviceNoPropertiesInterface->isReady(); }, timeout));
    SECTION("Test emit sigVoid")
    {
        std::atomic<bool> issigVoidEmitted = false;

        clientNoPropertiesInterface->connect(clientNoPropertiesInterface.get(), &tb_simple::AbstractNoPropertiesInterface::sigVoid,
        [&issigVoidEmitted]()
        {
            issigVoidEmitted  = true;
        });

        emit implNoPropertiesInterface->sigVoid();
        REQUIRE(QTest::qWaitFor([&issigVoidEmitted ]() {return issigVoidEmitted   == true; }, timeout));
    }
    SECTION("Test emit sigBool")
    {
        std::atomic<bool> issigBoolEmitted = false;

        clientNoPropertiesInterface->connect(clientNoPropertiesInterface.get(), &tb_simple::AbstractNoPropertiesInterface::sigBool,
        [&issigBoolEmitted](bool paramBool)
        {
            REQUIRE(paramBool == true);
            issigBoolEmitted  = true;
        });

        emit implNoPropertiesInterface->sigBool(true);
        REQUIRE(QTest::qWaitFor([&issigBoolEmitted ]() {return issigBoolEmitted   == true; }, timeout));
    }
    SECTION("Test method funcVoid")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientNoPropertiesInterface, &finished](){
            clientNoPropertiesInterface->funcVoid();
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
        auto resultFuture = clientNoPropertiesInterface->funcVoidAsync();
        resultFuture.then([&finished](){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcBool")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientNoPropertiesInterface, &finished](){
            [[maybe_unused]] auto result = clientNoPropertiesInterface->funcBool(false);
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
        auto resultFuture = clientNoPropertiesInterface->funcBoolAsync(false);
        resultFuture.then([&finished](bool /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == false);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientNoPropertiesInterface.reset();
    serviceNoPropertiesInterface.reset();
    client.disconnect();
    service.disconnect();
}
