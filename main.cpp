#include "mainwindow.h"
#include <QApplication>
#include <QWebEngineView>
#include <QSplashScreen>
#include <QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *splash=new QSplashScreen;
    splash->setPixmap(QPixmap("/home/yonathan/webrowse.png"));
    splash->show();
    MainWindow w;

    QTimer::singleShot(7500, splash, SLOT(close()));
    QTimer::singleShot(7500, &w, SLOT(show()));
   // w.show();

    return a.exec();
}
