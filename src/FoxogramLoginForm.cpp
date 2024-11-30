#include "FoxogramLoginForm.h"
#include <iostream>
#include <QMainWindow>
#include <QResizeEvent>

FoxogramLoginForm::FoxogramLoginForm(QWidget *parent)
        : QWidget(parent) {
    ui.setupUi(this);
}

void FoxogramLoginForm::on_loginButton_clicked() {
    try {
        this->me = new foxogram::Me(ui.emailInput->text().toStdString(), ui.passwordInput->text().toStdString());
        std::cout << me->getUsername() << std::endl << me->getId() << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void FoxogramLoginForm::resizeEvent(QResizeEvent* event) {
    double x = event->size().width(), y = event->size().height();
    double loginLabelx = x*(775.5/1920), loginLabely = y*(277.0/1080);
    double loginLabelw = x*(119.0/1920), loginLabelh = y*(48.0/1080);
    double loginLabelFontSizex = (loginLabelw/119)*26, loginLabelFontSizey=(loginLabelh/48)*26;
    double loginLabelFontSize = (loginLabelFontSizex < loginLabelFontSizey) ? loginLabelFontSizex : loginLabelFontSizey;
    QFont loginLabelFont = ui.loginLabel->font();
    loginLabelFont.setPointSize(floor(loginLabelFontSize));

    double emailLabelx = x*(775.5/1920), emailLabely = y*(335.5/1080);
    double emailLabelw = x*(61.0/1920), emailLabelh = y*(22.0/1080);
    double emailLabelFontSizex = (emailLabelw/61)*12, emailLabelFontSizey=(emailLabelh/22)*13;
    double emailLabelFontSize = (emailLabelFontSizex < emailLabelFontSizey) ? emailLabelFontSizex : emailLabelFontSizey;
    QFont emailLabelFont = ui.emailLabel->font();
    emailLabelFont.setPointSize(floor(emailLabelFontSize));

    double emailInputx = x*(775.5/1920), emailInputy = y*(361.5/1080);
    double emailInputw = x*(368.0/1920), emailInputh = y*(45.0/1080);
    double emailInputFontSizex = (emailInputw/368)*12, emailInputFontSizey=(emailInputh/45)*12;
    double emailInputFontSize = (emailInputFontSizex < emailInputFontSizey) ? emailInputFontSizex : emailInputFontSizey;
    QFont emailInputFont = ui.emailInput->font();
    emailInputFont.setPointSize(floor(emailInputFontSize));

    double passwordLabelx = x*(775.5/1920), passwordLabely = y*(422.5/1080);
    double passwordLabelw = x*(99.0/1920), passwordLabelh = y*(22.0/1080);
    double passwordLabelFontSizex = (passwordLabelw/61)*13, passwordLabelFontSizey=(passwordLabelh/22)*13;
    double passwordLabelFontSize = (passwordLabelFontSizex < passwordLabelFontSizey) ? passwordLabelFontSizex : passwordLabelFontSizey;
    QFont passwordLabelFont = ui.passwordLabel->font();
    passwordLabelFont.setPointSize(floor(passwordLabelFontSize));

    double passwordInputx = x*(775.5/1920), passwordInputy = y*(448.5/1080);
    double passwordInputw = x*(368.0/1920), passwordInputh = y*(45.0/1080);
    double passwordInputFontSizex = (passwordInputw/368)*12, passwordInputFontSizey=(passwordInputh/45)*12;
    double passwordInputFontSize = (passwordInputFontSizex < passwordInputFontSizey) ? passwordInputFontSizex : passwordInputFontSizey;
    QFont passwordInputFont = ui.passwordInput->font();
    passwordInputFont.setPointSize(floor(passwordInputFontSize));

    double loginButtonx = x*(775.5/1920), loginButtony = y*(514.0/1080);
    double loginButtonw = x*(368.0/1920), loginButtonh = y*(48.0/1080);
    double loginButtonFontSizex = (loginButtonw/368)*15, loginButtonFontSizey=(loginButtonh/48)*15;
    double loginButtonFontSize = (loginButtonFontSizex < loginButtonFontSizey) ? loginButtonFontSizex : loginButtonFontSizey;
    std::cout << loginButtony << std::endl;
    QFont loginButtonFont = ui.loginButton->font();
    loginButtonFont.setPointSize(floor(loginButtonFontSize));
    
    ui.loginLabel->setGeometry(loginLabelx, loginLabely, loginLabelw, loginLabelh);
    ui.loginLabel->setFont(loginLabelFont);
    ui.emailLabel->setGeometry(emailLabelx, emailLabely, emailLabelw, emailLabelh);
    ui.emailLabel->setFont(emailLabelFont);
    ui.emailInput->setGeometry(emailInputx, emailInputy, emailInputw, emailInputh);
    ui.emailInput->setFont(emailInputFont);
    ui.passwordLabel->setGeometry(passwordLabelx, passwordLabely, passwordLabelw, passwordLabelh);
    ui.passwordLabel->setFont(passwordLabelFont);
    ui.passwordInput->setGeometry(passwordInputx, passwordInputy, passwordInputw, passwordInputh);
    ui.passwordInput->setFont(passwordInputFont);
    ui.loginButton->setGeometry(loginButtonx, loginButtony, loginButtonw, loginButtonh);
    ui.loginButton->setFont(loginButtonFont);
}