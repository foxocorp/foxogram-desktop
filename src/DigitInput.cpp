#include <DigitInput.h>
#include <QResizeEvent>
#include <QRegularExpressionValidator>

DigitInput::DigitInput(QWidget* parent) : QLineEdit(parent) {
    QRegularExpression rx("\\d");
    auto* re = new QRegularExpressionValidator(rx, nullptr);
    this->setValidator(re);
    QSizePolicy sp(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sp.setHeightForWidth(true);
    setSizePolicy(sp);
}

QSize DigitInput::minimumSizeHint() const {
    return {20, 20};
}

int DigitInput::heightForWidth(int w) const {
    return w;
}

QSize DigitInput::sizeHint() const {
    return {48, 48};
}
