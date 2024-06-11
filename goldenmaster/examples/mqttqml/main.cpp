
#include "testbed2/implementation/manyparaminterface.h"
#include "testbed2/qmlplugin/qmlmanyparaminterface.h"
#include "testbed2/mqtt/mqttmanyparaminterfaceadapter.h"
#include "testbed2/implementation/nestedstruct1interface.h"
#include "testbed2/qmlplugin/qmlnestedstruct1interface.h"
#include "testbed2/mqtt/mqttnestedstruct1interfaceadapter.h"
#include "testbed2/implementation/nestedstruct2interface.h"
#include "testbed2/qmlplugin/qmlnestedstruct2interface.h"
#include "testbed2/mqtt/mqttnestedstruct2interfaceadapter.h"
#include "testbed2/implementation/nestedstruct3interface.h"
#include "testbed2/qmlplugin/qmlnestedstruct3interface.h"
#include "testbed2/mqtt/mqttnestedstruct3interfaceadapter.h"
#include "testbed2/qmlplugin/apifactory.h"
#include "testbed2/mqtt/mqttfactory.h"
#include "testbed2/monitor/tracedapifactory.h"
#include "tb_enum/implementation/enuminterface.h"
#include "tb_enum/qmlplugin/qmlenuminterface.h"
#include "tb_enum/mqtt/mqttenuminterfaceadapter.h"
#include "tb_enum/qmlplugin/apifactory.h"
#include "tb_enum/mqtt/mqttfactory.h"
#include "tb_enum/monitor/tracedapifactory.h"
#include "tb_same1/implementation/samestruct1interface.h"
#include "tb_same1/qmlplugin/qmlsamestruct1interface.h"
#include "tb_same1/mqtt/mqttsamestruct1interfaceadapter.h"
#include "tb_same1/implementation/samestruct2interface.h"
#include "tb_same1/qmlplugin/qmlsamestruct2interface.h"
#include "tb_same1/mqtt/mqttsamestruct2interfaceadapter.h"
#include "tb_same1/implementation/sameenum1interface.h"
#include "tb_same1/qmlplugin/qmlsameenum1interface.h"
#include "tb_same1/mqtt/mqttsameenum1interfaceadapter.h"
#include "tb_same1/implementation/sameenum2interface.h"
#include "tb_same1/qmlplugin/qmlsameenum2interface.h"
#include "tb_same1/mqtt/mqttsameenum2interfaceadapter.h"
#include "tb_same1/qmlplugin/apifactory.h"
#include "tb_same1/mqtt/mqttfactory.h"
#include "tb_same1/monitor/tracedapifactory.h"
#include "tb_same2/implementation/samestruct1interface.h"
#include "tb_same2/qmlplugin/qmlsamestruct1interface.h"
#include "tb_same2/mqtt/mqttsamestruct1interfaceadapter.h"
#include "tb_same2/implementation/samestruct2interface.h"
#include "tb_same2/qmlplugin/qmlsamestruct2interface.h"
#include "tb_same2/mqtt/mqttsamestruct2interfaceadapter.h"
#include "tb_same2/implementation/sameenum1interface.h"
#include "tb_same2/qmlplugin/qmlsameenum1interface.h"
#include "tb_same2/mqtt/mqttsameenum1interfaceadapter.h"
#include "tb_same2/implementation/sameenum2interface.h"
#include "tb_same2/qmlplugin/qmlsameenum2interface.h"
#include "tb_same2/mqtt/mqttsameenum2interfaceadapter.h"
#include "tb_same2/qmlplugin/apifactory.h"
#include "tb_same2/mqtt/mqttfactory.h"
#include "tb_same2/monitor/tracedapifactory.h"
#include "tb_simple/implementation/voidinterface.h"
#include "tb_simple/qmlplugin/qmlvoidinterface.h"
#include "tb_simple/mqtt/mqttvoidinterfaceadapter.h"
#include "tb_simple/implementation/simpleinterface.h"
#include "tb_simple/qmlplugin/qmlsimpleinterface.h"
#include "tb_simple/mqtt/mqttsimpleinterfaceadapter.h"
#include "tb_simple/implementation/simplearrayinterface.h"
#include "tb_simple/qmlplugin/qmlsimplearrayinterface.h"
#include "tb_simple/mqtt/mqttsimplearrayinterfaceadapter.h"
#include "tb_simple/implementation/nopropertiesinterface.h"
#include "tb_simple/qmlplugin/qmlnopropertiesinterface.h"
#include "tb_simple/mqtt/mqttnopropertiesinterfaceadapter.h"
#include "tb_simple/implementation/nooperationsinterface.h"
#include "tb_simple/qmlplugin/qmlnooperationsinterface.h"
#include "tb_simple/mqtt/mqttnooperationsinterfaceadapter.h"
#include "tb_simple/implementation/nosignalsinterface.h"
#include "tb_simple/qmlplugin/qmlnosignalsinterface.h"
#include "tb_simple/mqtt/mqttnosignalsinterfaceadapter.h"
#include "tb_simple/qmlplugin/apifactory.h"
#include "tb_simple/mqtt/mqttfactory.h"
#include "tb_simple/monitor/tracedapifactory.h"
#include "testbed1/implementation/structinterface.h"
#include "testbed1/qmlplugin/qmlstructinterface.h"
#include "testbed1/mqtt/mqttstructinterfaceadapter.h"
#include "testbed1/implementation/structarrayinterface.h"
#include "testbed1/qmlplugin/qmlstructarrayinterface.h"
#include "testbed1/mqtt/mqttstructarrayinterfaceadapter.h"
#include "testbed1/qmlplugin/apifactory.h"
#include "testbed1/mqtt/mqttfactory.h"
#include "testbed1/monitor/tracedapifactory.h"
#include "tb_names/implementation/nam_es.h"
#include "tb_names/qmlplugin/qmlnam_es.h"
#include "tb_names/mqtt/mqttnam_esadapter.h"
#include "tb_names/qmlplugin/apifactory.h"
#include "tb_names/mqtt/mqttfactory.h"
#include "tb_names/monitor/tracedapifactory.h"

#include <QtCore>
#include "apigear/mqtt/mqttservice.h"
#include "apigear/mqtt/mqttclient.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>


#include <memory>
#include <iostream>

#include <QtPlugin>


// This example contains service started from main and qml client.
// Remember to use also a mqtt broker of your choice.
// Be aware that some brokers limit maximum number of messages queued per client, if you send a lot of messages consider using more clients
// e.g. one per interface.
// Have in mind, that this example only instantiates the interfaces, you need to add some action to it by yourself, like:
// changing properties or executing methods, also make sure you are subscribed for the changes and signals.
// If you use a service example try out implementing some changes like: setting some properties or emitting signals to see any effects here.

int main(int argc, char *argv[]){

    // Prepare Factory before app is created.
    ApiGear::Mqtt::Client client("UniqueClientForQmlExample");
    ApiGear::Mqtt::ServiceAdapter service("UniqueService");
    
    testbed2::MqttFactory testbed2MqttFactory(client);
    testbed2::TracedApiFactory testbed2TracedMqttFactory(testbed2MqttFactory); 
    testbed2::ApiFactory::set(&testbed2TracedMqttFactory);
    
    tb_enum::MqttFactory tb_enumMqttFactory(client);
    tb_enum::TracedApiFactory tb_enumTracedMqttFactory(tb_enumMqttFactory); 
    tb_enum::ApiFactory::set(&tb_enumTracedMqttFactory);
    
    tb_same1::MqttFactory tb_same1MqttFactory(client);
    tb_same1::TracedApiFactory tb_same1TracedMqttFactory(tb_same1MqttFactory); 
    tb_same1::ApiFactory::set(&tb_same1TracedMqttFactory);
    
    tb_same2::MqttFactory tb_same2MqttFactory(client);
    tb_same2::TracedApiFactory tb_same2TracedMqttFactory(tb_same2MqttFactory); 
    tb_same2::ApiFactory::set(&tb_same2TracedMqttFactory);
    
    tb_simple::MqttFactory tb_simpleMqttFactory(client);
    tb_simple::TracedApiFactory tb_simpleTracedMqttFactory(tb_simpleMqttFactory); 
    tb_simple::ApiFactory::set(&tb_simpleTracedMqttFactory);
    
    testbed1::MqttFactory testbed1MqttFactory(client);
    testbed1::TracedApiFactory testbed1TracedMqttFactory(testbed1MqttFactory); 
    testbed1::ApiFactory::set(&testbed1TracedMqttFactory);
    
    tb_names::MqttFactory tb_namesMqttFactory(client);
    tb_names::TracedApiFactory tb_namesTracedMqttFactory(tb_namesMqttFactory); 
    tb_names::ApiFactory::set(&tb_namesTracedMqttFactory);

    // Create main app
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QGuiApplication app(argc, argv);

    // Hardcoded path to plugins for runtime app, works only in this folder structure
    // You may want to try out setting QML_IMPORT_PATH and QML2_IMPORT_PATH variables instead of following line.
    app.addLibraryPath(app.applicationDirPath() + "../../imports");
    QQmlApplicationEngine engine;

    engine.load(url);

    // Connect client and service adapter
    client.connectToHost("localhost", 1883);
    service.connectToHost("localhost", 1883);


    // Create and add services
    auto testbed2ManyParamInterface = std::make_shared<testbed2::ManyParamInterface>();
    auto testbed2MqttManyParamInterfaceService = std::make_shared<testbed2::MqttManyParamInterfaceAdapter>(service, testbed2ManyParamInterface);
    auto testbed2NestedStruct1Interface = std::make_shared<testbed2::NestedStruct1Interface>();
    auto testbed2MqttNestedStruct1InterfaceService = std::make_shared<testbed2::MqttNestedStruct1InterfaceAdapter>(service, testbed2NestedStruct1Interface);
    auto testbed2NestedStruct2Interface = std::make_shared<testbed2::NestedStruct2Interface>();
    auto testbed2MqttNestedStruct2InterfaceService = std::make_shared<testbed2::MqttNestedStruct2InterfaceAdapter>(service, testbed2NestedStruct2Interface);
    auto testbed2NestedStruct3Interface = std::make_shared<testbed2::NestedStruct3Interface>();
    auto testbed2MqttNestedStruct3InterfaceService = std::make_shared<testbed2::MqttNestedStruct3InterfaceAdapter>(service, testbed2NestedStruct3Interface);
    auto tbEnumEnumInterface = std::make_shared<tb_enum::EnumInterface>();
    auto tbEnumMqttEnumInterfaceService = std::make_shared<tb_enum::MqttEnumInterfaceAdapter>(service, tbEnumEnumInterface);
    auto tbSame1SameStruct1Interface = std::make_shared<tb_same1::SameStruct1Interface>();
    auto tbSame1MqttSameStruct1InterfaceService = std::make_shared<tb_same1::MqttSameStruct1InterfaceAdapter>(service, tbSame1SameStruct1Interface);
    auto tbSame1SameStruct2Interface = std::make_shared<tb_same1::SameStruct2Interface>();
    auto tbSame1MqttSameStruct2InterfaceService = std::make_shared<tb_same1::MqttSameStruct2InterfaceAdapter>(service, tbSame1SameStruct2Interface);
    auto tbSame1SameEnum1Interface = std::make_shared<tb_same1::SameEnum1Interface>();
    auto tbSame1MqttSameEnum1InterfaceService = std::make_shared<tb_same1::MqttSameEnum1InterfaceAdapter>(service, tbSame1SameEnum1Interface);
    auto tbSame1SameEnum2Interface = std::make_shared<tb_same1::SameEnum2Interface>();
    auto tbSame1MqttSameEnum2InterfaceService = std::make_shared<tb_same1::MqttSameEnum2InterfaceAdapter>(service, tbSame1SameEnum2Interface);
    auto tbSame2SameStruct1Interface = std::make_shared<tb_same2::SameStruct1Interface>();
    auto tbSame2MqttSameStruct1InterfaceService = std::make_shared<tb_same2::MqttSameStruct1InterfaceAdapter>(service, tbSame2SameStruct1Interface);
    auto tbSame2SameStruct2Interface = std::make_shared<tb_same2::SameStruct2Interface>();
    auto tbSame2MqttSameStruct2InterfaceService = std::make_shared<tb_same2::MqttSameStruct2InterfaceAdapter>(service, tbSame2SameStruct2Interface);
    auto tbSame2SameEnum1Interface = std::make_shared<tb_same2::SameEnum1Interface>();
    auto tbSame2MqttSameEnum1InterfaceService = std::make_shared<tb_same2::MqttSameEnum1InterfaceAdapter>(service, tbSame2SameEnum1Interface);
    auto tbSame2SameEnum2Interface = std::make_shared<tb_same2::SameEnum2Interface>();
    auto tbSame2MqttSameEnum2InterfaceService = std::make_shared<tb_same2::MqttSameEnum2InterfaceAdapter>(service, tbSame2SameEnum2Interface);
    auto tbSimpleVoidInterface = std::make_shared<tb_simple::VoidInterface>();
    auto tbSimpleMqttVoidInterfaceService = std::make_shared<tb_simple::MqttVoidInterfaceAdapter>(service, tbSimpleVoidInterface);
    auto tbSimpleSimpleInterface = std::make_shared<tb_simple::SimpleInterface>();
    auto tbSimpleMqttSimpleInterfaceService = std::make_shared<tb_simple::MqttSimpleInterfaceAdapter>(service, tbSimpleSimpleInterface);
    auto tbSimpleSimpleArrayInterface = std::make_shared<tb_simple::SimpleArrayInterface>();
    auto tbSimpleMqttSimpleArrayInterfaceService = std::make_shared<tb_simple::MqttSimpleArrayInterfaceAdapter>(service, tbSimpleSimpleArrayInterface);
    auto tbSimpleNoPropertiesInterface = std::make_shared<tb_simple::NoPropertiesInterface>();
    auto tbSimpleMqttNoPropertiesInterfaceService = std::make_shared<tb_simple::MqttNoPropertiesInterfaceAdapter>(service, tbSimpleNoPropertiesInterface);
    auto tbSimpleNoOperationsInterface = std::make_shared<tb_simple::NoOperationsInterface>();
    auto tbSimpleMqttNoOperationsInterfaceService = std::make_shared<tb_simple::MqttNoOperationsInterfaceAdapter>(service, tbSimpleNoOperationsInterface);
    auto tbSimpleNoSignalsInterface = std::make_shared<tb_simple::NoSignalsInterface>();
    auto tbSimpleMqttNoSignalsInterfaceService = std::make_shared<tb_simple::MqttNoSignalsInterfaceAdapter>(service, tbSimpleNoSignalsInterface);
    auto testbed1StructInterface = std::make_shared<testbed1::StructInterface>();
    auto testbed1MqttStructInterfaceService = std::make_shared<testbed1::MqttStructInterfaceAdapter>(service, testbed1StructInterface);
    auto testbed1StructArrayInterface = std::make_shared<testbed1::StructArrayInterface>();
    auto testbed1MqttStructArrayInterfaceService = std::make_shared<testbed1::MqttStructArrayInterfaceAdapter>(service, testbed1StructArrayInterface);
    auto tbNamesNamEs = std::make_shared<tb_names::NamEs>();
    auto tbNamesMqttNamEsService = std::make_shared<tb_names::MqttNam_EsAdapter>(service, tbNamesNamEs);


    /**
    * You may want to try out the bindings in qml for your interface
    * by changing properites of your interface or emitting signals from here.
    * You may use sth like:
    *
    *   auto future = std::async(std::launch::async,
    *                         [&yourInterfaceInstance](){
    *   std::this_thread::sleep_for(std::chrono::milliseconds(500));
    *   yourInterfaceInstance.setYourProperty(args);
    *   std::this_thread::sleep_for(std::chrono::milliseconds(500));
    *   yourInterfaceInstance.yourSingal(args);
    */

    auto result = app.exec();

    return result;
}
