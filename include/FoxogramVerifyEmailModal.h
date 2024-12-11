#pragma once

#include <FoxogramModal.h>
#include <DigitInput.h>

class FoxogramVerifyEmailModal : public FoxogramModal {
public:
    FoxogramVerifyEmailModal(QWidget* parent);
private:
    QHBoxLayout layout;
    DigitInput input;
    DigitInput input2;
    DigitInput input3;
    DigitInput input4;
    DigitInput input5;
    DigitInput input6;
    QLabel label;
};
