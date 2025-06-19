#include<QCoreApplication>
#include<QTcpServer>
#include<QTcpSocket>
#include<QDebug>

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	
	QTcpServer *server = new QTcpServer;

	QObject::connect(server, &QTcpServer::newConnection, [server]() {

		QTcpSocket *socket = server->nextPendingConnection();

		QObject::connect(socket, &QTcpSocket::readyRead, [socket]() {
			QString request = socket->readAll();
			qDebug()<<"Request from client: "<<request;
			socket->write(("echo back: "+request).toUtf8());
		});

	});


	server->listen(QHostAddress::Any, 8080);
	qDebug()<<"Server Listening on port 8080...";

	return app.exec();
}