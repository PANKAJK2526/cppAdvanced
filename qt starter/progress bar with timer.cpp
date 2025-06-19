#include<QApplication>
#include<QWidget>
#include<QVBoxLayout>
#include<QPushButton>
#include<QProgressBar>
#include<QThread>
#include<QTimer>

int main(int argc, char *argv[])
{

	QApplication app(argc, argv);
	QWidget window;
	QVBoxLayout *layout = new QVBoxLayout;
	QPushButton *button = new QPushButton;
	layout->addWidget(button);

	QObject::connect(button, &QPushButton::clicked, [layout]() {

		auto x = std::make_shared<int>(0);
		QProgressBar *progress = new QProgressBar;
		progress->setRange(0,100);
		layout->addWidget(progress);
		QTimer *timer = new QTimer;
		QObject::connect(timer, &QTimer::timeout, [timer, x, progress](){
			progress->setValue((*x)++);
		});	
		timer->start(100);
	});

	window.setLayout(layout);
	window.setWindowTitle("Multithreading ProgressBar");
	window.show();

	return app.exec();
}