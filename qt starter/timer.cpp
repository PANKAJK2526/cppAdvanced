#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>

class TimerWindow : public QWidget {
    Q_OBJECT

public:
    TimerWindow(QWidget *parent = nullptr) : QWidget(parent), secondsPassed(0) {
        label = new QLabel("Seconds passed: 0", this);
        label->setAlignment(Qt::AlignCenter);

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(label);
        setLayout(layout);
        setWindowTitle("Timer Example");
        resize(300, 100);

        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &TimerWindow::updateLabel);
        timer->start(1000); // every 1 second
    }

private slots:
    void updateLabel() {
        ++secondsPassed;
        label->setText(QString("Seconds passed: %1").arg(secondsPassed));
    }

private:
    QLabel *label;
    QTimer *timer;
    int secondsPassed;
};

#include "main.moc"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    TimerWindow window;
    window.show();
    return app.exec();
}
