#include<QCoreApplication>
#include<QObject>
#include<QThread>
#include<QDebug>

class Worker: public QObject 
{

	Q_OBJECT

	public slots:
		void doWork() 
		{
			qDebug()<<"Running in the thread: "<<QThread::currentThread();
		}

};

#include "main.moc"

int main(int argc, char * argv[])
{

	QCoreApplication app(argc, argv);

	Worker *worker = new Worker();
	QThread *thread = new QThread();

	worker->moveToThread(thread);

	QObject::connect(thread, &QThread::started, worker, &Worker::doWork, Qt::QueuedConnection);
	thread->start();

	return app.exec();

}