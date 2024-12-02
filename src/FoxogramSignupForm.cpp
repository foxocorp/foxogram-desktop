#include "FoxogramSignupForm.h"
#include <iostream>
#include <QMainWindow>

FoxogramSignupForm::FoxogramSignupForm(QWidget *parrent) : QWidget(parrent) {
    ui.setupUi(this);
}

//void FoxogramSignupForm::on_registerButton_clicked() {
//    try {
//        this->me = new foxogram::Me(ui.emailInput->text().toStdString(), ui.passwordInput->text().toStdString());
//        std::cout << me->getUsername() << std::endl << me->getId() << std::endl;
//    } catch (std::exception& e) {
//        std::cout << e.what() << std::endl;
//    }
//}