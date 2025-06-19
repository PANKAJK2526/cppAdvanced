#include <QApplication>
#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QDebug>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QObject>

// Custom widget that handles key and mouse events
class MyWidget : public QWidget 
{
    Q_OBJECT

public:
    MyWidget(QWidget* parent = nullptr) : QWidget(parent) {}

protected:
    void keyPressEvent(QKeyEvent* event) override 
    {
        qDebug() << "Key Pressed:" << event->key();
    }

    void mousePressEvent(QMouseEvent* event) override
    {
        qDebug() << "Mouse Clicked at:" << event->pos();
    }
};

// Custom event filter
class Filter : public QObject 
{
    Q_OBJECT

protected:
    bool eventFilter(QObject *obj, QEvent* event) override
    {
        if (event->type() == QEvent::KeyPress)
        {
            qDebug() << "Key intercepted by event filter!";
            return true; // stop event propagation
        }
        return QObject::eventFilter(obj, event);
    }
};

#include "main.moc"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create custom widget
    MyWidget window;
    window.setWindowTitle("Event Filter Demo");
    window.resize(300, 150);

    // Create QLineEdit and layout
    QVBoxLayout* layout = new QVBoxLayout;
    QLineEdit* edit = new QLineEdit;
    layout->addWidget(edit);

    // Create and install event filter
    Filter* filter = new Filter; // set parent to auto-delete
    edit->installEventFilter(filter);

    window.show();
    return app.exec();
}
