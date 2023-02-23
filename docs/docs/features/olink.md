---
sidebar_position: 3
---
import CodeBlock from '@theme/CodeBlock';
import helloWorldModuleComponent from '!!raw-loader!./data/helloworld.module.yaml';
import objectSink from '!!raw-loader!./data/iobjectsink.h';
import objectSource from '!!raw-loader!./data/iobjectsource.h';
import simulationExampleCMake from '!!raw-loader!./data/example/CMakeLists.txt';
import simulationExampleMain from '!!raw-loader!./data/example/main.cpp';
import simulationExampleQml from '!!raw-loader!./data/example/main.qml';
import simulationExampleQrc from '!!raw-loader!./data/example/resources.qrc';
import simulationExampleTestScenario from '!!raw-loader!./data/example/helloworldtest.scenario.yaml';
import Figure from '../figure'

# Olink

 This feature provides a *client* and a *server* adapter for your interfaces for the [ObjectLink](https://docs.apigear.io/objectlink/) protocol. It allows you to connect different applications in the same or different technologies (check all of our [templates](https://docs.apigear.io/docs/category/sdk-templates)).<br />
 Use an *OLink client* instead of your interface implementation to connect to a remote service, or to a the [ApiGear simulation](olink#simulation).  Use an *OLink server adapter* to expose your interface implementation as a remote service.<br />
 Below you'll find short introduction on `ApiGear ObjectLink` protocol. Before details on client and server, you'll also find piece of information on a network layer implementation for handling ObjectLink in `Qt`. 

:::note
 The `OLink client` and the `OLink server` objects are ready-to-use as they are, they don't' need any extra implementation.
 If you want quickly start working with them go to use sections of [client](olink#use-olinkhello), [server](olink#use-olinkhelloadapter) or [qml version](olink#olink-factory---for-qml-usage)
:::

### Apigear ObjectLink protocol and ObjectLink core library 
The [ObjectLink](https://docs.apigear.io/objectlink/) protocol is a lightweight protocol for the Objects described with an interface. It allows connecting a client object with a server object, and perform remote operations like: remote property change request (client) or notifications on property changed (server), inform about signal emission (server) and allows requesting a call of a method (client) and giving a response to the outcome (server).

The Olink feature for your interface uses a library [ObjectLink core](https://github.com/apigear-io/objectlink-core-cpp), common for cpp based templates. The provided CMakeLists already contain all the dependencies, so you don't have to add it manually.

The library provides an abstraction layer for handling the protocol, independent of the actual network stack. It encodes and decodes the messages and routes them to corresponding objects stored in its registry. The setup is minimal: instantiate the registries (for client and/or server) and pass them to network layer objects in [qt apigear library](olink#qt-apigear---the-network-layer) 

:::caution
 In this library we use STL classes in public interfaces.
We assume that this library is built from source (configuration provided by generated CMakeLists).
Otherwise, it has to be ensured that your build configuration matches the library build configuration.
:::
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
 ┃ ┣ 📂olink
 ┃ ┃ ┣ 📜CMakeLists.txt
 ┃ ┃ ┣ 📜olinkclient.cpp
 ┃ ┃ ┣ 📜olinkclient.h
 ┃ ┃ ┣ 📜olinkhost.cpp
 ┃ ┃ ┣ 📜olinkhost.h
 ┃ ┃ ┣ 📜olinkremote.cpp
 ┃ ┃ ┗ 📜olinkremote.h
 ┃ ...
 ┣ 📂qt_hello_world
 ┃ ┣ 📂apigear
 ┃ ┣ 📂examples
 ┃ ┣ 📂io_world
 ┃ ┃ ┣ 📂api
 ┃ ┃ ┣ 📂implementation
 ┃ ┃ ┣ 📂olink
 ┃ ┃ ┃ ┣ 📜CMakeLists.txt
 ┃ ┃ ┃ ┣ 📜olinkfactory.cpp
 ┃ ┃ ┃ ┣ 📜olinkfactory.h
 ┃ ┃ ┃ ┣ 📜olinkhello.cpp
 ┃ ┃ ┃ ┣ 📜olinkhello.h
 ┃ ┃ ┃ ┣ 📜olinkhelloadapter.cpp
 ┃ ┃ ┃ ┗ 📜olinkhelloadapter.h
 ...
```

### Qt apigear - The Network Layer

When generating the olink feature (or monitor feature) you'll get an additional folder it the top most directory: the 📂hello-world/📂apigear. The 📂olink subfolder contains objects that implement a network layer (based on QtWebSocket library) for the ObjectLink protocol. Those are:
- OlinkClient - the client, that serves your [interface client adapters](olink#Olink-Client-Adapter). 
                The class is responsible for network connection for ObjectLink client side. It uses the ObjectLink core library for handling messages according to the ObjectLink protocol. Handles linking and unlinking with a remote service for the sink added by the user (the interface OlinkClient Adapters), with regard to the connection state. All the messages dedicated to your object will be delivered to the adapter and proper actions will be performed for the clients that use it, without any of your actions. Also the OlinkClient holds a message queue for messages during disconnected time.
- OlinkHost and a helper class OlinkRemote- the server, which hosts your services exposed to network through the [interface server adapters](olink#Olink-Server-Adapter). The class is responsible to set up the server and manage connections requested by clients. It uses ObjectLink core library for handling messages according to the ObjectLink protocol. All incoming messages will be translated to calls and routed to your local object.


### Olink Client Adapter

Files `📜olinkhello.h` and `📜olinkhello.cpp` contain the olink client version of the `Hello` interface - an `OLinkHello` class.<br /> 
It implements two interfaces: `AbstractHello` and a `IObjectSink`. <br />
The IObjectSink interface comes from [ObjectLink core](https://github.com/apigear-io/objectlink-core-cpp):

<details><summary>IObjectSink (click to expand)</summary>
<CodeBlock language="cpp" >{objectSink}</CodeBlock>
</details>

and is necessary for handling incoming messages from the server side and is used by a `OlinkClient` ([Qt Apigear Olink lib](olink#Qt-apigear---The-Network-Layer)). Apart from setting up and tear down of the `OLinkHello` object, you don't need to perform any additional actions, the object `OLinkHello` will communicate with the server transparently and you should use it as an `AbstractHello` Object only.

#### Properties
The property getters (here `Message last()` ) return immediately the locally stored last received value from server. <br /> 
The property setter (here `void setLast(const Message& last)` ) requests setting a value on server side, local value is not changed. <br /> 
You can connect to a property changed signals (here `void lastChanged(const Message& last)` )
When the client receives information that server changed the property, a target property (here `last`) is updated locally and a signal that property has changed is emitted ( here `void lastChanged(const Message& last)`.

:::note
The connected client has its local properties initialized - on a successful linking client with server the client receives the init message, which contains current state of properties of the service on server side.
:::
#### Operations
The operations have additionally the async version, which is called by the immediate version.<br />
The async version sends an invoke operation request to a server.<br />
So calling `myOlinkHelloInstance.say(myWhen)` implements execution of `sayAsync` and waits for the result (for non-void type of operations). Have in mind that this is a blocking operation.

#### Signals
You should not emit any signals from a client.
You can connect to any signals offered by your interface (here `void justSaid(const Message& msg)` )
When a OlinkHello client receives the olinkOnSignal, a signal (here `justSaid`) is emitted.

#### Use `OLinkHello`

As mentioned earlier you need a network layer, here provided by a `ApiGear::ObjectLink::OLinkClient` which also contains the protocol handling `ClientNode`. All you need to do is give it a global `ApiGear::ObjectLink::ClientRegistry`, request connecting to host when it is convenient for you and then add your `OlinkHello`.

```cpp 
    // Create a global registry.
    ApiGear::ObjectLink::ClientRegistry registry;
    // Create a client and make a connection
    ApiGear::ObjectLink::OLinkClient client(registry);
    client.connectToHost(QUrl("ws://127.0.0.1:8182"));

    // Create your service client and request it linking, which will try to connect with a server side for this object.
    auto ioWorldHello = std::make_shared<io_world::OLinkHello>();
    client.linkObjectSource(ioWorldHello);

    // use your ioWorldHello as it was Hello implementation
    ioWorldHello.say(someWhen);
    auto lastMessage = ioWorldHello->last();
    ioWorldHello->setLast(someMessage);
    ioWorldHello->connect(ioWorldHello.get(), &io_world::AbstractHello::justSaid, *otherObject, &SomeJustSaidUser::handleJustSaid);

    // remember to unlink your object if you won't use it anymore.
    client.unlinkObjectSource(ioWorldHello->olinkObjectName());
```

:::caution
ApiGear::ObjectLink::ClientRegistry can have only one object of a certain type. This means that, to have more than one 'OlinkHello' objects you need to put them in different registries. Each Object has an identifier which is created based on the Interface Name, this way client object can be matched with proper server object.
:::

### Olink Server Adapter

Files `📜olinkhelloadapter.h` and `📜olinkhelloadapter.h` contain the olink server adapter for the `Hello` interface - the `OLinkHelloAdapter` class.<br />
It implements an `IObjectSource` interface (from [ObjectLink core](https://github.com/apigear-io/objectlink-core-cpp)), which wraps your `Hello` and exposes it for remote usage with the [ObjectLink](https://docs.apigear.io/objectlink/) protocol. It handles all the network requests, and calls your local object.<br />
When creating the `OLinkHelloAdapter` you need to provide the local `AbstractHello` service object, you want to expose to clients.

The IObjectSource interface:
<details><summary>IObjectSource (click to expand)</summary>
<CodeBlock language="cpp" >{objectSource}</CodeBlock>
</details>

After setting up the OlinkHost (Qt Apigear Olink lib) and registering your Interface registered, the client connections and communication with them is handled transparently for you, no additional actions are needed.

:::note
All the received messages from the clients are handled in a thread in which the connection resides, this means that your object may be used from different threads (local and each connection).
::: 

#### Properties
Each time a property changed signal (here `void lastChanged(const Message& last)` ) is emitted, a message is sent to all connected clients with information, which property changed to which value. This may occur either when you change a property directly on your local `Hello` object, or when a change property request message is received by the `OLinkHelloAdapter`, which applies the property on your local `Hello` object.

#### Operations
The operations invocation which came from the clients through the network will be performed on your local `Hello` object. The result of the operation (if any) will be returned only to a caller, not all clients. Have in mind that your object may be called from more that one thread.

#### Signals
All the signals emitted by your local `Hello` objects are forwarded to all connected clients.

#### Use `OLinkHelloAdapter`

As mentioned earlier you need a network layer, here provided by a `ApiGear::ObjectLink::OLinkHost` (The `ApiGear::ObjectLink::OLinkRemote` objects are created automatically per connection) which also contains the protocol handling `RemoteNodes`. All you need to do is give  a global `ApiGear::ObjectLink::RemoteRegistry` with your `OLinkHelloAdapter` in it to `ApiGear::ObjectLink::OLinkHost`.

```cpp 

    // Prepare the registry, the server, and an object which you want to expose.
    ApiGear::ObjectLink::RemoteRegistry registry;
    ApiGear::ObjectLink::OLinkHost server(registry);
    server.listen("localhost", 8182);
    auto ioWorldHello = std::make_shared<io_world::Hello>();

    // Create your OLinkHelloAdapter and add it to registry.
    auto ioWorldOlinkHelloService = std::make_shared<io_world::OLinkHelloAdapter>(registry, &ioWorldHello);
    registry.addSource(ioWorldOlinkHelloService);

    // use your ioWorldHello as it was Hello implementation
    ioWorldHello.say(someWhen);
    auto lastMessage = ioWorldHello->last();
    ioWorldHello->setLast(someMessage); // after this call - if new property is different than current one - all clients will be informed about new value.
    ioWorldHello->connect(ioWorldHello.get(), &io_world::AbstractHello::justSaid, *otherObject, &SomeJustSaidUser::handleJustSaid);

    // Remember to remove your ioWorldOlinkHelloService after you finish using it.
    registry.removeSource(ioWorldOlinkHelloService->olinkObjectName());
```

### Olink Factory - for QML usage
Files `📜olinkfactory.h`  and `📜olinkfactory.cpp` contain the `OLinkFactory` which creates the `OlinkClient` version of your interfaces (returned as a`AbstractHello` interfaces). <br />
The factory is necessary when you want to use the OlinkClient implementation version for the [QML wrapper](api#qml-wrappers). You need to set the `OlinkFactory` as an API factory. See more details [on providing backend to QML wrapper](api#providing-backend-to-qml-wrapper)

```cpp 
    // Prepare Factory before app is created.
    ApiGear::ObjectLink::ClientRegistry client_registry;
    ApiGear::ObjectLink::OLinkClient client(client_registry);
    io_world::OLinkFactory io_worldOlinkFactory(client);
    io_world::ApiFactory::set(&io_worldOlinkFactory);
    ...
    // Connect the client - all qml olink clients will be linked if the server services are already up.
    client.connectToHost(QUrl("ws://127.0.0.1:8182"));
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

 ## Simulation
 
 The simulation can be used to test, demonstrate or develop applications without the need to have the actual service available.
 The simulation server is integrated into the [ApiGear studio](https://docs.apigear.io/docs/category/desktop-studio) and the [CLI](https://docs.apigear.io/docs/cli/simulate).
 
 For simulating you will use [simulation scenarios](https://docs.apigear.io/docs/advanced/simulation/scenario) They allow to define sequences of actions. The actions can change the property values of the service or emit signals. The scenarios can be written using a YAML schema.

See more on [simulation](https://docs.apigear.io/docs/advanced/simulation/intro).

### Prepare your application
Make sure you are using OlinkClient as your `Hello` object, either:
- instance on [cpp side](olink#olink-client-adapter)
- or [qml version](olink#olink-factory---for-qml-usage) and connect to the same url and port that you configure in the ApiGear studio.

You may try our example - copy the code into new folder in generated `examples` folder
This is an example with qml version of using OlinkClient. 
##### main.cpp
The main.cpp sets up the qml factory
 <details><summary>main.cpp (click to expand)</summary>
<CodeBlock language="yaml" showLineNumbers>{simulationExampleMain}</CodeBlock>
</details>

:::note
Make sure to configure the client to use the correct IP and port configuration of your simulation server e.g. set `client.connectToHost(QUrl("ws://127.0.0.1:8182/ws"));`
:::

##### main.qml
As a starting point, describes 3 buttons, which are connected to:
1. Usage of method - on click, it executes the method (request to server) and shows the outcome as a button text.
2. Binding to a property - text of button 2
3. Binding to a signal outcome - text of button 3

with a following code

<details><summary>main.qml(click to expand)</summary>
<CodeBlock language="yaml" showLineNumbers>{simulationExampleQml}</CodeBlock>
</details>
you should get an app like this

<Figure caption="Testing application used with the simulation." src="/img/qtSimuApp.png" />

##### CMakeLists.txt and resource.qrc
<details><summary>CMakeLists.txt(click to expand)</summary>
<CodeBlock language="yaml" >{simulationExampleCMake}</CodeBlock>
</details>
<details><summary>resources.qrc(click to expand)</summary>
<CodeBlock language="yaml" >{simulationExampleQrc}</CodeBlock>
</details>


### Prepare the scenario
As a starting point you can check our simulation scenario: 
<details><summary>Scenario(click to expand)</summary>
<CodeBlock language="yaml" showLineNumbers>{simulationExampleTestScenario}</CodeBlock>
</details>

Apart from the header with the scenario name and its version it consists of two parts:
- initialization - for each interface (here, our ui.world.Hello line 6), we're setting initial values of properties(line 8) and the return value of function calls (line 12)
- sequence of events. You can prepare more than one sequence. For each of them set interval between calling each action (line 16), set how many runs of that sequence you want to execute (line 18) and name the interface the action should be applied to (line 17). In each action you may change many properties, and emit signals.

### Run the simulation

Put your scenario file in the `📂hello-world/apigear`  along with other `.yaml` files.
If you are using the studio, reload your project. Go to `settings` and make sure to set same the port as in your client app (here `8182`). 
Click the `play` button in the application in the `simulation` tab to start the simulation scenario, then start the client application.

Instead of the Apigear Studio application can also use its console version, run your scenario with command:
```bash 
apigear simulate run path-from-cli-to-scenario/helloworldtest.scenario.yaml --addr :8182
```

