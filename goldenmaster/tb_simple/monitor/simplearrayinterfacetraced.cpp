
#include "simplearrayinterfacetraced.h"
#include "tb_simple/monitor/agent.h"

namespace tb_simple {


SimpleArrayInterfaceTraced::SimpleArrayInterfaceTraced(std::shared_ptr<AbstractSimpleArrayInterface> impl)
    :m_impl(impl)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }

    // Connect signals emitted by implementation with tracing function.
     connect(m_impl.get(), &AbstractSimpleArrayInterface::sigBool, this, &SimpleArrayInterfaceTraced::sigBool);
     connect(m_impl.get(), &AbstractSimpleArrayInterface::sigInt, this, &SimpleArrayInterfaceTraced::sigInt);
     connect(m_impl.get(), &AbstractSimpleArrayInterface::sigInt32, this, &SimpleArrayInterfaceTraced::sigInt32);
     connect(m_impl.get(), &AbstractSimpleArrayInterface::sigInt64, this, &SimpleArrayInterfaceTraced::sigInt64);
     connect(m_impl.get(), &AbstractSimpleArrayInterface::sigFloat, this, &SimpleArrayInterfaceTraced::sigFloat);
     connect(m_impl.get(), &AbstractSimpleArrayInterface::sigFloat32, this, &SimpleArrayInterfaceTraced::sigFloat32);
     connect(m_impl.get(), &AbstractSimpleArrayInterface::sigFloat64, this, &SimpleArrayInterfaceTraced::sigFloat64);
     connect(m_impl.get(), &AbstractSimpleArrayInterface::sigString, this, &SimpleArrayInterfaceTraced::sigString);

    // Connect signals emitted by implementation with this object.
     connect(m_impl.get(), &AbstractSimpleArrayInterface::sigBool, this, &SimpleArrayInterfaceTraced::traceSigBool);
     connect(m_impl.get(), &AbstractSimpleArrayInterface::sigInt, this, &SimpleArrayInterfaceTraced::traceSigInt);
     connect(m_impl.get(), &AbstractSimpleArrayInterface::sigInt32, this, &SimpleArrayInterfaceTraced::traceSigInt32);
     connect(m_impl.get(), &AbstractSimpleArrayInterface::sigInt64, this, &SimpleArrayInterfaceTraced::traceSigInt64);
     connect(m_impl.get(), &AbstractSimpleArrayInterface::sigFloat, this, &SimpleArrayInterfaceTraced::traceSigFloat);
     connect(m_impl.get(), &AbstractSimpleArrayInterface::sigFloat32, this, &SimpleArrayInterfaceTraced::traceSigFloat32);
     connect(m_impl.get(), &AbstractSimpleArrayInterface::sigFloat64, this, &SimpleArrayInterfaceTraced::traceSigFloat64);
     connect(m_impl.get(), &AbstractSimpleArrayInterface::sigString, this, &SimpleArrayInterfaceTraced::traceSigString);

    // Connect property changed signals emitted by implementation with this object.
    connect(m_impl.get(), &AbstractSimpleArrayInterface::propBoolChanged, this, &AbstractSimpleArrayInterface::propBoolChanged);
    connect(m_impl.get(), &AbstractSimpleArrayInterface::propIntChanged, this, &AbstractSimpleArrayInterface::propIntChanged);
    connect(m_impl.get(), &AbstractSimpleArrayInterface::propInt32Changed, this, &AbstractSimpleArrayInterface::propInt32Changed);
    connect(m_impl.get(), &AbstractSimpleArrayInterface::propInt64Changed, this, &AbstractSimpleArrayInterface::propInt64Changed);
    connect(m_impl.get(), &AbstractSimpleArrayInterface::propFloatChanged, this, &AbstractSimpleArrayInterface::propFloatChanged);
    connect(m_impl.get(), &AbstractSimpleArrayInterface::propFloat32Changed, this, &AbstractSimpleArrayInterface::propFloat32Changed);
    connect(m_impl.get(), &AbstractSimpleArrayInterface::propFloat64Changed, this, &AbstractSimpleArrayInterface::propFloat64Changed);
    connect(m_impl.get(), &AbstractSimpleArrayInterface::propStringChanged, this, &AbstractSimpleArrayInterface::propStringChanged);
}

QList<bool> SimpleArrayInterfaceTraced::funcBool(const QList<bool>& paramBool) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    SimpleArrayInterfaceAgent::trace_funcBool(this, paramBool);
    return m_impl->funcBool(paramBool);
}


QList<int> SimpleArrayInterfaceTraced::funcInt(const QList<int>& paramInt) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    SimpleArrayInterfaceAgent::trace_funcInt(this, paramInt);
    return m_impl->funcInt(paramInt);
}


QList<qint32> SimpleArrayInterfaceTraced::funcInt32(const QList<qint32>& paramInt32) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    SimpleArrayInterfaceAgent::trace_funcInt32(this, paramInt32);
    return m_impl->funcInt32(paramInt32);
}


QList<qint64> SimpleArrayInterfaceTraced::funcInt64(const QList<qint64>& paramInt64) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    SimpleArrayInterfaceAgent::trace_funcInt64(this, paramInt64);
    return m_impl->funcInt64(paramInt64);
}


QList<qreal> SimpleArrayInterfaceTraced::funcFloat(const QList<qreal>& paramFloat) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    SimpleArrayInterfaceAgent::trace_funcFloat(this, paramFloat);
    return m_impl->funcFloat(paramFloat);
}


QList<float> SimpleArrayInterfaceTraced::funcFloat32(const QList<float>& paramFloat32) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    SimpleArrayInterfaceAgent::trace_funcFloat32(this, paramFloat32);
    return m_impl->funcFloat32(paramFloat32);
}


QList<double> SimpleArrayInterfaceTraced::funcFloat64(const QList<double>& paramFloat) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    SimpleArrayInterfaceAgent::trace_funcFloat64(this, paramFloat);
    return m_impl->funcFloat64(paramFloat);
}


QList<QString> SimpleArrayInterfaceTraced::funcString(const QList<QString>& paramString) 
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return  {} ;
    }
    SimpleArrayInterfaceAgent::trace_funcString(this, paramString);
    return m_impl->funcString(paramString);
}

void SimpleArrayInterfaceTraced::setPropBool(const QList<bool>& propBool)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    SimpleArrayInterfaceAgent::trace_state(this);
    m_impl->setPropBool(propBool);
}
QList<bool> SimpleArrayInterfaceTraced::propBool() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->propBool();
}

void SimpleArrayInterfaceTraced::setPropInt(const QList<int>& propInt)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    SimpleArrayInterfaceAgent::trace_state(this);
    m_impl->setPropInt(propInt);
}
QList<int> SimpleArrayInterfaceTraced::propInt() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->propInt();
}

void SimpleArrayInterfaceTraced::setPropInt32(const QList<qint32>& propInt32)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    SimpleArrayInterfaceAgent::trace_state(this);
    m_impl->setPropInt32(propInt32);
}
QList<qint32> SimpleArrayInterfaceTraced::propInt32() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->propInt32();
}

void SimpleArrayInterfaceTraced::setPropInt64(const QList<qint64>& propInt64)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    SimpleArrayInterfaceAgent::trace_state(this);
    m_impl->setPropInt64(propInt64);
}
QList<qint64> SimpleArrayInterfaceTraced::propInt64() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->propInt64();
}

void SimpleArrayInterfaceTraced::setPropFloat(const QList<qreal>& propFloat)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    SimpleArrayInterfaceAgent::trace_state(this);
    m_impl->setPropFloat(propFloat);
}
QList<qreal> SimpleArrayInterfaceTraced::propFloat() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->propFloat();
}

void SimpleArrayInterfaceTraced::setPropFloat32(const QList<float>& propFloat32)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    SimpleArrayInterfaceAgent::trace_state(this);
    m_impl->setPropFloat32(propFloat32);
}
QList<float> SimpleArrayInterfaceTraced::propFloat32() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->propFloat32();
}

void SimpleArrayInterfaceTraced::setPropFloat64(const QList<double>& propFloat64)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    SimpleArrayInterfaceAgent::trace_state(this);
    m_impl->setPropFloat64(propFloat64);
}
QList<double> SimpleArrayInterfaceTraced::propFloat64() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->propFloat64();
}

void SimpleArrayInterfaceTraced::setPropString(const QList<QString>& propString)
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return;
    }
    SimpleArrayInterfaceAgent::trace_state(this);
    m_impl->setPropString(propString);
}
QList<QString> SimpleArrayInterfaceTraced::propString() const
{
    if (!m_impl) {
        qDebug() << Q_FUNC_INFO << " object to trace is invalid. ";
        return {};
    }
    return m_impl->propString();
}

void SimpleArrayInterfaceTraced::traceSigBool(const QList<bool>& paramBool)
{
    SimpleArrayInterfaceAgent::trace_sigBool(this, paramBool);
}
void SimpleArrayInterfaceTraced::traceSigInt(const QList<int>& paramInt)
{
    SimpleArrayInterfaceAgent::trace_sigInt(this, paramInt);
}
void SimpleArrayInterfaceTraced::traceSigInt32(const QList<qint32>& paramInt32)
{
    SimpleArrayInterfaceAgent::trace_sigInt32(this, paramInt32);
}
void SimpleArrayInterfaceTraced::traceSigInt64(const QList<qint64>& paramInt64)
{
    SimpleArrayInterfaceAgent::trace_sigInt64(this, paramInt64);
}
void SimpleArrayInterfaceTraced::traceSigFloat(const QList<qreal>& paramFloat)
{
    SimpleArrayInterfaceAgent::trace_sigFloat(this, paramFloat);
}
void SimpleArrayInterfaceTraced::traceSigFloat32(const QList<float>& paramFloa32)
{
    SimpleArrayInterfaceAgent::trace_sigFloat32(this, paramFloa32);
}
void SimpleArrayInterfaceTraced::traceSigFloat64(const QList<double>& paramFloat64)
{
    SimpleArrayInterfaceAgent::trace_sigFloat64(this, paramFloat64);
}
void SimpleArrayInterfaceTraced::traceSigString(const QList<QString>& paramString)
{
    SimpleArrayInterfaceAgent::trace_sigString(this, paramString);
}

} // namespace tb_simple
