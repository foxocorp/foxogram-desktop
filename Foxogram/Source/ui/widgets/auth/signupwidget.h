#ifndef SIGNUPWIDGET_H
#define SIGNUPWIDGET_H

#include "signwidgetabstract.h"
#include "authwidget.h"
#include "verifyemailmodal.h"

#include <QPushButton>

namespace Auth {
class SignUpWidget : public SignWidgetAbstract
{
    Q_OBJECT
public:
    explicit SignUpWidget(AuthWidget *parent = nullptr);
    ~SignUpWidget();

private:
    VerifyEmailModal* codeModal;

Q_SIGNALS:
    void emailConfirmationRequested(UserData* data);

protected:
    void setupFieldsLimitations() override;
    void connectValidatorsToFields() override;

private:
    QLineEdit   *usernameInput;
    FieldLabel  *usernameLabel;
    QLineEdit   *emailInput;
    FieldLabel  *emailLabel;
    QLineEdit   *passwordInput;
    FieldLabel  *passwordLabel;
    QPushButton *registerButton;
    QPushButton *haveAccountButton;
};
}

#endif // SIGNUPWIDGET_H
