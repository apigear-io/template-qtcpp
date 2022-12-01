
#include "testbed2/lib/manyparaminterface.h"
#include "testbed2//olink/olinkmanyparaminterfaceadapter.h"
#include "testbed2/lib/nestedstruct1interface.h"
#include "testbed2//olink/olinknestedstruct1interfaceadapter.h"
#include "testbed2/lib/nestedstruct2interface.h"
#include "testbed2//olink/olinknestedstruct2interfaceadapter.h"
#include "testbed2/lib/nestedstruct3interface.h"
#include "testbed2//olink/olinknestedstruct3interfaceadapter.h"
#include "tb_enum/lib/enuminterface.h"
#include "tb_enum//olink/olinkenuminterfaceadapter.h"
#include "tb_same1/lib/samestruct1interface.h"
#include "tb_same1//olink/olinksamestruct1interfaceadapter.h"
#include "tb_same1/lib/samestruct2interface.h"
#include "tb_same1//olink/olinksamestruct2interfaceadapter.h"
#include "tb_same1/lib/sameenum1interface.h"
#include "tb_same1//olink/olinksameenum1interfaceadapter.h"
#include "tb_same1/lib/sameenum2interface.h"
#include "tb_same1//olink/olinksameenum2interfaceadapter.h"
#include "tb_same2/lib/samestruct1interface.h"
#include "tb_same2//olink/olinksamestruct1interfaceadapter.h"
#include "tb_same2/lib/samestruct2interface.h"
#include "tb_same2//olink/olinksamestruct2interfaceadapter.h"
#include "tb_same2/lib/sameenum1interface.h"
#include "tb_same2//olink/olinksameenum1interfaceadapter.h"
#include "tb_same2/lib/sameenum2interface.h"
#include "tb_same2//olink/olinksameenum2interfaceadapter.h"
#include "tb_simple/lib/simpleinterface.h"
#include "tb_simple//olink/olinksimpleinterfaceadapter.h"
#include "tb_simple/lib/simplearrayinterface.h"
#include "tb_simple//olink/olinksimplearrayinterfaceadapter.h"
#include "testbed1/lib/structinterface.h"
#include "testbed1//olink/olinkstructinterfaceadapter.h"
#include "testbed1/lib/structarrayinterface.h"
#include "testbed1//olink/olinkstructarrayinterfaceadapter.h"

#include <QtCore>
#include "apigear/olink/olinkhost.h"
#include "olink/remoteregistry.h"
#include <memory>

#include <iostream>

int main(){

    ApiGear::ObjectLink::RemoteRegistry registry;
    ApiGear::ObjectLink::OLinkHost server(registry);
    server.listen("localhost", 8182);
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
    return 0;
}
