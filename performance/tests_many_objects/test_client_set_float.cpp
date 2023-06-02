#include "inspected_sink.h"
#include "olink/clientnode.h"
#include "olink/clientregistry.h"
#include "olink/core/types.h"
#include "apigear/olink/olinkclient.h"
#include <memory>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <future>

#include "prepare_test_data.h"

struct PropertyFloatTestData
{
public:
    std::shared_ptr<InspectedSink> sink;
    std::function<void(int)> testFunction;
};

class FloatPropertySetter {
public:
    template<class Interface>
    void testFunction(std::shared_ptr<Interface> object, float value)
    {
        object->setPropFloat(value);
    }
};

int main(int argc, char* argv[])
{
    std::vector<uint16_t> timePerMessage;
    auto messages_number = 1000u;
    if (argc > 1)
    {
        char* p;
        messages_number = strtol(argv[1], &p, 10);
    }
    auto portNumber = 8000;
    auto localHostAddress = "ws://127.0.0.1:" + std::to_string(portNumber);

    ApiGear::ObjectLink::ClientRegistry client_registry;
    ApiGear::ObjectLink::OLinkClient client(client_registry);
    client.connectToHost(QUrl("ws://127.0.0.1:8000/ws"));
    std::vector<std::shared_future<void>> tasks;
    FloatPropertySetter setter;
    auto testData = getTestData<PropertyFloatTestData, FloatPropertySetter>(setter);

    for (auto& element : testData)
    {
        client.linkObjectSource(element.sink);
    }
    auto begin = std::chrono::high_resolution_clock::now();
    for (auto& element : testData)
    {
        auto sendMessagesTask = std::async(std::launch::async,
            [&element, messages_number]() {
                while (element.sink->initReceived != true)
                {
                    // wait until ready to use.
                }
                for (auto i = 0; i < messages_number; i++)
                {
                    element.testFunction(i + float(i)/1000 + 1);
                }
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
