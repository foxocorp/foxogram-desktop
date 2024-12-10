#include <DigitInput.h>
#include <QResizeEvent>
#include <QRegularExpressionValidator>

DigitInput::DigitInput(QWidget* parent) : QLineEdit(parent) {
    QRegularExpression rx("\\d");
    auto* re = new QRegularExpressionValidator(rx, nullptr);
    this->setValidator(re);
    setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
}