#include "signin.h"


namespace Auth {
SignIn::SignIn(AuthWidget *parent) : MultiLayerWidget{parent}, parent(parent)
{
    signInWidget = new SignInWidget(parent);
    connect(signInWidget, &SignInWidget::passwordResetRequested, this, &SignIn::showPasswordResetModal);
    addWidget(signInWidget);

    setModalBackgroundBlurred(true);
}

void SignIn::showPasswordResetModal()
{
    resetPwdWidget = new ResetPasswordModal(this);

    setActiveWidget(resetPwdWidget, true);
}
}
