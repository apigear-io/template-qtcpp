
#pragma once

#include <QtCore>

#include "custom_types/api/api.h"

#if defined(CUSTOM_TYPES_MONITOR_LIBRARY)
#  define CUSTOM_TYPES_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define CUSTOM_TYPES_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace custom_types {

} // namespace custom_types