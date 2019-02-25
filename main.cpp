#include "mainwindow.h"
#include <QApplication>
#include <iostream>
int main(int argc, char *argv[])
{
    qputenv("QT_AUTO_SCREEN_SCALE_FACTOR","1");
    qputenv("QT_SCREEN_SCALE_FACTORS","1");
    qputenv("QT_SCALE_FACTOR","1");

    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
