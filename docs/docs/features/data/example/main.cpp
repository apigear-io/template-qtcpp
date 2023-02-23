#include "io_world/api/apifactory.h"
#include "io_world/olink/olinkfactory.h"
#include "io_world/monitor/tracedapifactory.h"

#include <QtCore>
#include "olink/clientregistry.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "olink/olinkclient.h"

#include <memory>
#include <iostream>

#include <QtPlugin>


int main(int argc, char *argv[]){

    // Prepare Factory before app is created.
    ApiGear::ObjectLink::ClientRegistry client_registry;
    ApiGear::ObjectLink::OLinkClient client(client_registry);
    io_world::OLinkFactory io_worldOlinkFactory(client);
    io_world::ApiFactory::set(&io_worldOlinkFactory);

    // Create main app
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    engine.load(url);

    // Connect the client - all qml olink clients will be linked
    client.connectToHost(QUrl("ws://127.0.0.1:8182/ws"));

    auto result = app.exec();

    return result;
}
