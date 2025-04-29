#include "authwidget.h"
#include "../style.h"
#include "signup.h"
#include "signin.h"

namespace Auth {

AuthWidget::AuthWidget(QWidget *parent, foxogram::Me* user) : QWidget(parent)
    , authService(new AuthorizationService(this, user))
{
    setObjectName("AuthWidget");
    setStyleSheet(Style::controllerStyleSheet);

    layout = new QGridLayout(this);

    stackedWidget = new QStackedWidget(this);
    layout->addWidget(stackedWidget);

    setAttribute(Qt::WA_StyledBackground, true);

    pages[Page::SIGN_IN_PAGE] = new SignIn(this);
    pages[Page::SIGN_UP_PAGE] = new SignUp(this);

    for (auto const &p : std::as_const(pages))
        stackedWidget->addWidget(p);

    switchToLogin();
    proceedLoading();
}

AuthWidget::~AuthWidget()
{
    for (auto const &p : std::as_const(pages))
        delete p;
}

void AuthWidget::switchToSignUp()
{
    setPage(Page::SIGN_UP_PAGE);
}

void AuthWidget::switchToLogin()
{
    setPage(Page::SIGN_IN_PAGE);
}

void AuthWidget::proceedLoading()
{
    emit created();
}

void AuthWidget::setPage(const Page &pageName)
{
    if (QWidget* widget = pages.value(pageName, nullptr)) {
        stackedWidget->setCurrentWidget(widget);
    }
}
}
