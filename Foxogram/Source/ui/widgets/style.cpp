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

namespace Messenger::Style {
    const QString leftBarWidgetStyleSheet = R"(
    #leftBarWidget {
        background-color: #1e1e1e;
    }
    )";

    const QString messengerWidgetStyleSheet = R"(
    #messengerWidget {
        background-color: #141414;
    }
    )";
    const QString chatComponentInfoLayout = R"(
    *[defaultAvatar=true] {
        image: url(:/ui/icons/messenger/avatar.svg);
    }
    #avatar {
        font: 35px;
        font-weight: 900;
    }
    #chatName {
        font: bold 16px;
    }
    #timeLabel {
        font: 14px;
        color: #616161;
    }
    #author {
        font: 16px;
        color: #b7b7b7;
    }
    #message {
        font: 16px;
        color: #818181;
    }
    )";

    const QString searchBarStyleSheet = R"(
    #searchField {
        border-radius: 10px;
        image-position: left;
        background-color: #161616;
        placeholder-text-color: #818181;
        background-image: url(:/ui/icons/messenger/magnifyingglass.svg);
        background-repeat: no-repeat;
        background-origin: content;
        background-position: left center;
        padding-left: 16px;
    }
    #createButton {
        image: url(:/ui/icons/messenger/plus.app.svg);
        background-color: #161616;
        padding: 12px;
        border: transparent;
        border-radius: 10px;
    }
    )";
}