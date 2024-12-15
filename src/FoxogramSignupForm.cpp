#include <FoxogramSignupForm.h>
#include <FoxogramMainWindow.h>
#include <QDialog>
#include <iostream>
#include <QRegularExpressionValidator>

FoxogramSignupForm::FoxogramSignupForm(FoxogramMainWindow* parent) : QWidget(nullptr) {
    ui.setupUi(this);
    this->parent = parent;
    ui.line_2->setFixedHeight(1);
    ui.line_2->setStyleSheet("background-color: #606060");
    modal = new FoxogramVerifyEmailModal(this);
    connect(parent, &FoxogramMainWindow::moved, modal, &FoxogramVerifyEmailModal::parentMoved);
    QRegularExpression rxEmail(R"(^[_A-Za-z0-9-+]+(\.[_A-Za-z0-9-]+)*@[A-Za-z0-9-]+(\.[A-Za-z0-9]+)*(\.[A-Za-z]{2,})$)");
    ui.emailInput->setMaxLength(64);
    ui.emailInput->setValidator(new QRegularExpressionValidator(rxEmail));
    QRegularExpression rxUsername("^[_A-Za-z0-9-.]+$");
    ui.usernameInput->setMaxLength(32);
    ui.usernameInput->setValidator(new QRegularExpressionValidator(rxUsername));
    ui.passwordInput->setMaxLength(128);
    ui.passwordInput->setEchoMode(QLineEdit::Password);
}

void FoxogramSignupForm::on_registerButton_clicked() {
    try {
        this->me = new foxogram::Me(ui.usernameInput->text().toStdString(),ui.emailInput->text().toStdString(), ui.passwordInput->text().toStdString());
        modal->show();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void FoxogramSignupForm::on_loginButton_clicked() {
    emit login();
}