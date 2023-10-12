{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{ cppGpl .Module }}
#include <QtTest/QtTest>

{{- $class :=  printf "%s%s" (Camel .Module.Name) (Camel .Interface.Name) }}

class Test{{$class}}: public QObject
{
    Q_OBJECT
    // setup your test
    void initTestCase();
    void initTestCase_data();
    void cleanupTestCase();
    void init();
    void cleanup();

private slots:
{{- range .Interface.Operations }}
    void {{.Name}}();
{{- end }}
{{- range .Interface.Properties }}
    void {{.Name}}();
{{- end }}
};
