#pragma once

#include <QtCore>

#include "api.h"

namespace tb_same1 {


class TB_SAME1_EXPORT SameStruct1InterfaceAgent
{
public:
  SameStruct1InterfaceAgent();
  static QVariantMap capture_state(AbstractSameStruct1Interface* obj);
  static void trace_state(AbstractSameStruct1Interface* obj);
  static void trace_func1(AbstractSameStruct1Interface* obj, const Struct1& param1);
};


class TB_SAME1_EXPORT SameStruct2InterfaceAgent
{
public:
  SameStruct2InterfaceAgent();
  static QVariantMap capture_state(AbstractSameStruct2Interface* obj);
  static void trace_state(AbstractSameStruct2Interface* obj);
  static void trace_func1(AbstractSameStruct2Interface* obj, const Struct1& param1);
  static void trace_func2(AbstractSameStruct2Interface* obj, const Struct1& param1, const Struct2& param2);
};


class TB_SAME1_EXPORT SameEnum1InterfaceAgent
{
public:
  SameEnum1InterfaceAgent();
  static QVariantMap capture_state(AbstractSameEnum1Interface* obj);
  static void trace_state(AbstractSameEnum1Interface* obj);
  static void trace_func1(AbstractSameEnum1Interface* obj, const Enum1::Enum1Enum param1);
};


class TB_SAME1_EXPORT SameEnum2InterfaceAgent
{
public:
  SameEnum2InterfaceAgent();
  static QVariantMap capture_state(AbstractSameEnum2Interface* obj);
  static void trace_state(AbstractSameEnum2Interface* obj);
  static void trace_func1(AbstractSameEnum2Interface* obj, const Enum1::Enum1Enum param1);
  static void trace_func2(AbstractSameEnum2Interface* obj, const Enum1::Enum1Enum param1, const Enum2::Enum2Enum param2);
};

} // namespace tb_same1