#include <FoxogramSignupForm.h>
#include <FoxogramMainWindow.h>
#include <IconButton.h>
#include <FoxogramVerifyEmailModal.h>
#include <QDialog>
#include <iostream>

FoxogramSignupForm::FoxogramSignupForm(FoxogramMainWindow* parent) : QWidget(nullptr) {
    ui.setupUi(this);
    this->parent = parent;
    ui.line_2->setFixedHeight(1);
    ui.line_2->setStyleSheet("background-color: #606060");
}

void FoxogramSignupForm::on_registerButton_clicked() {
    try {
        auto m = new FoxogramVerifyEmailModal(this);
        m->show();
        m->setStyleSheet("background-color: #080808");
        this->me = new foxogram::Me(ui.usernameInput->text().toStdString(),ui.emailInput->text().toStdString(), ui.passwordInput->text().toStdString());
        std::cout << me->getUsername() << " " << me->getId() << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void FoxogramSignupForm::on_loginButton_clicked() {
    emit login();
}

