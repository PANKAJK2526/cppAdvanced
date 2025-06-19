#include <QApplication>
#include <QPushButton>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget mainWindow;
    QVBoxLayout *layout = new QVBoxLayout;
    QPushButton *openDialogBtn = new QPushButton("Open Dialog");

    layout->addWidget(openDialogBtn);
    mainWindow.setLayout(layout);
    mainWindow.setWindowTitle("Dialog Example");

    QObject::connect(openDialogBtn, &QPushButton::clicked, []() {
        QDialog dialog;
        QVBoxLayout *dialogLayout = new QVBoxLayout;
        QLabel *label = new QLabel("This is a modal dialog");
        QPushButton *closeBtn = new QPushButton("Close");

        dialogLayout->addWidget(label);
        dialogLayout->addWidget(closeBtn);
        dialog.setLayout(dialogLayout);
        QObject::connect(closeBtn, &QPushButton::clicked, &dialog, &QDialog::accept);

        dialog.exec();  // Modal
    });

    mainWindow.show();
    return app.exec();
}
