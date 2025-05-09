#include "ChatComponent.h"
#include "../style.h"
#include <qboxlayout.h>
#include <qdatetime.h>
#include <QLabel>

ChatComponent::ChatComponent(QWidget* parent, const foxogram::ChannelPtr& channel) : QWidget(parent), channel(channel) {

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setSpacing(16);
    mainLayout->setContentsMargins(16, 14, 16, 14);

    QLabel *avatar = new QLabel();
    avatar->setAlignment(Qt::AlignCenter);
    avatar->setFixedSize(72, 72);
    avatar->setObjectName("avatar");
    avatar->setProperty("defaultAvatar", channel->getIcon().empty());
    if (channel->getIcon().empty()) {
        avatar->setText(QChar::fromLatin1(std::toupper(channel->getDisplayName().front())));
    }

    QVBoxLayout *chatInfoLayout = new QVBoxLayout();

    QHBoxLayout *infoLayout = new QHBoxLayout();
    QLabel *chatName = new QLabel(QString::fromStdString(channel->getDisplayName()));
    chatName->setObjectName("chatName");

    QSpacerItem* infoSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QDateTime time = QDateTime::fromSecsSinceEpoch(channel->getMessages().back()->getCreatedAt());
    QLabel* timeLabel = new QLabel(time.toString("hh:mm"));
    timeLabel->setObjectName("timeLabel");

    QHBoxLayout* messageLayout = new QHBoxLayout();
    QLabel* author = new QLabel(QString::fromStdString(channel->getMessages().back()->getAuthor()->getUsername()
        + ": "));
    author->setObjectName("author");
    QLabel* message = new QLabel(QString::fromStdString(channel->getMessages().back()->getContent()));
    message->setObjectName("message");
    QSpacerItem* messageSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    infoLayout->addWidget(chatName);
    infoLayout->addSpacerItem(infoSpacer);
    infoLayout->addWidget(timeLabel);
    infoLayout->setContentsMargins(0, 3, 0, 3);

    messageLayout->addWidget(author);
    messageLayout->addWidget(message);
    messageLayout->addSpacerItem(messageSpacer);
    messageLayout->setSpacing(5);
    chatInfoLayout->addLayout(infoLayout);
    chatInfoLayout->addLayout(messageLayout);
    chatInfoLayout->setSpacing(4);
    chatInfoLayout->setContentsMargins(0, 0, 0, 20);

    mainLayout->addWidget(avatar);
    mainLayout->addLayout(chatInfoLayout);
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    setStyleSheet(Messenger::Style::chatComponentInfoLayout);
}