#pragma once

#include <FoxogramModal.h>
#include <DigitInput.h>
#include <QTime>
#include <QTimer>

class FoxogramVerifyEmailModal : public FoxogramModal {
    Q_OBJECT
public:
    explicit FoxogramVerifyEmailModal(class FoxogramSignupForm* parent);
    void showEvent(QShowEvent *event);
public slots:
    void parentMoved(QMoveEvent* event);
    void timerChanged();
    void linkClicked();
    void confirmClicked();
signals:
    void emailConfirmed();
private:
    QTimer timer;
    QTime time;
    QHBoxLayout layout;
    DigitInput input;
    DigitInput input2;
    DigitInput input3;
    DigitInput input4;
    DigitInput input5;
    DigitInput input6;
    QLabel label;
    QLabel timeLabel;
    FoxogramSignupForm* parent;
};
