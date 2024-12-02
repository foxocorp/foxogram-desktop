#pragma once

#include "ui_FoxogramSignup.h"
#include <foxogram/Me.h>

class FoxogramSignupForm : public QWidget {
Q_OBJECT
public:
    explicit FoxogramSignupForm(QWidget *parrent = nullptr);
private slots:
    //void on_registerButton_clicked();
private:
    foxogram::Me* me;
    Ui::FoxogramSignupUi ui;
};

