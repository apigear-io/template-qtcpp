#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>
#include <condition_variable>


#include <QtCore>
#include <QTest>
#include <QThreadPool>
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/nooperationsinterface.h"
#include "mqtt/mqttnooperationsinterface.h"
#include "mqtt/mqttnooperationsinterfaceadapter.h"


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

TEST_CASE("MQTT  tb.simple NoOperationsInterface tests")
{
    ApiGear::Mqtt::ServiceAdapter service("ServiceUniqueNameInMqtt");
    service.connectToHost("localhost", 1883);

    ApiGear::Mqtt::Client client("UniqueClientName");
    client.connectToHost("localhost", 1883);

    auto clientNoOperationsInterface = std::make_shared<tb_simple::MqttNoOperationsInterface >(client);
    auto implNoOperationsInterface = std::make_shared<tb_simple::NoOperationsInterface>();
    auto serviceNoOperationsInterface = std::make_shared<tb_simple::MqttNoOperationsInterfaceAdapter>(service, implNoOperationsInterface);

    REQUIRE(QTest::qWaitFor([&client, &service]() {return client.isReady() && service.isReady(); }, timeout));
    REQUIRE(QTest::qWaitFor([&clientNoOperationsInterface, &serviceNoOperationsInterface]() {return clientNoOperationsInterface->isReady() && serviceNoOperationsInterface->isReady(); }, timeout));
    SECTION("Test setting propBool")
    {
        std::atomic<bool> ispropBoolChanged = false;
        clientNoOperationsInterface->connect(clientNoOperationsInterface.get(), &tb_simple::AbstractNoOperationsInterface::propBoolChanged, [&ispropBoolChanged ](auto value){ispropBoolChanged  = true;});
        auto test_value = true;
        clientNoOperationsInterface->setPropBool(test_value);
        REQUIRE(QTest::qWaitFor([&ispropBoolChanged]() {return ispropBoolChanged  == true; }, timeout));
        REQUIRE(implNoOperationsInterface->propBool() == test_value);
        REQUIRE(clientNoOperationsInterface->propBool() == test_value);
    }
    SECTION("Test setting propInt")
    {
        std::atomic<bool> ispropIntChanged = false;
        clientNoOperationsInterface->connect(clientNoOperationsInterface.get(), &tb_simple::AbstractNoOperationsInterface::propIntChanged, [&ispropIntChanged ](auto value){ispropIntChanged  = true;});
        auto test_value = 1;
        clientNoOperationsInterface->setPropInt(test_value);
        REQUIRE(QTest::qWaitFor([&ispropIntChanged]() {return ispropIntChanged  == true; }, timeout));
        REQUIRE(implNoOperationsInterface->propInt() == test_value);
        REQUIRE(clientNoOperationsInterface->propInt() == test_value);
    }
    SECTION("Test emit sigVoid")
    {
        std::atomic<bool> issigVoidEmitted = false;

        clientNoOperationsInterface->connect(clientNoOperationsInterface.get(), &tb_simple::AbstractNoOperationsInterface::sigVoid,
        [&issigVoidEmitted]()
        {
            issigVoidEmitted  = true;
        });

        emit implNoOperationsInterface->sigVoid();
        REQUIRE(QTest::qWaitFor([&issigVoidEmitted ]() {return issigVoidEmitted   == true; }, timeout));
    }
    SECTION("Test emit sigBool")
    {
        std::atomic<bool> issigBoolEmitted = false;

        clientNoOperationsInterface->connect(clientNoOperationsInterface.get(), &tb_simple::AbstractNoOperationsInterface::sigBool,
        [&issigBoolEmitted](bool paramBool)
        {
            REQUIRE(paramBool == true);
            issigBoolEmitted  = true;
        });

        emit implNoOperationsInterface->sigBool(true);
        REQUIRE(QTest::qWaitFor([&issigBoolEmitted ]() {return issigBoolEmitted   == true; }, timeout));
    }

    clientNoOperationsInterface.reset();
    serviceNoOperationsInterface.reset();
    client.disconnect();
    service.disconnect();
}
