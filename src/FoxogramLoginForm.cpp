#include <FoxogramLoginForm.h>
#include <FoxogramMainWindow.h>
#include <FoxogramIconButton.h>
#include <iostream>
#include <QMainWindow>

FoxogramLoginForm::FoxogramLoginForm(FoxogramMainWindow *parent) : QWidget(nullptr) {
    ui.setupUi(this);
    this->parent = parent;

    GoogleButton_1 = new FoxogramIconButton(parent);
    GoogleButton_2 = new FoxogramIconButton(parent);
    GoogleButton_3 = new FoxogramIconButton(parent);
    GoogleButton_4 = new FoxogramIconButton(parent);
    GoogleButton_5 = new FoxogramIconButton(parent);
    GoogleButton_6 = new FoxogramIconButton(parent);
    ui.horizontalLayout->addWidget(GoogleButton_1);
    ui.horizontalLayout->addWidget(GoogleButton_2);
    ui.horizontalLayout->addWidget(GoogleButton_3);
    ui.horizontalLayout->addWidget(GoogleButton_4);
    ui.horizontalLayout->addWidget(GoogleButton_5);
    ui.horizontalLayout->addWidget(GoogleButton_6);
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