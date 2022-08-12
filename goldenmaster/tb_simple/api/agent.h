#pragma once

#include <QtCore>

#include "api.h"


class TB_SIMPLE_EXPORT SimpleInterfaceAgent
{
public:
  SimpleInterfaceAgent();
  static QVariantMap capture_state(AbstractSimpleInterface* obj);
  static void trace_state(AbstractSimpleInterface* obj);
  static void trace_funcBool(AbstractSimpleInterface* obj, bool paramBool);
  static void trace_funcInt(AbstractSimpleInterface* obj, int paramInt);
  static void trace_funcFloat(AbstractSimpleInterface* obj, qreal paramFloat);
  static void trace_funcString(AbstractSimpleInterface* obj, const QString& paramString);
};


class TB_SIMPLE_EXPORT SimpleArrayInterfaceAgent
{
public:
  SimpleArrayInterfaceAgent();
  static QVariantMap capture_state(AbstractSimpleArrayInterface* obj);
  static void trace_state(AbstractSimpleArrayInterface* obj);
  static void trace_funcBool(AbstractSimpleArrayInterface* obj, const QList<bool>& paramBool);
  static void trace_funcInt(AbstractSimpleArrayInterface* obj, const QList<int>& paramInt);
  static void trace_funcFloat(AbstractSimpleArrayInterface* obj, const QList<qreal>& paramFloat);
  static void trace_funcString(AbstractSimpleArrayInterface* obj, const QList<QString>& paramString);
};