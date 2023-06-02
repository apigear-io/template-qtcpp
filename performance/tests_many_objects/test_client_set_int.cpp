#include "inspected_sink.h"
#include "olink/clientregistry.h"
#include "apigear/olink/olinkclient.h"
#include <memory>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <future>

#include "prepare_test_data.h"

struct PropertyIntTestData
{
public:
    std::shared_ptr<InspectedSink> sink;
    std::function<void(int)> testFunction;
};

class IntPropertySetter {
public:
    template<class Interface>
    void testFunction(std::shared_ptr<Interface> object, int value)
    {
        object->setPropInt(value);
    }
};

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    std::vector<uint16_t> timePerMessage;
    auto messages_number = 100u;
    if (argc > 1)
    {
        char* p;
        messages_number = strtol(argv[1], &p, 10);
    }
    auto portNumber = 8000;
    QString localHostAddressWithPort = "ws://127.0.0.1:" + QString::fromStdString(std::to_string(portNumber)) + QString("/ws");
    ApiGear::ObjectLink::ClientRegistry client_registry;
    ApiGear::ObjectLink::OLinkClient client(client_registry);
    client.connectToHost(QUrl(localHostAddressWithPort));

    std::vector<std::shared_future<void>> tasks;
    IntPropertySetter setter;
    auto testData = getTestData<PropertyIntTestData, IntPropertySetter>(setter);

    for (auto& element : testData)
    {
        client.linkObjectSource(element.sink);
    }

    auto result = app.exec();

    auto begin = std::chrono::high_resolution_clock::now();
    for (auto& element : testData)
    {
        auto sendMessagesTask = std::async(std::launch::async,
            [&element, messages_number](){
                while (element.sink->initReceived != true)
                {
                    // wait until ready to use.
                }
                std::cout<<"Init received "<<element.sink->olinkObjectName() << std::endl;
                for (auto i = 0; i < messages_number; i++)
                {
                    element.testFunction(i + 1);
                }
                std::cout<<"Sent all messages for "<<element.sink->olinkObjectName() << std::endl;
            });
        tasks.push_back(sendMessagesTask.share());
    }

    for (auto task : tasks)
    {
        task.wait();
    }
    auto allMessagesReceived = false;
    while (!allMessagesReceived)
    {
        auto serviceWithAllMessages = 0u;
        for (auto& element : testData)
        {
            if (element.sink->propertyChangedTimes == messages_number)
            {
                serviceWithAllMessages++;
            }
        }
        allMessagesReceived = serviceWithAllMessages == testData.size();
    }
    for (auto& element : testData)
    {
        client.unlinkObjectSource(element.sink->olinkObjectName());
    }
    auto end = std::chrono::high_resolution_clock::now();
    client.disconnect();
  
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);


    std::cout << "Time measured " << time.count() << std::endl;

    return 0;
}
