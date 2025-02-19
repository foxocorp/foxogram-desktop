#pragma once

#include <ui_ChannelComponent.h>
#include <foxogram/Channel.h>

class ChannelComponent : public QWidget {
Q_OBJECT
public:
    explicit ChannelComponent(foxogram::ChannelPtr channel);
private:
    Ui::ChannelComponent ui;
    long long channelId;
};
