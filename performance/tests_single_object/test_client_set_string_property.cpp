#include "test_sink.h"
#include "olink/clientnode.h"
#include "olink/clientregistry.h"
#include "olink/core/types.h"
#include "apigear/olink/olinkclient.h"
#include <memory>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <future>

/*
By default test request property string change 600 times from each of 100 threads.
Each message is over 100 character long.
Test waits for the responses after sending all the messages, not for each one.
You can play around with running this program with different messages number and different threads number.
*/
int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    std::vector<uint16_t> timePerMessage;
    auto sendThreadNumber = 1u;
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

            // Prepare messages to send before test starts not to slow down it with allocation of this many messages:
            std::vector<std::vector<QString>> messagesToSend;
            for (int threadNo = 0u; threadNo < sendThreadNumber; threadNo++)
            {
                std::vector<QString> msgsForSingleThread;
                for (auto i = 0u; i < messages_number; i++)
                {
                    auto message = "Some longer property to be set, prepared before test for each message number to reduce allocating time in tests"+ std::to_string(threadNo* messages_number + i);
                    msgsForSingleThread.push_back(QString::fromStdString(message));//make every message different
                }
                messagesToSend.push_back(msgsForSingleThread);
            }

            client.linkObjectSource(sink);
            auto begin = std::chrono::high_resolution_clock::now();
            sink->connect(sink.get(), &api::OLinkTestApi0::isReady,
                    [sink, messages_number, &tasks, sendThreadNumber, &messagesToSend]()
                    {
                        for (int threadNo = 0u; threadNo < sendThreadNumber; threadNo++)
                        {
                            auto& messagesForThread = messagesToSend[threadNo];
                            auto sendMessagesTask = std::async(std::launch::async,
                                [sink, messages_number, &messagesForThread](){
                                    auto beginM = std::chrono::high_resolution_clock::now();
                                    for (auto i = 0u; i < messages_number; i++)
                                    {
                                        sink->setPropString(messagesForThread[i]);
                                    }

                                auto endM = std::chrono::high_resolution_clock::now();
                                return std::chrono::duration_cast<std::chrono::milliseconds>(endM - beginM).count();
                            });
                            tasks.push_back(sendMessagesTask.share());
                        }
                    });

            for (auto task : tasks)
            {
                task.wait();
            }
            while (sink->propertyChangedTimes < messages_number * sendThreadNumber)
            {
                // Wait until all responses received.
            }
            client.unlinkObjectSource(sink->olinkObjectName());
            auto end = std::chrono::high_resolution_clock::now();
            std::cout << "received " << sink->propertyChangedTimes << " of " << messages_number * sendThreadNumber << "  " << (double)sink->propertyChangedTimes / (double)messages_number / (double)sendThreadNumber << std::endl;;

            auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
            std::cout << "Time measured " << time.count() << std::endl;
    });
 

    return app.exec();
}
