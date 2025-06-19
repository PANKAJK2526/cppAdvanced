#include<QObject>
#include<QDebug>
#include<QCoreApplication>

class MyClass: public QObject {

	Q_OBJECT

public:
	void trigger()
	{
		emit mySignal(4);
	}

public slots:
	void print(int i)
	{
		qDebug()<<"Signal Recieved, run..."<<i;
	}


signals:
	void mySignal(int);

};

#include "main.moc"

int main(int argc, char *argv[])
{

	QCoreApplication app(argc, argv);

	MyClass obj;

	QObject::connect(&obj, &MyClass::mySignal, &obj, &MyClass::print);

	obj.trigger();

	return 0;

}

