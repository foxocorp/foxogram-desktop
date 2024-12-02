#pragma once

#include "ui_FoxogramSignup.h"
#include <foxogram/Me.h>

class FoxogramSignupForm : public QWidget {
Q_OBJECT
public:
    explicit FoxogramSignupForm(QWidget *parrent = nullptr);
private slots:
    void on_registerButton_clicked();
    void on_loginButton_clicked();
    signals:
    void login();
private:
    QWidget* parrent;
    foxogram::Me* me;
    Ui::FoxogramSignupUi ui;
};

