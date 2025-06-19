// MainWindow.h - Declaration of the MainWindow class

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow> // Provides a framework for main windows with menus, toolbars, etc.
#include <QSplitter>   // Used to create resizable panes in the UI
#include <QWidget>     // Base class for all Qt widgets

class FileExplorerWidget; // Forward declaration since we only need a pointer here

class MainWindow : public QMainWindow
{
Q_OBJECT // Enables Qt's meta-object features like signals and slots

    public : explicit MainWindow(QWidget *parent = nullptr); // Constructor with optional parent widget
    ~MainWindow();                                           // Virtual destructor for cleanup

private:
    FileExplorerWidget *fileExplorer; // Our main custom widget for file listing/search
};

#endif // MAINWINDOW_H
