#ifndef CHATCOMPONENT_H
#define CHATCOMPONENT_H

#include <QWidget>
#include <foxogram/Channel.h>

class ChatComponent : public QWidget {
Q_OBJECT
public:
    explicit ChatComponent(QWidget *parent = nullptr, const foxogram::ChannelPtr& channel = nullptr);
    foxogram::ChannelPtr channel;
};



#endif //CHATCOMPONENT_H
