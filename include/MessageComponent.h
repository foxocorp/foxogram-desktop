#pragma once

#include <ui_MessageComponent.h>
#include <foxogram/Message.h>

class MessageComponent : public QWidget {
Q_OBJECT
public:
    explicit MessageComponent(foxogram::MessagePtr message);
private:
    Ui::MessageComponent ui;
    long long channelId;
    long long messageId;
};
