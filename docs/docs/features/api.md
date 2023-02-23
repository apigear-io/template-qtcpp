---
sidebar_position: 1
---
import CodeBlock from '@theme/CodeBlock';
import helloWorldModuleComponent from '!!raw-loader!./data/helloworld.module.yaml';

# API

The feature `api` is the bare minimum for the code generation. What you receive is:
- abstract `QObject` base class for each *interface*
- *enums*
- *structs* with a basic implementation
- qml wrappers and utilities to use your interfaces in qml.


### File overview for module

With an example API

<details><summary>Hello World API (click to expand)</summary>
<CodeBlock language="yaml" showLineNumbers>{helloWorldModuleComponent}</CodeBlock>
</details>

the following file structure will be generated. The purpose and content of each file is explained below.

```bash {7}
📂hello-world
 ┣ 📂apigear
 ┣ 📂qt_hello_world
 ┃ ┣ 📂apigear
 ┃ ┣ 📂examples
 ┃ ┣ 📂io_world
 ┃ ┃ ┣ 📂api
 ┃ ┃ ┃  ┣ 📜api.cpp
 ┃ ┃ ┃  ┣ 📜api.h
 ┃ ┃ ┃  ┣ 📜apifactory.cpp
 ┃ ┃ ┃  ┣ 📜apifactory.h
 ┃ ┃ ┃  ┣ 📜iapifactory.h
 ┃ ┃ ┃  ┣ 📜json.adapter.h
 ┃ ┃ ┃  ┣ 📜qmlhello.cpp
 ┃ ┃ ┃  ┣ 📜qmlhello.h
 ┃ ┃ ┃  ┗ 📜CMakeLists.txt
 ...
```

### Api
Files `📜api.h` and `📜api.cpp` contain the api: interfaces, data structures and enums.

#### Enums
Each enum is exposed to qml and their metatype is declared with `Q_DECLARE_METATYPE`.
For convenience of use each enum has:
- `toEnum` function converts given `quint8` to enum value.
- `QDataSteram` in and out operators for the enum.

#### Structs

Each struct has its fields exposed for qml
```cpp  title="api.h"
...
struct IO_WORLD_API_EXPORT Message
{
    Q_GADGET
    Q_PROPERTY(QString content MEMBER m_content )
...
```
:::note
We generate the import/export statements (here IO_WORLD_API_EXPORT) for all the classes and structs that have an implementation in a *cpp* file and may be used outside of the library.
:::

For convenience of use each structure has:
- equality comparison operators
- the `QDataSteram` in and out operators for the generated struct `Message`.
- the factory of structures with `Q_INVOKABLE` `create()` method, here for `MessageFactory`, to make an instance of the `Message` in qml.

The struct metatype is declared with `Q_DECLARE_METATYPE`. That may not be enough if you want to bind to fields of the struct in qml. In that case you need to register your `struct` either using a [plugin](qmlplugin.md) or in your `main.cpp` - see example below. The example shows also registering the `MessageFactory` class - necessary if you need to instantiate `Message` in qml. Factory registration can be achieved in more than one way - we're showing' registering it as singleton and importing the singleton in qml file - no instances needed. But also you can try registering it with `qmlRegisterType` and create an instance (either in qml, or in c++ and set it as context variable).

```cpp showLineNumbers  title="main.cpp"
registerTypes()
{
    auto versionMajor = 1;
    auto versionMinor = 0;
    // register struct
    qRegisterMetaType<io_world::Message>();

    // register struct factory
    auto createIoWorldMessageFactorySingleton = [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
         Q_UNUSED(engine)
         Q_UNUSED(scriptEngine)
         return new io_world::MessageFactory();
    };
    const std::string uriIoWorldMessageFactory = io_world_module_name + ".MessageFactorySingleton";
    qmlRegisterSingletonType<io_world::MessageFactory>(uriIoWorldMessageFactory.c_str(), versionMajor, versionMinor, "IoWorldMessageFactory", createIoWorldMessageFactorySingleton);

    // you also may want to register your enums:
    qmlRegisterUncreatableType<io_world::When>(io_world_module_name, versionMajor, versionMinor, "IoWorldWhen", "An enum can not be created");

    // and interfaces:
    qmlRegisterType<io_world::QmlHello>(io_world_module_name, versionMajor, versionMinor, "IoWorldHello");
}
```
:::note
The qml plugin uses the version information form helloworld.module.yaml to register types. When registering "by hand" you should also use the same version.
:::

#### Interfaces

Base interface version for Qt template is a QObject Abstract base class, here `AbstractHello`. <br />
It contains:
- a pure virtual `getters` and a `setters` for each property
``` cpp
   virtual void setLast(const Message& last) = 0;
   virtual Message last() const = 0;
```
- pure virtual functions for each operation
```cpp
virtual int say(const Message& msg, When::WhenEnum when) = 0;
```
- signals: for each api signal and for each api property - on property changed signal
```cpp
signals:
    void justSaid(const Message& msg);
    void lastChanged(const Message& last);
```
### Qml Wrappers

Files `📜qmlhello.h` and `📜qmlhello.cpp` contain a qml wrapper for the `Hello` interface.<br />
The qml wrapper requires providing an implemented `AbstractHello` instance. For that factory files are necessary: `📜iapifactory.h` `📜apifactory.h` and `📜apifactory.cpp`. The functionality is explained [below](api#providing-backend-to-qml-wrapper).

The Qml wrapper (simplified version)
```cpp showLineNumbers  title="qmlhello.h"
class IO_WORLD_API_EXPORT QmlHello : public AbstractHello
{
    Q_OBJECT
    ...
    Q_PROPERTY(Message last READ last WRITE setLast NOTIFY lastChanged)
    ...
    Q_INVOKABLE int say(const Message& msg, When::WhenEnum when) override;
    ...
Q_SIGNALS:
    void lastChanged(const Message& last);
}
```
The qml wrapper makes the interface usable from qml:<br />
Line 5 shows exposed properties, with emitting signal on property changed from qml (`NOTIFY lastChanged`) - hence overriding signal for property changed (line 10). <br />
Line 7 shows the function exposed as a callable from qml.  <br />
The wrapper forwards the calls to backend and all the signals from backend to qml wrapper.

:::caution
The signals defined in the api shall be emitted by the backend and handled in qml, not the other way around. When the signal is emitted in qml, it won't reach the backend implementation.
:::

To use QmlHello you just need to create an instance of it in your Qml code with a proper (registered) name:

```bash
import QtQuick 2.15
import QtQuick.Layouts 1.2
import io_world 1.0

ApplicationWindow {
    id: appWindow
    visible: true
    width: 300
    height: 300

    IoWorldHello { id: qmlIoWorldHello }
```

Here QmlHello is registered as `IoWorldHello` (The module name combined with the Interface name). You can do it either by using a [plugin](qmlplugin.md) or in your `main.cpp` with e.g. 
```
qmlRegisterType<io_world::QmlHello>(io_world, 1, 0, "IoWorldHello");
``` 
which puts `IoWorldHello` to `io_world 1.0` module.
:::note
The qml plugin uses the version information form helloworld.module.yaml to register types. When registering "by hand" you should also use the same version.
:::


### Providing backend to Qml Wrapper.

The `QmlHello` is instantiated in qml without any handle to get or set the backend. Therefore, the global `ApiFactory` class of `IApiFactory` type is added to provide a flexible and extensible way to create it. The `QmlHello` class creates the `Hello` backend object by itself using the global `ApiFactory`. By providing your `IApiFactory` implementation, you will be able to use a `Hello` backend of your choice. 

Here is an example code snippet that shows how to prepare your `IApiFactory`
```cpp title="io_world/customfactory.h"
#pragma once

#include "io_world/api/iapifactory.h"
// #include "your CustomHello header file"
#include <QtCore>

class CustomFactory : public QObject, public IApiFactory
{
public:
    CustomFactory(..., QObject *parent = nullptr); //provide any extra resources your factory needs.

    std::shared_ptr<AbstractHello> createHello(QObject *parent = nullptr) override
    {
        return make_shared<CustomHello>(...); // provide any resource your CustomHello needs.
    }
};

```
and set in code

```cpp title="main.cpp"
#include "io_world/api/apifactory.h"
#include "io_world/customfactory.h"

#include <QtCore>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]){

    io_world::CustomFactory io_worldFactory();
    // Setting the CustomFactory as a global factory. From now, each qml object will create backend with it.
    io_world::ApiFactory::set(&io_worldFactory); 

    // Starting your application after setting the factory.
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    engine.load(url);
    ...
```
this way, on every `QmlHello` instantiation, your `CustomFactory::createHello` is called, and the returned object is used by `QmlHello`.
:::note
You can check the `qml example` or factories provided by other features. For instance [olink](features/olink.md).
::: 

:::caution
Your IApiFactory implementation needs to be set to `ApiFactory` once, before the QML file is loaded.
:::

### Other
`📜 CMakeLists.txt` for building this module, describing it's dependencies, and exposing built package for other features that will use it.
`📜 json.adapter.h` prepares adapters for structs to easy read from or write to `nlohmann::json`
```
Message message = json.get<Message>();
nlohmann::json message = message;
```
