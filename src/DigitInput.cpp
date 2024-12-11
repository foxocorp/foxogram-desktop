#include <DigitInput.h>
#include <QResizeEvent>
#include <QRegularExpressionValidator>

DigitInput::DigitInput(QWidget* parent) : QLineEdit(parent) {
    QRegularExpression rx("\\d");
    auto* re = new QRegularExpressionValidator(rx, nullptr);
    this->setValidator(re);
    setSizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Expanding);
}

QSize DigitInput::minimumSizeHint() const {
    return {20, 31};
}