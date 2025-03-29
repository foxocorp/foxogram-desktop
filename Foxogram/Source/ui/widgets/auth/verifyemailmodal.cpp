#include "verifyemailmodal.h"
#include "style.h"

#include <QKeyEvent>
#include <QClipboard>
#include <QPushButton>
#include <QLabel>

namespace Auth {
constexpr int verifyCodeLength = 6;

VerifyEmailModal::VerifyEmailModal(QWidget *parent, UserData *userData) : ModalWidget(parent)
{
    setStyleSheet(Style::verifyEmailModalStyleSheet);

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
    innerLayout->setContentsMargins(32, 20, 32  , 20);
    innerLayout->setSpacing(10);

    // Title label
    QLabel *titleLabel = new QLabel("Check your email", this);
    QFont titleFont;
    titleFont.setPointSize(26);
    titleFont.setWeight(QFont::Bold);
    titleLabel->setFont(titleFont);
    innerLayout->addWidget(titleLabel);

    // Email label
    QLabel *emailLabel = new QLabel(this);
    emailLabel->setObjectName("emailLabel");
    innerLayout->addWidget(emailLabel);

    // Digits widget
    QWidget *digitsWidget = new QWidget(this);
    digitsLayout = new QHBoxLayout(digitsWidget);
    digitsLayout->setContentsMargins(0, 0, 0, 0);
    digitsLayout->setSpacing(13);
    digitsWidget->setLayout(digitsLayout);
    innerLayout->addWidget(digitsWidget);

    // Confirm button
    QPushButton *confirmButton = new QPushButton("Confirm", this);
    confirmButton->setObjectName("confirmButton");
    QFont buttonFont;
    buttonFont.setPointSize(16);
    buttonFont.setWeight(QFont::DemiBold);
    confirmButton->setFont(buttonFont);
    confirmButton->setFocusPolicy(Qt::NoFocus);
    confirmButton->setFixedSize(352, 48);
    innerLayout->addWidget(confirmButton);

    connect(confirmButton, &QPushButton::clicked, this, [=]() {
        std::string code = "";
        for (auto& d : digits) {
               code += d->text().toStdString();
        }
        if (code.length() != verifyCodeLength) {
            return;
        }

    });

    // Resend code label
    QLabel *resendLabel = new QLabel("Time until you can resend code", this);
    innerLayout->addWidget(resendLabel);

    // Grid layout placement
    gridLayout->addItem(verticalSpacerTop, 0, 1);
    gridLayout->addWidget(innerWidget, 2, 1);
    gridLayout->addItem(verticalSpacerBottom, 3, 1);
    gridLayout->addItem(horizontalSpacerLeft, 2, 0);
    gridLayout->addItem(horizontalSpacerRight, 2, 2);

    // All tasks
    setupDigits();

    if (userData) {
        emailLabel->setText(userData->email);
    }
}

VerifyEmailModal::~VerifyEmailModal()
{
    for (auto &d : digits) {
        delete d;
    }
}

void VerifyEmailModal::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_V:
        if (event->modifiers().testFlag(Qt::ControlModifier))
            pasteFromClipboard();
        break;
    default:
        // Set 1st digit
        bool anyDigitIsFocused = false;

        for (auto &v : digits)
            if (v->hasFocus()) {
                anyDigitIsFocused = true;
                break;
            }

        if (!anyDigitIsFocused) {
            QString key = QKeySequence(event->key()).toString();
            QChar c = key.at(0);

            if (c.isDigit())
                digits[0]->setText(c);
        }
    }

    return ModalWidget::keyPressEvent(event);
}

void VerifyEmailModal::pasteFromClipboard()
{
    QClipboard *clipboard = QGuiApplication::clipboard();

    QString text = clipboard->text();

    for (auto [k, v] : digits.asKeyValueRange()) {
        if (k < text.length() && text[k].isDigit())
            v->setText(text[k]);
    }
}

void VerifyEmailModal::setupDigits()
{
    for (int i = 0; i < verifyCodeLength; ++i) {
        DigitInput *di = new DigitInput(this);
        digits.insert(i, di);
        di->setFixedSize(48, 48);
        digitsLayout->addWidget(di);
    }

    for (auto it : digits.asKeyValueRange()) {
        auto &k = it.first;
        auto &v = it.second;

        // Switching to next digit
        if (k < digits.size() - 1) {
            connect(v, &DigitInput::digitAdded, this, [=]() {
                digits[k + 1]->setFocus();
            });
        }

        // Erasing digits
        if (k > 0) {
            connect(v, &DigitInput::digitRemoved, this, [=]() {
                if (digits[k]->text().isEmpty() && (k == digits.size() - 1 || (k + 1 < digits.size() && digits[k + 1]->text().isEmpty()))) {
                    digits[k - 1]->setFocus();
                }
            });
        }

        // Move to next digit
        connect(v, &DigitInput::nextDigit, this, [=]() {
            digits[(k + 1) % digits.size()]->setFocus();
        });

        // Move to prev digit
        connect(v, &DigitInput::previousDigit, this, [=]() {
            digits[(k - 1 + digits.size()) % digits.size()]->setFocus();
        });

        // Handle keyboard insert event
        connect(v, &DigitInput::requestPaste, this, [=]() {
            pasteFromClipboard();
        });
    }
}
}
