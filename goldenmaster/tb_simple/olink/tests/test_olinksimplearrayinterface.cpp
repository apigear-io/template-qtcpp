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

    clientNode->unlinkRemote(clientSimpleArrayInterface->olinkObjectName());
    remote_registry.removeSource(serviceSimpleArrayInterface->olinkObjectName());
    client_registry.removeSink(clientSimpleArrayInterface->olinkObjectName());
}