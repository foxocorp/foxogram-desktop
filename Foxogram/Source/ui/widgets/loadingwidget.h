#ifndef LOADINGWIDGET_H
#define LOADINGWIDGET_H

#include <QWidget>
#include <QLabel>

class LoadingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoadingWidget(QWidget *parent = nullptr);
    ~LoadingWidget();

    void proceedLoading();

Q_SIGNALS:
    void loaded();

private:
    QLabel *animLabel;
    QLabel *logoLabel;

    void makeLoadingAnimation();
};

#endif // LOADINGWIDGET_H
