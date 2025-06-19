// ThreadedFileSearcher.h - Declares a QThread to perform recursive file search

#ifndef THREADEDFILESEARCHER_H
#define THREADEDFILESEARCHER_H

#include <QThread>   // Base class for thread support in Qt
#include <QString>   // Used for file paths and search terms

class ThreadedFileSearcher : public QThread {
    Q_OBJECT  // Enables custom signals

public:
    ThreadedFileSearcher(const QString &directory, const QString &searchTerm, QObject *parent = nullptr);

signals:
    void fileFound(const QString &filePath); // Signal emitted when matching file is found

protected:
    void run() override; // Thread entry point

private:
    QString baseDir; // Directory to start search from
    QString keyword; // Search term
};

#endif // THREADEDFILESEARCHER_H
