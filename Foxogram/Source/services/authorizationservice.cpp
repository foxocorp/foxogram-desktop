#include "authorizationservice.h"

#include <QRegularExpression>

#include <foxogram/exceptions.h>

namespace AuthConstants {
const int minLength = 4;

const int minEmailLength = minLength;
const int maxEmailLength = 64;

const int minUsernameLength = minLength;
const int maxUsernameLength = 32;

const int minPasswordLength = minLength;
const int maxPasswordLength = 128;

inline const QRegularExpression rxEmail(R"(^[_A-Za-z0-9-+]+(\.[_A-Za-z0-9-]+)*@[A-Za-z0-9-]+(\.[A-Za-z0-9]+)*(\.[A-Za-z]{2,})$)");
inline const QRegularExpression rxUsername(R"(^[_A-Za-z0-9-.]+$)");
inline const QRegularExpression rxPassword(R"(^.{8,}$)");
}

AuthorizationService::AuthorizationService(QObject *parent, foxogram::Me* user) : QObject{parent}, user(user) {}

bool AuthorizationService::requestAuthorization(LoginUserData *ud)
{
    try {
        new (user) foxogram::Me{ud->email.toStdString(), ud->password.toStdString()};
        emit successfulLogin();
    } catch (std::exception& e) {
        qCritical() << e.what();
    }

    return false;
}
