#include "foxogramclient.h"

#include <QApplication>
#include <QtConcurrent>

FoxogramClient::FoxogramClient()
{
    loadApplication();

    QThreadPool::globalInstance()->start([&] {
        initializeAuthWidget();
    });
}

FoxogramClient::~FoxogramClient()
{
    if (mainWindow)
        mainWindow->deleteLater();

    if (lw)
        lw->deleteLater();

    if (authWidget)
        authWidget->deleteLater();
}

void FoxogramClient::requestAuthorization()
{
    qDebug() << "Authorization requested";

    authWidget->show();

    connect(authWidget->authService, &AuthorizationService::successfulLogin, this, &FoxogramClient::setupMainOnAuth);
    connect(authWidget->authService, &AuthorizationService::successfulEmailVerification, this, &FoxogramClient::setupMainOnAuth);

    if (lw)
        lw->deleteLater();
}

void FoxogramClient::setupMainOnAuth()
{
    qDebug() << "Successful authorization";

    authWidget->setDisabled(true);
    authWidget->close();

    openMainWindow();
}

void FoxogramClient::loadApplication()
{
    lw = std::make_unique<LoadingWidget>();
    lw->show();

    connect(lw.get(), &LoadingWidget::loaded, this, &FoxogramClient::requestAuthorization);
}

void FoxogramClient::openMainWindow()
{
    mainWindow = std::make_unique<MainWindow>();
    mainWindow->show();
}

void FoxogramClient::initializeAuthWidget()
{
    user = (foxogram::Me*)malloc(sizeof(foxogram::Me));
    QMetaObject::invokeMethod(this, [=]() {
        authWidget = std::make_unique<Auth::AuthWidget>(nullptr, user);

        if (lw)
            lw->proceedLoading();
    });
}
