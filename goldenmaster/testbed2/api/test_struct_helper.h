#pragma once

#include "api.h"

#include <QDataStream>
#include <QtCore/QtGlobal>
#include <QtCore>

#if defined(TESTBED2_API_LIBRARY)
#  define TESTBED2_API_EXPORT Q_DECL_EXPORT
#else
#  define TESTBED2_API_EXPORT Q_DECL_IMPORT
#endif

namespace testbed2 {

TESTBED2_API_EXPORT void fillTestStruct1(Struct1& test_struct1);

TESTBED2_API_EXPORT void fillTestStruct2(Struct2& test_struct2);

TESTBED2_API_EXPORT void fillTestStruct3(Struct3& test_struct3);

TESTBED2_API_EXPORT void fillTestStruct4(Struct4& test_struct4);

TESTBED2_API_EXPORT void fillTestNestedStruct1(NestedStruct1& test_nested_struct1);

TESTBED2_API_EXPORT void fillTestNestedStruct2(NestedStruct2& test_nested_struct2);

TESTBED2_API_EXPORT void fillTestNestedStruct3(NestedStruct3& test_nested_struct3);

}
