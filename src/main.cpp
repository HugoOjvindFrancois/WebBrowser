#include <QApplication>

#include "header/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow main;

    if (argc >= 2) {
        main.loadUrl(QString(argv[1]));
    }

    main.show();

    return a.exec();
}
