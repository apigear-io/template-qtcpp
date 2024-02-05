import QtQuick 2.15
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.15
import testbed2 1.0
import testbed2.Struct1FactorySingleton 1.0
import testbed2.Struct2FactorySingleton 1.0
import testbed2.Struct3FactorySingleton 1.0
import testbed2.Struct4FactorySingleton 1.0
import testbed2.NestedStruct1FactorySingleton 1.0
import testbed2.NestedStruct2FactorySingleton 1.0
import testbed2.NestedStruct3FactorySingleton 1.0
import tb.enum 1.0
import tb.same1 1.0
import tb.same1.Struct1FactorySingleton 1.0
import tb.same1.Struct2FactorySingleton 1.0
import tb.same2 1.0
import tb.same2.Struct1FactorySingleton 1.0
import tb.same2.Struct2FactorySingleton 1.0
import tb.simple 1.0
import testbed1 1.0
import testbed1.StructBoolFactorySingleton 1.0
import testbed1.StructIntFactorySingleton 1.0
import testbed1.StructFloatFactorySingleton 1.0
import testbed1.StructStringFactorySingleton 1.0
import tb.names 1.0

ApplicationWindow {
    id: appWindow
    visible: true
    width: 300
    height: 300
    ColumnLayout {
        spacing: 10
        id: mainLayout
        anchors.fill: parent

        Button {
            width: 200
            height: 200
            text: "Add your property or signal bindings"
            onClicked: {
                console.log("Or events like changing properties or invoking methods")
            }
        }
    }
    Testbed2ManyParamInterface { id: qmlTestbed2ManyParamInterface }
    Testbed2NestedStruct1Interface { id: qmlTestbed2NestedStruct1Interface }
    Testbed2NestedStruct2Interface { id: qmlTestbed2NestedStruct2Interface }
    Testbed2NestedStruct3Interface { id: qmlTestbed2NestedStruct3Interface }
    TbEnumEnumInterface { id: qmlTbEnumEnumInterface }
    TbSame1SameStruct1Interface { id: qmlTbSame1SameStruct1Interface }
    TbSame1SameStruct2Interface { id: qmlTbSame1SameStruct2Interface }
    TbSame1SameEnum1Interface { id: qmlTbSame1SameEnum1Interface }
    TbSame1SameEnum2Interface { id: qmlTbSame1SameEnum2Interface }
    TbSame2SameStruct1Interface { id: qmlTbSame2SameStruct1Interface }
    TbSame2SameStruct2Interface { id: qmlTbSame2SameStruct2Interface }
    TbSame2SameEnum1Interface { id: qmlTbSame2SameEnum1Interface }
    TbSame2SameEnum2Interface { id: qmlTbSame2SameEnum2Interface }
    TbSimpleSimpleInterface { id: qmlTbSimpleSimpleInterface }
    TbSimpleSimpleArrayInterface { id: qmlTbSimpleSimpleArrayInterface }
    Testbed1StructInterface { id: qmlTestbed1StructInterface }
    Testbed1StructArrayInterface { id: qmlTestbed1StructArrayInterface }
    TbNamesNam_Es { id: qmlTbNamesNam_Es }

}
