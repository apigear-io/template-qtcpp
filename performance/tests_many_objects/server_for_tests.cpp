#include "prepare_test_services.h"

#include "olink/remoteregistry.h"

#include "apigear/olink/olinkhost.h"

#include <memory>
#include <chrono>
#include <iostream>
#include <algorithm>


int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    ApiGear::ObjectLink::RemoteRegistry registry;
    auto services = prepareServices(registry);

    quint16 portNumber = 8000;
    ApiGear::ObjectLink::OLinkHost server(registry);
    QString address = "127.0.0.1";

    server.listen(address, portNumber);

    auto serviceWorker = std::async(std::launch::async,
                                    [&services](){
        bool testStarted = false;
        // Will be overwritten with receiving link message
        auto begin = std::chrono::high_resolution_clock::now();
        auto servicesfinished = 0;
        do {

            servicesfinished = 0;
            for (auto& service : services)
            {
                if (!testStarted && service->m_status == ServiceStatus::LinkedRceived)
                {
                    testStarted = true;
                    begin = std::chrono::high_resolution_clock::now();
                }
                if (service->m_status == ServiceStatus::UnlinkedReceived)
                {
                    servicesfinished++;
                }
            }

        } while (servicesfinished != services.size());
        auto end = std::chrono::high_resolution_clock::now();

        auto test_duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << "server finished work, time measured " << test_duration.count() << std::endl;
    });

    return app.exec();
}
