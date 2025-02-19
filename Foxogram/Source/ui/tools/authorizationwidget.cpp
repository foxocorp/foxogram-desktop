#include "authorizationwidget.h"
#include "signupwidget.h"
#include "ui_authorizationwidget.h"

AuthorizationWidget::AuthorizationWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuthorizationWidget)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_StyledBackground, true);

    connect(signupwidget, &SignUpWidget::toLogin, this, &AuthorizationWidget::switchToLogin);
    connect(ui->createAccountButton, SIGNAL(clicked()), this, SLOT(switchToSignUp()));
}

AuthorizationWidget::~AuthorizationWidget()
{
    delete ui;
}

void AuthorizationWidget::attempLoginUser()
{

}

void AuthorizationWidget::switchToSignUp()
{

}

void AuthorizationWidget::switchToLogin()
{

}
