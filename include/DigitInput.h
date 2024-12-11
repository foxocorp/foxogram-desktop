#pragma once

#include <QLineEdit>

class DigitInput : public QLineEdit {
public:
    [[nodiscard]] QSize minimumSizeHint() const override;
    [[nodiscard]] QSize sizeHint() const override;
    [[nodiscard]] int heightForWidth(int w) const override;
    explicit DigitInput(QWidget* = nullptr);
};
