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

:::note
To use the your API in `QML` directly see the [plugin](qmlplugin.md) feature which adds QML wrappers and factory implementation for interfaces, factories for structures and creates a module plugin for the api types.
:::


### File overview for module

With an example API

<details>
    <summary>Hello World API (click to expand)</summary>
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
 ┃ ┃ ┃  ┣ 📜iapifactory.h
 ┃ ┃ ┃  ┣ 📜json.adapter.h
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


The struct metatype is declared with `Q_DECLARE_METATYPE`. That may not be enough if you want to bind to fields of the struct in qml. In that case we suggest using a [plugin](qmlplugin.md) which provides factory for it. 

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

### Other
`📜 CMakeLists.txt` for building this module, describing it's dependencies, and exposing built package for other features that will use it.
`📜 json.adapter.h` prepares adapters for structs to easy read from or write to `nlohmann::json`
```
Message message = json.get<Message>();
nlohmann::json message = message;
```
`📜iapifactory.h` provides an interface for ApiFactory which can produce your interface instances, here the `AbstractHello` instance. It's purpose is to provide the chosen implementation to a QML wrappers.
The factory main implementation is provided by the [qmlplugin](qmlplugin.md), which explains its purpose and usage in details.
You can also find implementation of factory interface in [stubs](stubs), [monitor](monitor.md) and [olink](olink.md) features. They all allow creating different `AbstractHello` backend for QML wrapper.
