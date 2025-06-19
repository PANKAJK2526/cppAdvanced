#ifndef FILEEXPLORERWIDGET_H
#define FILEEXPLORERWIDGET_H

// QWidget is the base class for all UI objects in Qt
#include <QWidget>

// QFileSystemModel provides a data model for accessing the file system
#include <QFileSystemModel>

// QTreeView is used to visually represent hierarchical data (like folders/files)
#include <QTreeView>

// QLineEdit provides a single-line text input field (used for search input)
#include <QLineEdit>

// QPushButton represents a clickable button (used to trigger search)
#include <QPushButton>

// QListWidget is a UI element that shows a scrollable list of items
#include <QListWidget>

// FileExplorerWidget is a composite widget that includes:
// - A directory view
// - A search bar and button
// - A list to show search results
class FileExplorerWidget : public QWidget
{
Q_OBJECT // Enables the use of Qt's signal and slot mechanism

    public :
    // Constructor: accepts an optional parent for ownership/memory hierarchy
    explicit FileExplorerWidget(QWidget *parent = nullptr);

private slots:
    // Slot function triggered when the user clicks the search button
    void onSearchClicked();

    // Slot function that handles each file path found during the threaded search
    void handleSearchResult(const QString &path);

private:
    // QFileSystemModel is used to get the file/folder data for the QTreeView
    QFileSystemModel *model;

    // Tree view to display the file system structure visually
    QTreeView *treeView;

    // Input field where the user enters the filename or pattern to search
    QLineEdit *searchInput;

    // Button to trigger the search operation
    QPushButton *searchButton;

    // List widget to display paths of matching files
    QListWidget *searchResultsList;

    // Sets up the layout and connects signals/slots
    void setupLayout();

    // Initiates a threaded search for the given term
    void performSearch(const QString &searchTerm);
};

#endif // FILEEXPLORERWIDGET_H
