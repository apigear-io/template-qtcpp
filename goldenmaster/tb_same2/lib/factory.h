#pragma once

#include <QtCore>

#include "tb_same2/api/apifactory.h"

namespace tb_same2 {

/** 
* A Factory that creates the actual implementaion for interfaces in tb.same2
* You can check the usage of ApiFactoryInterface in Qml versions of interface implementation.
* By default this factory is not used as ApiFactoryInterface.
* See also the ApiFactory, where you can set this factory as an ApiFactoryInterface implementation.
*/
class Factory : public QObject, public ApiFactoryInterface
{
public:
    Factory(QObject *parent = nullptr);
    /** @return implementation of SameStruct1Interface */
    AbstractSameStruct1Interface* createSameStruct1Interface(QObject *parent) override;
    /** @return implementation of SameStruct2Interface */
    AbstractSameStruct2Interface* createSameStruct2Interface(QObject *parent) override;
    /** @return implementation of SameEnum1Interface */
    AbstractSameEnum1Interface* createSameEnum1Interface(QObject *parent) override;
    /** @return implementation of SameEnum2Interface */
    AbstractSameEnum2Interface* createSameEnum2Interface(QObject *parent) override;
};

} // namespace tb_same2

