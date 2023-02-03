#pragma once

#include <QtCore>

#include "api.h"

namespace tb_enum {


class TB_ENUM_EXPORT EnumInterfaceAgent
{
public:
  EnumInterfaceAgent();
  static QVariantMap capture_state(AbstractEnumInterface* obj);
  static void trace_state(AbstractEnumInterface* obj);
  static void trace_func0(AbstractEnumInterface* obj, Enum0::Enum0Enum param0);
  static void trace_func1(AbstractEnumInterface* obj, Enum1::Enum1Enum param1);
  static void trace_func2(AbstractEnumInterface* obj, Enum2::Enum2Enum param2);
  static void trace_func3(AbstractEnumInterface* obj, Enum3::Enum3Enum param3);
};

} // namespace tb_enum