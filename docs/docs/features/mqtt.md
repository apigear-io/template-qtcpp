---
sidebar_position: 3
---
import CodeBlock from '@theme/CodeBlock';
import helloWorldModuleComponent from '!!raw-loader!./data/helloworld.module.yaml';
import mqttMessagesFormat from '/files/mqtt/ApiGearMQTTv0.1.pdf';


# MQTT

:::caution
This is an experimental feature. It contains smallest working set of functionalities to adapt the generated interface for using over the network with MQTT protocol.
It doesn't include the security. The error handling is minimal. It is not production ready.
Please also check issues on github for this template.
:::

This feature purpose is not only to help you introduce MQTT protocol into your project, but also show that an existing protocol can be adapted for sharing your data in your ecosystem. When going through this document you may notice this implementation contains general client/server adapters in 📂hello-world/apigear/mqtt
and an interface specific part generated from templates for each interface in  📂hello-world/qt_hello_world/io_world/mqtt. <br /> <br /> 
 This feature provides a *client* and a *server* adapter for your interfaces for the MQTT protocol. It allows you to connect different applications in the same or different technologies (check all of our [templates](https://docs.apigear.io/docs/category/sdk-templates)).<br />
 Use an *Mqtt client* instead of your interface implementation to connect to be able to receive data from remote service.  Use an *Mqtt server adapter* to expose your interface implementation as a remote service.<br />

:::tip
The MQTT broker is not provided with implementation. To be able to run client and service you need to run a broker of your choice.
:::

:::caution
 In this library we use STL classes in public interfaces.
We assume that this library is built from source (configuration provided by generated CMakeLists).
Otherwise, it has to be ensured that your build configuration matches the library build configuration.
:::

### Before Start - prepare QMqtt Module

The mqtt library is not a part of standard Qt build. You need to install this module on your own, you can find it [here](https://github.com/qt/qtmqtt).
Once you get the repository we recommend to build it with relWithDebug options e.g. like that
```bash
cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo  -DCMAKE_CXX_FLAGS_DEBUG="-O2" .
cmake --build . --config RelWithDebInfo
cmake --install . --verbose 
```

## File overview for module
 
 With an example  API

<details><summary>Hello World API (click to expand)</summary>
<CodeBlock language="yaml" showLineNumbers>{helloWorldModuleComponent}</CodeBlock>
</details>

the following file structure will be generated. The purpose and content of each file is explained below.

```bash {4,19}
📂hello-world
 ┣ 📂apigear
 ┃ ┣ 📂monitor
 ┃ ┣ 📂mqtt
 ┃ ┃ ┣ 📜CMakeLists.txt
 ┃ ┃ ┣ 📜mqttclient.cpp
 ┃ ┃ ┣ 📜mqttclient.h
 ┃ ┃ ┣ 📜mqttservice.cpp
 ┃ ┃ ┣ 📜mqttservice.h
 ┃ ┃ ┣ ... (helper files)
 ┃ ...
 ┣ 📂qt_hello_world
 ┃ ┣ 📂apigear
 ┃ ┣ 📂examples
 ┃ ┣ 📂io_world
 ┃ ┃ ┣ 📂api
 ┃ ┃ ┣ 📂implementation
 ┃ ┃ ┣ 📂monitor
 ┃ ┃ ┣ 📂mqtt
 ┃ ┃ ┃ ┣ 📜CMakeLists.txt
 ┃ ┃ ┃ ┣ 📜mqtt_common.h
 ┃ ┃ ┃ ┣ 📜mqttfactory.cpp
 ┃ ┃ ┃ ┣ 📜mqttfactory.h
 ┃ ┃ ┃ ┣ 📜mqtthello.cpp
 ┃ ┃ ┃ ┣ 📜mqtthello.h
 ┃ ┃ ┃ ┣ 📜mqtthelloadapter.cpp
 ┃ ┃ ┃ ┗ 📜mqtthelloadapter.h
 ...
```

### Qt apigear - The Network Layer

When generating the mqtt feature (or any of those: olink monitor feature) you'll get an additional folder it the top most directory: the 📂hello-world/📂apigear. The 📂mqtt subfolder contains objects that implement a network layer (based on Qt Mqtt library) for the MQTT protocol. Those are:
- Client - Adapts the Qt MQTT client, to serve as an network endpoint for [interface client adapters](mqtt#MQTT-Client-Adapter). 
Exposes methods that allow receiving data for remote service: subscribing for properties changes, signals emission and method response invocation;
 methods that allow remote using the service: requesting property change or invoking a method. The client may serve many client interface adapters, even for the same interfaces (allows subscribing for same topic).
 In case many interface clients adapters for some interface are connected: property changes and signals are provided to all interface client adapters, but the invoke method response will be delivered only for the one that requested it.
- ServiceAdapter - Adapts the Qt MQTT client to serve as an network endpoint for [interface service adapters](mqtt#MQTT-Server-Adapter). Exposes methods that allow receiving requests from remote clients: subscribing for properties change requests, send method invocation;
 methods that allow publishing property change, signal, functionality to handles sending a response for method invocation requests. This ServiceAdapter may be used for many interface service adapters, but it is not recommended to use more than one interface service adapter for same interface.

:::tip
Have in mind that MQTT might not be suitable for high-frequency messages especially with one mqtt client serving more than one object.
Also the brokers have limits for messages number/size queued from one client. In case you are not getting all the messages consider changing those or splitting traffic between more clients (maybe some handle the properties, some handle the methods).
:::

### MQTT Client Adapter

Files `📜mqtthello.h` and `📜mqtthello.cpp` implement the remote client for the `Hello` interface  - a `MqttHello` class.<br /> 
The object is an `AbstractHello` implementation.<br />
It requires an instance of Apigear::Mqtt::Client to work.  It uses the Client to subscribe (and unsubscribe) for topics that allow receiving properties, signals and invoke responses from service.

#### Properties
The property getters (here `Message last()` ) return immediately the locally stored last received value from server. <br /> 
The property setter (here `void setLast(const Message& last)` ) requests setting a value on server side, local value is not changed. <br /> 
You can connect to a property changed signals (here `void lastChanged(const Message& last)` )
When the client receives information that server changed the property, a target property (here `last`) is updated locally and a signal that property has changed is emitted ( here `void lastChanged(const Message& last)`.

:::note
The connected interface client adapter has its local properties in sync with a service. The properties messages are retained in mqtt broker, so all already set properties are provided.
:::
#### Operations
The operations have additionally the async version, which is called by the immediate version.<br />
The async version sends an invoke operation request to a server.<br />
So calling `myMqttHelloInstance.say(myWhen)` implements execution of `sayAsync` and waits for the result (for non-void type of operations). Have in mind that this is a blocking operation.

#### Signals
You should not emit any signals from a client.
You can connect to any signals offered by your interface (here `void justSaid(const Message& msg)` )
When a MqttHello client receives the message from server that indicates the signal was emitted it emits a signal (here `justSaid`).

#### Use `MqttHello`

As mentioned earlier you an adapter of QtMqtt (with protcol and network layer implementation), here provided by a `ApiGear::Mqtt::Client`. All you need to do is to pass this Client to your Interface Client Adapter, and request connecting to host when it is convenient for you.

```cpp 
    // Create a client and make a connection
    ApiGear::Mqtt::Client client("UniqueClientName");
    client.connectToHost("localhost", 1883); // Use the same port number as your broker is using. Typically, without any other settings it is "1883".

    // Create your service client.
    auto ioWorldHello = std::make_shared<io_world::MqttHello>(client);

    // use your ioWorldHello as it was Hello implementation
    ioWorldHello.say(someWhen);
    auto lastMessage = ioWorldHello->last();
    ioWorldHello->setLast(someMessage);
    ioWorldHello->connect(ioWorldHello.get(), &io_world::AbstractHello::justSaid, *otherObject, &SomeJustSaidUser::handleJustSaid);
```
### MQTT Server Adapter

Files `📜mqtthelloadapter.h` and `📜mqtthelloadapter.h` contain the mqtt server side adapter for the `Hello` interface - the `MqttHelloAdapter` class.<br />
When creating the `MqttHelloAdapter` you need to provide the Apigear::Mqtt::ServiceAdapter and the local `AbstractHello` service object, you want to expose to clients.<br />
`MqttHelloAdapter` object exposes the local object for remote usage with the MQTT protocol. It handles all the network requests, and calls your local object.
The client connections and communication with them is handled transparently for you, no additional actions are needed.

#### Properties
Each time a property changed signal (here `void lastChanged(const Message& last)` ) is emitted, a message is sent to all connected clients with information, which property changed to which value. This may occur either when you change a property directly on your local `Hello` object, or when a change property request message is received by the `MqttHelloAdapter`, which applies the property on your local `Hello` object.

#### Operations
The operations invocation which came from the clients through the network will be performed on your local `Hello` object. The result of the operation (if any) will be returned only to a client, from which the message was send, not all clients.

#### Signals
All the signals emitted by your local `Hello` objects are forwarded to all connected clients.

#### Use `MqttHelloAdapter`

As mentioned earlier you an adapter of QtMqtt (with protcol and network layer implementation), here provided by a `ApiGear::Mqtt::ServiceAdapter` 
All you need to do is to pass this ServiceAdapter to your Interface Service Adapter, and request connecting to host when it is convenient for you.

```cpp 

    // Prepare the Mqtt Service Adapter and an object which you want to expose.
    ApiGear::Mqtt::ServiceAdapter service("ServiceUniqueNameInMqtt");
    service.connectToHost("localhost", 1883);  // Use the same port number as your broker is using. Typically, without any other settings it is "1883".
    auto ioWorldHello = std::make_shared<io_world::Hello>();

    // Create your MqttHelloAdapter and add it to registry.
    auto ioWorldMqttHelloService = std::make_shared<io_world::MqttHelloAdapter>(service, ioWorldHello);

    // use your ioWorldHello as it was Hello implementation, all property changes, and signals will be passed to connected MqttHello clients.
    ioWorldHello.say(someWhen);
    auto lastMessage = ioWorldHello->last();
    ioWorldHello->setLast(someMessage); // after this call - if new property is different than current one - all clients will be informed about new value.
    ioWorldHello->connect(ioWorldHello.get(), &io_world::AbstractHello::justSaid, *otherObject, &SomeJustSaidUser::handleJustSaid);

```

### MQTT Factory - for QML usage
Files `📜mqttfactory.h`  and `📜mqttfactory.cpp` contain the `MqttFactory` which creates the `MqttClient` version of your interfaces (returned as a`AbstractHello` interfaces). <br />
The factory is necessary when you want to use the MqttClient implementation version for the [QML wrapper](api#qml-wrappers). You need to set the `MqttFactory` as an API factory. See more details [on providing backend to QML wrapper](api#providing-backend-to-qml-wrapper)

```cpp 
    // Prepare Factory before app is created.
    ApiGear::Mqtt::Client client("UniqueClientForQmlExample");
    io_world::MqttFactory io_worldMqttFactory(client);
    io_world::ApiFactory::set(&io_worldMqttFactory);
    ...

    client.connectToHost("localhost", 1883);
```
The factory uses the `ApiGear::ObjectLink::OLinkClient` and links the objects when they are created, you don't have to perform any other actions.

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

### MQTT Messages
In case you want construct messages for client or server side on your own, please check how topics are created and how does the payload look like, check this documentS [messages format](/files/mqtt/ApiGearMQTTv0.1.pdf).
