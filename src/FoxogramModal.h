#pragma once
#include <QDialog>
#include "ui_FoxogramModal.h"


class FoxogramModal : public QWidget {
Q_OBJECT
public:
    explicit FoxogramModal(QWidget *parent = nullptr);
private:
    Ui::Form* ui;
};

