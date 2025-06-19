// ThreadedFileSearcher.cpp - Implements recursive file search in a separate thread

#include "ThreadedFileSearcher.h"
#include <QDirIterator> // Allows recursive traversal of directories

ThreadedFileSearcher::ThreadedFileSearcher(const QString &directory, const QString &searchTerm, QObject *parent)
    : QThread(parent), baseDir(directory), keyword(searchTerm) {}

void ThreadedFileSearcher::run() {
    // Iterate through all files under baseDir recursively
    QDirIterator it(baseDir, QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        QString filePath = it.next(); // Get next file path
        if (filePath.contains(keyword, Qt::CaseInsensitive)) {
            emit fileFound(filePath); // Notify listeners of match
        }
    }
}
