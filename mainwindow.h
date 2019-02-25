#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include "nexttab.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QWebEngineView *view;
    //QWebEngineView *view;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_searchButton_clicked();
    void on_urlEditButton_clicked();
    void on_back_clicked();
    void on_forward_clicked();
     void on_reload_clicked();
     void on_tabWidget_tabCloseRequested(int index);

     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    nextTab *nexttab;

};

#endif // MAINWINDOW_H
