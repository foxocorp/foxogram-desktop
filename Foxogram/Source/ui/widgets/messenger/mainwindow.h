#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <foxogram/Me.h>

#include "ChatComponent.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, foxogram::Me* user = nullptr);
private:
    foxogram::Me* user;
    std::list<ChatComponent*> chatsList;
public Q_SLOTS:
    void searchFilter(const QString& s);

};
#endif // MAINWINDOW_H
