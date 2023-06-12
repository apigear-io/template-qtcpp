#include "test_sink.h"
#include "apigear/olink/olinkclient.h"
#include "api/olink/olinktestapi0.h"
#include "olink/clientregistry.h"
#include <memory>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <future>

/*
By default test request property int change 1000 times from each of 100 threads.
Test waits for the responses after sending all the messages, not for each one.
You can play around with running this program with different messages number and different threads number.
*/
int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    std::vector<uint16_t> timePerMessage;
    auto sendThreadNumber = 100u;
    auto messages_number = 1000u;
    if (argc > 1)
    {
        char* p;
        messages_number = strtol(argv[1], &p, 10);
    }
    if (argc > 2)
    {
        char* p;
        sendThreadNumber = strtol(argv[2], &p, 10);
    }

    ApiGear::ObjectLink::ClientRegistry client_registry;
    ApiGear::ObjectLink::OLinkClient client(client_registry);
    client.connectToHost(QUrl("ws://127.0.0.1:8000/ws"));
    auto sink = std::make_shared<TestSink>();


    auto clientThread = std::async(std::launch::async,
        [sendThreadNumber, messages_number, sink, &client](){


        std::vector<std::shared_future<long long>> tasks;
        auto begin = std::chrono::high_resolution_clock::now();

        client.linkObjectSource(sink);

        sink->connect(sink.get(), &api::OLinkTestApi0::isReady,
            [sink, messages_number, &tasks, sendThreadNumber]()
            {
                for (int threadNo = 0u; threadNo < sendThreadNumber; threadNo++)
                {
                    auto sendMessagesTask = std::async(std::launch::async,
                        [sink, messages_number, threadNo]() {
                            auto beginM = std::chrono::high_resolution_clock::now();

                            for (auto i = 0u; i < messages_number; i++)
                            {
                                sink->setPropInt(threadNo * messages_number + i + 1);
                            }

                            auto endM = std::chrono::high_resolution_clock::now();
                            return (beginM-endM).count();
                        });
                    tasks.push_back(sendMessagesTask.share());
                }
            });

        for (auto task : tasks)
        {
            task.wait();
        }
        while (sink->propertyChangedTimes < messages_number* sendThreadNumber)
        {
            // Wait until all responses received.
        }
        client.unlinkObjectSource(sink->olinkObjectName());

        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "received " << sink->propertyChangedTimes << " of " << messages_number * sendThreadNumber << "  " << (double)sink->propertyChangedTimes / (double)messages_number / (double)sendThreadNumber << std::endl;;

        auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        std::cout<<"Time measured "<< time .count() << std::endl;
    });
    return app.exec();
}
