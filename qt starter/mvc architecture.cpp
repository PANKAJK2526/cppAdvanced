#include<QApplication>
#include<QTableView>
#include<QStandardItemModel>
#include<QStandardItem>

int main(int argc, char *argv[])
{

	QApplication app(argc, argv);

	QTableView *view = new QTableView();

	QStandardItemModel *model = new QStandardItemModel(2,2);
	model->setHorizontalHeaderLabels({"Item", "Price"});

	model->setItem(0,0, new QStandardItem("Apple"));
	model->setItem(0,1, new QStandardItem("100"));

	model->setItem(1,0, new QStandardItem("Grapes"));
	model->setItem(1,1, new QStandardItem("200"));


	view->setModel(model);
	view->setWindowTitle("Fruit Prices");
	view->show();

	return app.exec();
}