#include "SearchBar.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCursor>
#include "mainwindow.h"
#include "../style.h"

SearchBar::SearchBar(MainWindow* parent) {
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->setSpacing(16);
    mainLayout->setContentsMargins(16, 10, 16, 10);

    QLineEdit* searchField = new QLineEdit();
#ifdef __APPLE__
    searchField->setPlaceholderText("Search (⌘+K)");
#else
    searchField->setPlaceholderText("Search (Ctrl+K)");
#endif
    searchField->setTextMargins(30, 0, 0, 0);
    searchField->setObjectName("searchField");
    auto searchFieldFont = searchField->font();
    searchFieldFont.setPointSize(13);
    searchField->setFont(searchFieldFont);
    searchField->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    searchField->setFrame(false);

    QPushButton* createButton = new QPushButton();
    createButton->setObjectName("createButton");
    createButton->setFixedSize(53, 53);
    auto cursor = createButton->cursor();
    cursor.setShape(Qt::CursorShape::PointingHandCursor);
    createButton->setCursor(cursor);

    mainLayout->addWidget(searchField);
    mainLayout->addWidget(createButton);
    setStyleSheet(Messenger::Style::searchBarStyleSheet);
    connect(searchField, &QLineEdit::textChanged, parent, &MainWindow::searchFilter);
}
