{% comment %} // Copyright (c) ApiGear UG 2020 {% endcomment -%}
{{ cppGpl .Module }}
#pragma once

#include <QtQml>

class Plugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri) override;
};
