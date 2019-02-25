#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"
#include <QWebEngineView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
   view = new QWebEngineView(this);
        view->setMaximumSize(200,100);
        view->setMinimumSize(1300,615);
        view->load(QUrl("http://google.com" ));
      view->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_searchButton_clicked()
{
    view->load(QUrl(ui->urlEditButton->text()));
}
void MainWindow::on_urlEditButton_clicked()
{
    view->load(QUrl(ui->urlEditButton->text()));

}




void MainWindow::on_back_clicked()
{
    view->back();
}

void MainWindow::on_forward_clicked()
{
    view->forward();
}

void MainWindow::on_reload_clicked()
{
    view->reload();
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}

void MainWindow::on_pushButton_clicked()
{
    ui->tabWidget->addTab(new Form(), QString("Tab %0"). arg (ui->tabWidget->count()+1));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);

}

void MainWindow::on_pushButton_2_clicked()
{
   /* nextTab nexttab;
    nexttab.setModal(true);
    nexttab.exec();
*/
    nexttab = new nextTab(this);
    nexttab-> show();
}
