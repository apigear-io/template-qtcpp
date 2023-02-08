#pragma once

#include <QtCore>

#include "testbed2/api/iapifactory.h"
#include "testbed2/api/api.h"
#if defined(TESTBED2_MONITOR_LIBRARY)
#  define TESTBED2_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define TESTBED2_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace testbed2 {

/** 
* A Factory that uses an interface created by other factory and wraps it with traces.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/

class TESTBED2_MONITOR_EXPORT TracedApiFactory : public QObject, public IApiFactory
{
public:
    TracedApiFactory(IApiFactory& factory, QObject *parent = nullptr);
    /** @return Traced version of ManyParamInterface created by other factory*/
    std::shared_ptr<AbstractManyParamInterface> createManyParamInterface(QObject *parent = nullptr) override;
    /** @return Traced version of NestedStruct1Interface created by other factory*/
    std::shared_ptr<AbstractNestedStruct1Interface> createNestedStruct1Interface(QObject *parent = nullptr) override;
    /** @return Traced version of NestedStruct2Interface created by other factory*/
    std::shared_ptr<AbstractNestedStruct2Interface> createNestedStruct2Interface(QObject *parent = nullptr) override;
    /** @return Traced version of NestedStruct3Interface created by other factory*/
    std::shared_ptr<AbstractNestedStruct3Interface> createNestedStruct3Interface(QObject *parent = nullptr) override;
private:
    IApiFactory& m_factory;
};

} //namespace testbed2
