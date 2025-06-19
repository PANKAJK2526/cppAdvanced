#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    qDebug() << "Hello from Qt Console App";
    return app.exec();
}
