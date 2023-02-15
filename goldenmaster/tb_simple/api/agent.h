#pragma once

#include <QtCore>

#include "api.h"

namespace tb_simple {


class TB_SIMPLE_EXPORT SimpleInterfaceAgent
{
public:
  SimpleInterfaceAgent();
  static QVariantMap capture_state(AbstractSimpleInterface* obj);
  static void trace_state(AbstractSimpleInterface* obj);
  static void trace_funcBool(AbstractSimpleInterface* obj, bool paramBool);
  static void trace_funcInt(AbstractSimpleInterface* obj, int paramInt);
  static void trace_funcInt32(AbstractSimpleInterface* obj, qint32 paramInt32);
  static void trace_funcInt64(AbstractSimpleInterface* obj, qint64 paramInt64);
  static void trace_funcFloat(AbstractSimpleInterface* obj, qreal paramFloat);
  static void trace_funcFloat32(AbstractSimpleInterface* obj, float paramFloat32);
  static void trace_funcFloat64(AbstractSimpleInterface* obj, double paramFloat);
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
  static void trace_funcInt32(AbstractSimpleArrayInterface* obj, const QList<qint32>& paramInt32);
  static void trace_funcInt64(AbstractSimpleArrayInterface* obj, const QList<qint64>& paramInt64);
  static void trace_funcFloat(AbstractSimpleArrayInterface* obj, const QList<qreal>& paramFloat);
  static void trace_funcFloat32(AbstractSimpleArrayInterface* obj, const QList<float>& paramFloat32);
  static void trace_funcFloat64(AbstractSimpleArrayInterface* obj, const QList<double>& paramFloat);
  static void trace_funcString(AbstractSimpleArrayInterface* obj, const QList<QString>& paramString);
};

} // namespace tb_simple