Performance tests are separate CMake project, they are not build with main CMake.
Tests are designed to find bottle necks in template cpp14.
They can be started under performance profiler (e.g. Visual Studio Performance Profiler) to find bottle necks
but they also provide some time measurements which may be some indication for you.
Tests are not using any test framework - to exclude 3rd party calls
Tests use generated implementation of apigear/performance_interface.module for test sinks and source.

Tests scenarios are split into 2 folders:
tests_single_object - those tests use only single object
tests_many_objects - those tests use all generated objects

Test server part is passive - it only responds to client requests
- it registers one or all objects (depending if version for single or many objects was run)
- on receive (first) link message it starts time measurement
- it responses any message it receives - using logic implemented in the testApi/modules/api_module/api/implementation
- time measurement ends when last unlink message is received, server starts closing procedure and the program ends.

The test scenario is determined with client part. Each test_client is a separate scenario.

To run test:
1. Start server side - either from console or using performance profiler
2. Start one of client side tests - either from console or using performance profiler 


Real object with network layer are used for tests.
In case the sinks and sources need to be regenerated please do following:
1. Make sure the API file is in shape you want `performance\apigear\performance_interface.module.yaml`
2. USe The `performance\apigear\GenerateIdl.py' to generate `performance\apigear\performance_interface100.module.yaml` which contains this api generated 100 times with a number added to the name.
3. Make sure the solution file `performance\apigear\performance.solution.yaml` generates the olink and stubs feature and it uses template-cpp14 and regenerate the api

