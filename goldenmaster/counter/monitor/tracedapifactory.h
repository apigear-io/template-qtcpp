#pragma once

#include <QtCore>

#include "counter/api/iapifactory.h"
#include "counter/api/api.h"
#if defined(COUNTER_MONITOR_LIBRARY)
#  define COUNTER_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define COUNTER_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace counter {

/** 
* A Factory that uses an interface created by other factory and wraps it with traces.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/

class COUNTER_MONITOR_EXPORT TracedApiFactory : public QObject, public IApiFactory
{
public:
    TracedApiFactory(IApiFactory& factory, QObject *parent = nullptr);
    /** @return Traced version of Counter created by other factory*/
    std::shared_ptr<AbstractCounter> createCounter(QObject *parent = nullptr) override;
private:
    IApiFactory& m_factory;
};

} //namespace counter
