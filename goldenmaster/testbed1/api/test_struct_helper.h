#pragma once

#include "api.h"

#include <QDataStream>
#include <QtCore/QtGlobal>
#include <QtCore>

#if defined(TESTBED1_API_LIBRARY)
#  define TESTBED1_API_EXPORT Q_DECL_EXPORT
#else
#  define TESTBED1_API_EXPORT Q_DECL_IMPORT
#endif

namespace testbed1 {

TESTBED1_API_EXPORT void fillTestStructBool(StructBool& test_struct_bool);

TESTBED1_API_EXPORT void fillTestStructInt(StructInt& test_struct_int);

TESTBED1_API_EXPORT void fillTestStructFloat(StructFloat& test_struct_float);

TESTBED1_API_EXPORT void fillTestStructString(StructString& test_struct_string);

}
