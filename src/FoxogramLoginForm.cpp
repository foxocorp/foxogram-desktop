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
