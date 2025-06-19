// basic_server.cpp
#include <QCoreApplication>
#include <QWebSocketServer>
#include <QWebSocket>
#include <QDebug>

class BasicServer : public QObject {
    Q_OBJECT
public:
    BasicServer(quint16 port, QObject *parent = nullptr)
        : QObject(parent),
          server(new QWebSocketServer("Basic Server", QWebSocketServer::NonSecureMode, this)) {
        if (server->listen(QHostAddress::Any, port)) {
            qDebug() << "Server listening on port" << port;
            connect(server, &QWebSocketServer::newConnection, this, &BasicServer::onNewConnection);
        }
    }

private slots:
    void onNewConnection() {
        QWebSocket *clientSocket = server->nextPendingConnection();
        qDebug() << "Client connected";

        connect(clientSocket, &QWebSocket::textMessageReceived, this, [clientSocket](const QString &message) {
            qDebug() << "Received:" << message;
            clientSocket->sendTextMessage("Echo: " + message);
        });

        connect(clientSocket, &QWebSocket::disconnected, clientSocket, &QObject::deleteLater);
    }

private:
    QWebSocketServer *server;
};

#include "basic server.moc"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    BasicServer server(12345);
    return app.exec();
}
