#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWebSocket>
#include <QJsonDocument>
#include <QJsonObject>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget win;
    QVBoxLayout layout(&win);
    QLabel label;
    QLineEdit edit;
    QPushButton button("Upload");
    layout.addWidget(&label);
    layout.addWidget(&edit);
    layout.addWidget(&button);
    QWebSocket socket;

    QObject::connect(&socket, &QWebSocket::connected, [&]()
                     { qDebug("Connected to server"); });
    QObject::connect(&socket, &QWebSocket::textMessageReceived, [&](QString msg)
                     {
        QJsonDocument doc = QJsonDocument::fromJson(msg.toUtf8());
        if (doc["type"] == "content_update") {
            QString content = doc["content"].toString();
            label.setText(content);
        } });
    QObject::connect(&button, &QPushButton::clicked, [&]()
                     {
        QJsonObject msg;
        msg["type"] = "update_request";
        msg["content"] = edit.text();
        socket.sendTextMessage(QJsonDocument(msg).toJson()); });
    socket.open(QUrl("ws://127.0.0.1:12345"));
    win.show();
    return app.exec();
}