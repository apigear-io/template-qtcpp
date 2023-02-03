#pragma once

#include <QtCore>

#include "tb_same2/api/apifactory.h"

namespace tb_same2 {

/** 
* A Factory that creates a OlinkClient version of interfaces in tb.same2
* The created interfaces implementation connect with a matching service objects on server side
* that provides functionality of the interface.
* You can check the usage of ApiFactoryInterface in Qml versions of interface implementation.
* By default this factory is not used as ApiFactoryInterface.
* See also the ApiFactory, where you can set this factory as an ApiFactoryInterface implementation.
*/

class OLinkFactory : public QObject, public ApiFactoryInterface
{
public:
    OLinkFactory(QObject *parent = nullptr);
    /** @return Olink Client version of SameStruct1Interface */
    AbstractSameStruct1Interface* createSameStruct1Interface(QObject *parent) override;
    /** @return Olink Client version of SameStruct2Interface */
    AbstractSameStruct2Interface* createSameStruct2Interface(QObject *parent) override;
    /** @return Olink Client version of SameEnum1Interface */
    AbstractSameEnum1Interface* createSameEnum1Interface(QObject *parent) override;
    /** @return Olink Client version of SameEnum2Interface */
    AbstractSameEnum2Interface* createSameEnum2Interface(QObject *parent) override;
};

} //namespace tb_same2
