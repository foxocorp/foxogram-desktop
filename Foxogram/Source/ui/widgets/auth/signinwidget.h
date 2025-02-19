#ifndef SIGNINWIDGET_H
#define SIGNINWIDGET_H

#include "signwidgetabstract.h"
#include "authwidget.h"
#include "fieldlabel.h"

#include <QPushButton>

namespace Auth {
class SignInWidget : public SignWidgetAbstract
{
    Q_OBJECT
public:
    explicit SignInWidget(AuthWidget *parent = nullptr);
    ~SignInWidget();

Q_SIGNALS:
    void passwordResetRequested();

protected:
    void setupFieldsLimitations() override;
    void connectValidatorsToFields() override;

private:
    QLineEdit   *emailInput;
    FieldLabel  *emailLabel;
    QLineEdit   *passwordInput;
    FieldLabel  *passwordLabel;
    QPushButton *loginButton;
    QPushButton *resetPasswordButton;
    QPushButton *createAccountButton;
};
}

#endif // SIGNINWIDGET_H
