#include "fieldlabel.h"

namespace Auth {
FieldLabel::FieldLabel(const QString &typeText, QWidget *parent) : QLabel(parent), typeText(typeText) {}

void FieldLabel::setErrorText(const QString &newErrorText)
{
    errorText = newErrorText;
    update();
}

void FieldLabel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QFont cFont = font();
    cFont.setPointSize(11);
    cFont.setWeight(QFont::DemiBold);

    painter.setFont(cFont);

    QFontMetrics fm(cFont);
    int normalTextWidth = fm.horizontalAdvance(typeText);

    painter.setPen(palette().text().color());
    int yTypeText = height() / 2 + (fm.ascent() - fm.descent()) / 2;
    painter.drawText(0, yTypeText, typeText);

    painter.setFont(font());
    QPen pen(errorColor);
    painter.setPen(pen);

    QFontMetrics fmRegular(font());
    int yErrorText = height() / 2 + (fmRegular.ascent() - fmRegular.descent()) / 2;
    painter.drawText(normalTextWidth, yErrorText, " * " + errorText);
}
}
