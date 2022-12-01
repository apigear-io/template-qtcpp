{{- range .System.Modules }}
{{- $module := . }}
{{- range $module.Interfaces }}
{{- $interface := . }}
#include "{{snake $module.Name}}/lib/{{ lower ( camel $interface.Name) }}.h"
#include "{{snake $module.Name}}//olink/olink{{ lower ( camel $interface.Name) }}adapter.h"
{{- end }}
{{- end }}

#include <QtCore>
#include "apigear/olink/olinkhost.h"
#include "olink/remoteregistry.h"
#include <memory>

#include <iostream>

int main(){

    ApiGear::ObjectLink::RemoteRegistry registry;
    ApiGear::ObjectLink::OLinkHost server(registry);
    server.listen("localhost", 8182);

    {{- range.System.Modules }}
    {{- $module := . }}
    {{- range $module.Interfaces }}
    {{- $interface := . }}
    {{- $class := Camel $interface.Name }}
    {{- $modulePrefix := lower1 (Camel $module.Name)}}
    {{- $instanceName := printf "%s%s"  $modulePrefix $class }}
    {{- $serviceInstanceName := printf "%sOlink%sService" $modulePrefix $class }}
    {{ snake $module.Name }}::{{$class}} {{$instanceName}};
    auto {{$serviceInstanceName}} = std::make_shared< {{- snake $module.Name }}::OLink{{$interface.Name}}Adapter>(registry, &{{ $instanceName }});
    registry.addSource( {{- $serviceInstanceName }});
    {{- end }}
    {{- end }}

    // Use the server.
    {{- range.System.Modules }}
    {{- $module := . }}
    {{- range $module.Interfaces }}
    {{- $interface := . }}
    {{- $class := Camel $interface.Name }}
    {{- $modulePrefix := lower1 (Camel $module.Name)}}
    {{- $serviceInstanceName := printf "%sOlink%sService" $modulePrefix $class }}
    registry.removeSource( {{- $serviceInstanceName }}->olinkObjectName());
    {{- end }}
    {{- end }}
    return 0;
}
