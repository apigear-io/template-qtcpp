{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
{{- $MODULE_ID := printf "%s" (SNAKE .Module.Name) }}

#pragma once

#include <QtQml>

#if defined({{$MODULE_ID}}_PLUGIN_LIBRARY)
#  define {{$MODULE_ID}}_PLUGIN_EXPORT Q_DECL_EXPORT
#else
#  define {{$MODULE_ID}}_PLUGIN_EXPORT Q_DECL_IMPORT
#endif


/** A QML extension plugin for {{.Module}} */
class {{$MODULE_ID}}_PLUGIN_EXPORT Plugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    /** Registers all the enums, sturcts and QML versions of implementation for interfaces in this module. */
    void registerTypes(const char *uri) override;
};
