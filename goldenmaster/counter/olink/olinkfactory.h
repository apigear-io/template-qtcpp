#pragma once

#include <QtCore>

#include "counter/api/iapifactory.h"
#include <apigear/olink/olinkclient.h>

namespace counter {

/** 
* A Factory that creates a OlinkClient version of interfaces in counter
* The created interfaces implementation connect with a matching service objects on server side
* that provides functionality of the interface.
* You can check the usage of IApiFactory in Qml versions of interface implementation.
* By default this factory is not used as IApiFactory.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*
* WARNING when creating the interface, make sure that server side already has the source (the interface service).
*    OR use unconnected client when creating the interface and connect it the source object is already there.
*
* WARNING Because the registry held by client cannot have multiple objects with same objectId (which is the combination of module and interface)
*         you will be able to have only one instance of each of your Interfaces connected to client at one time.
*         other interface instances wont be linked
*/

class OLinkFactory : public QObject, public IApiFactory
{
public:
    OLinkFactory(ApiGear::ObjectLink::OLinkClient& client, QObject *parent = nullptr);
    /** @return Olink Client version of Counter */
    std::shared_ptr<AbstractCounter> createCounter(QObject *parent = nullptr) override;
private:
    ApiGear::ObjectLink::OLinkClient& m_client;
};

} //namespace counter
