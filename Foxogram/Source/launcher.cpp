#include "launcher.h"

namespace Credentials {
const QString applicationName = "Foxogram";
const QString organizationName = "Foxocorp";
const QString applicationVersion = "1.0.0";
}

Launcher* Launcher::instance = nullptr;

Launcher::Launcher(int argc, char *argv[]) : _argc(argc), _argv(argv), app(new QApplication(argc, argv))
{
    setDefaultApplicationCredentials();
}

Launcher *Launcher::Create(int argc, char *argv[])
{
    if (!instance)
        instance = new Launcher(argc, argv);

    return instance;
}

Launcher &Launcher::Instance()
{
    if (!instance) {
        qCritical() << "Launcher instance is not created manually";
        QCoreApplication::exit(-1);
    }

    return *instance;
}

Launcher::~Launcher()
{
    instance->deleteLater();
}

void Launcher::setDefaultApplicationCredentials()
{
    QCoreApplication::setApplicationName(Credentials::applicationName);
    QCoreApplication::setOrganizationName(Credentials::organizationName);
    QCoreApplication::setApplicationVersion(Credentials::applicationVersion);
}

int Launcher::execute()
{
    client = std::make_unique<FoxogramClient>();

    return app->exec();
}
