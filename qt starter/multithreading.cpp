#include <QApplication>
#include <QThread>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QProgressBar>
#include <QMetaObject>

class Worker : public QObject {
    Q_OBJECT
public slots:
    void process() {
        for (int i = 0; i <= 100; i += 10) {
            QThread::sleep(1);  // Simulate work
            emit progress(i);
        }
        emit finished();
    }

signals:
    void progress(int value);
    void finished();
};

#include "multithreading.moc"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Multi-threaded Workers");
    QVBoxLayout *layout = new QVBoxLayout;

    QPushButton *startBtn = new QPushButton("Start Work");
    layout->addWidget(startBtn);

    QObject::connect(startBtn, &QPushButton::clicked, [&]() {
        // Create new progress bar and add to layout
        QProgressBar *progressBar = new QProgressBar;
        progressBar->setRange(0, 100);
        layout->addWidget(progressBar);

        // Create new worker and thread
        Worker *worker = new Worker;
        QThread *thread = new QThread;

        worker->moveToThread(thread);

        // Start thread and trigger worker's process() asynchronously
        QObject::connect(thread, &QThread::started, worker, &Worker::process);

        // Update progress bar when progress is emitted
        QObject::connect(worker, &Worker::progress, progressBar, &QProgressBar::setValue);

        // Clean up thread and worker when finished
        QObject::connect(worker, &Worker::finished, thread, &QThread::quit);
        QObject::connect(worker, &Worker::finished, worker, &QObject::deleteLater);
        QObject::connect(thread, &QThread::finished, thread, &QObject::deleteLater);

        thread->start();
    });

    window.setLayout(layout);
    window.show();
    return app.exec();
}
