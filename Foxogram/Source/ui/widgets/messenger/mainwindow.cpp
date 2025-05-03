#include "mainwindow.h"

#include <QGridLayout>
#include <QLabel>
#include <QStyle>
#include <QSplitter>
#include <QPalette>
#include "ChatComponent.h"
#include <foxogram/Logger.h>

#include "SearchBar.h"
#include "../style.h"

MainWindow::MainWindow(QWidget *parent, foxogram::Me* user) : QWidget(parent), user(user)
{
    foxogram::Logger::setLogLevel(foxogram::LOG_DEBUG);

    QHBoxLayout* HBoxLayout = new QHBoxLayout(this);
    HBoxLayout->setSpacing(0);
    HBoxLayout->setContentsMargins(0, 0, 0, 0);
    QSplitter* splitter = new QSplitter(Qt::Horizontal);
    auto channels = user->fetchChannels();
    QWidget* leftBarWidget = new QWidget();
    leftBarWidget->setFixedWidth(500);
    QVBoxLayout* leftBarLayout = new QVBoxLayout(leftBarWidget);
    leftBarLayout->setSpacing(0);
    leftBarLayout->setContentsMargins(0, 0, 0, 0);
    leftBarLayout->setAlignment(Qt::AlignTop);
    leftBarWidget->setLayout(leftBarLayout);
    SearchBar* searchBar = new SearchBar(this);
    searchBar->setFixedHeight(72);

    QWidget *line1 = new QWidget;
    line1->setFixedHeight(1);
    line1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    line1->setStyleSheet("background-color: #3f3f3f;");
    QWidget *line2 = new QWidget;
    line2->setFixedHeight(1);
    line2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    line2->setStyleSheet("background-color: #3f3f3f;");

    QWidget* chatsWidget = new QWidget();
    chatsWidget->setObjectName("chatsWidget");
    QVBoxLayout* chatsLayout = new QVBoxLayout(chatsWidget);
    chatsLayout->setSpacing(0);
    chatsLayout->setContentsMargins(0, 0, 0, 0);
    chatsLayout->setAlignment(Qt::AlignTop);
    for (auto channel : channels) {
        auto chatComponent = new ChatComponent(nullptr, channel);
        chatsLayout->addWidget(chatComponent);
        chatsList.push_back(chatComponent);
    }

    QWidget* messengerWidget = new QWidget();
    messengerWidget->setObjectName("messengerWidget");
    messengerWidget->setStyleSheet(Messenger::Style::messengerWidgetStyleSheet);
    QVBoxLayout* messengerLayout = new QVBoxLayout(messengerWidget);
    messengerLayout->setSpacing(0);

    leftBarLayout->addWidget(searchBar);
    leftBarLayout->addWidget(line1);
    leftBarLayout->addWidget(chatsWidget);
    leftBarLayout->addWidget(line2);
    splitter->addWidget(leftBarWidget);
    splitter->addWidget(messengerWidget);
    HBoxLayout->addWidget(splitter);
    leftBarWidget->setStyleSheet(Messenger::Style::leftBarWidgetStyleSheet);

    resize(900, 600);
}

void MainWindow::searchFilter(const QString& s) {
    for (auto chat : chatsList) {
        if (chat->channel->getDisplayName().find(s.toStdString()) == std::string::npos) {
            chat->hide();
        } else {
            chat->show();
        }
    }
}
