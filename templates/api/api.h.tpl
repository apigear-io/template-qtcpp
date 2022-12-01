{{- /* Copyright (c) ApiGear UG 2020 */}}
{{- $MODULE_ID := SNAKE .Module.Name }}
{{- $module_id := snake .Module.Name }}
{{- cppGpl .Module }}
#pragma once

#include <QtCore>
#include <QtCore/QtGlobal>

#if defined({{ $MODULE_ID }}_LIBRARY)
#  define {{ $MODULE_ID }}_EXPORT Q_DECL_EXPORT
#else
#  define {{ $MODULE_ID }}_EXPORT Q_DECL_IMPORT
#endif

namespace {{snake  .Module.Name }} {

{{- range .Module.Enums }}
{{- $class := .Name }}

// ********************************************************************
// Enumeration {{ $class }}
// ********************************************************************

class {{ $MODULE_ID }}_EXPORT {{ $class }} : public QObject {
    Q_OBJECT
public:
    {{ $class }}(QObject *parent = nullptr)
        : QObject(parent)
        {}
    enum {{ $class }}Enum {
    {{- range .Members }}
        {{.Name}} = {{ .Value }},
    {{- end }}
    };
    Q_ENUM({{$class}}Enum)

    static {{$class}}Enum toEnum(quint8 v, bool *ok);
};


inline QDataStream &operator<<(QDataStream &ds, const {{$class}}::{{$class}}Enum &obj)
{
    quint8 val = obj;
    ds << val;
    return ds;
}

inline QDataStream &operator>>(QDataStream &ds, {{$class}}::{{$class}}Enum &obj) {
    bool ok;
    quint8 val;
    ds >> val;
    obj = {{$class}}::toEnum(val, &ok);
    if (!ok) {
        qWarning() << "received an invalid enum value for typeState, value =" << val;
    }
    return ds;
}
{{- end }}
{{- range .Module.Structs }}
{{- $class := .Name }}
// ********************************************************************
// {{$class}} struct
// ********************************************************************

class {{ $MODULE_ID }}_EXPORT {{$class}}
{
    Q_GADGET
{{- range .Fields }}
    Q_PROPERTY({{qtReturn "" .}} {{.Name}} READ {{.Name}} WRITE set{{Camel .Name}})
{{- end }}

public:
    {{$class}}();

{{- range .Fields }}
    void set{{Camel .Name}}({{qtParam "" .}});
    {{qtReturn "" .}} {{.Name}}() const;

{{- end }}

    bool operator==(const {{$class}} &other) const;
    bool operator!=(const {{$class}} &other) const;

private:
{{- range .Fields }}
    {{qtReturn "" .}} m_{{.Name}};
{{- end }}
};

QDataStream &operator<<(QDataStream &stream, const {{$class}} &obj);
QDataStream &operator>>(QDataStream &stream, {{$class}} &obj);

// ********************************************************************
// {{$class}} struct factory
// ********************************************************************

class {{ $MODULE_ID }}_EXPORT {{$class}}Factory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE {{$class}} create();
};


{{- end }}
{{ range .Module.Interfaces }}
{{- $class := printf "Abstract%s" .Name }}
// ********************************************************************
// {{$class}} pure interface
// ********************************************************************


class {{ $MODULE_ID }}_EXPORT {{$class}} : public QObject {
    Q_OBJECT
public:
    {{$class}}(QObject * parent=nullptr);
{{- range .Properties }}
    virtual void set{{Camel .Name}}({{qtParam "" .}}) = 0;
    virtual {{qtReturn "" .}} {{.Name}}() const = 0;
{{- end }}

{{- range .Operations }}
    virtual {{qtReturn "" .Return }} {{.Name}}({{qtParams "" .Params}}) = 0;
{{- end }}
signals:
{{- range .Signals }}
    void {{.Name}}({{qtParams "" .Params}});
{{- end }}
{{- range .Properties }}
    void {{.Name}}Changed({{qtParam "" .}});
{{- end }}
};
{{ end }}

// ********************************************************************
// Interface Factory
// ********************************************************************

class {{ $MODULE_ID }}_EXPORT ApiFactoryInterface
{
public:
{{- range .Module.Interfaces }}
    virtual Abstract{{.Name}}* create{{Camel .Name}}(QObject *parent) = 0;
{{- end }}
};

} //namespace {{snake  .Module.Name }}

{{ range .Module.Enums }}
{{- $class := .Name }}
Q_DECLARE_METATYPE({{ $module_id }}::{{$class}}::{{$class}}Enum)
{{- end }}
{{- range .Module.Structs }}
{{- $class := .Name }}
Q_DECLARE_METATYPE({{ $module_id }}::{{$class}})
{{- end }}