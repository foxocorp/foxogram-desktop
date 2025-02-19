#ifndef BASESTYLE_H
#define BASESTYLE_H

#include <QObject>

// todo: move to cpp
namespace BaseStyle {
extern const QString backgroundColor = "#0A0A0A";

namespace Button {
extern const QString white = R"(
    color: "#000000";
    text-align: left;
    padding: 10;
    background-color: #ECECEC;
    border-radius: 5;
    image-position: right;
)";
}
}

#endif // BASESTYLE_H
