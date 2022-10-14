{% comment %} // Copyright (c) ApiGear UG 2020 {% endcomment -%}
{{ cppGpl .Module }}
#include <QtTest/QtTest>

{{ $class := .Name }}

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
{{- range .Operations }}
    void {{.Name}}();
{{- end }}
{% comment %} line seperator {% endcomment %}
{{- range .Properties }}
    void {{.Name}}();
{{- end }}
};
