#include <foxogram/Me.h>
#include <QMainWindow>
#include "ui_FoxogramLogin.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QMainWindow window;
    Ui::Form ui;
    ui.setupUi(&window);
    window.show();
    return app.exec();
}