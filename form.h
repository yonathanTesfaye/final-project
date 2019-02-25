#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QWebEngineView>
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:

    QWebEngineView *view;
    //QWebEngineView *view;
    explicit Form(QWidget *parent = 0);
    ~Form();
private:
    Ui::Form *ui;
};

#endif // FORM_H
