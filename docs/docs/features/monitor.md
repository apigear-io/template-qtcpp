﻿---
sidebar_position: 4
---
import CodeBlock from '@theme/CodeBlock';
import helloWorldModuleComponent from '!!raw-loader!./data/helloworld.module.yaml';

# Monitor

Use our monitor feature to examine the interface calls, state and signals. With this feature you obtain a monitor client and a monitored version of your interfaces. The monitoring server is embedded into the [ApiGear Studio](https://docs.apigear.io/docs/category/desktop-studio) and CLI application(https://docs.apigear.io/docs/category/command-line).
More details on [monitoring](https://docs.apigear.io/docs/advanced/monitor/intro)

## File overview for module
 
 With an example  API

<details><summary>Hello World API (click to expand)</summary>
<CodeBlock language="yaml" showLineNumbers>{helloWorldModuleComponent}</CodeBlock>
</details>

the following file structure will be generated. The purpose and content of each file is explained below.

```bash {4,16}
📂hello-world
 ┣ 📂apigear
 ┃ ...
 ┣ 📂qt_hello_world
 ┃ ┣ 📂apigear
 ┃ ┃ ┣ 📂monitor
 ┃ ┃ ┃ ┣ 📜agentclient.cpp
 ┃ ┃ ┃ ┣ 📜agentclient.h
 ┃ ┃ ┃ ┗ 📜CMakeLists.txt
 ┃ ┃ ...
 ┃ ┣ 📂examples
 ┃ ┣ 📂io_world
 ┃ ┃ ┣ 📂api
 ┃ ┃ ┣ 📂implementation
 ┃ ┃ ┣ 📂olink
 ┃ ┃ ┣ 📂monitor
 ┃ ┃ ┃ ┣ 📜agent.cpp
 ┃ ┃ ┃ ┣ 📜agent.h
 ┃ ┃ ┃ ┣ 📜CMakeLists.txt
 ┃ ┃ ┃ ┣ 📜tracedapifactory.cpp
 ┃ ┃ ┃ ┣ 📜tracedapifactory.h
 ┃ ┃ ┃ ┣ 📜hellotraced.cpp
 ┃ ┃ ┃ ┗ 📜hellotraced.h
 ...
```

### Qt Trace Client

When generating the monitor feature (or olink feature) you'll get an additional folder it the top most directory: 📂hello-world/📂apigear. The 📂monitor subfolder contains a client for logging, with a network layer (based on the QtWebSocket library).
The class connects to the `Apigear Trace Server` and takes care of formatting and sending the traces. 


### Monitor

Files `📜hellotraced.h` and `📜hellotraced.cpp` contain the trace wrapper for the `Hello` interface. The wrapper class is generated for each interface. 

```cpp
class IO_WORLD_MONITOR_EXPORT HelloTraced : public AbstractHello
{
    explicit HelloTraced(std::shared_ptr<AbstractHello> impl);

...
};
```
It shares the ownership of the wrapped object. It forwards all calls to the implementation and forwards all the signals (including the property changed signals) calls from it, so you can use the `TracedHello` as a `Hello` object. Note that the `Hello` object is the object that fulfills the `AbstractHello` interface, it can be e.g. the [`OlinkClient`](olink.md) version of `Hello`.

The `📜agent.h` and `📜agent.cpp` files contain helpers to prepare interface specific trace data for the general tracing [TraceClient](monitor#qt-trace-client)

### Tracing with QML objects

Files `📜tracedapifactory.h`  and `📜tracedapifactory.cpp` contain the TracedApiFactory which creates the interfaces wrapped with the trace decorator.
In our example it will produce only `Hello` interfaces:
```cpp
class IO_WORLD_MONITOR_EXPORT TracedApiFactory : public QObject, public IApiFactory
{
    TracedApiFactory(IApiFactory& factory, QObject *parent = nullptr);
 ```
The factory is necessary when you want to use the traced `Hello` object directly in QML. For that, you will choose the [QML version](api#qml-wrappers) of your API to which you need provide proper backend - this is what the factory is for. See more details [on providing backend to QML wrapper](api#providing-backend-to-qml-wrapper). The important difference between other factories implementations is, that the `TracedHello` is a wrapper, it requires the actual implementation to be passed to it. Therefor the factory needs a factory of the actual implementation objects, which it will wrap with the trace functionality. That it requires a factory in constructor. You can provide any backed you need e.g. your custom object, the [`OlinkClient`](olink.md).
See the example of traced OlinkClient backend below:

```cpp 
    // Prepare Factory before app is created.
    ApiGear::ObjectLink::ClientRegistry client_registry;
    ApiGear::ObjectLink::OLinkClient client(client_registry);
    io_world::OLinkFactory io_worldOlinkFactory(client);
    io_world::TracedApiFactory io_worldTracedOlinkFactory(io_worldOlinkFactory); 
    io_world::ApiFactory::set(&io_worldTracedOlinkFactory);
    ...
    // Connect the client - all qml olink clients will be linked if the server services are already up.
    client.connectToHost(QUrl("ws://127.0.0.1:8182"));
```
The factory uses the `ApiGear::ObjectLink::OLinkClient` and links the objects when they are created. You don't have to perform any other actions, just use your qml version of `Hello`. Also on trace the TracedHello calls the `AgentClient` monitor class that handles connection to trace server. So with such setup you'll be able to get your data from `OlinkServer` and see the traces in ApiGear studio.

```qml
...
import io_world 1.0

ApplicationWindow {
...
            Button {
            width: 80
            height: 80
            text: qmlIoWorldHello.last.content
            onClicked: {
                qmlIoWorldHello.say(someMessage, someWhen)
            }
        }
    IoWorldHello { id: qmlIoWorldHello }
...
}
```

### Setup

This feature requires using the classes wrapped with monitor decorators, which collect the traces, instead of using the implementation classes directly. Either in qml as shown above or in your code, where you create the interface instances.
```

#include "io_world/implementation/hello.h"
#include "io_world/monitor/hellotraced.h"

#include <QtCore>
#include <memory>

#include <iostream>

int main(){

    auto ioWorldHello = std::make_shared<io_world::Hello>();
    io_world::HelloTraced ioWorldHelloTraced(ioWorldHello);

    useIoWorldHEllo(ioWorldHelloTraced); // your code that requires io_world::Hello
}
```
Also make sure that you are using the same port for sending and receiving traces. 
For sending: check the [apigear monitor agent](monitor#qt-trace-client) `agentclient.cpp`, by default the address is set to `ws://localhost:8152/ws`.
For receiver: go to studio settings and set same port number.
