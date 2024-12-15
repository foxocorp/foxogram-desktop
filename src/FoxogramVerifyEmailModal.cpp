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
    timeLabel.setText("<html><head/><body><p><span style=\" color:#838383;\">01:00</span></p></body></html>");
    auto font = label.font();
    font.setPointSize(10);
    label.setFont(font);
    label.setStyleSheet("Text-align: left");
    label.setOpenExternalLinks(false);
    auto layout2 = new QHBoxLayout();
    layout2->addWidget(&label);
    layout2->addItem(new QSpacerItem(20, 1, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum));
    layout2->addWidget(&timeLabel);
    ui->verticalLayout_2->addLayout(layout2);
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
    label.setTextInteractionFlags(Qt::TextBrowserInteraction);
    connect(&label, &QLabel::linkActivated, this, &FoxogramVerifyEmailModal::linkClicked);
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
    time = QTime(0, 1, 0);
    connect(&timer, &QTimer::timeout, this, &FoxogramVerifyEmailModal::timerChanged);
    timer.start(1000);
}

void FoxogramVerifyEmailModal::timerChanged() {
    if (!comparesEqual(time, QTime(0,0,0))) {
        time = time.addSecs(-1);
        timeLabel.setText("<html><head/><body><p><span style=\" color:#838383;\">" + time.toString("mm:ss") + "</span></p></body></html>");
    } else {
        timeLabel.hide();
        label.setText(R"(Didn't receive code? <a href=\"\" style="color:#4a89ff;" style="text-decoration:none">Send again</a>)");
    }
}

void FoxogramVerifyEmailModal::linkClicked() {
    parent->me->resendEmail();
    label.setText("Time until you can resend code");
    timeLabel.setText("01:00");
    timeLabel.show();
    time = QTime(0, 1, 0);
    timer.start(1000);
}
