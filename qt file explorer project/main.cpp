/*

/qt-file-explorer
|--- main.cpp
|--- MainWindow.h / .cpp             // Hosts the layout
|--- FileExplorerWidget.h / .cpp     // Tree view for file browsing
|--- ThreadedFileSearcher.h / .cpp   // Background thread for search


*/

// main.cpp - Entry point of the Qt application

#include <QApplication> // QApplication handles application-wide settings and event loop
#include "MainWindow.h" // Our custom MainWindow that sets up the UI

int main(int argc, char *argv[])
{
    QApplication app(argc, argv); // Required to initialize Qt and handle events
    MainWindow window;            // Create the top-level window
    window.show();                // Display the window on screen
    return app.exec();            // Start the Qt event loop (blocks until window is closed)
}
