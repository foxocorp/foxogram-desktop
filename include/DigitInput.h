#pragma once

#include <QLineEdit>

class DigitInput : public QLineEdit {
    Q_OBJECT
public:
    [[nodiscard]] QSize minimumSizeHint() const override;
    [[nodiscard]] QSize sizeHint() const override;
    [[nodiscard]] int heightForWidth(int w) const override;
    explicit DigitInput(QWidget* = nullptr);
    void keyPressEvent(QKeyEvent *event) override;
public slots:
    void setFocused();
    void backspacePressed();
    void inputChanged(QString text);
signals:
    void digitInputed();
    void digitDeleted();
};
