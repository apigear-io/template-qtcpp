#pragma once

#include <QtCore>

#include "testbed1/api/apifactory.h"

namespace testbed1 {

/** 
* A Factory that creates a OlinkClient version of interfaces in testbed1
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
    /** @return Olink Client version of StructInterface */
    AbstractStructInterface* createStructInterface(QObject *parent) override;
    /** @return Olink Client version of StructArrayInterface */
    AbstractStructArrayInterface* createStructArrayInterface(QObject *parent) override;
};

} //namespace testbed1
