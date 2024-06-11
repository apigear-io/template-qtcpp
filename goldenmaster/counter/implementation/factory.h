#pragma once

#include <QtCore>

#include "counter/api/iapifactory.h"
#if defined(COUNTER_IMPL_LIBRARY)
#  define COUNTER_IMPL_EXPORT Q_DECL_EXPORT
#else
#  define COUNTER_IMPL_EXPORT Q_DECL_IMPORT
#endif

namespace counter {

/** 
* A Factory that creates the actual implementaion for interfaces in counter
* You can check the usage of IApiFactory in Qml versions of interface implementation.
* By default this factory is not used as IApiFactory.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/
class COUNTER_IMPL_EXPORT Factory : public QObject, public IApiFactory
{
public:
    Factory(QObject *parent = nullptr);
    /** @return implementation of Counter */
    std::shared_ptr<AbstractCounter> createCounter(QObject *parent) override;
};

} // namespace counter

