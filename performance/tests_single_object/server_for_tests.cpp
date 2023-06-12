#include "olink/remotenode.h"
#include "api/olink/olinktestapi0adapter.h"
#include "api/implementation/testapi0.h"
#include "olink/remoteregistry.h"
#include "olink/core/types.h"
#include "apigear/olink/olinkhost.h"
#include <memory>
#include <chrono>
#include <iostream>
#include <algorithm>

namespace {
    // Converter used in tests, should be same as one used by node.
    ApiGear::ObjectLink::MessageConverter converter(ApiGear::ObjectLink::MessageFormat::JSON);
}

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
class TestService : public api::OLinkTestApi0Adapter
{
public:
    TestService(ApiGear::ObjectLink::RemoteRegistry& registry, api::AbstractTestApi0* TestApi)
        :OLinkTestApi0Adapter(registry, TestApi)
    {}

    void olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* node) override
    {
        api::OLinkTestApi0Adapter::olinkLinked(objectId, node);
        m_status = ServiceStatus::LinkedRceived;
    }

    void olinkUnlinked(const std::string& objectId) override
    {
        api::OLinkTestApi0Adapter::olinkUnlinked(objectId);
        m_status = ServiceStatus::UnlinkedReceived;
    }
    ServiceStatus m_status = ServiceStatus::Default;
};

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    ApiGear::ObjectLink::RemoteRegistry registry;
    api::TestApi0 source;
    auto sourceService = std::make_shared<TestService>(registry, &source);
    registry.addSource(sourceService);

    quint16 portNumber = 8000;
    ApiGear::ObjectLink::OLinkHost server(registry);
    QString address = "127.0.0.1";

    server.listen(address, portNumber);
        
    auto serviceWorker = std::async(std::launch::async,
                                    [sourceService](){
        bool testStarted = false;
        // Will be overwritten with receiving link message
        auto begin = std::chrono::high_resolution_clock::now();
        auto servicesfinished = false;
        do {

            if (!testStarted && sourceService->m_status == ServiceStatus::LinkedRceived)
            {
                testStarted = true;
                begin = std::chrono::high_resolution_clock::now();
            }
            if (sourceService->m_status == ServiceStatus::UnlinkedReceived)
            {
                servicesfinished = true;
            }

        } while (!servicesfinished);
        auto end = std::chrono::high_resolution_clock::now();

        auto test_duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << "server finished work, time measured " << test_duration.count() << std::endl;
    });

    return app.exec();
}
