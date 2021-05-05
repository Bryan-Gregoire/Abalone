#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    abalone::Game game = {};

    MainWindow w(&game);
    w.show();
    return a.exec();
}
