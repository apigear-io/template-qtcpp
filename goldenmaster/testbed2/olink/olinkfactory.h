#pragma once

#include <QtCore>

#include "testbed2/api/apifactory.h"
#include <apigear/olink/olinkclient.h>

namespace testbed2 {

/** 
* A Factory that creates a OlinkClient version of interfaces in testbed2
* The created interfaces implementation connect with a matching service objects on server side
* that provides functionality of the interface.
* You can check the usage of ApiFactoryInterface in Qml versions of interface implementation.
* By default this factory is not used as ApiFactoryInterface.
* See also the ApiFactory, where you can set this factory as an ApiFactoryInterface implementation.
*
* WARNING when creating the interface, make sure that server side already has the source (the interface service).
*    OR use unconnected client when creating the interface and connect it the source object is already there.
*
* WARNING Because the registry held by client cannot have multiple objects with same objectId (which is the combination of module and interface)
*         you will be able to have only one instance of each of your Interfaces connected to client at one time.
*         other interface instances wont be linked
*/

class OLinkFactory : public QObject, public ApiFactoryInterface
{
public:
    OLinkFactory(ApiGear::ObjectLink::OLinkClient& client, QObject *parent = nullptr);
    /** @return Olink Client version of ManyParamInterface */
    std::shared_ptr<AbstractManyParamInterface> createManyParamInterface(QObject *parent = nullptr) override;
    /** @return Olink Client version of NestedStruct1Interface */
    std::shared_ptr<AbstractNestedStruct1Interface> createNestedStruct1Interface(QObject *parent = nullptr) override;
    /** @return Olink Client version of NestedStruct2Interface */
    std::shared_ptr<AbstractNestedStruct2Interface> createNestedStruct2Interface(QObject *parent = nullptr) override;
    /** @return Olink Client version of NestedStruct3Interface */
    std::shared_ptr<AbstractNestedStruct3Interface> createNestedStruct3Interface(QObject *parent = nullptr) override;
private:
    ApiGear::ObjectLink::OLinkClient& m_client;
};

} //namespace testbed2
