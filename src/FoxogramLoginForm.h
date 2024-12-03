#pragma once

#include "ui_FoxogramLogin.h"
#include <foxogram/Me.h>

class FoxogramMainWindow;

class FoxogramLoginForm : public QWidget {
    Q_OBJECT
public:
    explicit FoxogramLoginForm(FoxogramMainWindow *parrent);
private slots:
    void on_loginButton_clicked();
    void on_createAccountButton_clicked();
    signals:
    void createAccount();
private:
    FoxogramMainWindow* parent;
    foxogram::Me* me;
    Ui::FoxogramLoginUi ui;
};
