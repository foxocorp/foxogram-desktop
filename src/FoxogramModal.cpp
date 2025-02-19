#include <FoxogramModal.h>

FoxogramModal::FoxogramModal(QWidget *parent) :
        QWidget(parent) {
    ui.setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
}

