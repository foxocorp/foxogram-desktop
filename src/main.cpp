#include <QApplication>
#include <FoxogramMainWindow.h>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    FoxogramMainWindow window;
    window.show();
    return app.exec();
}