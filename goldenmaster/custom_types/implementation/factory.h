#pragma once

#include <QtCore>

#include "custom_types/api/iapifactory.h"
#if defined(CUSTOM_TYPES_IMPL_LIBRARY)
#  define CUSTOM_TYPES_IMPL_EXPORT Q_DECL_EXPORT
#else
#  define CUSTOM_TYPES_IMPL_EXPORT Q_DECL_IMPORT
#endif

namespace custom_types {

/** 
* A Factory that creates the actual implementaion for interfaces in custom_types
* You can check the usage of IApiFactory in Qml versions of interface implementation.
* By default this factory is not used as IApiFactory.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/
class CUSTOM_TYPES_IMPL_EXPORT Factory : public QObject, public IApiFactory
{
public:
    Factory(QObject *parent = nullptr);
};

} // namespace custom_types

