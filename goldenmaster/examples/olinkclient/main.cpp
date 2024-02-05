#include <QtQml>
#include <QGuiApplication>
#include "apigear/olink/olinkclient.h"
#include "olink/clientregistry.h"
#include "utilities/logger.h"
#include <memory>
#include "testbed2/olink/olinkmanyparaminterface.h"
#include "testbed2/monitor/manyparaminterfacetraced.h"
#include "testbed2/olink/olinknestedstruct1interface.h"
#include "testbed2/monitor/nestedstruct1interfacetraced.h"
#include "testbed2/olink/olinknestedstruct2interface.h"
#include "testbed2/monitor/nestedstruct2interfacetraced.h"
#include "testbed2/olink/olinknestedstruct3interface.h"
#include "testbed2/monitor/nestedstruct3interfacetraced.h"
#include "tb_enum/olink/olinkenuminterface.h"
#include "tb_enum/monitor/enuminterfacetraced.h"
#include "tb_same1/olink/olinksamestruct1interface.h"
#include "tb_same1/monitor/samestruct1interfacetraced.h"
#include "tb_same1/olink/olinksamestruct2interface.h"
#include "tb_same1/monitor/samestruct2interfacetraced.h"
#include "tb_same1/olink/olinksameenum1interface.h"
#include "tb_same1/monitor/sameenum1interfacetraced.h"
#include "tb_same1/olink/olinksameenum2interface.h"
#include "tb_same1/monitor/sameenum2interfacetraced.h"
#include "tb_same2/olink/olinksamestruct1interface.h"
#include "tb_same2/monitor/samestruct1interfacetraced.h"
#include "tb_same2/olink/olinksamestruct2interface.h"
#include "tb_same2/monitor/samestruct2interfacetraced.h"
#include "tb_same2/olink/olinksameenum1interface.h"
#include "tb_same2/monitor/sameenum1interfacetraced.h"
#include "tb_same2/olink/olinksameenum2interface.h"
#include "tb_same2/monitor/sameenum2interfacetraced.h"
#include "tb_simple/olink/olinksimpleinterface.h"
#include "tb_simple/monitor/simpleinterfacetraced.h"
#include "tb_simple/olink/olinksimplearrayinterface.h"
#include "tb_simple/monitor/simplearrayinterfacetraced.h"
#include "testbed1/olink/olinkstructinterface.h"
#include "testbed1/monitor/structinterfacetraced.h"
#include "testbed1/olink/olinkstructarrayinterface.h"
#include "testbed1/monitor/structarrayinterfacetraced.h"
#include "tb_names/olink/olinknam_es.h"
#include "tb_names/monitor/nam_estraced.h"


// You can run this client app together with the server side app - either also example, simulation,
// or implemented olink server (may be in other technology) to play around with it.
// Have in mind, that this example only instantiates the interfaces, you need to add some action to it by yourself, like:
// changing properties or executing methods, also make sure you are subscribed for the changes and signals.
// If you use a server example try out implementing some changes like: setting some properties or emitting signals to see any effects here.
// Note that the server should be started first.
// If you are running this example from qt creator make sure that the run project settings have "run in terminal" option selected.
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    ApiGear::ObjectLink::ClientRegistry registry;
    ApiGear::ObjectLink::OLinkClient client(registry);
    client.connectToHost(QUrl("ws://127.0.0.1:8182/ws"));
    auto testbed2ManyParamInterface = std::make_shared<testbed2::OLinkManyParamInterface>();
    client.linkObjectSource(testbed2ManyParamInterface);
    testbed2::ManyParamInterfaceTraced testbed2ManyParamInterfaceTraced(testbed2ManyParamInterface );
    auto testbed2NestedStruct1Interface = std::make_shared<testbed2::OLinkNestedStruct1Interface>();
    client.linkObjectSource(testbed2NestedStruct1Interface);
    testbed2::NestedStruct1InterfaceTraced testbed2NestedStruct1InterfaceTraced(testbed2NestedStruct1Interface );
    auto testbed2NestedStruct2Interface = std::make_shared<testbed2::OLinkNestedStruct2Interface>();
    client.linkObjectSource(testbed2NestedStruct2Interface);
    testbed2::NestedStruct2InterfaceTraced testbed2NestedStruct2InterfaceTraced(testbed2NestedStruct2Interface );
    auto testbed2NestedStruct3Interface = std::make_shared<testbed2::OLinkNestedStruct3Interface>();
    client.linkObjectSource(testbed2NestedStruct3Interface);
    testbed2::NestedStruct3InterfaceTraced testbed2NestedStruct3InterfaceTraced(testbed2NestedStruct3Interface );
    auto tbEnumEnumInterface = std::make_shared<tb_enum::OLinkEnumInterface>();
    client.linkObjectSource(tbEnumEnumInterface);
    tb_enum::EnumInterfaceTraced tbEnumEnumInterfaceTraced(tbEnumEnumInterface );
    auto tbSame1SameStruct1Interface = std::make_shared<tb_same1::OLinkSameStruct1Interface>();
    client.linkObjectSource(tbSame1SameStruct1Interface);
    tb_same1::SameStruct1InterfaceTraced tbSame1SameStruct1InterfaceTraced(tbSame1SameStruct1Interface );
    auto tbSame1SameStruct2Interface = std::make_shared<tb_same1::OLinkSameStruct2Interface>();
    client.linkObjectSource(tbSame1SameStruct2Interface);
    tb_same1::SameStruct2InterfaceTraced tbSame1SameStruct2InterfaceTraced(tbSame1SameStruct2Interface );
    auto tbSame1SameEnum1Interface = std::make_shared<tb_same1::OLinkSameEnum1Interface>();
    client.linkObjectSource(tbSame1SameEnum1Interface);
    tb_same1::SameEnum1InterfaceTraced tbSame1SameEnum1InterfaceTraced(tbSame1SameEnum1Interface );
    auto tbSame1SameEnum2Interface = std::make_shared<tb_same1::OLinkSameEnum2Interface>();
    client.linkObjectSource(tbSame1SameEnum2Interface);
    tb_same1::SameEnum2InterfaceTraced tbSame1SameEnum2InterfaceTraced(tbSame1SameEnum2Interface );
    auto tbSame2SameStruct1Interface = std::make_shared<tb_same2::OLinkSameStruct1Interface>();
    client.linkObjectSource(tbSame2SameStruct1Interface);
    tb_same2::SameStruct1InterfaceTraced tbSame2SameStruct1InterfaceTraced(tbSame2SameStruct1Interface );
    auto tbSame2SameStruct2Interface = std::make_shared<tb_same2::OLinkSameStruct2Interface>();
    client.linkObjectSource(tbSame2SameStruct2Interface);
    tb_same2::SameStruct2InterfaceTraced tbSame2SameStruct2InterfaceTraced(tbSame2SameStruct2Interface );
    auto tbSame2SameEnum1Interface = std::make_shared<tb_same2::OLinkSameEnum1Interface>();
    client.linkObjectSource(tbSame2SameEnum1Interface);
    tb_same2::SameEnum1InterfaceTraced tbSame2SameEnum1InterfaceTraced(tbSame2SameEnum1Interface );
    auto tbSame2SameEnum2Interface = std::make_shared<tb_same2::OLinkSameEnum2Interface>();
    client.linkObjectSource(tbSame2SameEnum2Interface);
    tb_same2::SameEnum2InterfaceTraced tbSame2SameEnum2InterfaceTraced(tbSame2SameEnum2Interface );
    auto tbSimpleSimpleInterface = std::make_shared<tb_simple::OLinkSimpleInterface>();
    client.linkObjectSource(tbSimpleSimpleInterface);
    tb_simple::SimpleInterfaceTraced tbSimpleSimpleInterfaceTraced(tbSimpleSimpleInterface );
    auto tbSimpleSimpleArrayInterface = std::make_shared<tb_simple::OLinkSimpleArrayInterface>();
    client.linkObjectSource(tbSimpleSimpleArrayInterface);
    tb_simple::SimpleArrayInterfaceTraced tbSimpleSimpleArrayInterfaceTraced(tbSimpleSimpleArrayInterface );
    auto testbed1StructInterface = std::make_shared<testbed1::OLinkStructInterface>();
    client.linkObjectSource(testbed1StructInterface);
    testbed1::StructInterfaceTraced testbed1StructInterfaceTraced(testbed1StructInterface );
    auto testbed1StructArrayInterface = std::make_shared<testbed1::OLinkStructArrayInterface>();
    client.linkObjectSource(testbed1StructArrayInterface);
    testbed1::StructArrayInterfaceTraced testbed1StructArrayInterfaceTraced(testbed1StructArrayInterface );
    auto tbNamesNamEs = std::make_shared<tb_names::OLinkNam_Es>();
    client.linkObjectSource(tbNamesNamEs);
    tb_names::NamEsTraced tbNamesNamEsTraced(tbNamesNamEs );

    
    // Try out properties: subscribe for changes
    testbed2ManyParamInterfaceTraced.connect(&testbed2ManyParamInterfaceTraced, &testbed2::AbstractManyParamInterface::prop1Changed, 
            []( int prop1){ 
                static const std::string message = "prop1 property changed ";
                AG_LOG_DEBUG(message);
            });
    // or ask for change.
    auto local_prop1 = 0;
    testbed2ManyParamInterfaceTraced.setProp1(local_prop1);
    
    // Check the signals with subscribing for its change
    testbed2ManyParamInterfaceTraced.connect(&testbed2ManyParamInterfaceTraced, &testbed2::AbstractManyParamInterface::sig1, 
        [](int param1){
                static const std::string message = "sig1 signal emitted ";
                AG_LOG_DEBUG(message);
        });
    
    // Play around executing your operations
    auto method_result = testbed2ManyParamInterfaceTraced.func1(0);
    

    auto result = app.exec();
    client.unlinkObjectSource(testbed2ManyParamInterface->olinkObjectName());
    client.unlinkObjectSource(testbed2NestedStruct1Interface->olinkObjectName());
    client.unlinkObjectSource(testbed2NestedStruct2Interface->olinkObjectName());
    client.unlinkObjectSource(testbed2NestedStruct3Interface->olinkObjectName());
    client.unlinkObjectSource(tbEnumEnumInterface->olinkObjectName());
    client.unlinkObjectSource(tbSame1SameStruct1Interface->olinkObjectName());
    client.unlinkObjectSource(tbSame1SameStruct2Interface->olinkObjectName());
    client.unlinkObjectSource(tbSame1SameEnum1Interface->olinkObjectName());
    client.unlinkObjectSource(tbSame1SameEnum2Interface->olinkObjectName());
    client.unlinkObjectSource(tbSame2SameStruct1Interface->olinkObjectName());
    client.unlinkObjectSource(tbSame2SameStruct2Interface->olinkObjectName());
    client.unlinkObjectSource(tbSame2SameEnum1Interface->olinkObjectName());
    client.unlinkObjectSource(tbSame2SameEnum2Interface->olinkObjectName());
    client.unlinkObjectSource(tbSimpleSimpleInterface->olinkObjectName());
    client.unlinkObjectSource(tbSimpleSimpleArrayInterface->olinkObjectName());
    client.unlinkObjectSource(testbed1StructInterface->olinkObjectName());
    client.unlinkObjectSource(testbed1StructArrayInterface->olinkObjectName());
    client.unlinkObjectSource(tbNamesNamEs->olinkObjectName());

    return result;
}
