#include<QApplication>
#include<QPushButton>
#include<QVBoxLayout>
#include<QWidget>
#include<QLabel>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout;

    QLabel *label = new QLabel("Before Click");
    layout->addWidget(label);

    QPushButton *button = new QPushButton("Click Me");
    layout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, [label]() {
        label->setText("After Click");
    });

    window.setLayout(layout);
    window.setWindowTitle("Button and Label");
    window.show();

    return app.exec();
}