#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QObject>

class MyWindow : public QWidget {
    
    Q_OBJECT

private:
    QLabel *label;

public:
    MyWindow() {
        QVBoxLayout *layout = new QVBoxLayout;

        label = new QLabel("Ready");
        QPushButton *button = new QPushButton("Go");

        layout->addWidget(label);
        layout->addWidget(button);
        this->setLayout(layout);

        connect(button, &QPushButton::clicked, this, &MyWindow::handleClick);
    }

//public slots:
    void handleClick() {
        label->setText("Running!");
    }

};

#include "custom slot and signal using class.moc"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyWindow window;
    window.setWindowTitle("Custom Slot Example");
    window.show();
    return app.exec();
}
