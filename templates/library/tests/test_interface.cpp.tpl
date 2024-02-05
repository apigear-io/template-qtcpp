{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- cppGpl .Module }}
#include "test_{{.Interface.Name|lower}}.h"
#include "implementation/{{.Interface.Name|lower}}.h"

{{- $class :=  printf "%s%s" (Camel .Module.Name) (Camel .Interface.Name) }}
{{- $testedClass := (Camel .Interface.Name) }}
{{- $moduleName :=  snake .Module.Name }}

/**
 *  will be called before the first test function is executed.
*/
void Test{{$class}}::initTestCase(){

}

/**
 *  will be called to create a global test data table.
*/
void Test{{$class}}::initTestCase_data(){

}

/**
 *  will be called after the last test function was executed.
*/
void Test{{$class}}::cleanupTestCase(){

}

/**
 *  will be called before each test function is executed.
*/
void Test{{$class}}::init(){

}

/**
 *  will be called after every test function.
*/
void Test{{$class}}::cleanup(){

}

{{- range .Interface.Operations }}
/**
 *  Test operation {{.Name}}
*/
void Test{{$class}}::{{.Name}}(){
    {{$moduleName}}::{{$testedClass}} test{{upper1 (lower $class)}};
    // Do implement test here
}
{{- end }}

{{- range .Interface.Properties }}
/**
 *  Test proptery {{.Name}}
*/
void Test{{$class}}::{{.Name}}(){
    {{$moduleName}}::{{$testedClass}} test{{upper1 (lower $class)}};
    // Do implement test here
}
{{- end }}

QTEST_MAIN(Test{{$class}});


