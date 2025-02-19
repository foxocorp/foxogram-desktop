#include "digitinput.h"

#include <QRegularExpression>
#include <QRegularExpressionValidator>

namespace Auth {
inline const QRegularExpression rxDigit("\\d");

inline const QString cStyle = R"(
#DigitInput {
    border-radius: 5;
    border-style: solid;
}

#DigitInput:focus {
    border-width: 1px;
    border-color: rgb(89, 135, 247);
}
)";

DigitInput::DigitInput(QWidget *parent) : QLineEdit{parent} {
    setPlaceholderText("0");
    setValidator(new QRegularExpressionValidator(rxDigit));
    setMaxLength(1);

    QSizePolicy sp(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sp.setHeightForWidth(true);
    setSizePolicy(sp);

    setAlignment(Qt::AlignmentFlag::AlignCenter);
    QFont f = this->font();
    f.setPointSize(25);
    setFont(f);

    setObjectName("DigitInput");
    setCursor(Qt::ArrowCursor);
    setStyleSheet(cStyle);

    connect(this, &QLineEdit::textChanged, this, &DigitInput::digitChanged);
}

int DigitInput::heightForWidth(int w) const {
    return w;
}

void DigitInput::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key::Key_Left:
        emit previousDigit();
        break;
    case Qt::Key::Key_Right:
        emit nextDigit();
        break;
    case Qt::Key_V:
        if (event->modifiers().testFlag(Qt::ControlModifier))
            emit requestPaste();
        break;
    }

    resetCursor();

    return QLineEdit::keyPressEvent(event);
}

void DigitInput::focusInEvent(QFocusEvent *e)
{
    resetCursor();

    return QLineEdit::focusInEvent(e);
}

void DigitInput::resetCursor()
{
    cursorWordForward(false);
}

void DigitInput::digitChanged(const QString &text)
{
    if (!text.isEmpty())
        emit digitAdded(text.toInt());
    else
        emit digitRemoved();
}
}
