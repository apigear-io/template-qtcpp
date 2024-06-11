#pragma once

#include <QtCore>

#include "custom_types/api/iapifactory.h"
#include "custom_types/api/api.h"
#if defined(CUSTOM_TYPES_MONITOR_LIBRARY)
#  define CUSTOM_TYPES_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define CUSTOM_TYPES_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace custom_types {

/** 
* A Factory that uses an interface created by other factory and wraps it with traces.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/

class CUSTOM_TYPES_MONITOR_EXPORT TracedApiFactory : public QObject, public IApiFactory
{
public:
    TracedApiFactory(IApiFactory& factory, QObject *parent = nullptr);
private:
    IApiFactory& m_factory;
};

} //namespace custom_types
