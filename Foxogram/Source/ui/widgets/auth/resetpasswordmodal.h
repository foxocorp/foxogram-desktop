#ifndef RESETPASSWORDMODAL_H
#define RESETPASSWORDMODAL_H

#include "ui/widgets/modalwidget.h"

namespace Auth {
class ResetPasswordModal : public ModalWidget
{
    Q_OBJECT
public:
    explicit ResetPasswordModal(QWidget *parent = nullptr);

private:
};
}

#endif // RESETPASSWORDMODAL_H
