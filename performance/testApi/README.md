# Qt C++ Blueprint

A Qt C++ blueprint with support for Qt Quick plugin.

## Features

* api:  creates api files with interfaces as QObjects with main cmake structure needed for compilation
        adds qml wrapper that exposes interfaces to qml. The Qml classes require api factory, that creates backend for the wrapper when instantiating the class in qml.
        For more details see qml example.
* stubs: adds a stub implementation (without business logic for methods) and sets up test project for your interfaces implementation.
* olink: Creates adapters for your interfaces to the ObjectLink protocol.
         The ObjectLink is an IPC protocol based on the idea to link a local object to a remote object a network connection. 
         Object link allows users to communicate state full objects over a network connection.
          
         See examples for more details.
         See https://docs.apigear.io/objectlink/
* monitor: adds a wrappers for your interfaces to monitor changes of your interfaces, also adds a wrapper for api factory.
           This way you obtain a monitor client, the monitoring server is embedded into the ApiGear Studio / CLI application.
           You can find the monitoring server settings in the settings page of the ApiGear Studio.
           
           See examples with monitor feature on for more details.

* http: http client adapter for ApiGear HTTP Protocol for each interface class
* qmlplugin: creates a QtQuick plugin that registers all necessary types and metatypes.
* examples:
    - object link server - see how to set up an object link server
    - object link client - see how to set up an object link client
    - qml app which contains both:
      the olink client as a backend for qml classes
      the a server in main app with the services for your interfaces
      You can use those services to trigger changes in qml part. Normally server should be separate app.
      With a monitor feature the examples are extended with a monitor wrapper.

* apigear - an internal feature that adds a support for olink protocol and monitor feature (automatically added for those features).

## Simulation

For simulation the object link core protocol is used.
Use the olink feature to prepare an olink client adapters and use it with your implementation of backend. (See olink client examples, set up proper server address).
Use a simulation server to make single changes of an api manually or load simulation scenarios to feed your application automatically with desired behavior.
See https://docs.apigear.io/docs/advanced/simulation/intro
