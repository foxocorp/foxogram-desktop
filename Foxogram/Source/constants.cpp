#include "constants.h"

#include <qstandardpaths.h>

namespace Credentials {
#ifndef DEV
    const QString applicationName = "Foxogram";
#else
    const QString applicationName = "FoxogramDev";
#endif
    const QString organizationName = "Foxocorp";
    const QString applicationVersion = "1.0.0";
}

namespace constants
{
    const QString DBFilename = QString("data") + DBExtension;
}
