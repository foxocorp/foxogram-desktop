#ifndef MODALWIDGET_H
#define MODALWIDGET_H

#include <QWidget>
#include <QKeyEvent>

class ModalWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ModalWidget(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // MODALWIDGET_H
