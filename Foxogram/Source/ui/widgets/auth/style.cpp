#include "style.h"

namespace Auth::Style {
const QString controllerStyleSheet = R"(
#AuthWidget {
    background-color: #000000;
    border-image: url(:/ui/images/authorization/blue.png);
}
)";

const QString styleSheet = R"(
QLineEdit#textInput {
    padding: 10;
    border: 1px solid #424242;
    border-radius: 5;
    background-color: #070707;
    color: #FFFFFF;
    placeholder-text-color: #616161;
}


QPushButton#whiteButton {
    color: "#000000";
    text-align: left;
    padding: 10;
    background-color: #ECECEC;
    border-radius: 5;
    image-position: right;
}

QPushButton#whiteButton:hover {
    background-color: #cfcfcf;
}


QPushButton#trButton {
    border: 1px solid "#303030";
    text-align: left;
    border-radius: 5;
    padding-left: 14;
    padding-right: 14;
    padding-top: 10;
    padding-bottom: 10;
    image-position: right;
}

QPushButton#trButton:hover {
    border: 1px solid "#252525";
    color: #a2a2a2
}


QPushButton[name="login"] {
    image: url(:/ui/icons/authorization/arrow.forward.svg);
}

QPushButton[name="reset"] {
    image: url(:/ui/icons/authorization/arrow.trianglehead.counterclockwise.svg);
}

QPushButton[name="create"] {
    image: url(:/ui/icons/authorization/plus.circle.svg);
}

QPushButton[name="have_account"] {
    image: url(:/ui/icons/authorization/person.svg);
}

QFrame#separator {
    color: #a2a2a2;
}
)";

const QString verifyEmailModalStyleSheet = R"(
#innerWidget {
    background-color: rgba(10, 10, 10, 240);
    border: 1px solid grey;
    border-radius: 5px;
}

#emailLabel {
    font-size: 14pt;
    color: gray;
}

QPushButton#confirmButton {
    color: #000000;
    text-align: left;
    padding: 10px;
    background-color: #ececec;
    border-radius: 5px;
    image: url(:/ui/icons/authorization/arrow.forward.svg);
    image-position: right;
}

QPushButton#confirmButton:hover {
    background-color: #cfcfcf;
}
)";

const QString resetPasswordModalStyleSheet = R"(
#innerWidget {
    background-color: rgba(10, 10, 10, 240);
    border: 1px solid grey;
    border-radius: 5px;
}

#hintLabel {
    font-size: 14pt;
    color: gray;
}

#textInput {
    padding: 10;
    border: 1px solid #424242;
    border-radius: 5;
    background-color: #070707;
    color: #FFFFFF;
    placeholder-text-color: #616161;
}

QPushButton#continueButton {
    color: "#000000";
    text-align: left;
    padding: 10;
    background-color: #ECECEC;
    border-radius: 5;
    image-position: right;
    image: url(:/ui/icons/authorization/arrow.forward.svg);
}

QPushButton#continueButton:hover {
    background-color: #cfcfcf;
}
)";
}
