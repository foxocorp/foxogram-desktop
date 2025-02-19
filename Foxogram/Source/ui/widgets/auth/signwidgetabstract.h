#ifndef SIGNWIDGETABSTRACT_H
#define SIGNWIDGETABSTRACT_H

#include <QWidget>
#include <QRegularExpressionValidator>
#include <QLabel>
#include <QLineEdit>

#include "authwidget.h"
#include "fieldlabel.h"

namespace Auth {

namespace Field {
namespace Label {
extern const QString titleText;
extern const QString email;
extern const QString password;
extern const QString username;
extern const QString incorrectType;
}

namespace Edit {
extern const QString cStyle;
}
}

class SignWidgetAbstract : public QWidget
{
    Q_OBJECT
public:
    explicit SignWidgetAbstract(AuthWidget *parent = nullptr);

protected:
    virtual void setupFieldsLimitations() = 0;
    virtual void connectValidatorsToFields() = 0;

    void setValidatableFieldState(FieldLabel *label, QLineEdit *field, bool state);
};
}

#endif // SIGNWIDGETABSTRACT_H
