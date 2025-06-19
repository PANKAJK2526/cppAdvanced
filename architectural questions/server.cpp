#include <QCoreApplication>
#include <QWebSocketServer>
#include <QWebSocket>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QTimer>

QList<QWebSocket *> clients;
QString currentContent;
QWebSocketServer server("FileSyncServer", QWebSocketServer::NonSecureMode);

void broadcast(const QString &content)
{
    QJsonObject msg;
    msg["type"] = "content_update";
    msg["content"] = content;
    QJsonDocument doc(msg);
    for (QWebSocket *client : clients)
        client->sendTextMessage(doc.toJson());
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile file("data.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        currentContent = file.readAll();
        file.close();
    }
    else
    {
        qWarning() << "Creating new data.txt";
        QFile f("data.txt");
        f.open(QIODevice::WriteOnly | QIODevice::Text);
        f.close();
        currentContent = "";
    }

    // using polling as QFileSystemWatcher is not working sometimes

    QTimer *pollTimer = new QTimer();
    pollTimer->setInterval(1000); // 1000 ms = 1 second
    QObject::connect(pollTimer, &QTimer::timeout, [&]()
                     {
        QFile f("data.txt");
        if (f.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QString content = f.readAll();
            f.close();
            if (content != currentContent) {
                currentContent = content;
                broadcast(content);
            }
        } });
    pollTimer->start();

    if (!server.listen(QHostAddress::Any, 12345))
    {
        qCritical() << "Failed to start server on port 12345.";
        return 1;
    }

    QObject::connect(&server, &QWebSocketServer::newConnection, [&]()
                     {
        QWebSocket* socket = server.nextPendingConnection();
        clients.append(socket);

        QJsonObject msg;
        msg["type"] = "content_update";
        msg["content"] = currentContent;
        socket->sendTextMessage(QJsonDocument(msg).toJson());

        QObject::connect(socket, &QWebSocket::textMessageReceived, [=](QString msgStr) {
            QJsonDocument doc = QJsonDocument::fromJson(msgStr.toUtf8());
            QJsonObject obj = doc.object();
            if (obj["type"] == "update_request") {
                QString newContent = obj["content"].toString();
                QFile f("data.txt");
                if (f.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    f.write(newContent.toUtf8());
                    f.close();
                    currentContent = newContent;
                    broadcast(newContent);
                }
            }
        });

        QObject::connect(socket, &QWebSocket::disconnected, [=]() {
            clients.removeAll(socket);
            socket->deleteLater();
        }); });

    qDebug() << "Server started on port 12345.";
    return a.exec();
}
