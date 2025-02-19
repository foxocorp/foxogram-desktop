#ifndef DIGITINPUT_H
#define DIGITINPUT_H

#include <QLineEdit>
#include <QKeyEvent>

namespace Auth {
extern const QRegularExpression rxDigit;

class DigitInput : public QLineEdit
{
    Q_OBJECT
public:
    explicit DigitInput(QWidget *parent = nullptr);

    int heightForWidth(int w) const override;

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void focusInEvent(QFocusEvent *e) override;

private:
    void resetCursor();

private Q_SLOTS:
    void digitChanged(const QString &text);

Q_SIGNALS:
    void digitAdded(int digit);
    void digitRemoved();

    void previousDigit();
    void nextDigit();

    void requestPaste();
};
}

#endif // DIGITINPUT_H
