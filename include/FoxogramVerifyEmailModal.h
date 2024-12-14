#pragma once

#include <FoxogramModal.h>
#include <DigitInput.h>

class FoxogramVerifyEmailModal : public FoxogramModal {
public:
    explicit FoxogramVerifyEmailModal(class FoxogramSignupForm* parent);
    void showEvent(QShowEvent *event);
public slots:
    void parentMoved(QMoveEvent* event);
private:
    QHBoxLayout layout;
    DigitInput input;
    DigitInput input2;
    DigitInput input3;
    DigitInput input4;
    DigitInput input5;
    DigitInput input6;
    QPushButton label;
    FoxogramSignupForm* parent;
};
