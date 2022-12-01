#pragma once

#include <QtCore>

#include "{{snake .Module.Name}}/api/apifactory.h"
#include "olink/clientnode.h"

class OLinkFactory : public QObject, public ApiFactoryInterface
{
public:
    OLinkFactory(ApiGear::ObjectLink::ClientRegistry& registry, QObject *parent = nullptr);
{{- range .Module.Interfaces }}
    Abstract{{.Name}}* create{{Camel .Name}}(QObject *parent) override;
{{- end }}
private:
ApiGear::ObjectLink::ClientRegistry& m_registry;
};
