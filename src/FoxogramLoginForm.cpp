#include <FoxogramLoginForm.h>
#include <FoxogramMainWindow.h>
#include <IconButton.h>
#include <iostream>
#include <QMainWindow>
#include <QRegularExpressionValidator>

FoxogramLoginForm::FoxogramLoginForm(FoxogramMainWindow *parent) : QWidget(nullptr) {
    ui.setupUi(this);
    this->parent = parent;
    ui.line_2->setFixedHeight(1);
    ui.line_2->setStyleSheet("background-color: #606060");
    QRegularExpression rxEmail(R"(^[_A-Za-z0-9-+]+(\.[_A-Za-z0-9-]+)*@[A-Za-z0-9-]+(\.[A-Za-z0-9]+)*(\.[A-Za-z]{2,})$)");
    ui.emailInput->setMaxLength(64);
    ui.emailInput->setValidator(new QRegularExpressionValidator(rxEmail));
    ui.passwordInput->setMaxLength(128);
    ui.passwordInput->setEchoMode(QLineEdit::Password);
}

void FoxogramLoginForm::on_loginButton_clicked() {
    try {
        this->me = new foxogram::Me(ui.emailInput->text().toStdString(), ui.passwordInput->text().toStdString());
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void FoxogramLoginForm::on_createAccountButton_clicked() {
    emit createAccount();
}