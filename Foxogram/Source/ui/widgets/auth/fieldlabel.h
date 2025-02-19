#ifndef FIELDLABEL_H
#define FIELDLABEL_H

#include <QLabel>
#include <QPainter>

namespace Auth {
static const QColor errorColor(165, 63, 63);

class FieldLabel : public QLabel
{
    Q_OBJECT
public:
    explicit FieldLabel(const QString &typeText, QWidget *parent = nullptr);

    void setErrorText(const QString &newErrorText);

    // Forbid manual set text of field
    void setText(const QString &text) = delete;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QString typeText;
    QString errorText;
};
}

#endif // FIELDLABEL_H
