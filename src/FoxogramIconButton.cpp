#include <FoxogramIconButton.h>
#include <QResizeEvent>

void FoxogramIconButton::resizeEvent(QResizeEvent* event) {
    int sqr = (event->size().width() > event->size().height()) ? event->size().height() : event->size().width();
    this->resize(sqr, sqr);
}

FoxogramIconButton::FoxogramIconButton(QWidget* parrent) : QPushButton(parrent) {
    setSizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
}