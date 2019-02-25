#ifndef NEXTTAB_H
#define NEXTTAB_H

#include <QDialog>
#include <QWebEngineView>

namespace Ui {
class nextTab;
}

class nextTab : public QDialog
{
    Q_OBJECT

public:
    QWebEngineView *view;
   explicit nextTab(QWidget *parent = 0);
    ~nextTab();
private slots:
    void on_back_clicked();
    void on_forward_clicked();
    void on_reload_clicked();
    void on_searchButton_clicked();
    void on_urlEditButton_clicked();
private:
    Ui::nextTab *ui;
};

#endif // NEXTTAB_H
