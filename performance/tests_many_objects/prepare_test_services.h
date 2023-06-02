#include "olink/remoteregistry.h"
#include "olink/iobjectsource.h"
#include "olink/core/types.h"

#include <memory>
#include <vector>

enum class ServiceStatus
{
    Default,
    LinkedRceived,
    UnlinkedReceived
};

/*
* Class that wraps tested object with additional info used for either test creation purpose:
* the link and unlink info is used to determine when test starts and when it stops.
*/
class InspectedService : public ApiGear::ObjectLink::IObjectSource
{
public:
    InspectedService(std::shared_ptr<ApiGear::ObjectLink::IObjectSource> source)
        : m_source(source)
    {
    }

    std::string olinkObjectName() override
    {
        return m_source->olinkObjectName();
    }

    nlohmann::json olinkInvoke(const std::string& methodId, const nlohmann::json& args) override
    {
        return m_source->olinkInvoke(methodId, args);
    }

    void olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) override
    {
        return m_source->olinkSetProperty(propertyId, value);
    }


    void olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* node) override
    {
        m_source->olinkLinked(objectId, node);
        m_status = ServiceStatus::LinkedRceived;
    }

    void olinkUnlinked(const std::string& objectId) override
    {
        m_source->olinkUnlinked(objectId);
        m_status = ServiceStatus::UnlinkedReceived;
    }

    nlohmann::json olinkCollectProperties() override
    {
        return m_source->olinkCollectProperties();
    }

    ServiceStatus m_status = ServiceStatus::Default;

    std::shared_ptr<ApiGear::ObjectLink::IObjectSource> m_source;
};


std::vector < std::shared_ptr<InspectedService>> prepareServices(ApiGear::ObjectLink::RemoteRegistry& registry);
