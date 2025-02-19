#include "signup.h"

namespace Auth {
SignUp::SignUp(AuthWidget *parent) : MultiLayerWidget{parent}, parent(parent)
{
    signUpWidget = new SignUpWidget(parent);
    connect(signUpWidget, &SignUpWidget::emailConfirmationRequested, this, &SignUp::showEmailConfirmationModal);
    addWidget(signUpWidget);

    setModalBackgroundBlurred(true);
}

void SignUp::showEmailConfirmationModal(UserData* userData)
{
    emailWidget = new VerifyEmailModal(parent, userData);

    setActiveWidget(emailWidget, true);
}
}
