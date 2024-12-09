#pragma once

#include "ui_FoxogramSignup.h"
#include "FoxogramIconButton.h"
#include "foxogram/Me.h"

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
    FoxogramIconButton* GoogleButton_1;
    FoxogramIconButton* GoogleButton_2;
    FoxogramIconButton* GoogleButton_3;
    FoxogramIconButton* GoogleButton_4;
    FoxogramIconButton* GoogleButton_5;
    FoxogramIconButton* GoogleButton_6;
    FoxogramMainWindow* parrent;
    foxogram::Me* me;
    Ui::FoxogramSignupUi ui;
};

