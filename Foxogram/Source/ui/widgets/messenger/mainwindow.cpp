#include "mainwindow.h"

#include <QGridLayout>
#include <QLabel>
#include <QStyle>
#include <QSplitter>
#include <QPalette>
#include "ChatComponent.h"
#include <foxogram/Logger.h>
#include "../style.h"

MainWindow::MainWindow(QWidget *parent, foxogram::Me* user) : QWidget(parent), user(user)
{
    qDebug() << (user == nullptr);
    foxogram::Logger::setLogLevel(foxogram::LOG_DEBUG);

    QHBoxLayout* HBoxLayout = new QHBoxLayout(this);
    HBoxLayout->setSpacing(0);
    HBoxLayout->setContentsMargins(0, 0, 0, 0);
    QSplitter* splitter = new QSplitter(Qt::Horizontal);
    auto channels = user->fetchChannels();
    QWidget* leftBarWidget = new QWidget();
    leftBarWidget->setFixedWidth(500);
    leftBarWidget->setObjectName("leftBarWidget");
    leftBarWidget->setStyleSheet(Messenger::Style::leftBarWidgetStyleSheet);
    QVBoxLayout* leftBarLayout = new QVBoxLayout(leftBarWidget);
    leftBarLayout->setSpacing(0);
    leftBarLayout->setContentsMargins(0, 0, 0, 0);
    leftBarLayout->setAlignment(Qt::AlignTop);
    for (auto channel : channels) {
        auto chatComponent = new ChatComponent(nullptr, channel);
        leftBarLayout->addWidget(chatComponent);
    }

    QWidget* messengerWidget = new QWidget();
    messengerWidget->setObjectName("messengerWidget");
    messengerWidget->setStyleSheet(Messenger::Style::messengerWidgetStyleSheet);
    QVBoxLayout* messengerLayout = new QVBoxLayout(messengerWidget);
    messengerLayout->setSpacing(0);

    splitter->addWidget(leftBarWidget);
    splitter->addWidget(messengerWidget);
    HBoxLayout->addWidget(splitter);

    resize(900, 600);
}
