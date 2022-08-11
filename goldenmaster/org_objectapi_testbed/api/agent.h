#pragma once

#include <QtCore>

#include "api.h"


class ORG_OBJECTAPI_TESTBED_EXPORT Interface1Agent
{
public:
  Interface1Agent();
  static QVariantMap capture_state(AbstractInterface1* obj);
  static void trace_state(AbstractInterface1* obj);
  static void trace_op1(AbstractInterface1* obj);
  static void trace_op2(AbstractInterface1* obj, int step);
  static void trace_op3(AbstractInterface1* obj);
};


class ORG_OBJECTAPI_TESTBED_EXPORT Interface2Agent
{
public:
  Interface2Agent();
  static QVariantMap capture_state(AbstractInterface2* obj);
  static void trace_state(AbstractInterface2* obj);
};