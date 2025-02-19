#include "flineedit.h"

namespace {
constexpr int inputSize = 12;
}

FLineEdit::FLineEdit(QWidget *parent)
{
    QFont inputFont;
    inputFont.setPointSize(inputSize);

    setFont(inputFont);
}
