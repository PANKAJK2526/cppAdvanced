#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QTableView>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QStandardItemModel>
#include <QMessageBox>

// Global pointers
QStandardItemModel *model = nullptr;
QLineEdit *lineEdit = nullptr;
QTableView *tableView = nullptr;

void readCsv(QWidget *parent) {
    QString fileName = QFileDialog::getOpenFileName(parent, "Open CSV File", "", "*.csv");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(parent, "Error", "Cannot open file");
        return;
    }

    model->clear();
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QList<QStandardItem *> items;
        for (const QString &text : line.split(',')) {
            items.append(new QStandardItem(text));
        }
        model->appendRow(items);
    }
    file.close();
}

void writeCsv(QWidget *parent) {
    QString data = lineEdit->text().trimmed();
    if (data.isEmpty()) return;

    QString fileName = QFileDialog::getSaveFileName(parent, "Save CSV File", "", "*.csv");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::warning(parent, "Error", "Cannot open file for writing");
        return;
    }

    QTextStream out(&file);
    out << data << "\n";
    file.close();
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow *window = new QMainWindow;
    QWidget *centralWidget = new QWidget(window);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QPushButton *readButton = new QPushButton("Read CSV");
    QPushButton *writeButton = new QPushButton("Write CSV");
    lineEdit = new QLineEdit;
    tableView = new QTableView;
    model = new QStandardItemModel;

    tableView->setModel(model);

    layout->addWidget(readButton);
    layout->addWidget(writeButton);
    layout->addWidget(lineEdit);
    layout->addWidget(tableView);

    QObject::connect(readButton, &QPushButton::clicked, [=]() { readCsv(window); });
    QObject::connect(writeButton, &QPushButton::clicked, [=]() { writeCsv(window); });

    window->setCentralWidget(centralWidget);
    window->resize(600, 400);
    window->show();

    return app.exec();
}
