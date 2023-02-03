{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
#pragma once

#include <QtQml>
/** A QML extension plugin for {{.Module}} */
class Plugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    /** Registers all the enums, sturcts and QML versions of implementation for interfaces in this module. */
    void registerTypes(const char *uri) override;
};
