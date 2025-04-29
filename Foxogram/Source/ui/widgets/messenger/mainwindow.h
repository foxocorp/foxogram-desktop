#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <foxogram/Me.h>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, foxogram::Me* user = nullptr);
private:
    foxogram::Me* user;
};
#endif // MAINWINDOW_H
