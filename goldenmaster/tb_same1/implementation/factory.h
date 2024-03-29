#pragma once

#include <QtCore>

#include "tb_same1/api/iapifactory.h"
#if defined(TB_SAME1_IMPL_LIBRARY)
#  define TB_SAME1_IMPL_EXPORT Q_DECL_EXPORT
#else
#  define TB_SAME1_IMPL_EXPORT Q_DECL_IMPORT
#endif

namespace tb_same1 {

/** 
* A Factory that creates the actual implementaion for interfaces in tb.same1
* You can check the usage of IApiFactory in Qml versions of interface implementation.
* By default this factory is not used as IApiFactory.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/
class TB_SAME1_IMPL_EXPORT Factory : public QObject, public IApiFactory
{
public:
    Factory(QObject *parent = nullptr);
    /** @return implementation of SameStruct1Interface */
    std::shared_ptr<AbstractSameStruct1Interface> createSameStruct1Interface(QObject *parent) override;
    /** @return implementation of SameStruct2Interface */
    std::shared_ptr<AbstractSameStruct2Interface> createSameStruct2Interface(QObject *parent) override;
    /** @return implementation of SameEnum1Interface */
    std::shared_ptr<AbstractSameEnum1Interface> createSameEnum1Interface(QObject *parent) override;
    /** @return implementation of SameEnum2Interface */
    std::shared_ptr<AbstractSameEnum2Interface> createSameEnum2Interface(QObject *parent) override;
};

} // namespace tb_same1

