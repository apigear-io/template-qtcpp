---
sidebar_position: 5
---
import CodeBlock from '@theme/CodeBlock';
import helloWorldModuleComponent from '!!raw-loader!./data/helloworld.module.yaml';

# Qml Plugin

You may want to use a [Qml plugin](https://doc.qt.io/qtcreator/creator-qml-modules-with-plugins.html) for your module. This may be handy when you don't want to register structs (with `qRegisterMetaType`) or the interfaces (with `qmlRegisterType`) on compile time, in the main. Instead you can use the structs and the interfaces as an external module.

The plugin registers all the types and all you have to do is just use it in your CMakeList.
For the qt 5.15 you  you should add a line to your application CMakeLists.txt

```
set(QML_IMPORT_PATH  ${PLUGIN_BINARY_PATH} CACHE STRING "" FORCE)
set(QML2_IMPORT_PATH  ${PLUGIN_BINARY_PATH} CACHE STRING "" FORCE)
```
usually the `${PLUGIN_BINARY_PATH}` is somewhere in your `CMAKE_BINARY_DIR` and ends with `imports` folder

in our example code we set it to simplest combination of those two. We define a variable in main CMakeLists.txt in case of many modules, the plugins will end in same directory
``` title="main CMakeLists.txt"
set(IMPORTS_PATH "${CMAKE_BINARY_DIR}/imports" CACHE STRING "Path where the plugins are deployed")
```
and then in each plugin we just use it.
``` title="plugin CMakeLists.txt"
set(OUTPUT_PATH ${IMPORTS_PATH}/io/world)
```
where `/io/world` is the module name

If you run your application outside of *Qt Creator* you need to add the import paths (paths where the plugins are) to runtime. You can either set the QML_IMPORT_PATH and QML2_IMPORT_PATH environment variables - for ad-hoc import paths (for debugging or testing) or use the `QQmlEngine::addImportPath()` function for fixed import paths that should always be available. 
```
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    app.addLibraryPath(the-directory);
```
When building and running with *Qt Creator* in theory it should be enough to have import paths in the CMake, but you may also need to add `QML_IMPORT_PATH` and `QML2_IMPORT_PATH` for `run environment` in project settings, even if the settings are using the build environment variables that already contain those.

Read more on [import paths](https://doc.qt.io/qt-6/qtqml-syntax-imports.html#qml-import-path)