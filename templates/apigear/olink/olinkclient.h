#pragma once

#include <QtCore>
#include <QtWebSockets>

#include "olink_common.h"

#include <memory>

namespace ApiGear {
namespace ObjectLink {

class ClientRegistry;
class ClientNode;
class IObjectSink;

class OLinkClientImpl;

/**
/**
* A class responsible for network connection for ObjectLink client side. Creates a socket
* connects it with Client Node - an abstract connection endpoint used by object sink.
* Handles linking and unlinking with remote service for the sink with regard to the connection state.
* Runs a connection in a separate thread
*/
class OLINKQT_EXPORT OLinkClient : public QObject {
    Q_OBJECT
public:

    /**
    * ctor
    * @param registry. A global client registry to which the client node and sink object are added.
    * Remark: the registered objects must provide unique identifiers
    */
    OLinkClient(ClientRegistry& registry, QObject *parent= nullptr);

    /** dtor */
    virtual ~OLinkClient() override;

public:
    void connectToHost(QUrl url=QUrl());
    void disconnect();

    ClientRegistry &registry();
    ClientNode* node();
    /**
    *  Use this function to setup linkage with the service object on the server side.
    * After successful linking the IObjectSink will receive confirmation from service with olinkOnInit handler call.
    * @param object An olink sink object which will be associated with network endpoint and for which linking with service object will be requested.
    */
    void linkObjectSource(std::weak_ptr<IObjectSink> objectSink);
    /**
     * Use this function to request unlinking with service object on the server side.
    * @param object An objectId no longer interested of using the service.
    */
    void unlinkObjectSource(std::string objectId);
    /**
     * Use this function to get state of connection reported by a socket.
    * @return The state of the socket.
    */
    QAbstractSocket::SocketState getConnectionState();

signals:
    // Internal signal to pass link request to a socket in its thread.
    void requestLinkObjectSource(std::weak_ptr<IObjectSink> objectSink);
    // Internal signal to pass an unlink request to a socket in its thread.
    void requestUnlinkObjectSource(std::string objectId);
    // Internal signal to pass connection request to a socket in its thread.
    void requestConnectToHost(QUrl url=QUrl());
    // Internal signal to pass a disconnect request to a socket in its thread.
    void requestDisconnect();
    // Internal signal to request the object to perform all the actions that require a working evnet loop that need to be done before desctruction.
    void requestTearDown();

private slots:
    // Internal slot to update the connection state.
    void onConnectionStatusChanged(QAbstractSocket::SocketState status){}
private:
    // Internal implementation with soceket in separate thread
    OLinkClientImpl* client = nullptr;
    // A thread in which socked lives
    QThread* clientthread = nullptr;
    // A registry used by a client node to map all olink objects
    ClientRegistry& m_registry;
    // Socket status
    QAbstractSocket::SocketState m_socektStatus = QAbstractSocket::SocketState::UnconnectedState;
};

}} // namespace ApiGear::ObjectLink
