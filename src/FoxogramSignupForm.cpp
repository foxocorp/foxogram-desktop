#include "FoxogramSignupForm.h"
#include "FoxogramMainWindow.h"
#include <iostream>
#include <QMainWindow>

FoxogramSignupForm::FoxogramSignupForm(FoxogramMainWindow *parrent) : QWidget(nullptr) {
    ui.setupUi(this);
    this->parrent = parrent;
}

void FoxogramSignupForm::on_registerButton_clicked() {
    try {
        this->me = new foxogram::Me(ui.usernameInput->text().toStdString(),ui.emailInput->text().toStdString(), ui.passwordInput->text().toStdString());
        std::cout << me->getUsername() << " " << me->getId() << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void FoxogramSignupForm::on_loginButton_clicked() {
    emit login();
}

