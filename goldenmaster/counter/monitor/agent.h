
#pragma once

#include <QtCore>

#include "counter/api/api.h"

#if defined(COUNTER_MONITOR_LIBRARY)
#  define COUNTER_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define COUNTER_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace counter {


class COUNTER_MONITOR_EXPORT CounterAgent
{
public:
  CounterAgent();
  static QVariantMap capture_state(AbstractCounter* obj);
  static void trace_state(AbstractCounter* obj);
  static void trace_increment(AbstractCounter* obj, const QVector3D& vec);
  static void trace_decrement(AbstractCounter* obj, const custom_types::Vector3D& vec);
};

} // namespace counter