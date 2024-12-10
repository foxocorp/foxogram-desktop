#include <IconButton.h>
#include <QResizeEvent>

void IconButton::resizeEvent(QResizeEvent* event) {
    int sqr = (event->size().width() > event->size().height()) ? event->size().height() : event->size().width();
    this->resize(sqr, sqr);
}

IconButton::IconButton(QWidget* parrent) : QPushButton(parrent) {
    setSizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
}