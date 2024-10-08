#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>
#include <condition_variable>


#include <QtCore>
#include <QTest>
#include <QThreadPool>
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/simplearrayinterface.h"
#include "mqtt/mqttsimplearrayinterface.h"
#include "mqtt/mqttsimplearrayinterfaceadapter.h"


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

TEST_CASE("MQTT  tb.simple SimpleArrayInterface tests")
{
    /** A ThreadPool to handle blocking functions in separate thread. By default the thread pool size is set to one to keep order of messages guaranteed */
    QThreadPool m_handleCallsThreads;
    m_handleCallsThreads.setMaxThreadCount(1);
    ApiGear::Mqtt::ServiceAdapter service("ServiceUniqueNameInMqtt");
    service.connectToHost("localhost", 1883);

    ApiGear::Mqtt::Client client("UniqueClientName");
    client.connectToHost("localhost", 1883);

    auto clientSimpleArrayInterface = std::make_shared<tb_simple::MqttSimpleArrayInterface >(client);
    auto implSimpleArrayInterface = std::make_shared<tb_simple::SimpleArrayInterface>();
    auto serviceSimpleArrayInterface = std::make_shared<tb_simple::MqttSimpleArrayInterfaceAdapter>(service, implSimpleArrayInterface);

    REQUIRE(QTest::qWaitFor([&client, &service]() {return client.isReady() && service.isReady(); }, timeout));
    REQUIRE(QTest::qWaitFor([&clientSimpleArrayInterface, &serviceSimpleArrayInterface]() {return clientSimpleArrayInterface->isReady() && serviceSimpleArrayInterface->isReady(); }, timeout));
    SECTION("Test setting propBool")
    {
        std::atomic<bool> ispropBoolChanged = false;
        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::propBoolChanged, [&ispropBoolChanged ](auto value){ispropBoolChanged  = true;});
        auto test_value = QList<bool>();  
        test_value.append(true);
        clientSimpleArrayInterface->setPropBool(test_value);
        REQUIRE(QTest::qWaitFor([&ispropBoolChanged]() {return ispropBoolChanged  == true; }, timeout));
        REQUIRE(implSimpleArrayInterface->propBool() == test_value);
        REQUIRE(clientSimpleArrayInterface->propBool() == test_value);
    }
    SECTION("Test setting propInt")
    {
        std::atomic<bool> ispropIntChanged = false;
        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::propIntChanged, [&ispropIntChanged ](auto value){ispropIntChanged  = true;});
        auto test_value = QList<int>();  
        test_value.append(1);
        clientSimpleArrayInterface->setPropInt(test_value);
        REQUIRE(QTest::qWaitFor([&ispropIntChanged]() {return ispropIntChanged  == true; }, timeout));
        REQUIRE(implSimpleArrayInterface->propInt() == test_value);
        REQUIRE(clientSimpleArrayInterface->propInt() == test_value);
    }
    SECTION("Test setting propInt32")
    {
        std::atomic<bool> ispropInt32Changed = false;
        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::propInt32Changed, [&ispropInt32Changed ](auto value){ispropInt32Changed  = true;});
        auto test_value = QList<qint32>();  
        test_value.append(1);
        clientSimpleArrayInterface->setPropInt32(test_value);
        REQUIRE(QTest::qWaitFor([&ispropInt32Changed]() {return ispropInt32Changed  == true; }, timeout));
        REQUIRE(implSimpleArrayInterface->propInt32() == test_value);
        REQUIRE(clientSimpleArrayInterface->propInt32() == test_value);
    }
    SECTION("Test setting propInt64")
    {
        std::atomic<bool> ispropInt64Changed = false;
        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::propInt64Changed, [&ispropInt64Changed ](auto value){ispropInt64Changed  = true;});
        auto test_value = QList<qint64>();  
        test_value.append(1LL);
        clientSimpleArrayInterface->setPropInt64(test_value);
        REQUIRE(QTest::qWaitFor([&ispropInt64Changed]() {return ispropInt64Changed  == true; }, timeout));
        REQUIRE(implSimpleArrayInterface->propInt64() == test_value);
        REQUIRE(clientSimpleArrayInterface->propInt64() == test_value);
    }
    SECTION("Test setting propFloat")
    {
        std::atomic<bool> ispropFloatChanged = false;
        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::propFloatChanged, [&ispropFloatChanged ](auto value){ispropFloatChanged  = true;});
        auto test_value = QList<qreal>();  
        test_value.append(1.1f);
        clientSimpleArrayInterface->setPropFloat(test_value);
        REQUIRE(QTest::qWaitFor([&ispropFloatChanged]() {return ispropFloatChanged  == true; }, timeout));
        REQUIRE(implSimpleArrayInterface->propFloat() == test_value);
        REQUIRE(clientSimpleArrayInterface->propFloat() == test_value);
    }
    SECTION("Test setting propFloat32")
    {
        std::atomic<bool> ispropFloat32Changed = false;
        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::propFloat32Changed, [&ispropFloat32Changed ](auto value){ispropFloat32Changed  = true;});
        auto test_value = QList<float>();  
        test_value.append(1.1f);
        clientSimpleArrayInterface->setPropFloat32(test_value);
        REQUIRE(QTest::qWaitFor([&ispropFloat32Changed]() {return ispropFloat32Changed  == true; }, timeout));
        REQUIRE(implSimpleArrayInterface->propFloat32() == test_value);
        REQUIRE(clientSimpleArrayInterface->propFloat32() == test_value);
    }
    SECTION("Test setting propFloat64")
    {
        std::atomic<bool> ispropFloat64Changed = false;
        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::propFloat64Changed, [&ispropFloat64Changed ](auto value){ispropFloat64Changed  = true;});
        auto test_value = QList<double>();  
        test_value.append(1.1);
        clientSimpleArrayInterface->setPropFloat64(test_value);
        REQUIRE(QTest::qWaitFor([&ispropFloat64Changed]() {return ispropFloat64Changed  == true; }, timeout));
        REQUIRE(implSimpleArrayInterface->propFloat64() == test_value);
        REQUIRE(clientSimpleArrayInterface->propFloat64() == test_value);
    }
    SECTION("Test setting propString")
    {
        std::atomic<bool> ispropStringChanged = false;
        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::propStringChanged, [&ispropStringChanged ](auto value){ispropStringChanged  = true;});
        auto test_value = QList<QString>();  
        test_value.append(QString("xyz"));
        clientSimpleArrayInterface->setPropString(test_value);
        REQUIRE(QTest::qWaitFor([&ispropStringChanged]() {return ispropStringChanged  == true; }, timeout));
        REQUIRE(implSimpleArrayInterface->propString() == test_value);
        REQUIRE(clientSimpleArrayInterface->propString() == test_value);
    }
    SECTION("Test emit sigBool")
    {
        std::atomic<bool> issigBoolEmitted = false;
        auto local_param_bool_array = QList<bool>();
        local_param_bool_array.append(true);

        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::sigBool,
        [&issigBoolEmitted, &local_param_bool_array](const QList<bool>& paramBool)
        {
            REQUIRE(paramBool == local_param_bool_array);
            issigBoolEmitted  = true;
        });

        emit implSimpleArrayInterface->sigBool(local_param_bool_array);
        REQUIRE(QTest::qWaitFor([&issigBoolEmitted ]() {return issigBoolEmitted   == true; }, timeout));
    }
    SECTION("Test emit sigInt")
    {
        std::atomic<bool> issigIntEmitted = false;
        auto local_param_int_array = QList<int>();
        local_param_int_array.append(1);

        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::sigInt,
        [&issigIntEmitted, &local_param_int_array](const QList<int>& paramInt)
        {
            REQUIRE(paramInt == local_param_int_array);
            issigIntEmitted  = true;
        });

        emit implSimpleArrayInterface->sigInt(local_param_int_array);
        REQUIRE(QTest::qWaitFor([&issigIntEmitted ]() {return issigIntEmitted   == true; }, timeout));
    }
    SECTION("Test emit sigInt32")
    {
        std::atomic<bool> issigInt32Emitted = false;
        auto local_param_int32_array = QList<qint32>();
        local_param_int32_array.append(1);

        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::sigInt32,
        [&issigInt32Emitted, &local_param_int32_array](const QList<qint32>& paramInt32)
        {
            REQUIRE(paramInt32 == local_param_int32_array);
            issigInt32Emitted  = true;
        });

        emit implSimpleArrayInterface->sigInt32(local_param_int32_array);
        REQUIRE(QTest::qWaitFor([&issigInt32Emitted ]() {return issigInt32Emitted   == true; }, timeout));
    }
    SECTION("Test emit sigInt64")
    {
        std::atomic<bool> issigInt64Emitted = false;
        auto local_param_int64_array = QList<qint64>();
        local_param_int64_array.append(1LL);

        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::sigInt64,
        [&issigInt64Emitted, &local_param_int64_array](const QList<qint64>& paramInt64)
        {
            REQUIRE(paramInt64 == local_param_int64_array);
            issigInt64Emitted  = true;
        });

        emit implSimpleArrayInterface->sigInt64(local_param_int64_array);
        REQUIRE(QTest::qWaitFor([&issigInt64Emitted ]() {return issigInt64Emitted   == true; }, timeout));
    }
    SECTION("Test emit sigFloat")
    {
        std::atomic<bool> issigFloatEmitted = false;
        auto local_param_float_array = QList<qreal>();
        local_param_float_array.append(1.1f);

        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::sigFloat,
        [&issigFloatEmitted, &local_param_float_array](const QList<qreal>& paramFloat)
        {
            REQUIRE(paramFloat == local_param_float_array);
            issigFloatEmitted  = true;
        });

        emit implSimpleArrayInterface->sigFloat(local_param_float_array);
        REQUIRE(QTest::qWaitFor([&issigFloatEmitted ]() {return issigFloatEmitted   == true; }, timeout));
    }
    SECTION("Test emit sigFloat32")
    {
        std::atomic<bool> issigFloat32Emitted = false;
        auto local_param_floa32_array = QList<float>();
        local_param_floa32_array.append(1.1f);

        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::sigFloat32,
        [&issigFloat32Emitted, &local_param_floa32_array](const QList<float>& paramFloa32)
        {
            REQUIRE(paramFloa32 == local_param_floa32_array);
            issigFloat32Emitted  = true;
        });

        emit implSimpleArrayInterface->sigFloat32(local_param_floa32_array);
        REQUIRE(QTest::qWaitFor([&issigFloat32Emitted ]() {return issigFloat32Emitted   == true; }, timeout));
    }
    SECTION("Test emit sigFloat64")
    {
        std::atomic<bool> issigFloat64Emitted = false;
        auto local_param_float64_array = QList<double>();
        local_param_float64_array.append(1.1);

        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::sigFloat64,
        [&issigFloat64Emitted, &local_param_float64_array](const QList<double>& paramFloat64)
        {
            REQUIRE(paramFloat64 == local_param_float64_array);
            issigFloat64Emitted  = true;
        });

        emit implSimpleArrayInterface->sigFloat64(local_param_float64_array);
        REQUIRE(QTest::qWaitFor([&issigFloat64Emitted ]() {return issigFloat64Emitted   == true; }, timeout));
    }
    SECTION("Test emit sigString")
    {
        std::atomic<bool> issigStringEmitted = false;
        auto local_param_string_array = QList<QString>();
        local_param_string_array.append(QString("xyz"));

        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::sigString,
        [&issigStringEmitted, &local_param_string_array](const QList<QString>& paramString)
        {
            REQUIRE(paramString == local_param_string_array);
            issigStringEmitted  = true;
        });

        emit implSimpleArrayInterface->sigString(local_param_string_array);
        REQUIRE(QTest::qWaitFor([&issigStringEmitted ]() {return issigStringEmitted   == true; }, timeout));
    }
    SECTION("Test method funcBool")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSimpleArrayInterface, &finished](){
            [[maybe_unused]] auto result = clientSimpleArrayInterface->funcBool(QList<bool>());
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
        auto resultFuture = clientSimpleArrayInterface->funcBoolAsync(QList<bool>());
        resultFuture.then([&finished](QList<bool> /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<bool>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcInt")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSimpleArrayInterface, &finished](){
            [[maybe_unused]] auto result = clientSimpleArrayInterface->funcInt(QList<int>());
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
        auto resultFuture = clientSimpleArrayInterface->funcIntAsync(QList<int>());
        resultFuture.then([&finished](QList<int> /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<int>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcInt32")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSimpleArrayInterface, &finished](){
            [[maybe_unused]] auto result = clientSimpleArrayInterface->funcInt32(QList<qint32>());
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
        auto resultFuture = clientSimpleArrayInterface->funcInt32Async(QList<qint32>());
        resultFuture.then([&finished](QList<qint32> /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<qint32>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcInt64")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSimpleArrayInterface, &finished](){
            [[maybe_unused]] auto result = clientSimpleArrayInterface->funcInt64(QList<qint64>());
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
        auto resultFuture = clientSimpleArrayInterface->funcInt64Async(QList<qint64>());
        resultFuture.then([&finished](QList<qint64> /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<qint64>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcFloat")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSimpleArrayInterface, &finished](){
            [[maybe_unused]] auto result = clientSimpleArrayInterface->funcFloat(QList<qreal>());
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
        auto resultFuture = clientSimpleArrayInterface->funcFloatAsync(QList<qreal>());
        resultFuture.then([&finished](QList<qreal> /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<qreal>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcFloat32")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSimpleArrayInterface, &finished](){
            [[maybe_unused]] auto result = clientSimpleArrayInterface->funcFloat32(QList<float>());
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
        auto resultFuture = clientSimpleArrayInterface->funcFloat32Async(QList<float>());
        resultFuture.then([&finished](QList<float> /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<float>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcFloat64")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSimpleArrayInterface, &finished](){
            [[maybe_unused]] auto result = clientSimpleArrayInterface->funcFloat64(QList<double>());
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
        auto resultFuture = clientSimpleArrayInterface->funcFloat64Async(QList<double>());
        resultFuture.then([&finished](QList<double> /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<double>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcString")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientSimpleArrayInterface, &finished](){
            [[maybe_unused]] auto result = clientSimpleArrayInterface->funcString(QList<QString>());
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
        auto resultFuture = clientSimpleArrayInterface->funcStringAsync(QList<QString>());
        resultFuture.then([&finished](QList<QString> /*res*/){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<QString>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientSimpleArrayInterface.reset();
    serviceSimpleArrayInterface.reset();
    client.disconnect();
    service.disconnect();
}
