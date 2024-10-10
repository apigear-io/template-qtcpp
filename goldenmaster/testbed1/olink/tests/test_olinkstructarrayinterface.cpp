#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>

#include <QtCore>
#include <QTest>
#include "olink/olinkstructarrayinterface.h"
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/structarrayinterface.h"
#include "olink/olinkstructarrayinterfaceadapter.h"


#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/remotenode.h"
#include "olink/olinkremote.h"
#include "olink/remoteregistry.h"

TEST_CASE("Olink  testbed1 StructArrayInterface tests")
{

    ClientRegistry client_registry;
    auto clientNode = ClientNode::create(client_registry);
    auto clientStructArrayInterface = std::make_shared< testbed1::OLinkStructArrayInterface>();

    RemoteRegistry remote_registry;
    auto remoteNode = ApiGear::ObjectLink::RemoteNode::createRemoteNode(remote_registry);
    auto implStructArrayInterface = std::make_shared< testbed1::StructArrayInterface>();
    auto serviceStructArrayInterface = std::make_shared< testbed1::OLinkStructArrayInterfaceAdapter>(remote_registry, implStructArrayInterface.get());
    remote_registry.addSource(serviceStructArrayInterface);

    remoteNode->onWrite([clientNode](std::string msg){clientNode->handleMessage(msg);});
    clientNode->onWrite([remoteNode](std::string msg){remoteNode->handleMessage(msg);});

    clientNode->registry().addSink(clientStructArrayInterface);
    clientNode->linkRemote(clientStructArrayInterface->olinkObjectName());
    SECTION("Test setting propBool")
    {
        bool ispropBoolChanged = false;
        clientStructArrayInterface->connect(clientStructArrayInterface.get(), &testbed1::AbstractStructArrayInterface::propBoolChanged, [&ispropBoolChanged ](auto value){ispropBoolChanged  = true;});
        auto test_value = QList<testbed1::StructBool>();
        auto element = testbed1::StructBool();
        testbed1::fillTestStructBool(element);
        test_value.append(element);
        clientStructArrayInterface->setPropBool(test_value);
        REQUIRE(ispropBoolChanged  == true);
        REQUIRE(implStructArrayInterface->propBool() == test_value);
        REQUIRE(clientStructArrayInterface->propBool() == test_value);
    }
    SECTION("Test setting propInt")
    {
        bool ispropIntChanged = false;
        clientStructArrayInterface->connect(clientStructArrayInterface.get(), &testbed1::AbstractStructArrayInterface::propIntChanged, [&ispropIntChanged ](auto value){ispropIntChanged  = true;});
        auto test_value = QList<testbed1::StructInt>();
        auto element = testbed1::StructInt();
        testbed1::fillTestStructInt(element);
        test_value.append(element);
        clientStructArrayInterface->setPropInt(test_value);
        REQUIRE(ispropIntChanged  == true);
        REQUIRE(implStructArrayInterface->propInt() == test_value);
        REQUIRE(clientStructArrayInterface->propInt() == test_value);
    }
    SECTION("Test setting propFloat")
    {
        bool ispropFloatChanged = false;
        clientStructArrayInterface->connect(clientStructArrayInterface.get(), &testbed1::AbstractStructArrayInterface::propFloatChanged, [&ispropFloatChanged ](auto value){ispropFloatChanged  = true;});
        auto test_value = QList<testbed1::StructFloat>();
        auto element = testbed1::StructFloat();
        testbed1::fillTestStructFloat(element);
        test_value.append(element);
        clientStructArrayInterface->setPropFloat(test_value);
        REQUIRE(ispropFloatChanged  == true);
        REQUIRE(implStructArrayInterface->propFloat() == test_value);
        REQUIRE(clientStructArrayInterface->propFloat() == test_value);
    }
    SECTION("Test setting propString")
    {
        bool ispropStringChanged = false;
        clientStructArrayInterface->connect(clientStructArrayInterface.get(), &testbed1::AbstractStructArrayInterface::propStringChanged, [&ispropStringChanged ](auto value){ispropStringChanged  = true;});
        auto test_value = QList<testbed1::StructString>();
        auto element = testbed1::StructString();
        testbed1::fillTestStructString(element);
        test_value.append(element);
        clientStructArrayInterface->setPropString(test_value);
        REQUIRE(ispropStringChanged  == true);
        REQUIRE(implStructArrayInterface->propString() == test_value);
        REQUIRE(clientStructArrayInterface->propString() == test_value);
    }
    SECTION("Test emit sigBool")
    {
        bool issigBoolEmitted = false;
        auto local_param_bool_array = QList<testbed1::StructBool>();
        auto element_paramBool = testbed1::StructBool();
        testbed1::fillTestStructBool(element_paramBool);
        local_param_bool_array .append(element_paramBool);

        clientStructArrayInterface->connect(clientStructArrayInterface.get(), &testbed1::AbstractStructArrayInterface::sigBool,
        [&issigBoolEmitted, &local_param_bool_array](const QList<testbed1::StructBool>& paramBool)
        {
            REQUIRE(paramBool == local_param_bool_array);
            issigBoolEmitted  = true;
        });

        emit implStructArrayInterface->sigBool(local_param_bool_array);
        REQUIRE(issigBoolEmitted  == true);
    }
    SECTION("Test emit sigInt")
    {
        bool issigIntEmitted = false;
        auto local_param_int_array = QList<testbed1::StructInt>();
        auto element_paramInt = testbed1::StructInt();
        testbed1::fillTestStructInt(element_paramInt);
        local_param_int_array .append(element_paramInt);

        clientStructArrayInterface->connect(clientStructArrayInterface.get(), &testbed1::AbstractStructArrayInterface::sigInt,
        [&issigIntEmitted, &local_param_int_array](const QList<testbed1::StructInt>& paramInt)
        {
            REQUIRE(paramInt == local_param_int_array);
            issigIntEmitted  = true;
        });

        emit implStructArrayInterface->sigInt(local_param_int_array);
        REQUIRE(issigIntEmitted  == true);
    }
    SECTION("Test emit sigFloat")
    {
        bool issigFloatEmitted = false;
        auto local_param_float_array = QList<testbed1::StructFloat>();
        auto element_paramFloat = testbed1::StructFloat();
        testbed1::fillTestStructFloat(element_paramFloat);
        local_param_float_array .append(element_paramFloat);

        clientStructArrayInterface->connect(clientStructArrayInterface.get(), &testbed1::AbstractStructArrayInterface::sigFloat,
        [&issigFloatEmitted, &local_param_float_array](const QList<testbed1::StructFloat>& paramFloat)
        {
            REQUIRE(paramFloat == local_param_float_array);
            issigFloatEmitted  = true;
        });

        emit implStructArrayInterface->sigFloat(local_param_float_array);
        REQUIRE(issigFloatEmitted  == true);
    }
    SECTION("Test emit sigString")
    {
        bool issigStringEmitted = false;
        auto local_param_string_array = QList<testbed1::StructString>();
        auto element_paramString = testbed1::StructString();
        testbed1::fillTestStructString(element_paramString);
        local_param_string_array .append(element_paramString);

        clientStructArrayInterface->connect(clientStructArrayInterface.get(), &testbed1::AbstractStructArrayInterface::sigString,
        [&issigStringEmitted, &local_param_string_array](const QList<testbed1::StructString>& paramString)
        {
            REQUIRE(paramString == local_param_string_array);
            issigStringEmitted  = true;
        });

        emit implStructArrayInterface->sigString(local_param_string_array);
        REQUIRE(issigStringEmitted  == true);
    }
    SECTION("Test method funcBool")
    {
        [[maybe_unused]] auto result = clientStructArrayInterface->funcBool(QList<testbed1::StructBool>());
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method funcBool async")
    {
        auto resultFuture = clientStructArrayInterface->funcBoolAsync(QList<testbed1::StructBool>());
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<testbed1::StructBool>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcInt")
    {
        [[maybe_unused]] auto result = clientStructArrayInterface->funcInt(QList<testbed1::StructInt>());
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method funcInt async")
    {
        auto resultFuture = clientStructArrayInterface->funcIntAsync(QList<testbed1::StructInt>());
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<testbed1::StructInt>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcFloat")
    {
        [[maybe_unused]] auto result = clientStructArrayInterface->funcFloat(QList<testbed1::StructFloat>());
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method funcFloat async")
    {
        auto resultFuture = clientStructArrayInterface->funcFloatAsync(QList<testbed1::StructFloat>());
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<testbed1::StructFloat>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcString")
    {
        [[maybe_unused]] auto result = clientStructArrayInterface->funcString(QList<testbed1::StructString>());
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method funcString async")
    {
        auto resultFuture = clientStructArrayInterface->funcStringAsync(QList<testbed1::StructString>());
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<testbed1::StructString>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientNode->unlinkRemote(clientStructArrayInterface->olinkObjectName());
    remote_registry.removeSource(serviceStructArrayInterface->olinkObjectName());
    client_registry.removeSink(clientStructArrayInterface->olinkObjectName());
}
