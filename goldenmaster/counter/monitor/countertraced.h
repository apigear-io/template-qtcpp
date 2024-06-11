

#pragma once
#include "counter/api/api.h"
#include "counter/monitor/agent.h"
#include <memory>

#if defined(COUNTER_MONITOR_LIBRARY)
#  define COUNTER_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define COUNTER_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace counter {

class CounterTracer;

/** 
* Trace decorator for Counter.
*/

class COUNTER_MONITOR_EXPORT CounterTraced : public AbstractCounter
{
public:
    /** 
    * ctor
    * Subscribes for signal emission.
    * @param impl The Counter object to trace.
    */
    explicit CounterTraced(std::shared_ptr<AbstractCounter> impl);
    /** dtor */
    virtual ~CounterTraced() = default;

    /** Traces increment and forwards call to Counter implementation. */
    QVector3D increment(const QVector3D& vec) override;
    
    /** Traces decrement and forwards call to Counter implementation. */
    custom_types::Vector3D decrement(const custom_types::Vector3D& vec) override;
    
    /** Traces and forwards call to Counter implementation. */
    void setVector(const custom_types::Vector3D& vector) override;
    /** Forwards call to Counter implementation. */
    custom_types::Vector3D vector() const override;
    
    /** Traces and forwards call to Counter implementation. */
    void setExternVector(const QVector3D& extern_vector) override;
    /** Forwards call to Counter implementation. */
    QVector3D extern_vector() const override;
    slots

private:
    /** The Counter object which is traced */
    std::shared_ptr<AbstractCounter> m_impl;
};
} // namespace counter
