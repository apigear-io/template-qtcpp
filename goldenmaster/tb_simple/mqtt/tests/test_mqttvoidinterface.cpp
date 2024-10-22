#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>
#include <condition_variable>


#include <QtCore>
#include <QTest>
#include <QThreadPool>
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/voidinterface.h"
#include "mqtt/mqttvoidinterface.h"
#include "mqtt/mqttvoidinterfaceadapter.h"


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

TEST_CASE("MQTT  tb.simple VoidInterface tests")
{
    /** A ThreadPool to handle blocking functions in separate thread. By default the thread pool size is set to one to keep order of messages guaranteed */
    QThreadPool m_handleCallsThreads;
    m_handleCallsThreads.setMaxThreadCount(1);
    ApiGear::Mqtt::ServiceAdapter service("ServiceUniqueNameInMqtt");
    service.connectToHost("localhost", 1883);

    ApiGear::Mqtt::Client client("UniqueClientName");
    client.connectToHost("localhost", 1883);

    auto clientVoidInterface = std::make_shared<tb_simple::MqttVoidInterface >(client);
    auto implVoidInterface = std::make_shared<tb_simple::VoidInterface>();
    auto serviceVoidInterface = std::make_shared<tb_simple::MqttVoidInterfaceAdapter>(service, implVoidInterface);

    REQUIRE(QTest::qWaitFor([&client, &service]() {return client.isReady() && service.isReady(); }, timeout));
    REQUIRE(QTest::qWaitFor([&clientVoidInterface, &serviceVoidInterface]() {return clientVoidInterface->isReady() && serviceVoidInterface->isReady(); }, timeout));
    SECTION("Test emit sigVoid")
    {
        std::atomic<bool> issigVoidEmitted = false;

        clientVoidInterface->connect(clientVoidInterface.get(), &tb_simple::AbstractVoidInterface::sigVoid,
        [&issigVoidEmitted]()
        {
            issigVoidEmitted  = true;
        });

        emit implVoidInterface->sigVoid();
        REQUIRE(QTest::qWaitFor([&issigVoidEmitted ]() {return issigVoidEmitted   == true; }, timeout));
    }
    SECTION("Test method funcVoid")
    {
        std::atomic<bool> finished = false;
        auto* task = new HandleCallTask([clientVoidInterface, &finished](){
            clientVoidInterface->funcVoid();
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
        auto resultFuture = clientVoidInterface->funcVoidAsync();
        resultFuture.then([&finished](){finished = true;});
        REQUIRE(QTest::qWaitFor([&finished ](){ return finished == true; }, timeout));
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientVoidInterface.reset();
    serviceVoidInterface.reset();
    client.disconnect();
    service.disconnect();
}
