#pragma once

#include "api.h"

#include <QDataStream>
#include <QtCore/QtGlobal>
#include <QtCore>

#if defined(TB_SAME1_API_LIBRARY)
#  define TB_SAME1_API_EXPORT Q_DECL_EXPORT
#else
#  define TB_SAME1_API_EXPORT Q_DECL_IMPORT
#endif

namespace tb_same1 {

TB_SAME1_API_EXPORT void fillTestStruct1(Struct1& test_struct1);

TB_SAME1_API_EXPORT void fillTestStruct2(Struct2& test_struct2);

}
