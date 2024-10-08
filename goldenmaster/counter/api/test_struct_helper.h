#pragma once

#include "api.h"

#include "custom_types/api/api.h"
#include "extern_types/api/api.h"
#include <QDataStream>
#include <QtCore/QtGlobal>
#include <QtCore>

#if defined(COUNTER_API_LIBRARY)
#  define COUNTER_API_EXPORT Q_DECL_EXPORT
#else
#  define COUNTER_API_EXPORT Q_DECL_IMPORT
#endif

namespace counter {

}
