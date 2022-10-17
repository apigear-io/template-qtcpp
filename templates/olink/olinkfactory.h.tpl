#pragma once

#include <QtCore>

#include "../api/apifactory.h"

class OLinkFactory : public QObject, public ApiFactoryInterface
{
public:
    OLinkFactory(QObject *parent = nullptr);
{{- range .Module.Interfaces }}
    Abstract{{.Name}}* create{{Camel .Name}}(QObject *parent) override;
{{- end }}
};
