#include <QApplication>
#include <FoxogramMainWindow.h>

int main(int argc, char* argv[]) {
    Q_INIT_RESOURCE(assets);
    QApplication app(argc, argv);
    FoxogramMainWindow window;
    window.show();
    return app.exec();
}