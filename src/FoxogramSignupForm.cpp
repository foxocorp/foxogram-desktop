#include "FoxogramSignupForm.h"
#include "FoxogramMainWindow.h"
#include "FoxogramIconButton.h"
#include "FoxogramModal.h"
#include <QDialog>
#include <iostream>

FoxogramSignupForm::FoxogramSignupForm(FoxogramMainWindow* parent) : QWidget(nullptr) {
    ui.setupUi(this);
    this->parrent = parrent;
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

void FoxogramSignupForm::on_registerButton_clicked() {
    try {
        auto m = new FoxogramModal(this);
        m->show();
        this->me = new foxogram::Me(ui.usernameInput->text().toStdString(),ui.emailInput->text().toStdString(), ui.passwordInput->text().toStdString());
        std::cout << me->getUsername() << " " << me->getId() << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void FoxogramSignupForm::on_loginButton_clicked() {
    emit login();
}

