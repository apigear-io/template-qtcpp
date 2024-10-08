#pragma once

#include "api.h"

#include <QDataStream>
#include <QtCore/QtGlobal>
#include <QtCore>

#if defined(TB_SIMPLE_API_LIBRARY)
#  define TB_SIMPLE_API_EXPORT Q_DECL_EXPORT
#else
#  define TB_SIMPLE_API_EXPORT Q_DECL_IMPORT
#endif

namespace tb_simple {

}
