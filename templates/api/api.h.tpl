{{- /* Copyright (c) ApiGear UG 2020 */}}
{{- $MODULE_ID := printf "%s_API" (SNAKE .Module.Name) }}
{{- $module_id := snake .Module.Name }}
{{- $namespacePrefix := printf "%s::" (snake .Module.Name) }}
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
 {{- if .Description }}
 *
 * {{.Description}}
{{- end }}
// ********************************************************************
class {{ $MODULE_ID }}_EXPORT {{ $class }} : public QObject {
    Q_OBJECT
public:
    {{ $class }}(QObject *parent = nullptr)
        : QObject(parent)
        {}
    enum {{ $class }}Enum {
    {{- range $idx, $elem := .Members }}
        {{- if $idx}},{{end}}
        {{upper1 .Name }} = {{ .Value }} 
        {{- if .Description -}}
        /** .Description */
        {{- end }}
    {{- end }}
    };
    Q_ENUM({{$class}}Enum)

    /**
    * Converter for {{$class}}Enum
    * @param v Value in quint8 format.
    * @param ok. Write parameter, will be set to true if conversion was successful, false otherwise.
    * @return An enum value for given quint8 or default value if in parameter is out of the enums range.
    */
    static {{$class}}Enum toEnum(quint8 v, bool *ok);
};

/** ostream operator. Allows writing the {{$class}}Enum value to an text output*/
inline QDataStream &operator<<(QDataStream &ds, const {{$class}}::{{$class}}Enum &obj)
{
    quint8 val = obj;
    ds << val;
    return ds;
}
/** istream operator. Allows reading to {{$class}}Enum value from input text*/
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
 {{- if .Description }}
 * {{.Description}}
{{- end }}
// ********************************************************************
struct {{ $MODULE_ID }}_EXPORT {{$class}}
{
    Q_GADGET
{{- range .Fields }}
    Q_PROPERTY({{qtReturn $namespacePrefix .}} {{.Name}} MEMBER m_{{.Name}} )
{{- end }}

public:
    {{$class}}();
    bool operator==(const {{$class}} &other) const;
    bool operator!=(const {{$class}} &other) const;

{{- range .Fields }}
    {{- if .Description }}
    /**
     * {{.Description}}
     */
    {{- end }}
    {{qtReturn "" .}} m_{{.Name}};
{{- end }}
};

/** ostream operator. Allows writing the {{$class}} value to an text output*/
QDataStream &operator<<(QDataStream &stream, const {{$class}} &obj);
/** istream operator. Allows reading to {{$class}} value from input text*/
QDataStream &operator>>(QDataStream &stream, {{$class}} &obj);

// ********************************************************************
// {{$class}} struct factory
// Registered by plugin to allow creating this type of objects in qml. 
// ********************************************************************
class {{ $MODULE_ID }}_EXPORT {{$class}}Factory : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE {{$module_id}}::{{$class}} create();
};


{{- end }}
{{ range .Module.Interfaces }}
{{- $class := printf "Abstract%s" (Camel .Name) }}
// ********************************************************************
/**
{{- if .Description }}
 * {{.Description}}
{{- end }}   {{- /* end if interface description */}}
*
* {{$class}} is a pure interface QObject class.
* Declares:
*  - Methods defined for {{.Name}} interface
*  - Property setters and getters for defined properties
*  - Property changed singals for properties of your interface.
*  - Signals described for {{.Name}} interface.
*/
// ********************************************************************


class {{ $MODULE_ID }}_EXPORT {{$class}} : public QObject {
    Q_OBJECT
public:
    {{$class}}(QObject * parent=nullptr);
{{- range .Properties }}
{{- $property := . }}
    /**
    * Sets the value of the {{$property.Name}} property.
    {{- if $property.Description }}
    * @param {{$property.Name}} {{$property.Description}}
    {{- end }}    {{- /* end if property.Description */}}
    */
    virtual void set{{Camel .Name}}({{qtParam "" .}}) = 0;
    /**
    * Gets the value of the {{$property.Name}} property.
    {{- if $property.Description }}
    * @return {{$property.Description}}
    {{- end }}    {{- /* end if property.Description */}}
    */
    virtual {{qtReturn "" .}} {{.Name}}() const = 0;
{{- end }}

{{- range .Operations }}
{{ $operation := . }}
{{- if $operation.Description }}
    /**
    * {{ $operation.Description }}
{{- range $operation.Params }}
{{- $param := . }}
{{- if $param.Description }}
    * @param {{$param}} {{$param.Description}}
{{- end }}   {{- /* end if param description */}}
{{- end }}   {{- /* end range operation param*/}}  
    */
{{- end }}   {{- /* end if operations description */}}
    virtual {{qtReturn "" .Return }} {{camel .Name}}({{qtParams "" .Params}}) = 0;
{{- end }}
signals:
{{- range .Signals }}
{{- $signal := . }}
{{- $signalName := camel .Name }}
    /**
    {{- if $signal.Description }}
    * {{$signal.Description}}
    {{- end }}
    {{- range $signal.Params }}
    {{- $param := . }}
    * @param {{$param.Name}} {{$param.Description}}
    {{- end -}} {{/* range singal.Params */}}
    */
    void {{$signalName}}({{qtParams $namespacePrefix .Params}});
{{- end }}
{{- range .Properties }}
{{- $property:= . }}
    /**
    * Emitted when {{$property.Name}} value has changed.
    {{- if $property.Description }}
    * @param {{$property.Name}} {{$property.Description}}
    {{- end }}
    */
    void {{.Name}}Changed({{qtParam "" .}});
{{- end }}
};
{{ end }}

} //namespace {{snake  .Module.Name }}

{{ range .Module.Enums }}
{{- $class := .Name }}
Q_DECLARE_METATYPE({{ $module_id }}::{{$class}}::{{$class}}Enum)
{{- end }}
{{- range .Module.Structs }}
{{- $class := .Name }}
Q_DECLARE_METATYPE({{ $module_id }}::{{$class}})
{{- end }}