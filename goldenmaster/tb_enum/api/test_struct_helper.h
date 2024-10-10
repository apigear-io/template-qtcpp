#pragma once

#include "api.h"

#include <QDataStream>
#include <QtCore/QtGlobal>
#include <QtCore>

#if defined(TB_ENUM_API_LIBRARY)
#  define TB_ENUM_API_EXPORT Q_DECL_EXPORT
#else
#  define TB_ENUM_API_EXPORT Q_DECL_IMPORT
#endif

namespace tb_enum {

}
