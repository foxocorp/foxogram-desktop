#pragma once

#include <QPushButton>

class IconButton : public QPushButton {
public:
    void resizeEvent(QResizeEvent*) override;
    explicit IconButton(QWidget* = nullptr);
};
