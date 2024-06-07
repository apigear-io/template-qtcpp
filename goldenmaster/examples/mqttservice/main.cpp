
#include "testbed2/implementation/manyparaminterface.h"
#include "testbed2/mqtt/mqttmanyparaminterfaceadapter.h"
#include "testbed2/monitor/manyparaminterfacetraced.h"
#include "testbed2/implementation/nestedstruct1interface.h"
#include "testbed2/mqtt/mqttnestedstruct1interfaceadapter.h"
#include "testbed2/monitor/nestedstruct1interfacetraced.h"
#include "testbed2/implementation/nestedstruct2interface.h"
#include "testbed2/mqtt/mqttnestedstruct2interfaceadapter.h"
#include "testbed2/monitor/nestedstruct2interfacetraced.h"
#include "testbed2/implementation/nestedstruct3interface.h"
#include "testbed2/mqtt/mqttnestedstruct3interfaceadapter.h"
#include "testbed2/monitor/nestedstruct3interfacetraced.h"
#include "tb_enum/implementation/enuminterface.h"
#include "tb_enum/mqtt/mqttenuminterfaceadapter.h"
#include "tb_enum/monitor/enuminterfacetraced.h"
#include "tb_same1/implementation/samestruct1interface.h"
#include "tb_same1/mqtt/mqttsamestruct1interfaceadapter.h"
#include "tb_same1/monitor/samestruct1interfacetraced.h"
#include "tb_same1/implementation/samestruct2interface.h"
#include "tb_same1/mqtt/mqttsamestruct2interfaceadapter.h"
#include "tb_same1/monitor/samestruct2interfacetraced.h"
#include "tb_same1/implementation/sameenum1interface.h"
#include "tb_same1/mqtt/mqttsameenum1interfaceadapter.h"
#include "tb_same1/monitor/sameenum1interfacetraced.h"
#include "tb_same1/implementation/sameenum2interface.h"
#include "tb_same1/mqtt/mqttsameenum2interfaceadapter.h"
#include "tb_same1/monitor/sameenum2interfacetraced.h"
#include "tb_same2/implementation/samestruct1interface.h"
#include "tb_same2/mqtt/mqttsamestruct1interfaceadapter.h"
#include "tb_same2/monitor/samestruct1interfacetraced.h"
#include "tb_same2/implementation/samestruct2interface.h"
#include "tb_same2/mqtt/mqttsamestruct2interfaceadapter.h"
#include "tb_same2/monitor/samestruct2interfacetraced.h"
#include "tb_same2/implementation/sameenum1interface.h"
#include "tb_same2/mqtt/mqttsameenum1interfaceadapter.h"
#include "tb_same2/monitor/sameenum1interfacetraced.h"
#include "tb_same2/implementation/sameenum2interface.h"
#include "tb_same2/mqtt/mqttsameenum2interfaceadapter.h"
#include "tb_same2/monitor/sameenum2interfacetraced.h"
#include "tb_simple/implementation/simpleinterface.h"
#include "tb_simple/mqtt/mqttsimpleinterfaceadapter.h"
#include "tb_simple/monitor/simpleinterfacetraced.h"
#include "tb_simple/implementation/simplearrayinterface.h"
#include "tb_simple/mqtt/mqttsimplearrayinterfaceadapter.h"
#include "tb_simple/monitor/simplearrayinterfacetraced.h"
#include "testbed1/implementation/structinterface.h"
#include "testbed1/mqtt/mqttstructinterfaceadapter.h"
#include "testbed1/monitor/structinterfacetraced.h"
#include "testbed1/implementation/structarrayinterface.h"
#include "testbed1/mqtt/mqttstructarrayinterfaceadapter.h"
#include "testbed1/monitor/structarrayinterfacetraced.h"
#include "tb_names/implementation/nam_es.h"
#include "tb_names/mqtt/mqttnam_esadapter.h"
#include "tb_names/monitor/nam_estraced.h"

#include <QtCore>
#include "apigear/mqtt/mqttservice.h"
#include <memory>

#include <iostream>

// You can run this service app together with the client side app - either also example,
// or implemented mqtt client (may be using other technology) to play around with it.
// Remember to use also a mqtt broker of your choice.
// Be aware that some brokers limit maximum number of messages queued per client, if you send a lot of messages consider using more clients
// e.g. one per interface.
// Have in mind, that this example only instantiates the interfaces and the services.
// To see results make sure the clients are sending request to server or add some actions by yourself.
// If you are running this example from qt creator make sure that the run project settings have "run in terminal" option selected.

int main(int argc, char *argv[]){

    QCoreApplication app(argc, argv);
    ApiGear::Mqtt::ServiceAdapter service("ServiceUniqueNameInMqtt");
    service.connectToHost("localhost", 1883);
    
    auto testbed2ManyParamInterface = std::make_shared<testbed2::ManyParamInterface>();
    auto testbed2ManyParamInterfaceTraced = std::make_shared<testbed2::ManyParamInterfaceTraced>(testbed2ManyParamInterface );
    auto testbed2MqttManyParamInterfaceService = std::make_shared<testbed2::MqttManyParamInterfaceAdapter>(service, testbed2ManyParamInterfaceTraced);
    
    auto testbed2NestedStruct1Interface = std::make_shared<testbed2::NestedStruct1Interface>();
    auto testbed2NestedStruct1InterfaceTraced = std::make_shared<testbed2::NestedStruct1InterfaceTraced>(testbed2NestedStruct1Interface );
    auto testbed2MqttNestedStruct1InterfaceService = std::make_shared<testbed2::MqttNestedStruct1InterfaceAdapter>(service, testbed2NestedStruct1InterfaceTraced);
    
    auto testbed2NestedStruct2Interface = std::make_shared<testbed2::NestedStruct2Interface>();
    auto testbed2NestedStruct2InterfaceTraced = std::make_shared<testbed2::NestedStruct2InterfaceTraced>(testbed2NestedStruct2Interface );
    auto testbed2MqttNestedStruct2InterfaceService = std::make_shared<testbed2::MqttNestedStruct2InterfaceAdapter>(service, testbed2NestedStruct2InterfaceTraced);
    
    auto testbed2NestedStruct3Interface = std::make_shared<testbed2::NestedStruct3Interface>();
    auto testbed2NestedStruct3InterfaceTraced = std::make_shared<testbed2::NestedStruct3InterfaceTraced>(testbed2NestedStruct3Interface );
    auto testbed2MqttNestedStruct3InterfaceService = std::make_shared<testbed2::MqttNestedStruct3InterfaceAdapter>(service, testbed2NestedStruct3InterfaceTraced);
    
    auto tbEnumEnumInterface = std::make_shared<tb_enum::EnumInterface>();
    auto tbEnumEnumInterfaceTraced = std::make_shared<tb_enum::EnumInterfaceTraced>(tbEnumEnumInterface );
    auto tbEnumMqttEnumInterfaceService = std::make_shared<tb_enum::MqttEnumInterfaceAdapter>(service, tbEnumEnumInterfaceTraced);
    
    auto tbSame1SameStruct1Interface = std::make_shared<tb_same1::SameStruct1Interface>();
    auto tbSame1SameStruct1InterfaceTraced = std::make_shared<tb_same1::SameStruct1InterfaceTraced>(tbSame1SameStruct1Interface );
    auto tbSame1MqttSameStruct1InterfaceService = std::make_shared<tb_same1::MqttSameStruct1InterfaceAdapter>(service, tbSame1SameStruct1InterfaceTraced);
    
    auto tbSame1SameStruct2Interface = std::make_shared<tb_same1::SameStruct2Interface>();
    auto tbSame1SameStruct2InterfaceTraced = std::make_shared<tb_same1::SameStruct2InterfaceTraced>(tbSame1SameStruct2Interface );
    auto tbSame1MqttSameStruct2InterfaceService = std::make_shared<tb_same1::MqttSameStruct2InterfaceAdapter>(service, tbSame1SameStruct2InterfaceTraced);
    
    auto tbSame1SameEnum1Interface = std::make_shared<tb_same1::SameEnum1Interface>();
    auto tbSame1SameEnum1InterfaceTraced = std::make_shared<tb_same1::SameEnum1InterfaceTraced>(tbSame1SameEnum1Interface );
    auto tbSame1MqttSameEnum1InterfaceService = std::make_shared<tb_same1::MqttSameEnum1InterfaceAdapter>(service, tbSame1SameEnum1InterfaceTraced);
    
    auto tbSame1SameEnum2Interface = std::make_shared<tb_same1::SameEnum2Interface>();
    auto tbSame1SameEnum2InterfaceTraced = std::make_shared<tb_same1::SameEnum2InterfaceTraced>(tbSame1SameEnum2Interface );
    auto tbSame1MqttSameEnum2InterfaceService = std::make_shared<tb_same1::MqttSameEnum2InterfaceAdapter>(service, tbSame1SameEnum2InterfaceTraced);
    
    auto tbSame2SameStruct1Interface = std::make_shared<tb_same2::SameStruct1Interface>();
    auto tbSame2SameStruct1InterfaceTraced = std::make_shared<tb_same2::SameStruct1InterfaceTraced>(tbSame2SameStruct1Interface );
    auto tbSame2MqttSameStruct1InterfaceService = std::make_shared<tb_same2::MqttSameStruct1InterfaceAdapter>(service, tbSame2SameStruct1InterfaceTraced);
    
    auto tbSame2SameStruct2Interface = std::make_shared<tb_same2::SameStruct2Interface>();
    auto tbSame2SameStruct2InterfaceTraced = std::make_shared<tb_same2::SameStruct2InterfaceTraced>(tbSame2SameStruct2Interface );
    auto tbSame2MqttSameStruct2InterfaceService = std::make_shared<tb_same2::MqttSameStruct2InterfaceAdapter>(service, tbSame2SameStruct2InterfaceTraced);
    
    auto tbSame2SameEnum1Interface = std::make_shared<tb_same2::SameEnum1Interface>();
    auto tbSame2SameEnum1InterfaceTraced = std::make_shared<tb_same2::SameEnum1InterfaceTraced>(tbSame2SameEnum1Interface );
    auto tbSame2MqttSameEnum1InterfaceService = std::make_shared<tb_same2::MqttSameEnum1InterfaceAdapter>(service, tbSame2SameEnum1InterfaceTraced);
    
    auto tbSame2SameEnum2Interface = std::make_shared<tb_same2::SameEnum2Interface>();
    auto tbSame2SameEnum2InterfaceTraced = std::make_shared<tb_same2::SameEnum2InterfaceTraced>(tbSame2SameEnum2Interface );
    auto tbSame2MqttSameEnum2InterfaceService = std::make_shared<tb_same2::MqttSameEnum2InterfaceAdapter>(service, tbSame2SameEnum2InterfaceTraced);
    
    auto tbSimpleSimpleInterface = std::make_shared<tb_simple::SimpleInterface>();
    auto tbSimpleSimpleInterfaceTraced = std::make_shared<tb_simple::SimpleInterfaceTraced>(tbSimpleSimpleInterface );
    auto tbSimpleMqttSimpleInterfaceService = std::make_shared<tb_simple::MqttSimpleInterfaceAdapter>(service, tbSimpleSimpleInterfaceTraced);
    
    auto tbSimpleSimpleArrayInterface = std::make_shared<tb_simple::SimpleArrayInterface>();
    auto tbSimpleSimpleArrayInterfaceTraced = std::make_shared<tb_simple::SimpleArrayInterfaceTraced>(tbSimpleSimpleArrayInterface );
    auto tbSimpleMqttSimpleArrayInterfaceService = std::make_shared<tb_simple::MqttSimpleArrayInterfaceAdapter>(service, tbSimpleSimpleArrayInterfaceTraced);
    
    auto testbed1StructInterface = std::make_shared<testbed1::StructInterface>();
    auto testbed1StructInterfaceTraced = std::make_shared<testbed1::StructInterfaceTraced>(testbed1StructInterface );
    auto testbed1MqttStructInterfaceService = std::make_shared<testbed1::MqttStructInterfaceAdapter>(service, testbed1StructInterfaceTraced);
    
    auto testbed1StructArrayInterface = std::make_shared<testbed1::StructArrayInterface>();
    auto testbed1StructArrayInterfaceTraced = std::make_shared<testbed1::StructArrayInterfaceTraced>(testbed1StructArrayInterface );
    auto testbed1MqttStructArrayInterfaceService = std::make_shared<testbed1::MqttStructArrayInterfaceAdapter>(service, testbed1StructArrayInterfaceTraced);
    
    auto tbNamesNamEs = std::make_shared<tb_names::NamEs>();
    auto tbNamesNamEsTraced = std::make_shared<tb_names::NamEsTraced>(tbNamesNamEs );
    auto tbNamesMqttNamEsService = std::make_shared<tb_names::MqttNam_EsAdapter>(service, tbNamesNamEsTraced);

    auto result = app.exec();
    // Use the server.
    return result;
}
