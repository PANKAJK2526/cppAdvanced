#include<QApplication>
#include<QWidget>
#include<QVBoxLayout>
#include<QPushButton>
#include<QTextEdit>
#include<QFile>
#include<QTextStream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;

    QVBoxLayout *layout = new QVBoxLayout;

    QPushButton *saveButton = new QPushButton("Save");
    QPushButton *loadButton = new QPushButton("Load");
    QTextEdit *input = new QTextEdit("Edit...");

    layout->addWidget(input);
    layout->addWidget(saveButton);
    layout->addWidget(loadButton);

    QObject::connect(saveButton, &QPushButton::clicked, [input]() {
        QFile file("temp.txt");
        if(file.open(QIODevice::WriteOnly | QIODevice::Text)) 
        {
            QTextStream out(&file);
            out<<input->toPlainText();
            file.close();
        }

    });

    QObject::connect(loadButton, &QPushButton::clicked, [input]() {
        QFile file("temp.txt");
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)) 
        {
            QTextStream in(&file);
            input->setPlainText(in.readAll());
            file.close();
        }

    });

    window.setLayout(layout);
    window.setWindowTitle("File editor");
    window.show();

    return app.exec();
}