#pragma once

#include "ui_FoxogramLogin.h"
#include <foxogram/Me.h>

class FoxogramLoginForm : public QWidget {
    Q_OBJECT
public:
    explicit FoxogramLoginForm(QWidget *parrent = nullptr);
private slots:
    void on_loginButton_clicked();
private:
    foxogram::Me* me;
    Ui::FoxogramLoginUi ui;
};
