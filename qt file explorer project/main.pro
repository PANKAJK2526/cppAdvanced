TEMPLATE = app
QT += core gui widgets

CONFIG += c++17

SOURCES += \
    main.cpp \
    MainWindow.cpp \
    FileExplorerWidget.cpp \
    ThreadedFileSearcher.cpp

HEADERS += \
    MainWindow.h \
    FileExplorerWidget.h \
    ThreadedFileSearcher.h
