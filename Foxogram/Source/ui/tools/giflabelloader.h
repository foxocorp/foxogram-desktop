#ifndef GIFLABELLOADER_H
#define GIFLABELLOADER_H

#include <QMovie>
#include <QLabel>

namespace Tools {
namespace GifLabel {
QMovie* create(const QString &fileName, QLabel *label, const QSize *size);
QMovie* create(const QString &fileName, QLabel *label, const int size);
}
}

#endif // GIFLABELLOADER_H
