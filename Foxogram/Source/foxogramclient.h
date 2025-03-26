#ifndef FOXOGRAMCLIENT_H
#define FOXOGRAMCLIENT_H

#include <QObject>
#include <QtConcurrent>
#include <foxogram/Me.h>

#include "ui/widgets/auth/authwidget.h"
#include "ui/widgets/loadingwidget.h"
#include "ui/widgets/messenger/mainwindow.h"


class FoxogramClient final : public QObject
{
    Q_OBJECT; Q_DISABLE_COPY(FoxogramClient)
public:
    FoxogramClient();
    ~FoxogramClient();

private:
    void requestAuthorization();
    void setupMainOnAuth();
    void loadApplication();
    void openMainWindow();

    std::unique_ptr<MainWindow> mainWindow;
    std::unique_ptr<LoadingWidget> lw;
    std::unique_ptr<Auth::AuthWidget> authWidget;
    foxogram::Me* user;

private Q_SLOTS:
    void initializeAuthWidget();
};

#endif // FOXOGRAMCLIENT_H
