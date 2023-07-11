import QtQuick 2.15
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.15
{{- range .System.Modules }}
{{- $module := . }}
{{- $version := .Version }}
import {{ snake $module.Name }} {{$version.Major}}.{{$version.Minor}}
{{- end }}

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

{{- range.System.Modules }}
{{- $module := . }}
{{- $Modulename := Camel $module.Name }}
{{- range $module.Interfaces }}
{{- $interface := . }}
    {{$Modulename}}{{Camel $interface.Name}} { id: qml{{$Modulename}}{{$interface.Name}} }
{{- end }}
{{- end }}

}
