#pragma once

#include <QtCore>

#include "tb_names/api/iapifactory.h"
#include "tb_names/api/api.h"
#if defined(TB_NAMES_MONITOR_LIBRARY)
#  define TB_NAMES_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define TB_NAMES_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace tb_names {

/** 
* A Factory that uses an interface created by other factory and wraps it with traces.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/

class TB_NAMES_MONITOR_EXPORT TracedApiFactory : public QObject, public IApiFactory
{
public:
    TracedApiFactory(IApiFactory& factory, QObject *parent = nullptr);
    /** @return Traced version of Nam_Es created by other factory*/
    std::shared_ptr<AbstractNamEs> createNamEs(QObject *parent = nullptr) override;
private:
    IApiFactory& m_factory;
};

} //namespace tb_names
