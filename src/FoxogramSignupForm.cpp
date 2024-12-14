#include <FoxogramSignupForm.h>
#include <FoxogramMainWindow.h>
#include <QDialog>
#include <iostream>

FoxogramSignupForm::FoxogramSignupForm(FoxogramMainWindow* parent) : QWidget(nullptr) {
    ui.setupUi(this);
    this->parent = parent;
    ui.line_2->setFixedHeight(1);
    ui.line_2->setStyleSheet("background-color: #606060");
    modal = new FoxogramVerifyEmailModal(this);
    connect(parent, &FoxogramMainWindow::moved, modal, &FoxogramVerifyEmailModal::parentMoved);
}

void FoxogramSignupForm::on_registerButton_clicked() {
    try {
        modal->show();
        this->me = new foxogram::Me(ui.usernameInput->text().toStdString(),ui.emailInput->text().toStdString(), ui.passwordInput->text().toStdString());
        std::cout << me->getUsername() << " " << me->getId() << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void FoxogramSignupForm::on_loginButton_clicked() {
    emit login();
}