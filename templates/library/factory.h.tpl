#pragma once

#include <QtCore>

#include "{{snake .Module.Name}}/api/apifactory.h"

class Factory : public QObject, public ApiFactoryInterface
{
public:
    Factory(QObject *parent = nullptr);
{{- range .Module.Interfaces }}
    Abstract{{.Name}}* create{{Camel .Name}}(QObject *parent) override;
{{- end }}
};
