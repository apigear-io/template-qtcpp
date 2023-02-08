#pragma once

#include <QtCore>

#include "testbed1/api/iapifactory.h"
#if defined(TESTBED1_IMPL_LIBRARY)
#  define TESTBED1_IMPL_EXPORT Q_DECL_EXPORT
#else
#  define TESTBED1_IMPL_EXPORT Q_DECL_IMPORT
#endif

namespace testbed1 {

/** 
* A Factory that creates the actual implementaion for interfaces in testbed1
* You can check the usage of IApiFactory in Qml versions of interface implementation.
* By default this factory is not used as IApiFactory.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/
class TESTBED1_IMPL_EXPORT Factory : public QObject, public IApiFactory
{
public:
    Factory(QObject *parent = nullptr);
    /** @return implementation of StructInterface */
    std::shared_ptr<AbstractStructInterface> createStructInterface(QObject *parent) override;
    /** @return implementation of StructArrayInterface */
    std::shared_ptr<AbstractStructArrayInterface> createStructArrayInterface(QObject *parent) override;
};

} // namespace testbed1

