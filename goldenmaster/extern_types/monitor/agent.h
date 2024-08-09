
#pragma once

#include <QtCore>

#include "extern_types/api/api.h"

#if defined(EXTERN_TYPES_MONITOR_LIBRARY)
#  define EXTERN_TYPES_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define EXTERN_TYPES_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace extern_types {

} // namespace extern_types