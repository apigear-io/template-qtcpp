#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>
#include <condition_variable>


#include <QtCore>
#include <QTest>
#include <QThreadPool>
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/nam_es.h"
#include "mqtt/mqttnam_es.h"
#include "mqtt/mqttnam_esadapter.h"


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

TEST_CASE("MQTT  tb.names NamEs tests")
{
    /** A ThreadPool to handle blocking functions in separate thread. By default the thread pool size is set to one to keep order of messages guaranteed */
    QThreadPool m_handleCallsThreads;
    m_handleCallsThreads.setMaxThreadCount(1);
    ApiGear::Mqtt::ServiceAdapter service("ServiceUniqueNameInMqtt");
    service.connectToHost("localhost", 1883);

    ApiGear::Mqtt::Client client("UniqueClientName");
    client.connectToHost("localhost", 1883);

    auto clientNamEs = std::make_shared<tb_names::MqttNam_Es >(client);
    auto implNamEs = std::make_shared<tb_names::NamEs>();
    auto serviceNamEs = std::make_shared<tb_names::MqttNam_EsAdapter>(service, implNamEs);

    REQUIRE(QTest::qWaitFor([&client, &service]() {return client.isReady() && service.isReady(); }, timeout));
    REQUIRE(QTest::qWaitFor([&clientNamEs, &serviceNamEs]() {return clientNamEs->isReady() && serviceNamEs->isReady(); }, timeout));
    SECTION("Test setting Switch")
    {
        std::atomic<bool> isSwitchChanged = false;
        clientNamEs->connect(clientNamEs.get(), &tb_names::AbstractNamEs::SwitchChanged, [&isSwitchChanged ](auto value){isSwitchChanged  = true;});
        auto test_value = true;
        clientNamEs->setSwitch(test_value);
        REQUIRE(QTest::qWaitFor([&isSwitchChanged]() {return isSwitchChanged  == true; }, timeout));
        REQUIRE(implNamEs->Switch() == test_value);
        REQUIRE(clientNamEs->Switch() == test_value);
    }
    SECTION("Test setting SOME_PROPERTY")
    {
        std::atomic<bool> isSOME_PROPERTYChanged = false;
        clientNamEs->connect(clientNamEs.get(), &tb_names::AbstractNamEs::SOME_PROPERTYChanged, [&isSOME_PROPERTYChanged ](auto value){isSOME_PROPERTYChanged  = true;});
        auto test_value = 1;
        clientNamEs->setSomeProperty(test_value);
        REQUIRE(QTest::qWaitFor([&isSOME_PROPERTYChanged]() {return isSOME_PROPERTYChanged  == true; }, timeout));
        REQUIRE(implNamEs->SOME_PROPERTY() == test_value);
        REQUIRE(clientNamEs->SOME_PROPERTY() == test_value);
    }
    SECTION("Test setting Some_Poperty2")
    {
        std::atomic<bool> isSome_Poperty2Changed = false;
        clientNamEs->connect(clientNamEs.get(), &tb_names::AbstractNamEs::Some_Poperty2Changed, [&isSome_Poperty2Changed ](auto value){isSome_Poperty2Changed  = true;});
        auto test_value = 1;
        clientNamEs->setSomePoperty2(test_value);
        REQUIRE(QTest::qWaitFor([&isSome_Poperty2Changed]() {return isSome_Poperty2Changed  == true; }, timeout));
        REQUIRE(implNamEs->Some_Poperty2() == test_value);
        REQUIRE(clientNamEs->Some_Poperty2() == test_value);
    }
    SECTION("Test emit SOME_SIGNAL")
    {
        std::atomic<bool> isSOME_SIGNALEmitted = false;

        clientNamEs->connect(clientNamEs.get(), &tb_names::AbstractNamEs::someSignal,
        [&isSOME_SIGNALEmitted](bool SOME_PARAM)
        {
            REQUIRE(SOME_PARAM == true);
            isSOME_SIGNALEmitted  = true;
        });

        emit implNamEs->someSignal(true);
        REQUIRE(QTest::qWaitFor([&isSOME_SIGNALEmitted ]() {return isSOME_SIGNALEmitted   == true; }, timeout));
    }
    SECTION("Test emit Some_Signal2")
    {
        std::atomic<bool> isSome_Signal2Emitted = false;

        clientNamEs->connect(clientNamEs.get(), &tb_names::AbstractNamEs::someSignal2,
        [&isSome_Signal2Emitted](bool Some_Param)
        {
            REQUIRE(Some_Param == true);
            isSome_Signal2Emitted  = true;
        });

        emit implNamEs->someSignal2(true);
        REQUIRE(QTest::qWaitFor([&isSome_Signal2Emitted ]() {return isSome_Signal2Emitted   == true; }, timeout));
    }
    SECTION("Test method SOME_FUNCTION")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientNamEs, &finished](){
            clientNamEs->someFunction(false);
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method SOME_FUNCTION async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = clientNamEs->someFunctionAsync(false);
        resultFuture.then([&finished](){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method Some_Function2")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientNamEs, &finished](){
            clientNamEs->someFunction2(false);
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method Some_Function2 async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = clientNamEs->someFunction2Async(false);
        resultFuture.then([&finished](){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientNamEs.reset();
    serviceNamEs.reset();
    client.disconnect();
    service.disconnect();
}
