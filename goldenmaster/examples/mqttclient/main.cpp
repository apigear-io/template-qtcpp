#include <QGuiApplication>
#include "utilities/logger.h"
#include "apigear/mqtt/mqttclient.h"

#include <memory>
#include "testbed2/mqtt/mqttmanyparaminterface.h"
#include "testbed2/monitor/manyparaminterfacetraced.h"
#include "testbed2/mqtt/mqttnestedstruct1interface.h"
#include "testbed2/monitor/nestedstruct1interfacetraced.h"
#include "testbed2/mqtt/mqttnestedstruct2interface.h"
#include "testbed2/monitor/nestedstruct2interfacetraced.h"
#include "testbed2/mqtt/mqttnestedstruct3interface.h"
#include "testbed2/monitor/nestedstruct3interfacetraced.h"
#include "tb_enum/mqtt/mqttenuminterface.h"
#include "tb_enum/monitor/enuminterfacetraced.h"
#include "tb_same1/mqtt/mqttsamestruct1interface.h"
#include "tb_same1/monitor/samestruct1interfacetraced.h"
#include "tb_same1/mqtt/mqttsamestruct2interface.h"
#include "tb_same1/monitor/samestruct2interfacetraced.h"
#include "tb_same1/mqtt/mqttsameenum1interface.h"
#include "tb_same1/monitor/sameenum1interfacetraced.h"
#include "tb_same1/mqtt/mqttsameenum2interface.h"
#include "tb_same1/monitor/sameenum2interfacetraced.h"
#include "tb_same2/mqtt/mqttsamestruct1interface.h"
#include "tb_same2/monitor/samestruct1interfacetraced.h"
#include "tb_same2/mqtt/mqttsamestruct2interface.h"
#include "tb_same2/monitor/samestruct2interfacetraced.h"
#include "tb_same2/mqtt/mqttsameenum1interface.h"
#include "tb_same2/monitor/sameenum1interfacetraced.h"
#include "tb_same2/mqtt/mqttsameenum2interface.h"
#include "tb_same2/monitor/sameenum2interfacetraced.h"
#include "tb_simple/mqtt/mqttvoidinterface.h"
#include "tb_simple/monitor/voidinterfacetraced.h"
#include "tb_simple/mqtt/mqttsimpleinterface.h"
#include "tb_simple/monitor/simpleinterfacetraced.h"
#include "tb_simple/mqtt/mqttsimplearrayinterface.h"
#include "tb_simple/monitor/simplearrayinterfacetraced.h"
#include "tb_simple/mqtt/mqttnopropertiesinterface.h"
#include "tb_simple/monitor/nopropertiesinterfacetraced.h"
#include "tb_simple/mqtt/mqttnooperationsinterface.h"
#include "tb_simple/monitor/nooperationsinterfacetraced.h"
#include "tb_simple/mqtt/mqttnosignalsinterface.h"
#include "tb_simple/monitor/nosignalsinterfacetraced.h"
#include "testbed1/mqtt/mqttstructinterface.h"
#include "testbed1/monitor/structinterfacetraced.h"
#include "testbed1/mqtt/mqttstructarrayinterface.h"
#include "testbed1/monitor/structarrayinterfacetraced.h"
#include "tb_names/mqtt/mqttnam_es.h"
#include "tb_names/monitor/nam_estraced.h"
#include "counter/mqtt/mqttcounter.h"
#include "counter/monitor/countertraced.h"


// You can run this client app together with the service side app - either also example, simulation,
// or implemented mqtt service (may be in other technology) to play around with it.
// Remember to use also a mqtt broker of your choice.
// Be aware that some brokers limit maximum number of messages queued per client, if you send a lot of messages consider using more clients
// e.g. one per interface.
// Have in mind, that this example only instantiates the interfaces, you need to add some action to it by yourself, like:
// changing properties or executing methods, also make sure you are subscribed for the changes and signals.
// If you use a service example try out implementing some changes like: setting some properties or emitting signals to see any effects here.

// If you are running this example from qt creator make sure that the run project settings have "run in terminal" option selected.

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    ApiGear::Mqtt::Client client("UniqueClientName");
    client.connectToHost("localhost", 1883);
    auto testbed2ManyParamInterface = std::make_shared<testbed2::MqttManyParamInterface>(client);
    testbed2::ManyParamInterfaceTraced testbed2ManyParamInterfaceTraced(testbed2ManyParamInterface );
    auto testbed2NestedStruct1Interface = std::make_shared<testbed2::MqttNestedStruct1Interface>(client);
    testbed2::NestedStruct1InterfaceTraced testbed2NestedStruct1InterfaceTraced(testbed2NestedStruct1Interface );
    auto testbed2NestedStruct2Interface = std::make_shared<testbed2::MqttNestedStruct2Interface>(client);
    testbed2::NestedStruct2InterfaceTraced testbed2NestedStruct2InterfaceTraced(testbed2NestedStruct2Interface );
    auto testbed2NestedStruct3Interface = std::make_shared<testbed2::MqttNestedStruct3Interface>(client);
    testbed2::NestedStruct3InterfaceTraced testbed2NestedStruct3InterfaceTraced(testbed2NestedStruct3Interface );
    auto tbEnumEnumInterface = std::make_shared<tb_enum::MqttEnumInterface>(client);
    tb_enum::EnumInterfaceTraced tbEnumEnumInterfaceTraced(tbEnumEnumInterface );
    auto tbSame1SameStruct1Interface = std::make_shared<tb_same1::MqttSameStruct1Interface>(client);
    tb_same1::SameStruct1InterfaceTraced tbSame1SameStruct1InterfaceTraced(tbSame1SameStruct1Interface );
    auto tbSame1SameStruct2Interface = std::make_shared<tb_same1::MqttSameStruct2Interface>(client);
    tb_same1::SameStruct2InterfaceTraced tbSame1SameStruct2InterfaceTraced(tbSame1SameStruct2Interface );
    auto tbSame1SameEnum1Interface = std::make_shared<tb_same1::MqttSameEnum1Interface>(client);
    tb_same1::SameEnum1InterfaceTraced tbSame1SameEnum1InterfaceTraced(tbSame1SameEnum1Interface );
    auto tbSame1SameEnum2Interface = std::make_shared<tb_same1::MqttSameEnum2Interface>(client);
    tb_same1::SameEnum2InterfaceTraced tbSame1SameEnum2InterfaceTraced(tbSame1SameEnum2Interface );
    auto tbSame2SameStruct1Interface = std::make_shared<tb_same2::MqttSameStruct1Interface>(client);
    tb_same2::SameStruct1InterfaceTraced tbSame2SameStruct1InterfaceTraced(tbSame2SameStruct1Interface );
    auto tbSame2SameStruct2Interface = std::make_shared<tb_same2::MqttSameStruct2Interface>(client);
    tb_same2::SameStruct2InterfaceTraced tbSame2SameStruct2InterfaceTraced(tbSame2SameStruct2Interface );
    auto tbSame2SameEnum1Interface = std::make_shared<tb_same2::MqttSameEnum1Interface>(client);
    tb_same2::SameEnum1InterfaceTraced tbSame2SameEnum1InterfaceTraced(tbSame2SameEnum1Interface );
    auto tbSame2SameEnum2Interface = std::make_shared<tb_same2::MqttSameEnum2Interface>(client);
    tb_same2::SameEnum2InterfaceTraced tbSame2SameEnum2InterfaceTraced(tbSame2SameEnum2Interface );
    auto tbSimpleVoidInterface = std::make_shared<tb_simple::MqttVoidInterface>(client);
    tb_simple::VoidInterfaceTraced tbSimpleVoidInterfaceTraced(tbSimpleVoidInterface );
    auto tbSimpleSimpleInterface = std::make_shared<tb_simple::MqttSimpleInterface>(client);
    tb_simple::SimpleInterfaceTraced tbSimpleSimpleInterfaceTraced(tbSimpleSimpleInterface );
    auto tbSimpleSimpleArrayInterface = std::make_shared<tb_simple::MqttSimpleArrayInterface>(client);
    tb_simple::SimpleArrayInterfaceTraced tbSimpleSimpleArrayInterfaceTraced(tbSimpleSimpleArrayInterface );
    auto tbSimpleNoPropertiesInterface = std::make_shared<tb_simple::MqttNoPropertiesInterface>(client);
    tb_simple::NoPropertiesInterfaceTraced tbSimpleNoPropertiesInterfaceTraced(tbSimpleNoPropertiesInterface );
    auto tbSimpleNoOperationsInterface = std::make_shared<tb_simple::MqttNoOperationsInterface>(client);
    tb_simple::NoOperationsInterfaceTraced tbSimpleNoOperationsInterfaceTraced(tbSimpleNoOperationsInterface );
    auto tbSimpleNoSignalsInterface = std::make_shared<tb_simple::MqttNoSignalsInterface>(client);
    tb_simple::NoSignalsInterfaceTraced tbSimpleNoSignalsInterfaceTraced(tbSimpleNoSignalsInterface );
    auto testbed1StructInterface = std::make_shared<testbed1::MqttStructInterface>(client);
    testbed1::StructInterfaceTraced testbed1StructInterfaceTraced(testbed1StructInterface );
    auto testbed1StructArrayInterface = std::make_shared<testbed1::MqttStructArrayInterface>(client);
    testbed1::StructArrayInterfaceTraced testbed1StructArrayInterfaceTraced(testbed1StructArrayInterface );
    auto tbNamesNamEs = std::make_shared<tb_names::MqttNam_Es>(client);
    tb_names::NamEsTraced tbNamesNamEsTraced(tbNamesNamEs );
    auto counterCounter = std::make_shared<counter::MqttCounter>(client);
    counter::CounterTraced counterCounterTraced(counterCounter );

    
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

    return result;
}
