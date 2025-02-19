#include "modalwidget.h"

ModalWidget::ModalWidget(QWidget *parent) : QWidget{parent} {
    setWindowModality(Qt::ApplicationModal);
}

void ModalWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Escape:
        deleteLater();
        break;
    }

    return QWidget::keyPressEvent(event);
}
