import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import net.olink 1.0


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    GridLayout {
        columns: 4
        anchors.fill: parent
        Button {
            text: calc.total
            Layout.fillWidth: true
        }
        Button {
            text: "Add"
            onClicked: calc.add(2);
            Layout.fillWidth: true
        }
        Button {
            text:  "Sub"
            onClicked: calc.sub(1);
            Layout.fillWidth: true
        }
        Button {
            text:  "Clear"
            onClicked: calc.clear()
            Layout.fillWidth: true
        }
    }


    Calculator {
        id: calc
        onIsReadyChanged: {
            console.log("isReady=", isReady)
        }
        onTotalChanged: {
            console.log("total changed", total)
        }
    }

}
