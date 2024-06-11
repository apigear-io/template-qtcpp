#pragma once

#include <QtCore>

#include "extern_types/api/iapifactory.h"
#include "extern_types/api/api.h"
#if defined(EXTERN_TYPES_MONITOR_LIBRARY)
#  define EXTERN_TYPES_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define EXTERN_TYPES_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace extern_types {

/** 
* A Factory that uses an interface created by other factory and wraps it with traces.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/

class EXTERN_TYPES_MONITOR_EXPORT TracedApiFactory : public QObject, public IApiFactory
{
public:
    TracedApiFactory(IApiFactory& factory, QObject *parent = nullptr);
private:
    IApiFactory& m_factory;
};

} //namespace extern_types
