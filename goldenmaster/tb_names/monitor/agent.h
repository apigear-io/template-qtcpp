
#pragma once

#include <QtCore>

#include "tb_names/api/api.h"

#if defined(TB_NAMES_MONITOR_LIBRARY)
#  define TB_NAMES_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define TB_NAMES_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace tb_names {


class TB_NAMES_MONITOR_EXPORT NamEsAgent
{
public:
  NamEsAgent();
  static QVariantMap capture_state(AbstractNamEs* obj);
  static void trace_state(AbstractNamEs* obj);
  static void trace_SOME_FUNCTION(AbstractNamEs* obj, bool SOME_PARAM);
  static void trace_Some_Function2(AbstractNamEs* obj, bool Some_Param);
  static void trace_SOME_SIGNAL(AbstractNamEs* obj, bool SOME_PARAM);
  static void trace_Some_Signal2(AbstractNamEs* obj, bool Some_Param);
};

} // namespace tb_names