#pragma once

#include <QtCore>

#include "tb_enum/api/apifactory.h"

namespace tb_enum {

/** 
* A Factory that creates the actual implementaion for interfaces in tb.enum
* You can check the usage of ApiFactoryInterface in Qml versions of interface implementation.
* By default this factory is not used as ApiFactoryInterface.
* See also the ApiFactory, where you can set this factory as an ApiFactoryInterface implementation.
*/
class Factory : public QObject, public ApiFactoryInterface
{
public:
    Factory(QObject *parent = nullptr);
    /** @return implementation of EnumInterface */
    std::shared_ptr<AbstractEnumInterface> createEnumInterface(QObject *parent) override;
};

} // namespace tb_enum

