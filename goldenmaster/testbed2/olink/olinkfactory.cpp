#include "olinkfactory.h"
#include "utilities/logger.h"
#include "olink/olinkmanyparaminterface.h"
#include "olink/olinknestedstruct1interface.h"
#include "olink/olinknestedstruct2interface.h"
#include "olink/olinknestedstruct3interface.h"

namespace testbed2 {

OLinkFactory::OLinkFactory(ApiGear::ObjectLink::OLinkClient& client, QObject *parent)
    : QObject(parent),
      m_client(client)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

std::shared_ptr<AbstractManyParamInterface> OLinkFactory::createManyParamInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto many_param_interface = std::make_shared<OLinkManyParamInterface>();
    m_client.linkObjectSource(many_param_interface);
    return many_param_interface;
}

std::shared_ptr<AbstractNestedStruct1Interface> OLinkFactory::createNestedStruct1Interface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto nested_struct1_interface = std::make_shared<OLinkNestedStruct1Interface>();
    m_client.linkObjectSource(nested_struct1_interface);
    return nested_struct1_interface;
}

std::shared_ptr<AbstractNestedStruct2Interface> OLinkFactory::createNestedStruct2Interface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto nested_struct2_interface = std::make_shared<OLinkNestedStruct2Interface>();
    m_client.linkObjectSource(nested_struct2_interface);
    return nested_struct2_interface;
}

std::shared_ptr<AbstractNestedStruct3Interface> OLinkFactory::createNestedStruct3Interface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto nested_struct3_interface = std::make_shared<OLinkNestedStruct3Interface>();
    m_client.linkObjectSource(nested_struct3_interface);
    return nested_struct3_interface;
}

} //namespace testbed2