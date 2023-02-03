#pragma once

#include <QtCore>

#include "testbed2/api/apifactory.h"

namespace testbed2 {

/** 
* A Factory that creates the actual implementaion for interfaces in testbed2
* You can check the usage of ApiFactoryInterface in Qml versions of interface implementation.
* By default this factory is not used as ApiFactoryInterface.
* See also the ApiFactory, where you can set this factory as an ApiFactoryInterface implementation.
*/
class Factory : public QObject, public ApiFactoryInterface
{
public:
    Factory(QObject *parent = nullptr);
    /** @return implementation of ManyParamInterface */
    AbstractManyParamInterface* createManyParamInterface(QObject *parent) override;
    /** @return implementation of NestedStruct1Interface */
    AbstractNestedStruct1Interface* createNestedStruct1Interface(QObject *parent) override;
    /** @return implementation of NestedStruct2Interface */
    AbstractNestedStruct2Interface* createNestedStruct2Interface(QObject *parent) override;
    /** @return implementation of NestedStruct3Interface */
    AbstractNestedStruct3Interface* createNestedStruct3Interface(QObject *parent) override;
};

} // namespace testbed2

