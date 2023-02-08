#pragma once

#include <QtCore>

#include "testbed1/api/iapifactory.h"
#include "testbed1/api/api.h"
#if defined(TESTBED1_MONITOR_LIBRARY)
#  define TESTBED1_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define TESTBED1_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace testbed1 {

/** 
* A Factory that uses an interface created by other factory and wraps it with traces.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/

class TESTBED1_MONITOR_EXPORT TracedApiFactory : public QObject, public IApiFactory
{
public:
    TracedApiFactory(IApiFactory& factory, QObject *parent = nullptr);
    /** @return Traced version of StructInterface created by other factory*/
    std::shared_ptr<AbstractStructInterface> createStructInterface(QObject *parent = nullptr) override;
    /** @return Traced version of StructArrayInterface created by other factory*/
    std::shared_ptr<AbstractStructArrayInterface> createStructArrayInterface(QObject *parent = nullptr) override;
private:
    IApiFactory& m_factory;
};

} //namespace testbed1
