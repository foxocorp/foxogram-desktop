#include <FoxogramLoginForm.h>
#include <FoxogramMainWindow.h>
#include <IconButton.h>
#include <iostream>
#include <QMainWindow>

FoxogramLoginForm::FoxogramLoginForm(FoxogramMainWindow *parent) : QWidget(nullptr) {
    ui.setupUi(this);
    this->parent = parent;
    ui.line_2->setFixedHeight(1);
    ui.line_2->setStyleSheet("background-color: #606060");
}

void FoxogramLoginForm::on_loginButton_clicked() {
    try {
        this->me = new foxogram::Me(ui.emailInput->text().toStdString(), ui.passwordInput->text().toStdString());
        std::cout << me->getUsername() << std::endl << me->getId() << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void FoxogramLoginForm::on_createAccountButton_clicked() {
    emit createAccount();
}