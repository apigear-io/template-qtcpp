
#pragma once

#include <QtCore>

#include "tb_same1/api/api.h"

#if defined(TB_SAME1_MONITOR_LIBRARY)
#  define TB_SAME1_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define TB_SAME1_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace tb_same1 {


class TB_SAME1_MONITOR_EXPORT SameStruct1InterfaceAgent
{
public:
  SameStruct1InterfaceAgent();
  static QVariantMap capture_state(AbstractSameStruct1Interface* obj);
  static void trace_state(AbstractSameStruct1Interface* obj);
  static void trace_func1(AbstractSameStruct1Interface* obj, const Struct1& param1);
  static void trace_sig1(AbstractSameStruct1Interface* obj, const Struct1& param1);
};


class TB_SAME1_MONITOR_EXPORT SameStruct2InterfaceAgent
{
public:
  SameStruct2InterfaceAgent();
  static QVariantMap capture_state(AbstractSameStruct2Interface* obj);
  static void trace_state(AbstractSameStruct2Interface* obj);
  static void trace_func1(AbstractSameStruct2Interface* obj, const Struct1& param1);
  static void trace_func2(AbstractSameStruct2Interface* obj, const Struct1& param1, const Struct2& param2);
  static void trace_sig1(AbstractSameStruct2Interface* obj, const Struct1& param1);
  static void trace_sig2(AbstractSameStruct2Interface* obj, const Struct1& param1, const Struct2& param2);
};


class TB_SAME1_MONITOR_EXPORT SameEnum1InterfaceAgent
{
public:
  SameEnum1InterfaceAgent();
  static QVariantMap capture_state(AbstractSameEnum1Interface* obj);
  static void trace_state(AbstractSameEnum1Interface* obj);
  static void trace_func1(AbstractSameEnum1Interface* obj, Enum1::Enum1Enum param1);
  static void trace_sig1(AbstractSameEnum1Interface* obj, Enum1::Enum1Enum param1);
};


class TB_SAME1_MONITOR_EXPORT SameEnum2InterfaceAgent
{
public:
  SameEnum2InterfaceAgent();
  static QVariantMap capture_state(AbstractSameEnum2Interface* obj);
  static void trace_state(AbstractSameEnum2Interface* obj);
  static void trace_func1(AbstractSameEnum2Interface* obj, Enum1::Enum1Enum param1);
  static void trace_func2(AbstractSameEnum2Interface* obj, Enum1::Enum1Enum param1, Enum2::Enum2Enum param2);
  static void trace_sig1(AbstractSameEnum2Interface* obj, Enum1::Enum1Enum param1);
  static void trace_sig2(AbstractSameEnum2Interface* obj, Enum1::Enum1Enum param1, Enum2::Enum2Enum param2);
};

} // namespace tb_same1