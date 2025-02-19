#ifndef SIGNUP_H
#define SIGNUP_H

#include "ui/widgets/multilayerwidget.h"
#include "authwidget.h"
#include "signupwidget.h"

namespace Auth {
class SignUp : public MultiLayerWidget
{
    Q_OBJECT
public:
    explicit SignUp(AuthWidget *parent = nullptr);

private Q_SLOTS:
    void showEmailConfirmationModal(UserData* userData);

private:
    SignUpWidget* signUpWidget;
    VerifyEmailModal* emailWidget;

    AuthWidget* parent;
};
}

#endif // SIGNUP_H
