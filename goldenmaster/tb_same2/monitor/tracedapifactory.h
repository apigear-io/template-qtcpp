#pragma once

#include <QtCore>

#include "tb_same2/api/iapifactory.h"
#include "tb_same2/api/api.h"
#if defined(TB_SAME2_MONITOR_LIBRARY)
#  define TB_SAME2_MONITOR_EXPORT Q_DECL_EXPORT
#else
#  define TB_SAME2_MONITOR_EXPORT Q_DECL_IMPORT
#endif

namespace tb_same2 {

/** 
* A Factory that uses an interface created by other factory and wraps it with traces.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/

class TB_SAME2_MONITOR_EXPORT TracedApiFactory : public QObject, public IApiFactory
{
public:
    TracedApiFactory(IApiFactory& factory, QObject *parent = nullptr);
    /** @return Traced version of SameStruct1Interface created by other factory*/
    std::shared_ptr<AbstractSameStruct1Interface> createSameStruct1Interface(QObject *parent = nullptr) override;
    /** @return Traced version of SameStruct2Interface created by other factory*/
    std::shared_ptr<AbstractSameStruct2Interface> createSameStruct2Interface(QObject *parent = nullptr) override;
    /** @return Traced version of SameEnum1Interface created by other factory*/
    std::shared_ptr<AbstractSameEnum1Interface> createSameEnum1Interface(QObject *parent = nullptr) override;
    /** @return Traced version of SameEnum2Interface created by other factory*/
    std::shared_ptr<AbstractSameEnum2Interface> createSameEnum2Interface(QObject *parent = nullptr) override;
private:
    IApiFactory& m_factory;
};

} //namespace tb_same2
