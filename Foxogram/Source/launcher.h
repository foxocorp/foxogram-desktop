#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <QApplication>

#include "foxogramclient.h"


class Launcher final : public QObject {
    Q_DISABLE_COPY(Launcher)
public:
    ~Launcher();

    static Launcher* Create(int argc, char *argv[]);
    static Launcher& Instance();

    int execute();
private:
    Launcher(int argc, char *argv[]);

    int _argc;
    char **_argv;

    std::unique_ptr<QApplication> app;
    std::unique_ptr<FoxogramClient> client;

    static Launcher* instance;

    void setDefaultApplicationCredentials();
};

#endif // LAUNCHER_H
