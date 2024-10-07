#pragma warning (disable: 4251)
#pragma warning (disable: 4099)

#include <catch2/catch.hpp>

#include <QtCore>
#include <QTest>
#include "olink/olinksimpleinterface.h"
#include "api/api.h"
#include "api/test_struct_helper.h"
#include "implementation/simpleinterface.h"
#include "olink/olinksimpleinterfaceadapter.h"


#include "olink/clientregistry.h"
#include "olink/clientnode.h"
#include "olink/remotenode.h"
#include "olink/olinkremote.h"
#include "olink/remoteregistry.h"

TEST_CASE("Olink  tb.simple SimpleInterface tests")
{

    ClientRegistry client_registry;
    auto clientNode = ClientNode::create(client_registry);
    auto clientSimpleInterface = std::make_shared< tb_simple::OLinkSimpleInterface>();

    RemoteRegistry remote_registry;
    auto remoteNode = ApiGear::ObjectLink::RemoteNode::createRemoteNode(remote_registry);
    auto implSimpleInterface = std::make_shared< tb_simple::SimpleInterface>();
    auto serviceSimpleInterface = std::make_shared< tb_simple::OLinkSimpleInterfaceAdapter>(remote_registry, implSimpleInterface.get());
    remote_registry.addSource(serviceSimpleInterface);

    remoteNode->onWrite([clientNode](std::string msg){clientNode->handleMessage(msg);});
    clientNode->onWrite([remoteNode](std::string msg){remoteNode->handleMessage(msg);});

    clientNode->registry().addSink(clientSimpleInterface);
    clientNode->linkRemote(clientSimpleInterface->olinkObjectName());
    SECTION("Test setting propBool")
    {
        bool ispropBoolChanged = false;
        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::propBoolChanged, [&ispropBoolChanged ](auto value){ispropBoolChanged  = true;});
        auto test_value = true;
        clientSimpleInterface->setPropBool(test_value);
        REQUIRE(ispropBoolChanged  == true);
        REQUIRE(implSimpleInterface->propBool() == test_value);
        REQUIRE(clientSimpleInterface->propBool() == test_value);
    }
    SECTION("Test setting propInt")
    {
        bool ispropIntChanged = false;
        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::propIntChanged, [&ispropIntChanged ](auto value){ispropIntChanged  = true;});
        auto test_value = 1;
        clientSimpleInterface->setPropInt(test_value);
        REQUIRE(ispropIntChanged  == true);
        REQUIRE(implSimpleInterface->propInt() == test_value);
        REQUIRE(clientSimpleInterface->propInt() == test_value);
    }
    SECTION("Test setting propInt32")
    {
        bool ispropInt32Changed = false;
        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::propInt32Changed, [&ispropInt32Changed ](auto value){ispropInt32Changed  = true;});
        auto test_value = 1;
        clientSimpleInterface->setPropInt32(test_value);
        REQUIRE(ispropInt32Changed  == true);
        REQUIRE(implSimpleInterface->propInt32() == test_value);
        REQUIRE(clientSimpleInterface->propInt32() == test_value);
    }
    SECTION("Test setting propInt64")
    {
        bool ispropInt64Changed = false;
        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::propInt64Changed, [&ispropInt64Changed ](auto value){ispropInt64Changed  = true;});
        auto test_value = 1LL;
        clientSimpleInterface->setPropInt64(test_value);
        REQUIRE(ispropInt64Changed  == true);
        REQUIRE(implSimpleInterface->propInt64() == test_value);
        REQUIRE(clientSimpleInterface->propInt64() == test_value);
    }
    SECTION("Test setting propFloat")
    {
        bool ispropFloatChanged = false;
        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::propFloatChanged, [&ispropFloatChanged ](auto value){ispropFloatChanged  = true;});
        auto test_value = 1.1f;
        clientSimpleInterface->setPropFloat(test_value);
        REQUIRE(ispropFloatChanged  == true);
        REQUIRE(implSimpleInterface->propFloat() == test_value);
        REQUIRE(clientSimpleInterface->propFloat() == test_value);
    }
    SECTION("Test setting propFloat32")
    {
        bool ispropFloat32Changed = false;
        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::propFloat32Changed, [&ispropFloat32Changed ](auto value){ispropFloat32Changed  = true;});
        auto test_value = 1.1f;
        clientSimpleInterface->setPropFloat32(test_value);
        REQUIRE(ispropFloat32Changed  == true);
        REQUIRE(implSimpleInterface->propFloat32() == test_value);
        REQUIRE(clientSimpleInterface->propFloat32() == test_value);
    }
    SECTION("Test setting propFloat64")
    {
        bool ispropFloat64Changed = false;
        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::propFloat64Changed, [&ispropFloat64Changed ](auto value){ispropFloat64Changed  = true;});
        auto test_value = 1.1;
        clientSimpleInterface->setPropFloat64(test_value);
        REQUIRE(ispropFloat64Changed  == true);
        REQUIRE(implSimpleInterface->propFloat64() == test_value);
        REQUIRE(clientSimpleInterface->propFloat64() == test_value);
    }
    SECTION("Test setting propString")
    {
        bool ispropStringChanged = false;
        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::propStringChanged, [&ispropStringChanged ](auto value){ispropStringChanged  = true;});
        auto test_value = QString("xyz");
        clientSimpleInterface->setPropString(test_value);
        REQUIRE(ispropStringChanged  == true);
        REQUIRE(implSimpleInterface->propString() == test_value);
        REQUIRE(clientSimpleInterface->propString() == test_value);
    }
    SECTION("Test emit sigBool")
    {
        bool issigBoolEmitted = false;

        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::sigBool,
        [&issigBoolEmitted](bool paramBool)
        {
            REQUIRE(paramBool == true);
            issigBoolEmitted  = true;
        });

        emit implSimpleInterface->sigBool(true);
        REQUIRE(issigBoolEmitted  == true);
    }
    SECTION("Test emit sigInt")
    {
        bool issigIntEmitted = false;

        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::sigInt,
        [&issigIntEmitted](int paramInt)
        {
            REQUIRE(paramInt == 1);
            issigIntEmitted  = true;
        });

        emit implSimpleInterface->sigInt(1);
        REQUIRE(issigIntEmitted  == true);
    }
    SECTION("Test emit sigInt32")
    {
        bool issigInt32Emitted = false;

        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::sigInt32,
        [&issigInt32Emitted](qint32 paramInt32)
        {
            REQUIRE(paramInt32 == 1);
            issigInt32Emitted  = true;
        });

        emit implSimpleInterface->sigInt32(1);
        REQUIRE(issigInt32Emitted  == true);
    }
    SECTION("Test emit sigInt64")
    {
        bool issigInt64Emitted = false;

        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::sigInt64,
        [&issigInt64Emitted](qint64 paramInt64)
        {
            REQUIRE(paramInt64 == 1LL);
            issigInt64Emitted  = true;
        });

        emit implSimpleInterface->sigInt64(1LL);
        REQUIRE(issigInt64Emitted  == true);
    }
    SECTION("Test emit sigFloat")
    {
        bool issigFloatEmitted = false;

        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::sigFloat,
        [&issigFloatEmitted](qreal paramFloat)
        {
            REQUIRE(paramFloat == 1.1f);
            issigFloatEmitted  = true;
        });

        emit implSimpleInterface->sigFloat(1.1f);
        REQUIRE(issigFloatEmitted  == true);
    }
    SECTION("Test emit sigFloat32")
    {
        bool issigFloat32Emitted = false;

        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::sigFloat32,
        [&issigFloat32Emitted](float paramFloat32)
        {
            REQUIRE(paramFloat32 == 1.1f);
            issigFloat32Emitted  = true;
        });

        emit implSimpleInterface->sigFloat32(1.1f);
        REQUIRE(issigFloat32Emitted  == true);
    }
    SECTION("Test emit sigFloat64")
    {
        bool issigFloat64Emitted = false;

        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::sigFloat64,
        [&issigFloat64Emitted](double paramFloat64)
        {
            REQUIRE(paramFloat64 == 1.1);
            issigFloat64Emitted  = true;
        });

        emit implSimpleInterface->sigFloat64(1.1);
        REQUIRE(issigFloat64Emitted  == true);
    }
    SECTION("Test emit sigString")
    {
        bool issigStringEmitted = false;

        clientSimpleInterface->connect(clientSimpleInterface.get(), &tb_simple::AbstractSimpleInterface::sigString,
        [&issigStringEmitted](const QString& paramString)
        {
            REQUIRE(paramString == QString("xyz"));
            issigStringEmitted  = true;
        });

        emit implSimpleInterface->sigString(QString("xyz"));
        REQUIRE(issigStringEmitted  == true);
    }

    clientNode->unlinkRemote(clientSimpleInterface->olinkObjectName());
    remote_registry.removeSource(serviceSimpleInterface->olinkObjectName());
    client_registry.removeSink(clientSimpleInterface->olinkObjectName());
}
