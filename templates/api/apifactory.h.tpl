{{- $MODULE_ID := (SNAKE .Module.Name) }}
#pragma once

#include <QtCore>
#include "api.h"

class {{ $MODULE_ID }}_EXPORT ApiFactory : public QObject, public ApiFactoryInterface
{
    Q_OBJECT
public:
    ApiFactory(QObject *parent=nullptr);
    static void set(ApiFactoryInterface *instance);
    static ApiFactoryInterface *get();

{{- range .Module.Interfaces }}
    virtual Abstract{{.Name}}* create{{Camel .Name }}(QObject *parent);
{{- end }}
private:
    static ApiFactoryInterface *s_instance;
};
