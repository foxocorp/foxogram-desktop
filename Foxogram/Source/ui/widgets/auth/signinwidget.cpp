#include "signinwidget.h"
#include "style.h"

namespace Auth {
SignInWidget::SignInWidget(AuthWidget *parent) : SignWidgetAbstract(parent)
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

    QLabel *loginLabel = new QLabel("Log in");
    QFont loginFont;
    loginFont.setPointSize(28);
    loginFont.setBold(true);
    loginLabel->setFont(loginFont);
    mainLayout->addWidget(loginLabel);

    // Email
    QVBoxLayout *emailLayout = new QVBoxLayout();
    emailLabel = new FieldLabel("Email");
    emailLayout->addWidget(emailLabel);

    emailInput = new QLineEdit();
    QFont inputFont;
    inputFont.setPointSize(12);
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

    // Login
    loginButton = new QPushButton("Log in");
    QFont buttonFont;
    buttonFont.setPointSize(12);
    buttonFont.setWeight(QFont::DemiBold);
    loginButton->setFont(buttonFont);
    loginButton->setFocusPolicy(Qt::NoFocus);
    loginButton->setObjectName("whiteButton");
    loginButton->setProperty("name", "login");
    mainLayout->addWidget(loginButton);

    // Separator
    QFrame* hFrame = new QFrame;
    hFrame->setFrameShape(QFrame::HLine);
    hFrame->setObjectName("separator");
    mainLayout->addWidget(hFrame);

    // Reset password
    resetPasswordButton = new QPushButton("Reset your password");
    resetPasswordButton->setFont(buttonFont);
    resetPasswordButton->setFocusPolicy(Qt::NoFocus);
    resetPasswordButton->setObjectName("trButton");
    resetPasswordButton->setProperty("name", "reset");
    mainLayout->addWidget(resetPasswordButton);

    // Create account
    createAccountButton = new QPushButton("Create new account");
    createAccountButton->setFont(buttonFont);
    createAccountButton->setFocusPolicy(Qt::NoFocus);
    createAccountButton->setObjectName("trButton");
    createAccountButton->setProperty("name", "create");
    mainLayout->addWidget(createAccountButton);

    // Add to layout
    gridLayout->addLayout(mainLayout, 1, 1);

    // Slots
    connect(createAccountButton, &QPushButton::clicked, parent, &AuthWidget::switchToSignUp);
    connect(resetPasswordButton, &QPushButton::clicked, this, &SignInWidget::passwordResetRequested);

    connect(loginButton, &QPushButton::clicked, this, [=] {
        LoginUserData ud;

        ud.email = emailInput->text();
        ud.password = passwordInput->text();

        parent->authService->requestAuthorization(&ud);
    });

    SignInWidget::setupFieldsLimitations();
    SignInWidget::connectValidatorsToFields();
}

SignInWidget::~SignInWidget() = default;

void SignInWidget::setupFieldsLimitations()
{
    emailInput->setMaxLength(AuthConstants::maxEmailLength);
    emailInput->setValidator(new QRegularExpressionValidator(AuthConstants::rxEmail));

    passwordInput->setMaxLength(AuthConstants::maxPasswordLength);
    passwordInput->setValidator(new QRegularExpressionValidator(AuthConstants::rxPassword));
    passwordInput->setEchoMode(QLineEdit::EchoMode::Password);
}

void SignInWidget::connectValidatorsToFields()
{
    connect(emailInput, &QLineEdit::textChanged, this, [=] {
        setValidatableFieldState(emailLabel, emailInput, emailInput->hasAcceptableInput());
    });

    connect(passwordInput, &QLineEdit::textChanged, this, [=] {
        setValidatableFieldState(passwordLabel, passwordInput, passwordInput->hasAcceptableInput());
    });
}
}
