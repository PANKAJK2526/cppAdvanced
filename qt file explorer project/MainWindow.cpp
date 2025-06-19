// MainWindow.cpp - Implementation of MainWindow

#include "MainWindow.h"
#include "FileExplorerWidget.h" // Include our custom widget definition

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) // Pass parent to base QMainWindow constructor
{
    fileExplorer = new FileExplorerWidget(this); // Instantiate file explorer widget
    setCentralWidget(fileExplorer);              // Set it as the central widget
    setWindowTitle("Simple File Explorer");      // Set window title
}

MainWindow::~MainWindow() {} // Destructor: child widgets are automatically deleted by Qt
