
#pragma once

#include <QtCore>

#include "tb_simple/api/api.h"

#if defined(TB_SIMPLE_MONITOR_LIBRARY)
#  define TB_SIMPLE_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define TB_SIMPLE_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace tb_simple {


class TB_SIMPLE_MONITOR_EXPORT VoidInterfaceAgent
{
public:
  VoidInterfaceAgent();
  static QVariantMap capture_state(AbstractVoidInterface* obj);
  static void trace_state(AbstractVoidInterface* obj);
  static void trace_funcVoid(AbstractVoidInterface* obj );
  static void trace_sigVoid(AbstractVoidInterface* obj );
};


class TB_SIMPLE_MONITOR_EXPORT SimpleInterfaceAgent
{
public:
  SimpleInterfaceAgent();
  static QVariantMap capture_state(AbstractSimpleInterface* obj);
  static void trace_state(AbstractSimpleInterface* obj);
  static void trace_funcNoReturnValue(AbstractSimpleInterface* obj, bool paramBool);
  static void trace_funcBool(AbstractSimpleInterface* obj, bool paramBool);
  static void trace_funcInt(AbstractSimpleInterface* obj, int paramInt);
  static void trace_funcInt32(AbstractSimpleInterface* obj, qint32 paramInt32);
  static void trace_funcInt64(AbstractSimpleInterface* obj, qint64 paramInt64);
  static void trace_funcFloat(AbstractSimpleInterface* obj, qreal paramFloat);
  static void trace_funcFloat32(AbstractSimpleInterface* obj, float paramFloat32);
  static void trace_funcFloat64(AbstractSimpleInterface* obj, double paramFloat);
  static void trace_funcString(AbstractSimpleInterface* obj, const QString& paramString);
  static void trace_sigBool(AbstractSimpleInterface* obj, bool paramBool);
  static void trace_sigInt(AbstractSimpleInterface* obj, int paramInt);
  static void trace_sigInt32(AbstractSimpleInterface* obj, qint32 paramInt32);
  static void trace_sigInt64(AbstractSimpleInterface* obj, qint64 paramInt64);
  static void trace_sigFloat(AbstractSimpleInterface* obj, qreal paramFloat);
  static void trace_sigFloat32(AbstractSimpleInterface* obj, float paramFloa32);
  static void trace_sigFloat64(AbstractSimpleInterface* obj, double paramFloat64);
  static void trace_sigString(AbstractSimpleInterface* obj, const QString& paramString);
};


class TB_SIMPLE_MONITOR_EXPORT SimpleArrayInterfaceAgent
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
  static void trace_sigBool(AbstractSimpleArrayInterface* obj, const QList<bool>& paramBool);
  static void trace_sigInt(AbstractSimpleArrayInterface* obj, const QList<int>& paramInt);
  static void trace_sigInt32(AbstractSimpleArrayInterface* obj, const QList<qint32>& paramInt32);
  static void trace_sigInt64(AbstractSimpleArrayInterface* obj, const QList<qint64>& paramInt64);
  static void trace_sigFloat(AbstractSimpleArrayInterface* obj, const QList<qreal>& paramFloat);
  static void trace_sigFloat32(AbstractSimpleArrayInterface* obj, const QList<float>& paramFloa32);
  static void trace_sigFloat64(AbstractSimpleArrayInterface* obj, const QList<double>& paramFloat64);
  static void trace_sigString(AbstractSimpleArrayInterface* obj, const QList<QString>& paramString);
};


class TB_SIMPLE_MONITOR_EXPORT NoPropertiesInterfaceAgent
{
public:
  NoPropertiesInterfaceAgent();
  static QVariantMap capture_state(AbstractNoPropertiesInterface* obj);
  static void trace_state(AbstractNoPropertiesInterface* obj);
  static void trace_funcVoid(AbstractNoPropertiesInterface* obj );
  static void trace_funcBool(AbstractNoPropertiesInterface* obj, bool paramBool);
  static void trace_sigVoid(AbstractNoPropertiesInterface* obj );
  static void trace_sigBool(AbstractNoPropertiesInterface* obj, bool paramBool);
};


class TB_SIMPLE_MONITOR_EXPORT NoOperationsInterfaceAgent
{
public:
  NoOperationsInterfaceAgent();
  static QVariantMap capture_state(AbstractNoOperationsInterface* obj);
  static void trace_state(AbstractNoOperationsInterface* obj);
  static void trace_sigVoid(AbstractNoOperationsInterface* obj );
  static void trace_sigBool(AbstractNoOperationsInterface* obj, bool paramBool);
};


class TB_SIMPLE_MONITOR_EXPORT NoSignalsInterfaceAgent
{
public:
  NoSignalsInterfaceAgent();
  static QVariantMap capture_state(AbstractNoSignalsInterface* obj);
  static void trace_state(AbstractNoSignalsInterface* obj);
  static void trace_funcVoid(AbstractNoSignalsInterface* obj );
  static void trace_funcBool(AbstractNoSignalsInterface* obj, bool paramBool);
};

} // namespace tb_simple