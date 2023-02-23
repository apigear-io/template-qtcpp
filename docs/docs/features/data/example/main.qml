import QtQuick 2.15
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.15
import io.world 1.0
import io.world.MessageFactorySingleton 1.0

ApplicationWindow {
    id: appWindow
    visible: true
    width: 300
    height: 250
    ColumnLayout {
        spacing: 10
        id: mainLayout
        anchors.fill: parent

        Button {
            id: button1
            Layout.alignment: Qt.AlignCenter
            background: Rectangle {
                implicitWidth: 250
                implicitHeight: 50
                radius: 4
                color: "#9ed545"
            }
            text: "Click to get result of a method"
            onClicked: {
                var msg = IoWorldMessageFactory.create()
                msg.content = "some message"
                qmlIoWorldHello.say(msg, IoWorldWhen.New)
            }
        }
        Button {
            id: button2
            Layout.alignment: Qt.AlignCenter
            background: Rectangle {
                implicitWidth: 250
                implicitHeight: 50
                radius: 4
                color: "#9ed545"
            }
            text: qmlIoWorldHello.last.content
            onClicked: {
                console.log("Or events like changing properties or invoking methods")
            }
        }
        Button {
            id: button3
            Layout.alignment: Qt.AlignCenter
            background: Rectangle {
                implicitWidth: 250
                implicitHeight: 50
                radius: 4
                color: "#9ed545"
            }
            text: "Will show singal message"
        }
    }
    IoWorldHello { id: qmlIoWorldHello
        onJustSaid:{
            console.log("signal received")
            button3.text = msg.content
        }
    }

}
