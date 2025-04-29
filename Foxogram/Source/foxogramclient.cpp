#include "foxogramclient.h"

#include <QApplication>
#include <QtConcurrent>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <foxogram/Logger.h>

FoxogramClient::FoxogramClient()
{
    foxogram::Logger::setLogLevel(foxogram::LOG_DEBUG);
    loadApplication();
    user = (foxogram::Me*)malloc(sizeof(foxogram::Me));
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");
    db.open();
    QSqlQuery query(db);
    query.exec("CREATE TABLE IF NOT EXISTS me(id INTEGER PRIMARY KEY CHECK (id = 1), token TEXT)");
    query.exec("SELECT token FROM me");
    query.next();
    bool logged = false;
    if (!query.value("token").isNull() && !query.value("token").toString().isEmpty()) {
        try {
            new (user) foxogram::Me(query.value("token").toString().toStdString());
            logged = true;
        } catch (std::exception &e) {
            qCritical() << e.what();
        }
    }
    db.close();
    QThreadPool::globalInstance()->start([&, logged]() {
        std::cout << logged << std::endl;
        if (!logged) {
            initializeAuthWidget();
        } else {
            openMainWindow();
            lw->deleteLater();
        }
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

void FoxogramClient::openMainWindow() {
    QMetaObject::invokeMethod(this, [=]() {
        mainWindow = std::make_unique<MainWindow>(nullptr, user);
        mainWindow->show();
    });
}

void FoxogramClient::initializeAuthWidget()
{
    QMetaObject::invokeMethod(this, [=]() {
        authWidget = std::make_unique<Auth::AuthWidget>(nullptr, user);

        if (lw)
        lw->proceedLoading();
    });
}

