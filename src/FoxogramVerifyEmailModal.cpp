#include <FoxogramVerifyEmailModal.h>
#include <QGraphicsBlurEffect>
#include <QMoveEvent>
#include <iostream>
#include <FoxogramSignupForm.h>
#include <FoxogramMainWindow.h>

FoxogramVerifyEmailModal::FoxogramVerifyEmailModal(FoxogramSignupForm* parent) : FoxogramModal(parent) {
    resize(416, 263);
    ui->pushButton_2->deleteLater();
    ui->pushButton->setText("Confirm");
    layout.addWidget(&input);
    layout.addWidget(&input2);
    layout.addWidget(&input3);
    layout.addWidget(&input4);
    layout.addWidget(&input5);
    layout.addWidget(&input6);
    connect(&input, &DigitInput::digitInputed, &input2, &DigitInput::setFocused);
    connect(&input2, &DigitInput::digitInputed, &input3, &DigitInput::setFocused);
    connect(&input3, &DigitInput::digitInputed, &input4, &DigitInput::setFocused);
    connect(&input4, &DigitInput::digitInputed, &input5, &DigitInput::setFocused);
    connect(&input5, &DigitInput::digitInputed, &input6, &DigitInput::setFocused);
    connect(&input2, &DigitInput::digitDeleted, &input, &DigitInput::setFocused);
    connect(&input3, &DigitInput::digitDeleted, &input2, &DigitInput::setFocused);
    connect(&input4, &DigitInput::digitDeleted, &input3, &DigitInput::setFocused);
    connect(&input5, &DigitInput::digitDeleted, &input4, &DigitInput::setFocused);
    connect(&input6, &DigitInput::digitDeleted, &input5, &DigitInput::setFocused);
    ui->verticalLayout_2->insertLayout(1, &layout);
    label.setText("Time until you can resend code");
    auto font = label.font();
    font.setPointSize(10);
    label.setFont(font);
    label.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label.setFlat(true);
    label.setStyleSheet("Text-align: left");
    label.setEnabled(false);
    ui->verticalLayout_2->addWidget(&label);
    ui->gridLayout->setRowStretch(0, 16);
    ui->gridLayout->setRowStretch(1, 204);
    ui->gridLayout->setRowStretch(2, 16);
    ui->gridLayout->setColumnStretch(0, 31);
    ui->gridLayout->setColumnStretch(1, 354);
    ui->gridLayout->setColumnStretch(2, 31);
    ui->label->setText("Check your email");
    ui->label_2->setText("fox@foxmail.com");
    this->setStyleSheet("background-color: #080808;");
    setWindowOpacity(0.97);
    this->parent = parent;
}

void FoxogramVerifyEmailModal::parentMoved(QMoveEvent* event) {
    move(floor(event->pos().x()+(parent->parent->size().width()-size().width())/2.0),
         floor(event->pos().y()+(parent->parent->size().height()+23-size().height())/2.0));
}

void FoxogramVerifyEmailModal::showEvent(QShowEvent *event) {
    auto* p_blur = new QGraphicsBlurEffect;
    p_blur->setBlurRadius(15);
    p_blur->setBlurHints(QGraphicsBlurEffect::PerformanceHint);
    parent->setGraphicsEffect(p_blur);
}
