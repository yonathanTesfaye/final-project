#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SearchPushButton_clicked()
{
    QTextEdit *DocumentTextEdit = findChild<QTextEdit*>("DocumentTextEdit");
    QLineEdit *SearchKeylineEdit = findChild<QLineEdit*>("SearchKeylineEdit");

    QString searchString = SearchKeylineEdit->text();

    QTextDocument *document = DocumentTextEdit->document();
    bool found = false;
    document->undo();

    if (searchString.isEmpty()) {
            QMessageBox::information(this, tr("Empty Search Field"),
                                     tr("The search field is empty. "
                                        "Please enter a word and click Find."));
        } else {
            QTextCursor highlightCursor(document);
            QTextCursor cursor(document);

            cursor.beginEditBlock();

            QTextCharFormat plainFormat(highlightCursor.charFormat());
            QTextCharFormat colorFormat = plainFormat;
            colorFormat.setForeground(Qt::red);

            while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
                highlightCursor = document->find(searchString, highlightCursor,
                                                 QTextDocument::FindWholeWords);

                if (!highlightCursor.isNull()) {
                    found = true;
                    highlightCursor.movePosition(QTextCursor::WordRight,
                                                 QTextCursor::KeepAnchor);
                    highlightCursor.mergeCharFormat(colorFormat);
                }
            }

            cursor.endEditBlock();
            if (found == false) {
                QMessageBox::information(this, tr("Word Not Found"),
                                         tr("Sorry, the word cannot be found."));

            }
    }
}
