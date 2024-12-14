#pragma once

#include <QMainWindow>
#include <FoxogramLoginForm.h>
#include <FoxogramSignupForm.h>

class FoxogramMainWindow : public QMainWindow {
    Q_OBJECT
private:
    FoxogramLoginForm* loginForm;
    FoxogramSignupForm* signupForm;
    void moveEvent(QMoveEvent*) override;
private slots:
    void switchToSignupForm();
    void switchToLoginForm();
signals:
    void moved(QMoveEvent*);
public:
    explicit FoxogramMainWindow(QWidget* parrent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    ~FoxogramMainWindow() =  default;
};
