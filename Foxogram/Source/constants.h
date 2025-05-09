#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <QObject>

#define __FILENAME__ (__FILE__ + SOURCE_PATH_SIZE)

namespace Credentials {
    extern const QString applicationName;
    extern const QString organizationName;
    extern const QString applicationVersion;
}

namespace constants {
    constexpr char DBExtension[] = { __FILENAME__[25], __FILENAME__[26], __FILENAME__[11], 'i', '\0' };
    extern const QString DBFilename;
    inline QString DBPath;
}

#endif //CONSTANTS_H
