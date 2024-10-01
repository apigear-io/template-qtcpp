---
sidebar_position: 2
---
import QuickStartCommon from "@site/docs/_quickstart_common.md"

# Quick-Start

The Quick-Start guide explains how to, in few steps, get from an API to a functional *Qt* plugin.
Steps 1 and 3 are universal for other technologies. In the step 2 you will choose a concrete *Qt* template.
For more general information about first steps with ApiGear [First Steps](/docs/guide/intro)

The quick start enables only basic features: the [api](features/api.md) generation and simple [stub](features/stubs.md) implementation.
For all available features check the [overview](features/features.md).

<QuickStartCommon />

## 5. Use the generated Qt project

### Project folder structure

With the output directory set as in example, both *ApiGear* files reside in an `apigear` subfolder next to the *Qt* generated files.
In this case the folder structure should look similar to this
```bash
📂hello-world
 ┣ 📂apigear
 ┃ ┣ 📜helloworld.solution.yaml
 ┃ ┗ 📜helloworld.module.yaml
 ┣ 📂qt_hello_world
 # highlight-next-line
 ┃ ┣ 📂io_world
 ┃ ┃ ┣ 📂api
 ┃ ┃ ┗ 📂implementation
 ┃ ┗ 📜CMakeLists.txt
```

Using the solution file from the previous paragraph the code will be generated in the `qt_hello_world` folder. 
With subfolder for each module, here `io_world` as the name of module (defined in line 2 of `helloworld.module.yaml`).
It contains both features generated: a basic api and a stub implementation.

The generated code provides Qt *C++* implementations. The following paragraphs show how you can use it.
You can start your project loading the top level CMakeLists.txt in `qt_hello_world` folder.

The 'api.h' contains all definitions of the enums and structs for your module, as well as the QObject abstract base classes for your Interfaces.
From now on you can simply include the header files for the api interface or the stub implementation and use it.
For more details on generated features please check [api](features/api.md), [stubs](features/stubs.md). 

:::tip
Check the "example" and [qmlplugin](features/qmlplugin.md) features to see how to use your API directly in qml with the generated wrappers.
:::

:::note
For the pure virtual interface see the [pure C++ template](/template-cpp14/docs/features/api#interfaces)
:::

:::note
For the simulation check [the olink feature](features/olink.md) which provides middle layer on your code side and the [simulation](/docs/advanced/simulation/intro) explained.
:::

### Create and run an example

Prepare an `examples` folder in the `hello-world/qt_hello_world` directory with a main.cpp like this:
```cpp
#include <QGuiApplication>
#include "io_world/implementation/hello.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    io_world::Hello myHelloInstance;


    // Try out properties: subscribe for changes
    myHelloInstance.connect(&myHelloInstance, &io_world::AbstractHello::lastChanged,
                            []( const io_world::Message& last){ qDebug() << "last property changed ";});
    // and ask for change.
    io_world::Message messageForProperty;
    messageForProperty.m_content = QString("New message");
    myHelloInstance.setLast(messageForProperty);

    // Check the signals with subscribing for its change
    myHelloInstance.connect(&myHelloInstance, &io_world::AbstractHello::justSaid,
                            [](const io_world::Message& msg){ qDebug() << "justSaid signal emitted ";});
    // and emit one.
    io_world::Message messageForSignal;
    messageForSignal.m_content = QString("Message from signal");
    emit myHelloInstance.justSaid(messageForSignal);

    // Play around executing operations, maybe they emit signals? or change the properties?
    auto method_result = myHelloInstance.say(io_world::Message(), io_world::When::Now);

    return app.exec();
}
```

add a CMakeLists.txt

```bash
project(MyExample)
cmake_minimum_required(VERSION 3.20)

find_package(Qt6 REQUIRED COMPONENTS Gui)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MyExample main.cpp)

find_package(io_world QUIET COMPONENTS io_world_impl)
target_link_libraries(MyExample io_world_impl Qt6::Gui)
```
Add the `example` subdirectory to the hello-world/qt_hello_world/CMakeLists.txt. Now you can build the application and the libraries with it and run your example.
