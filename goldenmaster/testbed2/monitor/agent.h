
#pragma once

#include <QtCore>

#include "testbed2/api/api.h"

#if defined(TESTBED2_MONITOR_LIBRARY)
#  define TESTBED2_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define TESTBED2_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace testbed2 {


class TESTBED2_MONITOR_EXPORT ManyParamInterfaceAgent
{
public:
  ManyParamInterfaceAgent();
  static QVariantMap capture_state(AbstractManyParamInterface* obj);
  static void trace_state(AbstractManyParamInterface* obj);
  static void trace_func1(AbstractManyParamInterface* obj, int param1);
  static void trace_func2(AbstractManyParamInterface* obj, int param1, int param2);
  static void trace_func3(AbstractManyParamInterface* obj, int param1, int param2, int param3);
  static void trace_func4(AbstractManyParamInterface* obj, int param1, int param2, int param3, int param4);
  static void trace_sig1(AbstractManyParamInterface* obj, int param1);
  static void trace_sig2(AbstractManyParamInterface* obj, int param1, int param2);
  static void trace_sig3(AbstractManyParamInterface* obj, int param1, int param2, int param3);
  static void trace_sig4(AbstractManyParamInterface* obj, int param1, int param2, int param3, int param4);
};


class TESTBED2_MONITOR_EXPORT NestedStruct1InterfaceAgent
{
public:
  NestedStruct1InterfaceAgent();
  static QVariantMap capture_state(AbstractNestedStruct1Interface* obj);
  static void trace_state(AbstractNestedStruct1Interface* obj);
  static void trace_func1(AbstractNestedStruct1Interface* obj, const NestedStruct1& param1);
  static void trace_sig1(AbstractNestedStruct1Interface* obj, const NestedStruct1& param1);
};


class TESTBED2_MONITOR_EXPORT NestedStruct2InterfaceAgent
{
public:
  NestedStruct2InterfaceAgent();
  static QVariantMap capture_state(AbstractNestedStruct2Interface* obj);
  static void trace_state(AbstractNestedStruct2Interface* obj);
  static void trace_func1(AbstractNestedStruct2Interface* obj, const NestedStruct1& param1);
  static void trace_func2(AbstractNestedStruct2Interface* obj, const NestedStruct1& param1, const NestedStruct2& param2);
  static void trace_sig1(AbstractNestedStruct2Interface* obj, const NestedStruct1& param1);
  static void trace_sig2(AbstractNestedStruct2Interface* obj, const NestedStruct1& param1, const NestedStruct2& param2);
};


class TESTBED2_MONITOR_EXPORT NestedStruct3InterfaceAgent
{
public:
  NestedStruct3InterfaceAgent();
  static QVariantMap capture_state(AbstractNestedStruct3Interface* obj);
  static void trace_state(AbstractNestedStruct3Interface* obj);
  static void trace_func1(AbstractNestedStruct3Interface* obj, const NestedStruct1& param1);
  static void trace_func2(AbstractNestedStruct3Interface* obj, const NestedStruct1& param1, const NestedStruct2& param2);
  static void trace_func3(AbstractNestedStruct3Interface* obj, const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3);
  static void trace_sig1(AbstractNestedStruct3Interface* obj, const NestedStruct1& param1);
  static void trace_sig2(AbstractNestedStruct3Interface* obj, const NestedStruct1& param1, const NestedStruct2& param2);
  static void trace_sig3(AbstractNestedStruct3Interface* obj, const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3);
};

} // namespace testbed2