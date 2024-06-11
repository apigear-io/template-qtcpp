#pragma once

#include <QtCore>

#include "extern_types/api/iapifactory.h"
#if defined(EXTERN_TYPES_IMPL_LIBRARY)
#  define EXTERN_TYPES_IMPL_EXPORT Q_DECL_EXPORT
#else
#  define EXTERN_TYPES_IMPL_EXPORT Q_DECL_IMPORT
#endif

namespace extern_types {

/** 
* A Factory that creates the actual implementaion for interfaces in extern_types
* You can check the usage of IApiFactory in Qml versions of interface implementation.
* By default this factory is not used as IApiFactory.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/
class EXTERN_TYPES_IMPL_EXPORT Factory : public QObject, public IApiFactory
{
public:
    Factory(QObject *parent = nullptr);
};

} // namespace extern_types

