#include <MessageComponent.h>
#include <utility>
#include <foxogram/Member.h>

MessageComponent::MessageComponent(foxogram::MessagePtr message) {
    ui.setupUi(this);
    ui.content->setText(QString::fromStdString(message->getContent()));
    ui.username->setText(QString::fromStdString(message->getAuthor()->getUsername()));
}