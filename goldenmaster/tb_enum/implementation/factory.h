#pragma once

#include <QtCore>

#include "tb_enum/api/iapifactory.h"
#if defined(TB_ENUM_IMPL_LIBRARY)
#  define TB_ENUM_IMPL_EXPORT Q_DECL_EXPORT
#else
#  define TB_ENUM_IMPL_EXPORT Q_DECL_IMPORT
#endif

namespace tb_enum {

/** 
* A Factory that creates the actual implementaion for interfaces in tb.enum
* You can check the usage of IApiFactory in Qml versions of interface implementation.
* By default this factory is not used as IApiFactory.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/
class TB_ENUM_IMPL_EXPORT Factory : public QObject, public IApiFactory
{
public:
    Factory(QObject *parent = nullptr);
    /** @return implementation of EnumInterface */
    std::shared_ptr<AbstractEnumInterface> createEnumInterface(QObject *parent) override;
};

} // namespace tb_enum

