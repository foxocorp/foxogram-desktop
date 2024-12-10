#pragma once

#include <ui_FoxogramSignup.h>
#include <IconButton.h>
#include <foxogram/Me.h>

class FoxogramMainWindow;

class FoxogramSignupForm : public QWidget {
Q_OBJECT
public:
    explicit FoxogramSignupForm(FoxogramMainWindow *parrent);
private slots:
    void on_registerButton_clicked();
    void on_loginButton_clicked();
    signals:
    void login();
private:
    FoxogramMainWindow* parent;
    foxogram::Me* me;
    Ui::FoxogramSignupUi ui;
};

