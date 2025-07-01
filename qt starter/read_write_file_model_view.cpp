#include<QApplication>
#include<QFile>
#include<QTextStream>
#include<QTableView>
#include<QStandardItemModel>
#include<QWidget>
#include<QPushButton>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QLineEdit>

int main(int argc, char *argv[])
{

	QApplication app(argc, argv);

	QWidget window;

	QVBoxLayout *layout = new QVBoxLayout;

	QLineEdit *form = new QLineEdit;

	layout->addWidget(form);

	QPushButton *save = new QPushButton("Save to File");

	layout->addWidget(save);

	QObject::connect(save, &QPushButton::clicked, [&](){

		QFile *file = new QFile("data.csv");
		file->open(QIODevice::Append | QIODevice::Text);

		QTextStream out(file);

		out<<"\n"<<form->text().trimmed();

		file->close();

	});

	QPushButton *load = new QPushButton("Load the Table Data");

	layout->addWidget(load);

	QStandardItemModel *model = new QStandardItemModel;

	QTableView *view = new QTableView;

	view->setModel(model);

	QObject::connect(load, &QPushButton::clicked, [&](){

		QFile *file = new QFile("data.csv");
		file->open(QIODevice::ReadOnly);

		QTextStream in(file);
		bool isHeader = true;

		model->clear();

		while(!in.atEnd())
		{
			QString line = in.readLine();
			QStringList fields = line.split(",");

			QList<QStandardItem *> items;

			for(QString text: fields) {
				items << new QStandardItem(text);
			}

			if(isHeader)
			{
				model->setHorizontalHeaderLabels(fields);
				isHeader = false;
			}
			else
			{
				model->appendRow(items);
			}
		}

		layout->addWidget(view);

		file->close();

	});

	window.setLayout(layout);
	window.setWindowTitle("Demonstrate QT MVC");
	window.show();

	return app.exec();
}