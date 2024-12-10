#include <FoxogramVerifyEmailModal.h>

FoxogramVerifyEmailModal::FoxogramVerifyEmailModal(QWidget* parent) : FoxogramModal(parent) {
    ui->pushButton_2->deleteLater();
    ui->pushButton->setText("Confirm");
    layout.addWidget(&input);
    layout.addWidget(&input2);
    layout.addWidget(&input3);
    layout.addWidget(&input4);
    layout.addWidget(&input5);
    layout.addWidget(&input6);
    ui->verticalLayout->addLayout(&layout);
    ui->label->setText("Check your email");
    ui->label_2->setText("fox@foxmail.com");
}