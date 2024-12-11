#pragma once

#include <QLineEdit>

class DigitInput : public QLineEdit {
public:
    [[nodiscard]] QSize minimumSizeHint() const override;
    explicit DigitInput(QWidget* = nullptr);
};
