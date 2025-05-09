#ifndef AUTHORIZATIONSERVICE_H
#define AUTHORIZATIONSERVICE_H

#include <QObject>
#include <foxogram/Me.h>

namespace AuthConstants {
extern const int minLength;

extern const int minEmailLength;
extern const int maxEmailLength;

extern const int minUsernameLength;
extern const int maxUsernameLength;

extern const int minPasswordLength;
extern const int maxPasswordLength;

extern const QRegularExpression rxEmail;
extern const QRegularExpression rxUsername;
extern const QRegularExpression rxPassword;
}

struct LoginUserData {
    QString email;
    QString password;
};

struct UserData : LoginUserData
{
    QString username;
};

class AuthorizationService : public QObject
{
    Q_OBJECT
public:
    explicit AuthorizationService(QObject *parent = nullptr, foxogram::Me* user = nullptr);

    bool requestAuthorization(LoginUserData *ud);

    bool requestEmailVerification(std::string code);

    foxogram::Me* user;
Q_SIGNALS:
    void successfulLogin();
    void successfulEmailVerification();
};

#endif // AUTHORIZATIONSERVICE_H
