#include "signupwidget.h"
#include "style.h"

namespace Auth {
SignUpWidget::SignUpWidget(AuthWidget *parent) : SignWidgetAbstract(parent)
{
    setStyleSheet(Style::styleSheet);

    QGridLayout *gridLayout = new QGridLayout(this);
    gridLayout->setColumnStretch(0, 2);
    gridLayout->setColumnStretch(1, 3);
    gridLayout->setColumnStretch(2, 2);

    QSpacerItem *verticalSpacer = new QSpacerItem(20, 61, QSizePolicy::Minimum, QSizePolicy::Expanding);
    gridLayout->addItem(verticalSpacer, 0, 1);

    QSpacerItem *horizontalSpacerLeft = new QSpacerItem(182, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    gridLayout->addItem(horizontalSpacerLeft, 1, 0);

    QSpacerItem *horizontalSpacerRight = new QSpacerItem(182, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    gridLayout->addItem(horizontalSpacerRight, 1, 2);

    QSpacerItem *verticalSpacerBottom = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);
    gridLayout->addItem(verticalSpacerBottom, 2, 1);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->setSpacing(10);

    QLabel *loginLabel = new QLabel("Sign up");
    QFont loginFont;
    loginFont.setPointSize(28);
    loginFont.setBold(true);
    loginLabel->setFont(loginFont);
    mainLayout->addWidget(loginLabel);

    // Username
    QVBoxLayout *usernameLayout = new QVBoxLayout();
    usernameLabel = new FieldLabel("Username");
    usernameLayout->addWidget(usernameLabel);

    usernameInput = new QLineEdit();
    QFont inputFont;
    inputFont.setPointSize(12);
    usernameInput->setFont(inputFont);
    usernameInput->setObjectName("textInput");
    usernameInput->setPlaceholderText("floof_fox");
    usernameLayout->addWidget(usernameInput);

    mainLayout->addLayout(usernameLayout);

    // Email
    QVBoxLayout *emailLayout = new QVBoxLayout();
    emailLabel = new FieldLabel("Email");
    emailLayout->addWidget(emailLabel);

    emailInput = new QLineEdit();
    emailInput->setFont(inputFont);
    emailInput->setObjectName("textInput");
    emailInput->setPlaceholderText("floofer@coof.fox");
    emailLayout->addWidget(emailInput);

    mainLayout->addLayout(emailLayout);

    // Password
    QVBoxLayout *passwordLayout = new QVBoxLayout();
    passwordLabel = new FieldLabel("Password");
    passwordLayout->addWidget(passwordLabel);

    passwordInput = new QLineEdit();
    passwordInput->setFont(inputFont);
    passwordInput->setObjectName("textInput");
    passwordInput->setPlaceholderText("your floof password :3");
    passwordInput->setEchoMode(QLineEdit::Password);
    passwordLayout->addWidget(passwordInput);

    mainLayout->addLayout(passwordLayout);

    // Register button
    QFont buttonFont;
    buttonFont.setPointSize(12);
    buttonFont.setWeight(QFont::DemiBold);

    registerButton = new QPushButton("Register");
    registerButton->setFont(buttonFont);
    registerButton->setFocusPolicy(Qt::NoFocus);
    registerButton->setObjectName("whiteButton");
    registerButton->setProperty("name", "login");
    mainLayout->addWidget(registerButton);

    // Separator
    QFrame* hFrame = new QFrame;
    hFrame->setFrameShape(QFrame::HLine);
    hFrame->setObjectName("separator");
    mainLayout->addWidget(hFrame);

    // Have account button
    haveAccountButton = new QPushButton("Already have an account?");
    haveAccountButton->setFont(buttonFont);
    haveAccountButton->setFocusPolicy(Qt::NoFocus);
    haveAccountButton->setObjectName("trButton");
    haveAccountButton->setProperty("name", "have_account");
    mainLayout->addWidget(haveAccountButton);

    // Add to layout
    gridLayout->addLayout(mainLayout, 1, 1);

    // Slots
    connect(haveAccountButton, &QPushButton::clicked, this, [=]() {
        parent->switchToLogin();
    });

    connect(registerButton, &QPushButton::clicked, this, [=]() {
        UserData userData;

        userData.email = emailInput->text();

        emit emailConfirmationRequested(&userData);
    });

    SignUpWidget::setupFieldsLimitations();
    SignUpWidget::connectValidatorsToFields();
}

SignUpWidget::~SignUpWidget() = default;

void SignUpWidget::setupFieldsLimitations()
{
    usernameInput->setMaxLength(AuthConstants::maxUsernameLength);
    usernameInput->setValidator(new QRegularExpressionValidator(AuthConstants::rxUsername));

    emailInput->setMaxLength(AuthConstants::maxEmailLength);
    emailInput->setValidator(new QRegularExpressionValidator(AuthConstants::rxEmail));

    passwordInput->setMaxLength(AuthConstants::maxPasswordLength);
    passwordInput->setValidator(new QRegularExpressionValidator(AuthConstants::rxPassword));
    passwordInput->setEchoMode(QLineEdit::EchoMode::Password);
}

void SignUpWidget::connectValidatorsToFields()
{
    connect(usernameInput, &QLineEdit::textChanged, this, [=]() {
        setValidatableFieldState(usernameLabel, usernameInput, usernameInput->hasAcceptableInput());
    });

    connect(emailInput, &QLineEdit::textChanged, this, [=]() {
        setValidatableFieldState(emailLabel, emailInput, emailInput->hasAcceptableInput());
    });

    connect(passwordInput, &QLineEdit::textChanged, this, [=]() {
        setValidatableFieldState(passwordLabel, passwordInput, passwordInput->hasAcceptableInput());
    });
}
}
