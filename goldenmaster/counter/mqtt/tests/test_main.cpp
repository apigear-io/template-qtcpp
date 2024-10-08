#define CATCH_CONFIG_RUNNER

#include <QCoreApplication>
#include <catch2/catch.hpp>


int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv); // -platform offscreen
    int result = Catch::Session().run(argc, argv); // --break
    return result;
}
