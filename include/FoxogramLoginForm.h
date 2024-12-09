#pragma once

#include "ui_FoxogramLogin.h"
#include "FoxogramIconButton.h"
#include "foxogram/Me.h"

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
    FoxogramIconButton* GoogleButton_1;
    FoxogramIconButton* GoogleButton_2;
    FoxogramIconButton* GoogleButton_3;
    FoxogramIconButton* GoogleButton_4;
    FoxogramIconButton* GoogleButton_5;
    FoxogramIconButton* GoogleButton_6;

    FoxogramMainWindow* parent;
    foxogram::Me* me;
    Ui::FoxogramLoginUi ui;
};
