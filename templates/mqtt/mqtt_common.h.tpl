{{- $MODULE_ID := printf "%s_MQTT" (SNAKE .Module.Name) }}
#pragma once

#if defined({{$MODULE_ID}}_LIBRARY)
#  define {{$MODULE_ID}}_LIBRARY_EXPORT Q_DECL_EXPORT
#else
#  define {{$MODULE_ID}}_LIBRARY_EXPORT Q_DECL_IMPORT
#endif
