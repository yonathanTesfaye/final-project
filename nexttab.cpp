#include "nexttab.h"
#include "ui_nexttab.h"
#include <QWebEngineView>

nextTab::nextTab(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nextTab)
{
    ui->setupUi(this);
   view = new QWebEngineView(this);
        view->setMaximumSize(200,100);
        view->setMinimumSize(1300,680);
        view->load(QUrl("http://google.com" ));
      view->show();
}

nextTab::~nextTab()
{
    delete ui;
}

void nextTab::on_searchButton_clicked()
{
    view->load(QUrl(ui->urlEditButton->text()));
}
void nextTab::on_urlEditButton_clicked()
{
    view->load(QUrl(ui->urlEditButton->text()));

}
void nextTab::on_back_clicked()
{
    view->back();
}

void nextTab::on_forward_clicked()
{
    view->forward();
}

void nextTab::on_reload_clicked()
{
    view->reload();
}
