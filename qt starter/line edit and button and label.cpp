#include<QApplication>
#include<QWidget>
#include<QVBoxLayout>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout;

    QLabel *label = new QLabel("Enter Something");
    QLineEdit *input = new QLineEdit("Empty");
    QPushButton *button = new QPushButton("Submit");

    layout->addWidget(label);
    layout->addWidget(input);
    layout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, [input, label]() {
        QString text = input->text();
        label->setText("You entered: " + text);
    });

    window.setLayout(layout);
    window.setWindowTitle("Trying Line Edit...");
    window.show();

    return app.exec();
}