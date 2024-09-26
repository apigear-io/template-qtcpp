---
sidebar_position: 2
---

# Quick-Start

The Quick-Start guide explains how to, in few steps, get from an API to a functional *Qt* plugin.
Steps 1 and 3 are universal for other technologies. In the step 2 you will choose a concrete *Qt* template.
For more general information about first steps with ApiGear [First Steps](/docs/start/first_steps)

The quick start enables only basic features: the [api](features/api.md) generation and simple [stub](features/stubs.md) implementation.
For all available features check the [overview](features/features.md).

## 1. Install the code generator

Get the [ApiGear Studio](https://github.com/apigear-io/studio/releases) or [ApiGear CLI](https://github.com/apigear-io/cli/releases). For more information check the [ApiGear documentation](/docs/start/install).

## 2. Get the template

There are several options to get the template. Installation via the *Studio* or the *CLI*. Alternatively it is possible to clone or download from github.

### Installation via CLI

Use `template` command with `list` to check available templates or with `install` to install necessary one. You can always check whether the installation was successful via the `template cache` command.
```bash
$ apigear template list
list of templates from registry
name                      | installed | registry | url
apigear-io/template-qtcpp | false     | true     | https://github.com/apigear-io/template-qtcpp.git
...
# highlight-next-line
$ apigear template install apigear-io/template-qtcpp
$ apigear template cache
list templates in the local cache
name                             | url
apigear-io/template-qtcpp@v0.3.0 | https://github.com/apigear-io/template-qtcpp.git
...
```

### Installation via Studio

From within the studio the installation is really simple.

1. Open an existing project or create an new one
2. Go to the `Templates` tab
3. Click `Install` on the `apigear-io/template-qtcpp` entry

### Clone from github

In case you want to check or modify the source code of the template, it is easier to clone or download the repository. The repository does not need to be part of the project, but can be stored anywhere on the computer.
```bash
$ git clone https://github.com/apigear-io/template-qtcpp.git
```

## 3. Set up project

For a project we usually need two files. The solution which specifies what `APIs` and which template to use for it. And at least one `API` module file.
Both should ideally be in a folder called `apigear` next to each other.

Alternatively, you can also use the *Studio* to create a new project and modify the two example files.

### Solution file
Create a [solution](/docs/start/first_steps#create-a-solution) file.
The example below specifies
* module files in *line 8*, here the `helloworld.module.yaml` module with `Hello` API
* the output directory for generated files in *line 9*
* a template used to generate the code in *line 10*, here the `apigear-ui/template-qtcpp` template. This can also be a path to a local copy of the template.
* the enabled features of the template in *line 13*, here the `stubs` feature, a simple implementation of interfaces. For all available features check the [overview](features/features.md).

```yaml title="helloworld.solution.yaml" showLineNumbers
schema: "apigear.solution/1.0"
name: hello_world_example
version: "0.1.0"

targets:
  - name: qt_hello_world
    inputs:
      - helloworld.module.yaml
    output: ../qt_hello_world
    template: apigear-io/template-qtcpp
    force: true
    features:
      - stubs
```
:::tip Targets
You can extend this solution file with other targets, each for the different technology with  different template. The module.yaml is technology independent and may be used for any template.
:::

:::note
Set the force parameter to true if you want to always override all the generated files. With option set to false some files, like implementation (stub feature) won't be updated. All the API files are always updated.
:::

### API module file
Use your favorite text editor to create the `helloworld.module.yaml` with the example content:

```yaml title="helloworld.module.yaml" showLineNumbers
schema: apigear.module/1.0
name: io.world
version: "1.0.0"

interfaces:
  - name: Hello
    properties:
      - { name: last, type: Message }
    operations:
      - name: say
        params:
          - { name: msg, type: Message }
          - { name: when, type: When }
        return:
          type: int
    signals:
      - name: justSaid
        params:
          - { name: msg, type: Message }
enums:
  - name: When
    members:
      - { name: Now, value: 0 }
      - { name: Soon, value: 1 }
      - { name: Never, value: 2 }
structs:
  - name: Message
    fields:
      - { name: content, type: string }
```

## 4. Generate code

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

### Generate via CLI

The following snippet shows how the CLI can be run.

```bash
$ apigear generate solution apigear/helloworld.solution.yaml 
10:52:20 INF generated 21 files in 30ms. (20 write, 0 skip, 1 copy) topic=gen
```
* `generate` tells the CLI that it should generate code
* `solution` specifies that we want to run a solution file
  

### Generate via Studio

1. Open the project
2. Go to the `Solutions` tab
3. Click `Run` on the `helloworld.solution.yaml` entry

## 5. Use the generated Qt project.

The generated code provides Qt *C++* implementations. The following paragraphs show how you can use it.
You can start your project loading the top level CMakeLists.txt in `qt_hello_world` folder.

The 'api.h' contains all definitions of the enums and structs for your module, as well as the QObject abstract base classes for your Interfaces.
From now on you can simply include the header files for the api interface or the stub implementation and use it.
For more details on generated features please check [api](features/api.md), [stubs](features/stubs.md). 

:::tip
Check the "example" and [qmlplugin](features/qmlplugin.md) features to see how to use your API directly in qml with the generated wrappers.
:::

:::note
For the pure virtual interface see the pure C++ template 
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
