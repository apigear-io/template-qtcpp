#pragma once

#include <QtCore>

#include "api.h"


class TESTBED1_EXPORT StructInterfaceAgent
{
public:
  StructInterfaceAgent();
  static QVariantMap capture_state(AbstractStructInterface* obj);
  static void trace_state(AbstractStructInterface* obj);
  static void trace_funcBool(AbstractStructInterface* obj, const StructBool& paramBool);
  static void trace_funcInt(AbstractStructInterface* obj, const StructInt& paramInt);
  static void trace_funcFloat(AbstractStructInterface* obj, const StructFloat& paramFloat);
  static void trace_funcString(AbstractStructInterface* obj, const StructString& paramString);
};


class TESTBED1_EXPORT StructArrayInterfaceAgent
{
public:
  StructArrayInterfaceAgent();
  static QVariantMap capture_state(AbstractStructArrayInterface* obj);
  static void trace_state(AbstractStructArrayInterface* obj);
  static void trace_funcBool(AbstractStructArrayInterface* obj, const QList<StructBool>& paramBool);
  static void trace_funcInt(AbstractStructArrayInterface* obj, const QList<StructInt>& paramInt);
  static void trace_funcFloat(AbstractStructArrayInterface* obj, const QList<StructFloat>& paramFloat);
  static void trace_funcString(AbstractStructArrayInterface* obj, const QList<StructString>& paramString);
};