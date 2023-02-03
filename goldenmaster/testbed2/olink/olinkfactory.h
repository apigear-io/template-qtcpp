#pragma once

#include <QtCore>

#include "testbed2/api/apifactory.h"

namespace testbed2 {

/** 
* A Factory that creates a OlinkClient version of interfaces in testbed2
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
    /** @return Olink Client version of ManyParamInterface */
    AbstractManyParamInterface* createManyParamInterface(QObject *parent) override;
    /** @return Olink Client version of NestedStruct1Interface */
    AbstractNestedStruct1Interface* createNestedStruct1Interface(QObject *parent) override;
    /** @return Olink Client version of NestedStruct2Interface */
    AbstractNestedStruct2Interface* createNestedStruct2Interface(QObject *parent) override;
    /** @return Olink Client version of NestedStruct3Interface */
    AbstractNestedStruct3Interface* createNestedStruct3Interface(QObject *parent) override;
};

} //namespace testbed2
