#include<QCoreApplication>
#include<QTcpSocket>
#include<QDebug>

int main(int argc, char *argv[])
{

	QCoreApplication app(argc, argv);

	QTcpSocket socket;
	socket.connectToHost("127.0.0.1", 8080);
	if(!socket.waitForConnected(3000)) {
		qDebug() << "Connection Failed!";
		return 1;
	}
	qDebug()<<"Connected to server...";
	QString msg = "Hello, World!";
	qDebug()<<"Client request sent: "+msg;
	socket.write(msg.toUtf8());
	socket.waitForBytesWritten();

	if(socket.waitForReadyRead(3000)) {
		qDebug()<<"Server response:"<<socket.readAll();
	}

	socket.disconnectFromHost();

	return app.exec();
}