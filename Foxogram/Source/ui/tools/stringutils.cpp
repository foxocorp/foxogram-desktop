#include "stringutils.h"

namespace StringUtils {
QString arg(const QString &templateString, const QMap<QString, QString> &variables) {
    QString result = templateString;

    for (auto it = variables.constBegin(); it != variables.constEnd(); ++it) {
        QString placeholder = "%" + it.key() + "%";
        result.replace(placeholder, it.value());
    }

    return result;
}
}
