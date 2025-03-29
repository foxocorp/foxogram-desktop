#ifndef VERIFYEMAILMODAL_H
#define VERIFYEMAILMODAL_H

#include "services/authorizationservice.h"
#include "ui/widgets/modalwidget.h"
#include "digitinput.h"
#include <QHBoxLayout>

namespace Auth {
extern const int verifyCodeLength;

class VerifyEmailModal : public ModalWidget
{
    Q_OBJECT

public:
    explicit VerifyEmailModal(QWidget *parent, UserData *userData);
    ~VerifyEmailModal();

Q_SIGNALS:
    void verifyEmailRequested(std::string code);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    QHBoxLayout *digitsLayout;

    // Position, digit
    QMap<int, DigitInput*> digits;
    void setupDigits();

    void pasteFromClipboard();
};
}

#endif // VERIFYEMAILMODAL_H
