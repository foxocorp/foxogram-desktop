#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <QString>
#include <QMap>

namespace StringUtils {
    QString arg(const QString &templateString, const QMap<QString, QString> &variables);
}

#endif // STRINGUTILS_H
