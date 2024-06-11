#pragma once

#include <QtCore>

#include "tb_simple/api/iapifactory.h"
#include "tb_simple/api/api.h"
#if defined(TB_SIMPLE_MONITOR_LIBRARY)
#  define TB_SIMPLE_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define TB_SIMPLE_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace tb_simple {

/** 
* A Factory that uses an interface created by other factory and wraps it with traces.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/

class TB_SIMPLE_MONITOR_EXPORT TracedApiFactory : public QObject, public IApiFactory
{
public:
    TracedApiFactory(IApiFactory& factory, QObject *parent = nullptr);
    /** @return Traced version of VoidInterface created by other factory*/
    std::shared_ptr<AbstractVoidInterface> createVoidInterface(QObject *parent = nullptr) override;
    /** @return Traced version of SimpleInterface created by other factory*/
    std::shared_ptr<AbstractSimpleInterface> createSimpleInterface(QObject *parent = nullptr) override;
    /** @return Traced version of SimpleArrayInterface created by other factory*/
    std::shared_ptr<AbstractSimpleArrayInterface> createSimpleArrayInterface(QObject *parent = nullptr) override;
    /** @return Traced version of NoPropertiesInterface created by other factory*/
    std::shared_ptr<AbstractNoPropertiesInterface> createNoPropertiesInterface(QObject *parent = nullptr) override;
    /** @return Traced version of NoOperationsInterface created by other factory*/
    std::shared_ptr<AbstractNoOperationsInterface> createNoOperationsInterface(QObject *parent = nullptr) override;
    /** @return Traced version of NoSignalsInterface created by other factory*/
    std::shared_ptr<AbstractNoSignalsInterface> createNoSignalsInterface(QObject *parent = nullptr) override;
private:
    IApiFactory& m_factory;
};

} //namespace tb_simple
