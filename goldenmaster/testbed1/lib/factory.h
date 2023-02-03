#pragma once

#include <QtCore>

#include "testbed1/api/apifactory.h"

namespace testbed1 {

/** 
* A Factory that creates the actual implementaion for interfaces in testbed1
* You can check the usage of ApiFactoryInterface in Qml versions of interface implementation.
* By default this factory is not used as ApiFactoryInterface.
* See also the ApiFactory, where you can set this factory as an ApiFactoryInterface implementation.
*/
class Factory : public QObject, public ApiFactoryInterface
{
public:
    Factory(QObject *parent = nullptr);
    /** @return implementation of StructInterface */
    AbstractStructInterface* createStructInterface(QObject *parent) override;
    /** @return implementation of StructArrayInterface */
    AbstractStructArrayInterface* createStructArrayInterface(QObject *parent) override;
};

} // namespace testbed1

