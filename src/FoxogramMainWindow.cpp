#include "FoxogramMainWindow.h"
#include <iostream>

FoxogramMainWindow::~FoxogramMainWindow() {

}

void FoxogramMainWindow::switchToSignupForm() {
    this->centralWidget()->setParent(nullptr);
    this->setCentralWidget(signupForm);
}

void FoxogramMainWindow::switchToLoginForm() {
    this->centralWidget()->setParent(nullptr);
    this->setCentralWidget(loginForm);
}

FoxogramMainWindow::FoxogramMainWindow(QWidget *parrent, Qt::WindowFlags flags) : QMainWindow(parrent, flags) {
    this->loginForm = new FoxogramLoginForm();
    this->signupForm = new FoxogramSignupForm();
    connect(loginForm, &FoxogramLoginForm::createAccount, this, &FoxogramMainWindow::switchToSignupForm);
    connect(signupForm, &FoxogramSignupForm::login, this, &FoxogramMainWindow::switchToLoginForm);
    this->setCentralWidget(signupForm);
}