#include <DigitInput.h>
#include <QResizeEvent>
#include <QRegularExpressionValidator>
#include <iostream>

DigitInput::DigitInput(QWidget* parent) : QLineEdit(parent) {
    QRegularExpression rx("\\d");
    auto* re = new QRegularExpressionValidator(rx, nullptr);
    this->setValidator(re);
    QSizePolicy sp(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sp.setHeightForWidth(true);
    setSizePolicy(sp);
    setAlignment(Qt::AlignmentFlag::AlignCenter);
    setPlaceholderText("0");
    auto font = this->font();
    font.setPointSize(20);
    setFont(font);
    connect(this, &QLineEdit::textChanged, this, &DigitInput::inputChanged);
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

void DigitInput::setFocused() {
    setFocus();
}

void DigitInput::inputChanged(QString text) {
    if (!text.isEmpty()) {
        emit digitInputed();
    }
}

void DigitInput::backspacePressed() {
    if (text().isEmpty()) {
        emit digitDeleted();
    } else {
        setText("");
    }
}

void DigitInput::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_Delete:
        case Qt::Key_Backspace:
            emit backspacePressed();
            break;
        case Qt::Key_0:
        case Qt::Key_1:
        case Qt::Key_2:
        case Qt::Key_3:
        case Qt::Key_4:
        case Qt::Key_5:
        case Qt::Key_6:
        case Qt::Key_7:
        case Qt::Key_8:
        case Qt::Key_9:
            this->setText(QString::fromStdString(std::to_string(event->key() - 48)));
            break;
        case Qt::Key_Left:
            emit digitDeleted();
            break;
        case Qt::Key_Right:
            emit digitInputed();
            break;
    }
}