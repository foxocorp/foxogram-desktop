#include "launcher.h"

int main(int argc, char *argv[])
{
    Launcher* launcher = Launcher::Create(argc, argv);
    return launcher->execute();
}
