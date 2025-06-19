// basic_client.cpp
#include <QCoreApplication>
#include <QWebSocket>
#include <QDebug>

class BasicClient : public QObject {
    Q_OBJECT
public:
    BasicClient(const QUrl &url, QObject *parent = nullptr) : QObject(parent) {
        connect(&socket, &QWebSocket::connected, this, &BasicClient::onConnected);
        connect(&socket, &QWebSocket::textMessageReceived, this, &BasicClient::onMessageReceived);
        connect(&socket, &QWebSocket::disconnected, []() {
            qDebug() << "Disconnected from server";
            QCoreApplication::quit();
        });

        socket.open(url);
    }

private slots:
    void onConnected() {
        qDebug() << "Connected to server";
        socket.sendTextMessage("Hello from client!");
    }

    void onMessageReceived(const QString &message) {
        qDebug() << "Server says:" << message;
        socket.close();
    }

private:
    QWebSocket socket;
};

#include "basic client.moc"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    BasicClient client(QUrl(QStringLiteral("ws://localhost:12345")));
    return app.exec();
}
