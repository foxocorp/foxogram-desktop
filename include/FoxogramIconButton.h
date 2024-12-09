#pragma once

#include <QPushButton>

class FoxogramIconButton : public QPushButton {
public:
    void resizeEvent(QResizeEvent*) override;
    explicit FoxogramIconButton(QWidget* = nullptr);
};
