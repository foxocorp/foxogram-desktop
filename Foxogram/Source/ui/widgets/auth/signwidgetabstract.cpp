#include "signwidgetabstract.h"

namespace Auth {

namespace Field {
namespace Label {
inline const QString incorrectType = "— некорректный формат";
}

namespace Edit {
inline const QString cStyle = R"(
QLineEdit {
padding: 10;
border: 1px solid #424242;
border-radius: 5;
background-color: #070707;
color: #FFFFFF;
placeholder-text-color: #616161;
}

QLineEdit[state="true"] { border: 1px solid #424242; }
QLineEdit[state="false"] { border: 1px solid #A53F3F; }
)";
}
}

SignWidgetAbstract::SignWidgetAbstract(AuthWidget *parent) : QWidget(parent) {
    setWindowModality(Qt::NonModal);
    setGeometry(0, 0, 900, 700);
    setMinimumSize(500, 500);
}

void SignWidgetAbstract::setValidatableFieldState(FieldLabel *label, QLineEdit *field, bool state)
{
    label->setErrorText(state ? "" : Field::Label::incorrectType);

    field->setProperty("state", state);
    field->setStyleSheet(Field::Edit::cStyle);
}
}
