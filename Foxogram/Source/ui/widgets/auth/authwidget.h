#ifndef AUTHWIDGET_H
#define AUTHWIDGET_H

#include <QWidget>
#include <QMap>
#include <QStackedWidget>
#include <QGridLayout>
#include <foxogram/Me.h>

#include "services/authorizationservice.h"

namespace Auth {
enum class Page {
    SIGN_IN_PAGE,
    SIGN_UP_PAGE
};

class AuthWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AuthWidget(QWidget *parent = nullptr, foxogram::Me* user = nullptr);
    ~AuthWidget();

    AuthorizationService* authService;

public Q_SLOTS:
    void switchToSignUp();
    void switchToLogin();

Q_SIGNALS:
    void created();

private:
    QGridLayout *layout;

    QMap<Page, QWidget*> pages;
    QStackedWidget *stackedWidget;

private Q_SLOTS:
    void proceedLoading();

    void setPage(const Page &pageName);
};
}

#endif // AUTHWIDGET_H
