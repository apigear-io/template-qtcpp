#include <QtQml>
#include <QGuiApplication>
#include "apigear/olink/olinkclient.h"
#include "olink/clientregistry.h"
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


int main(int argc, char *argv[])
{

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    ApiGear::ObjectLink::ClientRegistry registry;
    ApiGear::ObjectLink::OLinkClient client(registry);
    client.connectToHost(QUrl("ws://127.0.0.1:8182"));
    auto testbed2ManyParamInterface = std::make_shared<testbed2::OLinkManyParamInterface>();
    client.linkObjectSource(testbed2ManyParamInterface);testbed2::ManyParamInterfaceTraced testbed2ManyParamInterfaceTraced(testbed2ManyParamInterface );
    auto testbed2NestedStruct1Interface = std::make_shared<testbed2::OLinkNestedStruct1Interface>();
    client.linkObjectSource(testbed2NestedStruct1Interface);testbed2::NestedStruct1InterfaceTraced testbed2NestedStruct1InterfaceTraced(testbed2NestedStruct1Interface );
    auto testbed2NestedStruct2Interface = std::make_shared<testbed2::OLinkNestedStruct2Interface>();
    client.linkObjectSource(testbed2NestedStruct2Interface);testbed2::NestedStruct2InterfaceTraced testbed2NestedStruct2InterfaceTraced(testbed2NestedStruct2Interface );
    auto testbed2NestedStruct3Interface = std::make_shared<testbed2::OLinkNestedStruct3Interface>();
    client.linkObjectSource(testbed2NestedStruct3Interface);testbed2::NestedStruct3InterfaceTraced testbed2NestedStruct3InterfaceTraced(testbed2NestedStruct3Interface );
    auto tbEnumEnumInterface = std::make_shared<tb_enum::OLinkEnumInterface>();
    client.linkObjectSource(tbEnumEnumInterface);tb_enum::EnumInterfaceTraced tbEnumEnumInterfaceTraced(tbEnumEnumInterface );
    auto tbSame1SameStruct1Interface = std::make_shared<tb_same1::OLinkSameStruct1Interface>();
    client.linkObjectSource(tbSame1SameStruct1Interface);tb_same1::SameStruct1InterfaceTraced tbSame1SameStruct1InterfaceTraced(tbSame1SameStruct1Interface );
    auto tbSame1SameStruct2Interface = std::make_shared<tb_same1::OLinkSameStruct2Interface>();
    client.linkObjectSource(tbSame1SameStruct2Interface);tb_same1::SameStruct2InterfaceTraced tbSame1SameStruct2InterfaceTraced(tbSame1SameStruct2Interface );
    auto tbSame1SameEnum1Interface = std::make_shared<tb_same1::OLinkSameEnum1Interface>();
    client.linkObjectSource(tbSame1SameEnum1Interface);tb_same1::SameEnum1InterfaceTraced tbSame1SameEnum1InterfaceTraced(tbSame1SameEnum1Interface );
    auto tbSame1SameEnum2Interface = std::make_shared<tb_same1::OLinkSameEnum2Interface>();
    client.linkObjectSource(tbSame1SameEnum2Interface);tb_same1::SameEnum2InterfaceTraced tbSame1SameEnum2InterfaceTraced(tbSame1SameEnum2Interface );
    auto tbSame2SameStruct1Interface = std::make_shared<tb_same2::OLinkSameStruct1Interface>();
    client.linkObjectSource(tbSame2SameStruct1Interface);tb_same2::SameStruct1InterfaceTraced tbSame2SameStruct1InterfaceTraced(tbSame2SameStruct1Interface );
    auto tbSame2SameStruct2Interface = std::make_shared<tb_same2::OLinkSameStruct2Interface>();
    client.linkObjectSource(tbSame2SameStruct2Interface);tb_same2::SameStruct2InterfaceTraced tbSame2SameStruct2InterfaceTraced(tbSame2SameStruct2Interface );
    auto tbSame2SameEnum1Interface = std::make_shared<tb_same2::OLinkSameEnum1Interface>();
    client.linkObjectSource(tbSame2SameEnum1Interface);tb_same2::SameEnum1InterfaceTraced tbSame2SameEnum1InterfaceTraced(tbSame2SameEnum1Interface );
    auto tbSame2SameEnum2Interface = std::make_shared<tb_same2::OLinkSameEnum2Interface>();
    client.linkObjectSource(tbSame2SameEnum2Interface);tb_same2::SameEnum2InterfaceTraced tbSame2SameEnum2InterfaceTraced(tbSame2SameEnum2Interface );
    auto tbSimpleSimpleInterface = std::make_shared<tb_simple::OLinkSimpleInterface>();
    client.linkObjectSource(tbSimpleSimpleInterface);tb_simple::SimpleInterfaceTraced tbSimpleSimpleInterfaceTraced(tbSimpleSimpleInterface );
    auto tbSimpleSimpleArrayInterface = std::make_shared<tb_simple::OLinkSimpleArrayInterface>();
    client.linkObjectSource(tbSimpleSimpleArrayInterface);tb_simple::SimpleArrayInterfaceTraced tbSimpleSimpleArrayInterfaceTraced(tbSimpleSimpleArrayInterface );
    auto testbed1StructInterface = std::make_shared<testbed1::OLinkStructInterface>();
    client.linkObjectSource(testbed1StructInterface);testbed1::StructInterfaceTraced testbed1StructInterfaceTraced(testbed1StructInterface );
    auto testbed1StructArrayInterface = std::make_shared<testbed1::OLinkStructArrayInterface>();
    client.linkObjectSource(testbed1StructArrayInterface);testbed1::StructArrayInterfaceTraced testbed1StructArrayInterfaceTraced(testbed1StructArrayInterface );

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine,
                     &QQmlApplicationEngine::objectCreated,
                     &app,
                     [url](QObject *obj, const QUrl &objUrl) {
                       if (!obj && url == objUrl)
                        QCoreApplication::exit(-1);
                     },
                     Qt::QueuedConnection);
    engine.load(url);

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

    return result;
}
