#include<QApplication>
#include<QWidget>
#include<QHBoxLayout>
#include<QLabel>
#include<QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    QHBoxLayout *layout = new QHBoxLayout;

    QLabel *lable = new QLabel("Hi");
    QPushButton *button = new QPushButton("Bye");

    layout->addWidget(lable);
    layout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, [lable]() {
        lable->setText("Bye");
    });

    window.setLayout(layout);
    window.setWindowTitle("Button and Lable");
    window.show();

    return app.exec();
}