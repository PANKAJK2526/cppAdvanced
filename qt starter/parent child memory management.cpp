#include<QObject>
#include<QDebug>

class MyObject : public QObject {
public:

	MyObject(QObject* parent = nullptr) : QObject(parent) {
		qDebug()<<"Contructed: "<<this;
	}

	~MyObject() {
		qDebug()<<"Destroyed:"<<this;
	}
};

int main()
{
	QObject parent;

	MyObject* child1 = new MyObject(&parent);
	MyObject* child2 = new MyObject(&parent);

	return 0;
}