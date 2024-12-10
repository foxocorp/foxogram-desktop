#pragma once
#include <QDialog>
#include <ui_FoxogramModal.h>


class FoxogramModal : public QWidget {
Q_OBJECT
public:
    explicit FoxogramModal(QWidget *parent = nullptr);

protected:
    Ui::Form* ui;
};

