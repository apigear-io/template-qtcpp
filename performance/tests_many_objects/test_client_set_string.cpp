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

#include "api/olink/olinktestapi0.h"
#include "prepare_test_data.h"


#include <iostream>


struct PropertyIntTestData
{
public:
    std::shared_ptr<InspectedSink> sink;
    std::function<void(int)> testFunction;
};

class StringPropertySetter {
public:
    StringPropertySetter(int numberOfMessages)
    {
        for (int messageNo = 0u; messageNo < numberOfMessages; messageNo++)
        {
            messagesToSend.push_back(QString::fromStdString("Some longer property to be set, prepared before test for each message number to reduce allocating time in tests"
                    + std::to_string(messageNo)));
        }
    }

    template<class Interface>
    void testFunction(std::shared_ptr<Interface> object, int number)
    {
        object->setPropString(messagesToSend[number]);
    }

    // Prepare messages to send before test starts not to slow down it with allocation of this many messages:
    std::vector<QString> messagesToSend;
};

void waitForReturnMessages(const std::vector<PropertyIntTestData>& testData, uint32_t messages_number)
{
    auto allMessagesReceived = false;
    while (!allMessagesReceived)
    {
        auto serviceWithAllMessages = 0u;
        for (const auto& element : testData)
        {
            if (element.sink->propertyChangedTimes == messages_number)
            {
                serviceWithAllMessages++;
            }
        }
        allMessagesReceived = serviceWithAllMessages == testData.size();
    }
}

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    std::vector<uint16_t> timePerMessage;
    auto messages_number = 1000u;
    if (argc > 1)
    {
        char* p;
        messages_number = strtol(argv[1], &p, 10);
    }

    ApiGear::ObjectLink::ClientRegistry client_registry;
    ApiGear::ObjectLink::OLinkClient client(client_registry);
    client.connectToHost(QUrl("ws://127.0.0.1:8000/ws"));
    std::vector<std::shared_future<void>> tasks;
    StringPropertySetter setter(messages_number);
    auto testData = getTestData<PropertyIntTestData, StringPropertySetter>(setter);


    auto clientThread = std::async(std::launch::async,
        [&tasks, messages_number, &testData, &client](){
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
                            element.testFunction(i);
                        }
                    });
                // Extend scope of task, not to wait here in a function for it to be over.
                tasks.push_back(sendMessagesTask.share());
            }

            waitForReturnMessages(testData, messages_number);

            for (auto& element : testData)
            {
                client.unlinkObjectSource(element.sink->olinkObjectName());
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
            std::cout << "Time measured " << time.count() << std::endl;
    });

    return app.exec();
}
