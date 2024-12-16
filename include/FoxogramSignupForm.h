#pragma once

#include <ui_FoxogramSignup.h>
#include <IconButton.h>
#include <foxogram/Me.h>
#include <FoxogramVerifyEmailModal.h>

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
    void moved(QMoveEvent*);
private:
    FoxogramVerifyEmailModal* modal;
    Ui::FoxogramSignupUi ui;
protected:
    FoxogramMainWindow* parent;
    foxogram::Me* me;
    friend class FoxogramVerifyEmailModal;
};

