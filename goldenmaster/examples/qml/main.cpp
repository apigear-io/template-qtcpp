
#include "testbed2/implementation/manyparaminterface.h"
#include "testbed2/api/qmlmanyparaminterface.h"
#include "testbed2/olink/olinkmanyparaminterfaceadapter.h"
#include "testbed2/implementation/nestedstruct1interface.h"
#include "testbed2/api/qmlnestedstruct1interface.h"
#include "testbed2/olink/olinknestedstruct1interfaceadapter.h"
#include "testbed2/implementation/nestedstruct2interface.h"
#include "testbed2/api/qmlnestedstruct2interface.h"
#include "testbed2/olink/olinknestedstruct2interfaceadapter.h"
#include "testbed2/implementation/nestedstruct3interface.h"
#include "testbed2/api/qmlnestedstruct3interface.h"
#include "testbed2/olink/olinknestedstruct3interfaceadapter.h"
#include "testbed2/api/apifactory.h"
#include "testbed2/olink/olinkfactory.h"
#include "testbed2/monitor/tracedapifactory.h"
#include "tb_enum/implementation/enuminterface.h"
#include "tb_enum/api/qmlenuminterface.h"
#include "tb_enum/olink/olinkenuminterfaceadapter.h"
#include "tb_enum/api/apifactory.h"
#include "tb_enum/olink/olinkfactory.h"
#include "tb_enum/monitor/tracedapifactory.h"
#include "tb_same1/implementation/samestruct1interface.h"
#include "tb_same1/api/qmlsamestruct1interface.h"
#include "tb_same1/olink/olinksamestruct1interfaceadapter.h"
#include "tb_same1/implementation/samestruct2interface.h"
#include "tb_same1/api/qmlsamestruct2interface.h"
#include "tb_same1/olink/olinksamestruct2interfaceadapter.h"
#include "tb_same1/implementation/sameenum1interface.h"
#include "tb_same1/api/qmlsameenum1interface.h"
#include "tb_same1/olink/olinksameenum1interfaceadapter.h"
#include "tb_same1/implementation/sameenum2interface.h"
#include "tb_same1/api/qmlsameenum2interface.h"
#include "tb_same1/olink/olinksameenum2interfaceadapter.h"
#include "tb_same1/api/apifactory.h"
#include "tb_same1/olink/olinkfactory.h"
#include "tb_same1/monitor/tracedapifactory.h"
#include "tb_same2/implementation/samestruct1interface.h"
#include "tb_same2/api/qmlsamestruct1interface.h"
#include "tb_same2/olink/olinksamestruct1interfaceadapter.h"
#include "tb_same2/implementation/samestruct2interface.h"
#include "tb_same2/api/qmlsamestruct2interface.h"
#include "tb_same2/olink/olinksamestruct2interfaceadapter.h"
#include "tb_same2/implementation/sameenum1interface.h"
#include "tb_same2/api/qmlsameenum1interface.h"
#include "tb_same2/olink/olinksameenum1interfaceadapter.h"
#include "tb_same2/implementation/sameenum2interface.h"
#include "tb_same2/api/qmlsameenum2interface.h"
#include "tb_same2/olink/olinksameenum2interfaceadapter.h"
#include "tb_same2/api/apifactory.h"
#include "tb_same2/olink/olinkfactory.h"
#include "tb_same2/monitor/tracedapifactory.h"
#include "tb_simple/implementation/simpleinterface.h"
#include "tb_simple/api/qmlsimpleinterface.h"
#include "tb_simple/olink/olinksimpleinterfaceadapter.h"
#include "tb_simple/implementation/simplearrayinterface.h"
#include "tb_simple/api/qmlsimplearrayinterface.h"
#include "tb_simple/olink/olinksimplearrayinterfaceadapter.h"
#include "tb_simple/api/apifactory.h"
#include "tb_simple/olink/olinkfactory.h"
#include "tb_simple/monitor/tracedapifactory.h"
#include "testbed1/implementation/structinterface.h"
#include "testbed1/api/qmlstructinterface.h"
#include "testbed1/olink/olinkstructinterfaceadapter.h"
#include "testbed1/implementation/structarrayinterface.h"
#include "testbed1/api/qmlstructarrayinterface.h"
#include "testbed1/olink/olinkstructarrayinterfaceadapter.h"
#include "testbed1/api/apifactory.h"
#include "testbed1/olink/olinkfactory.h"
#include "testbed1/monitor/tracedapifactory.h"
#include "tb_names/implementation/nam_es.h"
#include "tb_names/api/qmlnam_es.h"
#include "tb_names/olink/olinknam_esadapter.h"
#include "tb_names/api/apifactory.h"
#include "tb_names/olink/olinkfactory.h"
#include "tb_names/monitor/tracedapifactory.h"

#include <QtCore>
#include "apigear/olink/olinkhost.h"
#include "olink/remoteregistry.h"
#include "olink/clientregistry.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "olink/olinkhost.h"
#include "olink/olinkclient.h"

#include <memory>
#include <iostream>

#include <QtPlugin>

// Example uses Olink Client as a backend for Qml Interface Wrappers
// It sets up the server with InterfaceImplemenation and wrappes it with Olink Service Adapters
// The connection is set up, and you can observe changes of your qml class by changing an interface instance.
// Normally server (with InterfaceImplemenation and Olink Service Adapter) would be in separate app
// And your UI containing the factory and a client.

int main(int argc, char *argv[]){

    // Prepare Factory before app is created.
    ApiGear::ObjectLink::ClientRegistry client_registry;
    ApiGear::ObjectLink::OLinkClient client(client_registry);
    testbed2::OLinkFactory testbed2OlinkFactory(client);
    testbed2::TracedApiFactory testbed2TracedOlinkFactory(testbed2OlinkFactory); 
    testbed2::ApiFactory::set(&testbed2TracedOlinkFactory);
    tb_enum::OLinkFactory tb_enumOlinkFactory(client);
    tb_enum::TracedApiFactory tb_enumTracedOlinkFactory(tb_enumOlinkFactory); 
    tb_enum::ApiFactory::set(&tb_enumTracedOlinkFactory);
    tb_same1::OLinkFactory tb_same1OlinkFactory(client);
    tb_same1::TracedApiFactory tb_same1TracedOlinkFactory(tb_same1OlinkFactory); 
    tb_same1::ApiFactory::set(&tb_same1TracedOlinkFactory);
    tb_same2::OLinkFactory tb_same2OlinkFactory(client);
    tb_same2::TracedApiFactory tb_same2TracedOlinkFactory(tb_same2OlinkFactory); 
    tb_same2::ApiFactory::set(&tb_same2TracedOlinkFactory);
    tb_simple::OLinkFactory tb_simpleOlinkFactory(client);
    tb_simple::TracedApiFactory tb_simpleTracedOlinkFactory(tb_simpleOlinkFactory); 
    tb_simple::ApiFactory::set(&tb_simpleTracedOlinkFactory);
    testbed1::OLinkFactory testbed1OlinkFactory(client);
    testbed1::TracedApiFactory testbed1TracedOlinkFactory(testbed1OlinkFactory); 
    testbed1::ApiFactory::set(&testbed1TracedOlinkFactory);
    tb_names::OLinkFactory tb_namesOlinkFactory(client);
    tb_names::TracedApiFactory tb_namesTracedOlinkFactory(tb_namesOlinkFactory); 
    tb_names::ApiFactory::set(&tb_namesTracedOlinkFactory);

    // Create main app
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QGuiApplication app(argc, argv);

    // Hardcoded path to plugins for runtime app, works only in this folder structure
    // You may want to try out setting QML_IMPORT_PATH and QML2_IMPORT_PATH variables instead of following line.
    app.addLibraryPath(app.applicationDirPath() + "../../imports");
    QQmlApplicationEngine engine;

    engine.load(url);

    // Create server
    ApiGear::ObjectLink::RemoteRegistry registry;
    ApiGear::ObjectLink::OLinkHost server(registry);
    server.listen("localhost", 8182);

    // Create and add services to the server
    testbed2::ManyParamInterface testbed2ManyParamInterface;
    auto testbed2OlinkManyParamInterfaceService = std::make_shared<testbed2::OLinkManyParamInterfaceAdapter>(registry, &testbed2ManyParamInterface);
    registry.addSource(testbed2OlinkManyParamInterfaceService);
    testbed2::NestedStruct1Interface testbed2NestedStruct1Interface;
    auto testbed2OlinkNestedStruct1InterfaceService = std::make_shared<testbed2::OLinkNestedStruct1InterfaceAdapter>(registry, &testbed2NestedStruct1Interface);
    registry.addSource(testbed2OlinkNestedStruct1InterfaceService);
    testbed2::NestedStruct2Interface testbed2NestedStruct2Interface;
    auto testbed2OlinkNestedStruct2InterfaceService = std::make_shared<testbed2::OLinkNestedStruct2InterfaceAdapter>(registry, &testbed2NestedStruct2Interface);
    registry.addSource(testbed2OlinkNestedStruct2InterfaceService);
    testbed2::NestedStruct3Interface testbed2NestedStruct3Interface;
    auto testbed2OlinkNestedStruct3InterfaceService = std::make_shared<testbed2::OLinkNestedStruct3InterfaceAdapter>(registry, &testbed2NestedStruct3Interface);
    registry.addSource(testbed2OlinkNestedStruct3InterfaceService);
    tb_enum::EnumInterface tbEnumEnumInterface;
    auto tbEnumOlinkEnumInterfaceService = std::make_shared<tb_enum::OLinkEnumInterfaceAdapter>(registry, &tbEnumEnumInterface);
    registry.addSource(tbEnumOlinkEnumInterfaceService);
    tb_same1::SameStruct1Interface tbSame1SameStruct1Interface;
    auto tbSame1OlinkSameStruct1InterfaceService = std::make_shared<tb_same1::OLinkSameStruct1InterfaceAdapter>(registry, &tbSame1SameStruct1Interface);
    registry.addSource(tbSame1OlinkSameStruct1InterfaceService);
    tb_same1::SameStruct2Interface tbSame1SameStruct2Interface;
    auto tbSame1OlinkSameStruct2InterfaceService = std::make_shared<tb_same1::OLinkSameStruct2InterfaceAdapter>(registry, &tbSame1SameStruct2Interface);
    registry.addSource(tbSame1OlinkSameStruct2InterfaceService);
    tb_same1::SameEnum1Interface tbSame1SameEnum1Interface;
    auto tbSame1OlinkSameEnum1InterfaceService = std::make_shared<tb_same1::OLinkSameEnum1InterfaceAdapter>(registry, &tbSame1SameEnum1Interface);
    registry.addSource(tbSame1OlinkSameEnum1InterfaceService);
    tb_same1::SameEnum2Interface tbSame1SameEnum2Interface;
    auto tbSame1OlinkSameEnum2InterfaceService = std::make_shared<tb_same1::OLinkSameEnum2InterfaceAdapter>(registry, &tbSame1SameEnum2Interface);
    registry.addSource(tbSame1OlinkSameEnum2InterfaceService);
    tb_same2::SameStruct1Interface tbSame2SameStruct1Interface;
    auto tbSame2OlinkSameStruct1InterfaceService = std::make_shared<tb_same2::OLinkSameStruct1InterfaceAdapter>(registry, &tbSame2SameStruct1Interface);
    registry.addSource(tbSame2OlinkSameStruct1InterfaceService);
    tb_same2::SameStruct2Interface tbSame2SameStruct2Interface;
    auto tbSame2OlinkSameStruct2InterfaceService = std::make_shared<tb_same2::OLinkSameStruct2InterfaceAdapter>(registry, &tbSame2SameStruct2Interface);
    registry.addSource(tbSame2OlinkSameStruct2InterfaceService);
    tb_same2::SameEnum1Interface tbSame2SameEnum1Interface;
    auto tbSame2OlinkSameEnum1InterfaceService = std::make_shared<tb_same2::OLinkSameEnum1InterfaceAdapter>(registry, &tbSame2SameEnum1Interface);
    registry.addSource(tbSame2OlinkSameEnum1InterfaceService);
    tb_same2::SameEnum2Interface tbSame2SameEnum2Interface;
    auto tbSame2OlinkSameEnum2InterfaceService = std::make_shared<tb_same2::OLinkSameEnum2InterfaceAdapter>(registry, &tbSame2SameEnum2Interface);
    registry.addSource(tbSame2OlinkSameEnum2InterfaceService);
    tb_simple::SimpleInterface tbSimpleSimpleInterface;
    auto tbSimpleOlinkSimpleInterfaceService = std::make_shared<tb_simple::OLinkSimpleInterfaceAdapter>(registry, &tbSimpleSimpleInterface);
    registry.addSource(tbSimpleOlinkSimpleInterfaceService);
    tb_simple::SimpleArrayInterface tbSimpleSimpleArrayInterface;
    auto tbSimpleOlinkSimpleArrayInterfaceService = std::make_shared<tb_simple::OLinkSimpleArrayInterfaceAdapter>(registry, &tbSimpleSimpleArrayInterface);
    registry.addSource(tbSimpleOlinkSimpleArrayInterfaceService);
    testbed1::StructInterface testbed1StructInterface;
    auto testbed1OlinkStructInterfaceService = std::make_shared<testbed1::OLinkStructInterfaceAdapter>(registry, &testbed1StructInterface);
    registry.addSource(testbed1OlinkStructInterfaceService);
    testbed1::StructArrayInterface testbed1StructArrayInterface;
    auto testbed1OlinkStructArrayInterfaceService = std::make_shared<testbed1::OLinkStructArrayInterfaceAdapter>(registry, &testbed1StructArrayInterface);
    registry.addSource(testbed1OlinkStructArrayInterfaceService);
    tb_names::NamEs tbNamesNamEs;
    auto tbNamesOlinkNamEsService = std::make_shared<tb_names::OLinkNam_EsAdapter>(registry, &tbNamesNamEs);
    registry.addSource(tbNamesOlinkNamEsService);

    // With services ready connect the client - all qml olink clients will be linked
    client.connectToHost(QUrl("ws://127.0.0.1:8182/ws"));

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
    registry.removeSource(testbed2OlinkManyParamInterfaceService->olinkObjectName());
    registry.removeSource(testbed2OlinkNestedStruct1InterfaceService->olinkObjectName());
    registry.removeSource(testbed2OlinkNestedStruct2InterfaceService->olinkObjectName());
    registry.removeSource(testbed2OlinkNestedStruct3InterfaceService->olinkObjectName());
    registry.removeSource(tbEnumOlinkEnumInterfaceService->olinkObjectName());
    registry.removeSource(tbSame1OlinkSameStruct1InterfaceService->olinkObjectName());
    registry.removeSource(tbSame1OlinkSameStruct2InterfaceService->olinkObjectName());
    registry.removeSource(tbSame1OlinkSameEnum1InterfaceService->olinkObjectName());
    registry.removeSource(tbSame1OlinkSameEnum2InterfaceService->olinkObjectName());
    registry.removeSource(tbSame2OlinkSameStruct1InterfaceService->olinkObjectName());
    registry.removeSource(tbSame2OlinkSameStruct2InterfaceService->olinkObjectName());
    registry.removeSource(tbSame2OlinkSameEnum1InterfaceService->olinkObjectName());
    registry.removeSource(tbSame2OlinkSameEnum2InterfaceService->olinkObjectName());
    registry.removeSource(tbSimpleOlinkSimpleInterfaceService->olinkObjectName());
    registry.removeSource(tbSimpleOlinkSimpleArrayInterfaceService->olinkObjectName());
    registry.removeSource(testbed1OlinkStructInterfaceService->olinkObjectName());
    registry.removeSource(testbed1OlinkStructArrayInterfaceService->olinkObjectName());
    registry.removeSource(tbNamesOlinkNamEsService->olinkObjectName());

    return result;
}
