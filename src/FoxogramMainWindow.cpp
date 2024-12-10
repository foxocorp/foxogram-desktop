#include <FoxogramMainWindow.h>
#include <iostream>

void FoxogramMainWindow::switchToSignupForm() {
    this->centralWidget()->setParent(nullptr);
    this->setCentralWidget(signupForm);
}

void FoxogramMainWindow::switchToLoginForm() {
    this->centralWidget()->setParent(nullptr);
    this->setCentralWidget(loginForm);
}

FoxogramMainWindow::FoxogramMainWindow(QWidget *parrent, Qt::WindowFlags flags) : QMainWindow(parrent, flags) {
    this->setStyleSheet("background-color: #0a0a0a");
    this->loginForm = new FoxogramLoginForm(this);
    this->signupForm = new FoxogramSignupForm(this);
    connect(loginForm, &FoxogramLoginForm::createAccount, this, &FoxogramMainWindow::switchToSignupForm);
    connect(signupForm, &FoxogramSignupForm::login, this, &FoxogramMainWindow::switchToLoginForm);
    this->setCentralWidget(signupForm);
}