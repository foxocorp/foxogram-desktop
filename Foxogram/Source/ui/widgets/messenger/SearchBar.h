#ifndef SEARCHBAR_H
#define SEARCHBAR_H

#include <qboxlayout.h>
#include <QWidget>
#include <foxogram/Me.h>

class SearchBar : public QWidget {
Q_OBJECT
public:
    explicit SearchBar(class MainWindow *parent = nullptr);
};



#endif //SEARCHBAR_H
