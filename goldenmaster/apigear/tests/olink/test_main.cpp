#define CATCH_CONFIG_RUNNER

#include <QCoreApplication>
#include <catch2/catch.hpp>
#include <catch2/trompeloeil.hpp>


int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv); // -platform offscreen
    int result = Catch::Session().run(argc, argv); // --break
    return result;
}
