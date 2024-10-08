#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>
#include <condition_variable>


#include <QtCore>
#include <QTest>
#include <QThreadPool>
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/simpleinterface.h"
#include "mqtt/mqttsimpleinterface.h"
#include "mqtt/mqttsimpleinterfaceadapter.h"


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

TEST_CASE("MQTT  tb.simple SimpleInterface tests")
{
    /** A ThreadPool to handle blocking functions in separate thread. By default the thread pool size is set to one to keep order of messages guaranteed */
    QThreadPool m_handleCallsThreads;
    m_handleCallsThreads.setMaxThreadCount(1);
    ApiGear::Mqtt::ServiceAdapter service("ServiceUniqueNameInMqtt");
    service.connectToHost("localhost", 1883);

    ApiGear::Mqtt::Client client("UniqueClientName");
    client.connectToHost("localhost", 1883);

    auto clientSimpleInterface = std::make_shared<tb_simple::MqttSimpleInterface >(client);
    auto implSimpleInterface = std::make_shared<tb_simple::SimpleInterface>();
    auto serviceSimpleInterface = std::make_shared<tb_simple::MqttSimpleInterfaceAdapter>(service, implSimpleInterface);

    REQUIRE(QTest::qWaitFor([&client, &service]() {return client.isReady() && service.isReady(); }, timeout));
    REQUIRE(QTest::qWaitFor([&clientSimpleInterface, &serviceSimpleInterface]() {return clientSimpleInterface->isReady() && serviceSimpleInterface->isReady(); }, timeout));
    SECTION("Test setting propBool")
    {
        std::atomic<bool> ispropBoolChanged = false;
        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::propBoolChanged, [&ispropBoolChanged ](auto value){ispropBoolChanged  = true;});
        auto test_value = true;
        clientSimpleInterface->setPropBool(test_value);
        REQUIRE(QTest::qWaitFor([&ispropBoolChanged]() {return ispropBoolChanged  == true; }, timeout));
        REQUIRE(implSimpleInterface->propBool() == test_value);
        REQUIRE(clientSimpleInterface->propBool() == test_value);
    }
    SECTION("Test setting propInt")
    {
        std::atomic<bool> ispropIntChanged = false;
        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::propIntChanged, [&ispropIntChanged ](auto value){ispropIntChanged  = true;});
        auto test_value = 1;
        clientSimpleInterface->setPropInt(test_value);
        REQUIRE(QTest::qWaitFor([&ispropIntChanged]() {return ispropIntChanged  == true; }, timeout));
        REQUIRE(implSimpleInterface->propInt() == test_value);
        REQUIRE(clientSimpleInterface->propInt() == test_value);
    }
    SECTION("Test setting propInt32")
    {
        std::atomic<bool> ispropInt32Changed = false;
        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::propInt32Changed, [&ispropInt32Changed ](auto value){ispropInt32Changed  = true;});
        auto test_value = 1;
        clientSimpleInterface->setPropInt32(test_value);
        REQUIRE(QTest::qWaitFor([&ispropInt32Changed]() {return ispropInt32Changed  == true; }, timeout));
        REQUIRE(implSimpleInterface->propInt32() == test_value);
        REQUIRE(clientSimpleInterface->propInt32() == test_value);
    }
    SECTION("Test setting propInt64")
    {
        std::atomic<bool> ispropInt64Changed = false;
        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::propInt64Changed, [&ispropInt64Changed ](auto value){ispropInt64Changed  = true;});
        auto test_value = 1LL;
        clientSimpleInterface->setPropInt64(test_value);
        REQUIRE(QTest::qWaitFor([&ispropInt64Changed]() {return ispropInt64Changed  == true; }, timeout));
        REQUIRE(implSimpleInterface->propInt64() == test_value);
        REQUIRE(clientSimpleInterface->propInt64() == test_value);
    }
    SECTION("Test setting propFloat")
    {
        std::atomic<bool> ispropFloatChanged = false;
        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::propFloatChanged, [&ispropFloatChanged ](auto value){ispropFloatChanged  = true;});
        auto test_value = 1.1f;
        clientSimpleInterface->setPropFloat(test_value);
        REQUIRE(QTest::qWaitFor([&ispropFloatChanged]() {return ispropFloatChanged  == true; }, timeout));
        REQUIRE(implSimpleInterface->propFloat() == test_value);
        REQUIRE(clientSimpleInterface->propFloat() == test_value);
    }
    SECTION("Test setting propFloat32")
    {
        std::atomic<bool> ispropFloat32Changed = false;
        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::propFloat32Changed, [&ispropFloat32Changed ](auto value){ispropFloat32Changed  = true;});
        auto test_value = 1.1f;
        clientSimpleInterface->setPropFloat32(test_value);
        REQUIRE(QTest::qWaitFor([&ispropFloat32Changed]() {return ispropFloat32Changed  == true; }, timeout));
        REQUIRE(implSimpleInterface->propFloat32() == test_value);
        REQUIRE(clientSimpleInterface->propFloat32() == test_value);
    }
    SECTION("Test setting propFloat64")
    {
        std::atomic<bool> ispropFloat64Changed = false;
        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::propFloat64Changed, [&ispropFloat64Changed ](auto value){ispropFloat64Changed  = true;});
        auto test_value = 1.1;
        clientSimpleInterface->setPropFloat64(test_value);
        REQUIRE(QTest::qWaitFor([&ispropFloat64Changed]() {return ispropFloat64Changed  == true; }, timeout));
        REQUIRE(implSimpleInterface->propFloat64() == test_value);
        REQUIRE(clientSimpleInterface->propFloat64() == test_value);
    }
    SECTION("Test setting propString")
    {
        std::atomic<bool> ispropStringChanged = false;
        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::propStringChanged, [&ispropStringChanged ](auto value){ispropStringChanged  = true;});
        auto test_value = QString("xyz");
        clientSimpleInterface->setPropString(test_value);
        REQUIRE(QTest::qWaitFor([&ispropStringChanged]() {return ispropStringChanged  == true; }, timeout));
        REQUIRE(implSimpleInterface->propString() == test_value);
        REQUIRE(clientSimpleInterface->propString() == test_value);
    }
    SECTION("Test emit sigBool")
    {
        std::atomic<bool> issigBoolEmitted = false;

        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::sigBool,
        [&issigBoolEmitted](bool paramBool)
        {
            REQUIRE(paramBool == true);
            issigBoolEmitted  = true;
        });

        emit implSimpleInterface->sigBool(true);
        REQUIRE(QTest::qWaitFor([&issigBoolEmitted ]() {return issigBoolEmitted   == true; }, timeout));
    }
    SECTION("Test emit sigInt")
    {
        std::atomic<bool> issigIntEmitted = false;

        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::sigInt,
        [&issigIntEmitted](int paramInt)
        {
            REQUIRE(paramInt == 1);
            issigIntEmitted  = true;
        });

        emit implSimpleInterface->sigInt(1);
        REQUIRE(QTest::qWaitFor([&issigIntEmitted ]() {return issigIntEmitted   == true; }, timeout));
    }
    SECTION("Test emit sigInt32")
    {
        std::atomic<bool> issigInt32Emitted = false;

        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::sigInt32,
        [&issigInt32Emitted](qint32 paramInt32)
        {
            REQUIRE(paramInt32 == 1);
            issigInt32Emitted  = true;
        });

        emit implSimpleInterface->sigInt32(1);
        REQUIRE(QTest::qWaitFor([&issigInt32Emitted ]() {return issigInt32Emitted   == true; }, timeout));
    }
    SECTION("Test emit sigInt64")
    {
        std::atomic<bool> issigInt64Emitted = false;

        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::sigInt64,
        [&issigInt64Emitted](qint64 paramInt64)
        {
            REQUIRE(paramInt64 == 1LL);
            issigInt64Emitted  = true;
        });

        emit implSimpleInterface->sigInt64(1LL);
        REQUIRE(QTest::qWaitFor([&issigInt64Emitted ]() {return issigInt64Emitted   == true; }, timeout));
    }
    SECTION("Test emit sigFloat")
    {
        std::atomic<bool> issigFloatEmitted = false;

        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::sigFloat,
        [&issigFloatEmitted](qreal paramFloat)
        {
            REQUIRE(paramFloat == 1.1f);
            issigFloatEmitted  = true;
        });

        emit implSimpleInterface->sigFloat(1.1f);
        REQUIRE(QTest::qWaitFor([&issigFloatEmitted ]() {return issigFloatEmitted   == true; }, timeout));
    }
    SECTION("Test emit sigFloat32")
    {
        std::atomic<bool> issigFloat32Emitted = false;

        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::sigFloat32,
        [&issigFloat32Emitted](float paramFloat32)
        {
            REQUIRE(paramFloat32 == 1.1f);
            issigFloat32Emitted  = true;
        });

        emit implSimpleInterface->sigFloat32(1.1f);
        REQUIRE(QTest::qWaitFor([&issigFloat32Emitted ]() {return issigFloat32Emitted   == true; }, timeout));
    }
    SECTION("Test emit sigFloat64")
    {
        std::atomic<bool> issigFloat64Emitted = false;

        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::sigFloat64,
        [&issigFloat64Emitted](double paramFloat64)
        {
            REQUIRE(paramFloat64 == 1.1);
            issigFloat64Emitted  = true;
        });

        emit implSimpleInterface->sigFloat64(1.1);
        REQUIRE(QTest::qWaitFor([&issigFloat64Emitted ]() {return issigFloat64Emitted   == true; }, timeout));
    }
    SECTION("Test emit sigString")
    {
        std::atomic<bool> issigStringEmitted = false;

        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::sigString,
        [&issigStringEmitted](const QString& paramString)
        {
            REQUIRE(paramString == QString("xyz"));
            issigStringEmitted  = true;
        });

        emit implSimpleInterface->sigString(QString("xyz"));
        REQUIRE(QTest::qWaitFor([&issigStringEmitted ]() {return issigStringEmitted   == true; }, timeout));
    }
    SECTION("Test method funcNoReturnValue")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSimpleInterface, &finished](){
            clientSimpleInterface->funcNoReturnValue(false);
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method funcNoReturnValue async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = clientSimpleInterface->funcNoReturnValueAsync(false);
        resultFuture.then([&finished](){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcBool")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSimpleInterface, &finished](){
            [[maybe_unused]] auto result = clientSimpleInterface->funcBool(false);
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
        auto resultFuture = clientSimpleInterface->funcBoolAsync(false);
        resultFuture.then([&finished](bool /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == false);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcInt")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSimpleInterface, &finished](){
            [[maybe_unused]] auto result = clientSimpleInterface->funcInt(0);
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method funcInt async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = clientSimpleInterface->funcIntAsync(0);
        resultFuture.then([&finished](int /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == 0);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcInt32")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSimpleInterface, &finished](){
            [[maybe_unused]] auto result = clientSimpleInterface->funcInt32(0);
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method funcInt32 async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = clientSimpleInterface->funcInt32Async(0);
        resultFuture.then([&finished](qint32 /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == 0);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcInt64")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSimpleInterface, &finished](){
            [[maybe_unused]] auto result = clientSimpleInterface->funcInt64(0LL);
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method funcInt64 async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = clientSimpleInterface->funcInt64Async(0LL);
        resultFuture.then([&finished](qint64 /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == 0LL);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcFloat")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSimpleInterface, &finished](){
            [[maybe_unused]] auto result = clientSimpleInterface->funcFloat(0.0f);
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method funcFloat async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = clientSimpleInterface->funcFloatAsync(0.0f);
        resultFuture.then([&finished](qreal /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == 0.0f);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcFloat32")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSimpleInterface, &finished](){
            [[maybe_unused]] auto result = clientSimpleInterface->funcFloat32(0.0f);
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method funcFloat32 async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = clientSimpleInterface->funcFloat32Async(0.0f);
        resultFuture.then([&finished](float /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == 0.0f);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcFloat64")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSimpleInterface, &finished](){
            [[maybe_unused]] auto result = clientSimpleInterface->funcFloat64(0.0);
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method funcFloat64 async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = clientSimpleInterface->funcFloat64Async(0.0);
        resultFuture.then([&finished](double /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == 0.0);
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcString")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSimpleInterface, &finished](){
            [[maybe_unused]] auto result = clientSimpleInterface->funcString(QString());
            finished = true;
        });
        task->setAutoDelete(true);
        m_handleCallsThreads.start(task);
        REQUIRE(QTest::qWaitFor([&finished ]() {return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE


    }
    SECTION("Test method funcString async")
    {
        std::atomic<bool> finished = false;
        auto resultFuture = clientSimpleInterface->funcStringAsync(QString());
        resultFuture.then([&finished](QString /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QString());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientSimpleInterface.reset();
    serviceSimpleInterface.reset();
    client.disconnect();
    service.disconnect();
}
