#pragma once

#include <QMainWindow>
#include "FoxogramLoginForm.h"
#include "FoxogramSignupForm.h"

class FoxogramMainWindow : public QMainWindow {
private:
    FoxogramLoginForm* loginForm;
    FoxogramSignupForm* signupForm;
private slots:
    void switchToSignupForm();
    void switchToLoginForm();
public:
    explicit FoxogramMainWindow(QWidget* parrent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    ~FoxogramMainWindow();
};
