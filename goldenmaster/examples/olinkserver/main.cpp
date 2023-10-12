
#include "testbed2/implementation/manyparaminterface.h"
#include "testbed2//olink/olinkmanyparaminterfaceadapter.h"
#include "testbed2/monitor/manyparaminterfacetraced.h"
#include "testbed2/implementation/nestedstruct1interface.h"
#include "testbed2//olink/olinknestedstruct1interfaceadapter.h"
#include "testbed2/monitor/nestedstruct1interfacetraced.h"
#include "testbed2/implementation/nestedstruct2interface.h"
#include "testbed2//olink/olinknestedstruct2interfaceadapter.h"
#include "testbed2/monitor/nestedstruct2interfacetraced.h"
#include "testbed2/implementation/nestedstruct3interface.h"
#include "testbed2//olink/olinknestedstruct3interfaceadapter.h"
#include "testbed2/monitor/nestedstruct3interfacetraced.h"
#include "tb_enum/implementation/enuminterface.h"
#include "tb_enum//olink/olinkenuminterfaceadapter.h"
#include "tb_enum/monitor/enuminterfacetraced.h"
#include "tb_same1/implementation/samestruct1interface.h"
#include "tb_same1//olink/olinksamestruct1interfaceadapter.h"
#include "tb_same1/monitor/samestruct1interfacetraced.h"
#include "tb_same1/implementation/samestruct2interface.h"
#include "tb_same1//olink/olinksamestruct2interfaceadapter.h"
#include "tb_same1/monitor/samestruct2interfacetraced.h"
#include "tb_same1/implementation/sameenum1interface.h"
#include "tb_same1//olink/olinksameenum1interfaceadapter.h"
#include "tb_same1/monitor/sameenum1interfacetraced.h"
#include "tb_same1/implementation/sameenum2interface.h"
#include "tb_same1//olink/olinksameenum2interfaceadapter.h"
#include "tb_same1/monitor/sameenum2interfacetraced.h"
#include "tb_same2/implementation/samestruct1interface.h"
#include "tb_same2//olink/olinksamestruct1interfaceadapter.h"
#include "tb_same2/monitor/samestruct1interfacetraced.h"
#include "tb_same2/implementation/samestruct2interface.h"
#include "tb_same2//olink/olinksamestruct2interfaceadapter.h"
#include "tb_same2/monitor/samestruct2interfacetraced.h"
#include "tb_same2/implementation/sameenum1interface.h"
#include "tb_same2//olink/olinksameenum1interfaceadapter.h"
#include "tb_same2/monitor/sameenum1interfacetraced.h"
#include "tb_same2/implementation/sameenum2interface.h"
#include "tb_same2//olink/olinksameenum2interfaceadapter.h"
#include "tb_same2/monitor/sameenum2interfacetraced.h"
#include "tb_simple/implementation/simpleinterface.h"
#include "tb_simple//olink/olinksimpleinterfaceadapter.h"
#include "tb_simple/monitor/simpleinterfacetraced.h"
#include "tb_simple/implementation/simplearrayinterface.h"
#include "tb_simple//olink/olinksimplearrayinterfaceadapter.h"
#include "tb_simple/monitor/simplearrayinterfacetraced.h"
#include "testbed1/implementation/structinterface.h"
#include "testbed1//olink/olinkstructinterfaceadapter.h"
#include "testbed1/monitor/structinterfacetraced.h"
#include "testbed1/implementation/structarrayinterface.h"
#include "testbed1//olink/olinkstructarrayinterfaceadapter.h"
#include "testbed1/monitor/structarrayinterfacetraced.h"
#include "tb_names/implementation/nam_es.h"
#include "tb_names//olink/olinknam_esadapter.h"
#include "tb_names/monitor/nam_estraced.h"

#include <QtCore>
#include "apigear/olink/olinkhost.h"
#include "olink/remoteregistry.h"
#include <memory>

#include <iostream>

// You can run this server app together with the client side app - either also example,
// or implemented olink client (may be using other technology) to play around with it.
// Have in mind, that this example only instantiates the interfaces and the services.
// To see results make sure the clients are sending request to server or add some actions by yourself.
// Note that the server should be started before the client apps.
// If you are running this example from qt creator make sure that the run project settings have "run in terminal" option selected.

int main(int argc, char *argv[]){

    QCoreApplication app(argc, argv);  ApiGear::ObjectLink::RemoteRegistry registry;
    ApiGear::ObjectLink::OLinkHost server(registry);
    server.listen("localhost", 8182);
    auto testbed2ManyParamInterface = std::make_shared<testbed2::ManyParamInterface>();
    testbed2::ManyParamInterfaceTraced testbed2ManyParamInterfaceTraced(testbed2ManyParamInterface );
    auto testbed2OlinkManyParamInterfaceService = std::make_shared<testbed2::OLinkManyParamInterfaceAdapter>(registry, &testbed2ManyParamInterfaceTraced);
    registry.addSource(testbed2OlinkManyParamInterfaceService);
    auto testbed2NestedStruct1Interface = std::make_shared<testbed2::NestedStruct1Interface>();
    testbed2::NestedStruct1InterfaceTraced testbed2NestedStruct1InterfaceTraced(testbed2NestedStruct1Interface );
    auto testbed2OlinkNestedStruct1InterfaceService = std::make_shared<testbed2::OLinkNestedStruct1InterfaceAdapter>(registry, &testbed2NestedStruct1InterfaceTraced);
    registry.addSource(testbed2OlinkNestedStruct1InterfaceService);
    auto testbed2NestedStruct2Interface = std::make_shared<testbed2::NestedStruct2Interface>();
    testbed2::NestedStruct2InterfaceTraced testbed2NestedStruct2InterfaceTraced(testbed2NestedStruct2Interface );
    auto testbed2OlinkNestedStruct2InterfaceService = std::make_shared<testbed2::OLinkNestedStruct2InterfaceAdapter>(registry, &testbed2NestedStruct2InterfaceTraced);
    registry.addSource(testbed2OlinkNestedStruct2InterfaceService);
    auto testbed2NestedStruct3Interface = std::make_shared<testbed2::NestedStruct3Interface>();
    testbed2::NestedStruct3InterfaceTraced testbed2NestedStruct3InterfaceTraced(testbed2NestedStruct3Interface );
    auto testbed2OlinkNestedStruct3InterfaceService = std::make_shared<testbed2::OLinkNestedStruct3InterfaceAdapter>(registry, &testbed2NestedStruct3InterfaceTraced);
    registry.addSource(testbed2OlinkNestedStruct3InterfaceService);
    auto tbEnumEnumInterface = std::make_shared<tb_enum::EnumInterface>();
    tb_enum::EnumInterfaceTraced tbEnumEnumInterfaceTraced(tbEnumEnumInterface );
    auto tbEnumOlinkEnumInterfaceService = std::make_shared<tb_enum::OLinkEnumInterfaceAdapter>(registry, &tbEnumEnumInterfaceTraced);
    registry.addSource(tbEnumOlinkEnumInterfaceService);
    auto tbSame1SameStruct1Interface = std::make_shared<tb_same1::SameStruct1Interface>();
    tb_same1::SameStruct1InterfaceTraced tbSame1SameStruct1InterfaceTraced(tbSame1SameStruct1Interface );
    auto tbSame1OlinkSameStruct1InterfaceService = std::make_shared<tb_same1::OLinkSameStruct1InterfaceAdapter>(registry, &tbSame1SameStruct1InterfaceTraced);
    registry.addSource(tbSame1OlinkSameStruct1InterfaceService);
    auto tbSame1SameStruct2Interface = std::make_shared<tb_same1::SameStruct2Interface>();
    tb_same1::SameStruct2InterfaceTraced tbSame1SameStruct2InterfaceTraced(tbSame1SameStruct2Interface );
    auto tbSame1OlinkSameStruct2InterfaceService = std::make_shared<tb_same1::OLinkSameStruct2InterfaceAdapter>(registry, &tbSame1SameStruct2InterfaceTraced);
    registry.addSource(tbSame1OlinkSameStruct2InterfaceService);
    auto tbSame1SameEnum1Interface = std::make_shared<tb_same1::SameEnum1Interface>();
    tb_same1::SameEnum1InterfaceTraced tbSame1SameEnum1InterfaceTraced(tbSame1SameEnum1Interface );
    auto tbSame1OlinkSameEnum1InterfaceService = std::make_shared<tb_same1::OLinkSameEnum1InterfaceAdapter>(registry, &tbSame1SameEnum1InterfaceTraced);
    registry.addSource(tbSame1OlinkSameEnum1InterfaceService);
    auto tbSame1SameEnum2Interface = std::make_shared<tb_same1::SameEnum2Interface>();
    tb_same1::SameEnum2InterfaceTraced tbSame1SameEnum2InterfaceTraced(tbSame1SameEnum2Interface );
    auto tbSame1OlinkSameEnum2InterfaceService = std::make_shared<tb_same1::OLinkSameEnum2InterfaceAdapter>(registry, &tbSame1SameEnum2InterfaceTraced);
    registry.addSource(tbSame1OlinkSameEnum2InterfaceService);
    auto tbSame2SameStruct1Interface = std::make_shared<tb_same2::SameStruct1Interface>();
    tb_same2::SameStruct1InterfaceTraced tbSame2SameStruct1InterfaceTraced(tbSame2SameStruct1Interface );
    auto tbSame2OlinkSameStruct1InterfaceService = std::make_shared<tb_same2::OLinkSameStruct1InterfaceAdapter>(registry, &tbSame2SameStruct1InterfaceTraced);
    registry.addSource(tbSame2OlinkSameStruct1InterfaceService);
    auto tbSame2SameStruct2Interface = std::make_shared<tb_same2::SameStruct2Interface>();
    tb_same2::SameStruct2InterfaceTraced tbSame2SameStruct2InterfaceTraced(tbSame2SameStruct2Interface );
    auto tbSame2OlinkSameStruct2InterfaceService = std::make_shared<tb_same2::OLinkSameStruct2InterfaceAdapter>(registry, &tbSame2SameStruct2InterfaceTraced);
    registry.addSource(tbSame2OlinkSameStruct2InterfaceService);
    auto tbSame2SameEnum1Interface = std::make_shared<tb_same2::SameEnum1Interface>();
    tb_same2::SameEnum1InterfaceTraced tbSame2SameEnum1InterfaceTraced(tbSame2SameEnum1Interface );
    auto tbSame2OlinkSameEnum1InterfaceService = std::make_shared<tb_same2::OLinkSameEnum1InterfaceAdapter>(registry, &tbSame2SameEnum1InterfaceTraced);
    registry.addSource(tbSame2OlinkSameEnum1InterfaceService);
    auto tbSame2SameEnum2Interface = std::make_shared<tb_same2::SameEnum2Interface>();
    tb_same2::SameEnum2InterfaceTraced tbSame2SameEnum2InterfaceTraced(tbSame2SameEnum2Interface );
    auto tbSame2OlinkSameEnum2InterfaceService = std::make_shared<tb_same2::OLinkSameEnum2InterfaceAdapter>(registry, &tbSame2SameEnum2InterfaceTraced);
    registry.addSource(tbSame2OlinkSameEnum2InterfaceService);
    auto tbSimpleSimpleInterface = std::make_shared<tb_simple::SimpleInterface>();
    tb_simple::SimpleInterfaceTraced tbSimpleSimpleInterfaceTraced(tbSimpleSimpleInterface );
    auto tbSimpleOlinkSimpleInterfaceService = std::make_shared<tb_simple::OLinkSimpleInterfaceAdapter>(registry, &tbSimpleSimpleInterfaceTraced);
    registry.addSource(tbSimpleOlinkSimpleInterfaceService);
    auto tbSimpleSimpleArrayInterface = std::make_shared<tb_simple::SimpleArrayInterface>();
    tb_simple::SimpleArrayInterfaceTraced tbSimpleSimpleArrayInterfaceTraced(tbSimpleSimpleArrayInterface );
    auto tbSimpleOlinkSimpleArrayInterfaceService = std::make_shared<tb_simple::OLinkSimpleArrayInterfaceAdapter>(registry, &tbSimpleSimpleArrayInterfaceTraced);
    registry.addSource(tbSimpleOlinkSimpleArrayInterfaceService);
    auto testbed1StructInterface = std::make_shared<testbed1::StructInterface>();
    testbed1::StructInterfaceTraced testbed1StructInterfaceTraced(testbed1StructInterface );
    auto testbed1OlinkStructInterfaceService = std::make_shared<testbed1::OLinkStructInterfaceAdapter>(registry, &testbed1StructInterfaceTraced);
    registry.addSource(testbed1OlinkStructInterfaceService);
    auto testbed1StructArrayInterface = std::make_shared<testbed1::StructArrayInterface>();
    testbed1::StructArrayInterfaceTraced testbed1StructArrayInterfaceTraced(testbed1StructArrayInterface );
    auto testbed1OlinkStructArrayInterfaceService = std::make_shared<testbed1::OLinkStructArrayInterfaceAdapter>(registry, &testbed1StructArrayInterfaceTraced);
    registry.addSource(testbed1OlinkStructArrayInterfaceService);
    auto tbNamesNamEs = std::make_shared<tb_names::NamEs>();
    tb_names::NamEsTraced tbNamesNamEsTraced(tbNamesNamEs );
    auto tbNamesOlinkNamEsService = std::make_shared<tb_names::OLinkNam_EsAdapter>(registry, &tbNamesNamEsTraced);
    registry.addSource(tbNamesOlinkNamEsService);

    auto result = app.exec();
    // Use the server.
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
