
#pragma once

#include <QtCore>

#include "testbed1/api/api.h"

#if defined(TESTBED1_MONITOR_LIBRARY)
#  define TESTBED1_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define TESTBED1_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace testbed1 {


class TESTBED1_MONITOR_EXPORT StructInterfaceAgent
{
public:
  StructInterfaceAgent();
  static QVariantMap capture_state(AbstractStructInterface* obj);
  static void trace_state(AbstractStructInterface* obj);
  static void trace_funcBool(AbstractStructInterface* obj, const StructBool& paramBool);
  static void trace_funcInt(AbstractStructInterface* obj, const StructInt& paramInt);
  static void trace_funcFloat(AbstractStructInterface* obj, const StructFloat& paramFloat);
  static void trace_funcString(AbstractStructInterface* obj, const StructString& paramString);
  static void trace_sigBool(AbstractStructInterface* obj, const StructBool& paramBool);
  static void trace_sigInt(AbstractStructInterface* obj, const StructInt& paramInt);
  static void trace_sigFloat(AbstractStructInterface* obj, const StructFloat& paramFloat);
  static void trace_sigString(AbstractStructInterface* obj, const StructString& paramString);
};


class TESTBED1_MONITOR_EXPORT StructArrayInterfaceAgent
{
public:
  StructArrayInterfaceAgent();
  static QVariantMap capture_state(AbstractStructArrayInterface* obj);
  static void trace_state(AbstractStructArrayInterface* obj);
  static void trace_funcBool(AbstractStructArrayInterface* obj, const QList<StructBool>& paramBool);
  static void trace_funcInt(AbstractStructArrayInterface* obj, const QList<StructInt>& paramInt);
  static void trace_funcFloat(AbstractStructArrayInterface* obj, const QList<StructFloat>& paramFloat);
  static void trace_funcString(AbstractStructArrayInterface* obj, const QList<StructString>& paramString);
  static void trace_sigBool(AbstractStructArrayInterface* obj, const QList<StructBool>& paramBool);
  static void trace_sigInt(AbstractStructArrayInterface* obj, const QList<StructInt>& paramInt);
  static void trace_sigFloat(AbstractStructArrayInterface* obj, const QList<StructFloat>& paramFloat);
  static void trace_sigString(AbstractStructArrayInterface* obj, const QList<StructString>& paramString);
};

} // namespace testbed1