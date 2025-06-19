#include<QApplication>
#include<QWidget>
#include<QVBoxLayout>
#include<QLabel>
#include<QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout;

    static int count = 0;


    QLabel *label = new QLabel(QString::number(count));
    QPushButton *button = new QPushButton("Next");

    layout->addWidget(label);
    layout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, [label]() {
        count++;
        label->setText(QString::number(count));
    });

    window.setLayout(layout);
    window.setWindowTitle("Counter");
    window.show();

    return app.exec();
}