#pragma once

#include <QtCore>

#include "testbed2/api/iapifactory.h"
#if defined(TESTBED2_IMPL_LIBRARY)
#  define TESTBED2_IMPL_EXPORT Q_DECL_EXPORT
#else
#  define TESTBED2_IMPL_EXPORT Q_DECL_IMPORT
#endif

namespace testbed2 {

/** 
* A Factory that creates the actual implementaion for interfaces in testbed2
* You can check the usage of IApiFactory in Qml versions of interface implementation.
* By default this factory is not used as IApiFactory.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/
class TESTBED2_IMPL_EXPORT Factory : public QObject, public IApiFactory
{
public:
    Factory(QObject *parent = nullptr);
    /** @return implementation of ManyParamInterface */
    std::shared_ptr<AbstractManyParamInterface> createManyParamInterface(QObject *parent) override;
    /** @return implementation of NestedStruct1Interface */
    std::shared_ptr<AbstractNestedStruct1Interface> createNestedStruct1Interface(QObject *parent) override;
    /** @return implementation of NestedStruct2Interface */
    std::shared_ptr<AbstractNestedStruct2Interface> createNestedStruct2Interface(QObject *parent) override;
    /** @return implementation of NestedStruct3Interface */
    std::shared_ptr<AbstractNestedStruct3Interface> createNestedStruct3Interface(QObject *parent) override;
};

} // namespace testbed2

