#pragma once

#include <QtCore>

#include "tb_simple/api/iapifactory.h"
#if defined(TB_SIMPLE_IMPL_LIBRARY)
#  define TB_SIMPLE_IMPL_EXPORT Q_DECL_EXPORT
#else
#  define TB_SIMPLE_IMPL_EXPORT Q_DECL_IMPORT
#endif

namespace tb_simple {

/** 
* A Factory that creates the actual implementaion for interfaces in tb.simple
* You can check the usage of IApiFactory in Qml versions of interface implementation.
* By default this factory is not used as IApiFactory.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/
class TB_SIMPLE_IMPL_EXPORT Factory : public QObject, public IApiFactory
{
public:
    Factory(QObject *parent = nullptr);
    /** @return implementation of SimpleInterface */
    std::shared_ptr<AbstractSimpleInterface> createSimpleInterface(QObject *parent) override;
    /** @return implementation of SimpleArrayInterface */
    std::shared_ptr<AbstractSimpleArrayInterface> createSimpleArrayInterface(QObject *parent) override;
};

} // namespace tb_simple

