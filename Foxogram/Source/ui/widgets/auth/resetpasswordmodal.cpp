#include "resetpasswordmodal.h"
#include "style.h"

#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

namespace Auth {
ResetPasswordModal::ResetPasswordModal(QWidget *parent) : ModalWidget{parent} {
    setStyleSheet(Style::resetPasswordModalStyleSheet);

    // Main layout
    QGridLayout *gridLayout = new QGridLayout(this);
    gridLayout->setContentsMargins(0, 0, 0, 0);

    // Vertical spacers
    QSpacerItem *verticalSpacerTop = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QSpacerItem *verticalSpacerBottom = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    // Horizontal spacers
    QSpacerItem *horizontalSpacerLeft = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QSpacerItem *horizontalSpacerRight = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    // Inner widget
    QWidget *innerWidget = new QWidget(this);
    innerWidget->setObjectName("innerWidget");
    QVBoxLayout *innerLayout = new QVBoxLayout(innerWidget);
    innerLayout->setContentsMargins(32, 20, 32, 20);
    innerLayout->setSpacing(10);

    // Title label
    QLabel *titleLabel = new QLabel("Reset password", this);
    QFont titleFont;
    titleFont.setPointSize(26);
    titleFont.setWeight(QFont::Bold);
    titleLabel->setFont(titleFont);
    innerLayout->addWidget(titleLabel);

    // Email label
    QLabel *hintLabel = new QLabel(this);
    hintLabel->setObjectName("hintLabel");
    hintLabel->setText("Type your email to reset password");
    innerLayout->addWidget(hintLabel);

    // Email field
    QLineEdit *emailInput = new QLineEdit();
    QFont inputFont;
    inputFont.setPointSize(12);
    emailInput->setFont(inputFont);
    emailInput->setObjectName("textInput");
    emailInput->setPlaceholderText("floofer@coof.fox");
    emailInput->setFixedSize(352, 48);
    emailInput->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    innerLayout->addWidget(emailInput);

    innerLayout->addSpacing(5);

    // Confirm button
    QPushButton *confirmButton = new QPushButton("Continue", this);
    confirmButton->setObjectName("continueButton");
    QFont buttonFont;
    buttonFont.setPointSize(16);
    buttonFont.setWeight(QFont::DemiBold);
    confirmButton->setFont(buttonFont);
    confirmButton->setFocusPolicy(Qt::NoFocus);
    confirmButton->setFixedSize(352, 48);
    innerLayout->addWidget(confirmButton);

    // Grid layout placement
    gridLayout->addItem(verticalSpacerTop, 0, 1);
    gridLayout->addWidget(innerWidget, 2, 1);
    gridLayout->addItem(verticalSpacerBottom, 3, 1);
    gridLayout->addItem(horizontalSpacerLeft, 2, 0);
    gridLayout->addItem(horizontalSpacerRight, 2, 2);
}
}
