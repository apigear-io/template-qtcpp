#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>

#include <QtCore>
#include <QTest>
#include "olink/olinksimplearrayinterface.h"
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/simplearrayinterface.h"
#include "olink/olinksimplearrayinterfaceadapter.h"


#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/remotenode.h"
#include "olink/olinkremote.h"
#include "olink/remoteregistry.h"

TEST_CASE("Olink  tb.simple SimpleArrayInterface tests")
{

    ClientRegistry client_registry;
    auto clientNode = ClientNode::create(client_registry);
    auto clientSimpleArrayInterface = std::make_shared< tb_simple::OLinkSimpleArrayInterface>();

    RemoteRegistry remote_registry;
    auto remoteNode = ApiGear::ObjectLink::RemoteNode::createRemoteNode(remote_registry);
    auto implSimpleArrayInterface = std::make_shared< tb_simple::SimpleArrayInterface>();
    auto serviceSimpleArrayInterface = std::make_shared< tb_simple::OLinkSimpleArrayInterfaceAdapter>(remote_registry, implSimpleArrayInterface.get());
    remote_registry.addSource(serviceSimpleArrayInterface);

    remoteNode->onWrite([clientNode](std::string msg){clientNode->handleMessage(msg);});
    clientNode->onWrite([remoteNode](std::string msg){remoteNode->handleMessage(msg);});

    clientNode->registry().addSink(clientSimpleArrayInterface);
    clientNode->linkRemote(clientSimpleArrayInterface->olinkObjectName());
    SECTION("Test setting propBool")
    {
        bool ispropBoolChanged = false;
        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::propBoolChanged, [&ispropBoolChanged ](auto value){ispropBoolChanged  = true;});
        auto test_value = QList<bool>();  
        test_value.append(true);
        clientSimpleArrayInterface->setPropBool(test_value);
        REQUIRE(ispropBoolChanged  == true);
        REQUIRE(implSimpleArrayInterface->propBool() == test_value);
        REQUIRE(clientSimpleArrayInterface->propBool() == test_value);
    }
    SECTION("Test setting propInt")
    {
        bool ispropIntChanged = false;
        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::propIntChanged, [&ispropIntChanged ](auto value){ispropIntChanged  = true;});
        auto test_value = QList<int>();  
        test_value.append(1);
        clientSimpleArrayInterface->setPropInt(test_value);
        REQUIRE(ispropIntChanged  == true);
        REQUIRE(implSimpleArrayInterface->propInt() == test_value);
        REQUIRE(clientSimpleArrayInterface->propInt() == test_value);
    }
    SECTION("Test setting propInt32")
    {
        bool ispropInt32Changed = false;
        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::propInt32Changed, [&ispropInt32Changed ](auto value){ispropInt32Changed  = true;});
        auto test_value = QList<qint32>();  
        test_value.append(1);
        clientSimpleArrayInterface->setPropInt32(test_value);
        REQUIRE(ispropInt32Changed  == true);
        REQUIRE(implSimpleArrayInterface->propInt32() == test_value);
        REQUIRE(clientSimpleArrayInterface->propInt32() == test_value);
    }
    SECTION("Test setting propInt64")
    {
        bool ispropInt64Changed = false;
        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::propInt64Changed, [&ispropInt64Changed ](auto value){ispropInt64Changed  = true;});
        auto test_value = QList<qint64>();  
        test_value.append(1LL);
        clientSimpleArrayInterface->setPropInt64(test_value);
        REQUIRE(ispropInt64Changed  == true);
        REQUIRE(implSimpleArrayInterface->propInt64() == test_value);
        REQUIRE(clientSimpleArrayInterface->propInt64() == test_value);
    }
    SECTION("Test setting propFloat")
    {
        bool ispropFloatChanged = false;
        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::propFloatChanged, [&ispropFloatChanged ](auto value){ispropFloatChanged  = true;});
        auto test_value = QList<qreal>();  
        test_value.append(1.1f);
        clientSimpleArrayInterface->setPropFloat(test_value);
        REQUIRE(ispropFloatChanged  == true);
        REQUIRE(implSimpleArrayInterface->propFloat() == test_value);
        REQUIRE(clientSimpleArrayInterface->propFloat() == test_value);
    }
    SECTION("Test setting propFloat32")
    {
        bool ispropFloat32Changed = false;
        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::propFloat32Changed, [&ispropFloat32Changed ](auto value){ispropFloat32Changed  = true;});
        auto test_value = QList<float>();  
        test_value.append(1.1f);
        clientSimpleArrayInterface->setPropFloat32(test_value);
        REQUIRE(ispropFloat32Changed  == true);
        REQUIRE(implSimpleArrayInterface->propFloat32() == test_value);
        REQUIRE(clientSimpleArrayInterface->propFloat32() == test_value);
    }
    SECTION("Test setting propFloat64")
    {
        bool ispropFloat64Changed = false;
        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::propFloat64Changed, [&ispropFloat64Changed ](auto value){ispropFloat64Changed  = true;});
        auto test_value = QList<double>();  
        test_value.append(1.1);
        clientSimpleArrayInterface->setPropFloat64(test_value);
        REQUIRE(ispropFloat64Changed  == true);
        REQUIRE(implSimpleArrayInterface->propFloat64() == test_value);
        REQUIRE(clientSimpleArrayInterface->propFloat64() == test_value);
    }
    SECTION("Test setting propString")
    {
        bool ispropStringChanged = false;
        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::propStringChanged, [&ispropStringChanged ](auto value){ispropStringChanged  = true;});
        auto test_value = QList<QString>();  
        test_value.append(QString("xyz"));
        clientSimpleArrayInterface->setPropString(test_value);
        REQUIRE(ispropStringChanged  == true);
        REQUIRE(implSimpleArrayInterface->propString() == test_value);
        REQUIRE(clientSimpleArrayInterface->propString() == test_value);
    }
    SECTION("Test emit sigBool")
    {
        bool issigBoolEmitted = false;
        auto local_param_bool_array = QList<bool>();
        local_param_bool_array.append(true);

        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::sigBool,
        [&issigBoolEmitted, &local_param_bool_array](const QList<bool>& paramBool)
        {
            REQUIRE(paramBool == local_param_bool_array);
            issigBoolEmitted  = true;
        });

        emit implSimpleArrayInterface->sigBool(local_param_bool_array);
        REQUIRE(issigBoolEmitted  == true);
    }
    SECTION("Test emit sigInt")
    {
        bool issigIntEmitted = false;
        auto local_param_int_array = QList<int>();
        local_param_int_array.append(1);

        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::sigInt,
        [&issigIntEmitted, &local_param_int_array](const QList<int>& paramInt)
        {
            REQUIRE(paramInt == local_param_int_array);
            issigIntEmitted  = true;
        });

        emit implSimpleArrayInterface->sigInt(local_param_int_array);
        REQUIRE(issigIntEmitted  == true);
    }
    SECTION("Test emit sigInt32")
    {
        bool issigInt32Emitted = false;
        auto local_param_int32_array = QList<qint32>();
        local_param_int32_array.append(1);

        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::sigInt32,
        [&issigInt32Emitted, &local_param_int32_array](const QList<qint32>& paramInt32)
        {
            REQUIRE(paramInt32 == local_param_int32_array);
            issigInt32Emitted  = true;
        });

        emit implSimpleArrayInterface->sigInt32(local_param_int32_array);
        REQUIRE(issigInt32Emitted  == true);
    }
    SECTION("Test emit sigInt64")
    {
        bool issigInt64Emitted = false;
        auto local_param_int64_array = QList<qint64>();
        local_param_int64_array.append(1LL);

        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::sigInt64,
        [&issigInt64Emitted, &local_param_int64_array](const QList<qint64>& paramInt64)
        {
            REQUIRE(paramInt64 == local_param_int64_array);
            issigInt64Emitted  = true;
        });

        emit implSimpleArrayInterface->sigInt64(local_param_int64_array);
        REQUIRE(issigInt64Emitted  == true);
    }
    SECTION("Test emit sigFloat")
    {
        bool issigFloatEmitted = false;
        auto local_param_float_array = QList<qreal>();
        local_param_float_array.append(1.1f);

        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::sigFloat,
        [&issigFloatEmitted, &local_param_float_array](const QList<qreal>& paramFloat)
        {
            REQUIRE(paramFloat == local_param_float_array);
            issigFloatEmitted  = true;
        });

        emit implSimpleArrayInterface->sigFloat(local_param_float_array);
        REQUIRE(issigFloatEmitted  == true);
    }
    SECTION("Test emit sigFloat32")
    {
        bool issigFloat32Emitted = false;
        auto local_param_floa32_array = QList<float>();
        local_param_floa32_array.append(1.1f);

        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::sigFloat32,
        [&issigFloat32Emitted, &local_param_floa32_array](const QList<float>& paramFloa32)
        {
            REQUIRE(paramFloa32 == local_param_floa32_array);
            issigFloat32Emitted  = true;
        });

        emit implSimpleArrayInterface->sigFloat32(local_param_floa32_array);
        REQUIRE(issigFloat32Emitted  == true);
    }
    SECTION("Test emit sigFloat64")
    {
        bool issigFloat64Emitted = false;
        auto local_param_float64_array = QList<double>();
        local_param_float64_array.append(1.1);

        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::sigFloat64,
        [&issigFloat64Emitted, &local_param_float64_array](const QList<double>& paramFloat64)
        {
            REQUIRE(paramFloat64 == local_param_float64_array);
            issigFloat64Emitted  = true;
        });

        emit implSimpleArrayInterface->sigFloat64(local_param_float64_array);
        REQUIRE(issigFloat64Emitted  == true);
    }
    SECTION("Test emit sigString")
    {
        bool issigStringEmitted = false;
        auto local_param_string_array = QList<QString>();
        local_param_string_array.append(QString("xyz"));

        clientSimpleArrayInterface->connect(clientSimpleArrayInterface.get(), &tb_simple::AbstractSimpleArrayInterface::sigString,
        [&issigStringEmitted, &local_param_string_array](const QList<QString>& paramString)
        {
            REQUIRE(paramString == local_param_string_array);
            issigStringEmitted  = true;
        });

        emit implSimpleArrayInterface->sigString(local_param_string_array);
        REQUIRE(issigStringEmitted  == true);
    }
    SECTION("Test method funcBool")
    {
        [[maybe_unused]] auto result = clientSimpleArrayInterface->funcBool(QList<bool>());
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method funcBool async")
    {
        auto resultFuture = clientSimpleArrayInterface->funcBoolAsync(QList<bool>());
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<bool>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcInt")
    {
        [[maybe_unused]] auto result = clientSimpleArrayInterface->funcInt(QList<int>());
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method funcInt async")
    {
        auto resultFuture = clientSimpleArrayInterface->funcIntAsync(QList<int>());
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<int>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcInt32")
    {
        [[maybe_unused]] auto result = clientSimpleArrayInterface->funcInt32(QList<qint32>());
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method funcInt32 async")
    {
        auto resultFuture = clientSimpleArrayInterface->funcInt32Async(QList<qint32>());
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<qint32>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcInt64")
    {
        [[maybe_unused]] auto result = clientSimpleArrayInterface->funcInt64(QList<qint64>());
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method funcInt64 async")
    {
        auto resultFuture = clientSimpleArrayInterface->funcInt64Async(QList<qint64>());
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<qint64>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcFloat")
    {
        [[maybe_unused]] auto result = clientSimpleArrayInterface->funcFloat(QList<qreal>());
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method funcFloat async")
    {
        auto resultFuture = clientSimpleArrayInterface->funcFloatAsync(QList<qreal>());
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<qreal>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcFloat32")
    {
        [[maybe_unused]] auto result = clientSimpleArrayInterface->funcFloat32(QList<float>());
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method funcFloat32 async")
    {
        auto resultFuture = clientSimpleArrayInterface->funcFloat32Async(QList<float>());
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<float>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcFloat64")
    {
        [[maybe_unused]] auto result = clientSimpleArrayInterface->funcFloat64(QList<double>());
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method funcFloat64 async")
    {
        auto resultFuture = clientSimpleArrayInterface->funcFloat64Async(QList<double>());
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<double>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }
    SECTION("Test method funcString")
    {
        [[maybe_unused]] auto result = clientSimpleArrayInterface->funcString(QList<QString>());
        // CHECK EFFECTS OF YOUR METHOD HERE

    }
    SECTION("Test method funcString async")
    {
        auto resultFuture = clientSimpleArrayInterface->funcStringAsync(QList<QString>());
        resultFuture.waitForFinished();
        auto return_value = resultFuture.result();
        REQUIRE(return_value == QList<QString>());
        // CHECK EFFECTS OF YOUR METHOD HERE
    }

    clientNode->unlinkRemote(clientSimpleArrayInterface->olinkObjectName());
    remote_registry.removeSource(serviceSimpleArrayInterface->olinkObjectName());
    client_registry.removeSink(clientSimpleArrayInterface->olinkObjectName());
}
