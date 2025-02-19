#include "giflabelloader.h"

namespace Tools {
namespace GifLabel {
static const QSize defaultGifSize(100, 100);

QMovie *create(const QString &fileName, QLabel *label, const QSize *size = &defaultGifSize)
{
    QMovie *movie = new QMovie(fileName);

    movie->setScaledSize(defaultGifSize);
    label->setMovie(movie);
    movie->start();

    return movie;
}

QMovie *create(const QString &fileName, QLabel *label, const int size)
{
    QSize gifScaleSize(size, size);

    return create(fileName, label, &gifScaleSize);
}

}
}
