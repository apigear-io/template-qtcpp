#include "olinkfactory.h"
#include "utilities/logger.h"
#include "olink/olinkvoidinterface.h"
#include "olink/olinksimpleinterface.h"
#include "olink/olinksimplearrayinterface.h"
#include "olink/olinknopropertiesinterface.h"
#include "olink/olinknooperationsinterface.h"
#include "olink/olinknosignalsinterface.h"

namespace tb_simple {

OLinkFactory::OLinkFactory(ApiGear::ObjectLink::OLinkClient& client, QObject *parent)
    : QObject(parent),
      m_client(client)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
}

std::shared_ptr<AbstractVoidInterface> OLinkFactory::createVoidInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto void_interface = std::make_shared<OLinkVoidInterface>();
    m_client.linkObjectSource(void_interface);
    return void_interface;
}

std::shared_ptr<AbstractSimpleInterface> OLinkFactory::createSimpleInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto simple_interface = std::make_shared<OLinkSimpleInterface>();
    m_client.linkObjectSource(simple_interface);
    return simple_interface;
}

std::shared_ptr<AbstractSimpleArrayInterface> OLinkFactory::createSimpleArrayInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto simple_array_interface = std::make_shared<OLinkSimpleArrayInterface>();
    m_client.linkObjectSource(simple_array_interface);
    return simple_array_interface;
}

std::shared_ptr<AbstractNoPropertiesInterface> OLinkFactory::createNoPropertiesInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto no_properties_interface = std::make_shared<OLinkNoPropertiesInterface>();
    m_client.linkObjectSource(no_properties_interface);
    return no_properties_interface;
}

std::shared_ptr<AbstractNoOperationsInterface> OLinkFactory::createNoOperationsInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto no_operations_interface = std::make_shared<OLinkNoOperationsInterface>();
    m_client.linkObjectSource(no_operations_interface);
    return no_operations_interface;
}

std::shared_ptr<AbstractNoSignalsInterface> OLinkFactory::createNoSignalsInterface(QObject *parent)
{
    AG_LOG_DEBUG(Q_FUNC_INFO);
    auto no_signals_interface = std::make_shared<OLinkNoSignalsInterface>();
    m_client.linkObjectSource(no_signals_interface);
    return no_signals_interface;
}

} //namespace tb_simple