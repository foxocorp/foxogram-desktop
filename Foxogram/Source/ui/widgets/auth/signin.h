#ifndef SIGNIN_H
#define SIGNIN_H

#include "ui/widgets/multilayerwidget.h"
#include "authwidget.h"
#include "signinwidget.h"
#include "resetpasswordmodal.h"

namespace Auth {
class SignIn : public MultiLayerWidget
{
    Q_OBJECT
public:
    explicit SignIn(AuthWidget *parent = nullptr);

private:
    SignInWidget* signInWidget;
    ResetPasswordModal* resetPwdWidget;

    AuthWidget* parent;

private Q_SLOTS:
    void showPasswordResetModal();
};
}

#endif // SIGNIN_H
