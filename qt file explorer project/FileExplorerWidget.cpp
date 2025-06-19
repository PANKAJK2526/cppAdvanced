// FileExplorerWidget.cpp - Implements the FileExplorerWidget class

#include "FileExplorerWidget.h"   // Include the header file for this widget
#include "ThreadedFileSearcher.h" // Include the threaded search logic

#include <QVBoxLayout> // For vertical stacking of UI elements
#include <QHeaderView> // To manage tree view header behavior

// Constructor: Initializes the widget and sets up the layout
FileExplorerWidget::FileExplorerWidget(QWidget *parent)
    : QWidget(parent) // Call base QWidget constructor
{
    setupLayout(); // Initialize and arrange UI components
}

// Helper function to construct the UI layout and connect events
void FileExplorerWidget::setupLayout()
{
    // QFileSystemModel provides access to the local filesystem
    model = new QFileSystemModel(this);
    model->setRootPath(QDir::homePath()); // Set the root to the user's home directory

    // QTreeView presents the file/folder structure visually
    treeView = new QTreeView(this);
    treeView->setModel(model);                              // Bind the model to the view
    treeView->setRootIndex(model->index(QDir::homePath())); // Show user's home directory
    treeView->header()->setStretchLastSection(true);        // Make last column stretch to fill space

    // QLineEdit allows the user to input the search text
    searchInput = new QLineEdit(this);

    // QPushButton triggers the search
    searchButton = new QPushButton("Search", this);

    // QListWidget shows the list of found search results
    searchResultsList = new QListWidget(this); // Widget to display matched paths

    // Connect the search button click event to the slot function
    connect(searchButton, &QPushButton::clicked,
            this, &FileExplorerWidget::onSearchClicked);

    // Layout the widgets vertically using QVBoxLayout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(searchInput);       // Input field
    layout->addWidget(searchButton);      // Search button
    layout->addWidget(searchResultsList); // List for search output
    layout->addWidget(treeView);          // File/folder browser

    setLayout(layout); // Apply layout to this widget
}

// Slot called when the search button is clicked
void FileExplorerWidget::onSearchClicked()
{
    QString searchTerm = searchInput->text().trimmed(); // Get and trim user input
    if (!searchTerm.isEmpty())
    {
        searchResultsList->clear(); // Clear previous search results
        performSearch(searchTerm);  // Start the search operation
    }
}

// Kicks off a threaded search for the given term
void FileExplorerWidget::performSearch(const QString &searchTerm)
{
    // ThreadedFileSearcher performs the search in a separate thread
    ThreadedFileSearcher *searcher = new ThreadedFileSearcher(QDir::homePath(), searchTerm, this);

    // Connect the searcher’s signal to a slot that updates the UI with each match
    connect(searcher, &ThreadedFileSearcher::fileFound,
            this, &FileExplorerWidget::handleSearchResult);

    // Clean up the thread object when done
    connect(searcher, &ThreadedFileSearcher::finished,
            searcher, &QObject::deleteLater);

    searcher->start(); // Begin the search thread
}

// Slot that handles each found file and updates the result list
void FileExplorerWidget::handleSearchResult(const QString &path)
{
    searchResultsList->addItem(path); // Add the file path to the visible list
}
