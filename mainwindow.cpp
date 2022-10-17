#include "mainwindow.h"
#include"adminwindow.h"
#include"ui_adminwindow.h"
#include "./ui_mainwindow.h"
#include"admin.h"
#include"studentwindow.h"
#include"ui_studentwindow.h"
#include"QMessageBox"
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Zezo/Documents/student/img/back ground .png");

//    ui->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Admin a;
    Student s;
    QString text1 = ui->lineEdit_2->text();
    QString text2 =  ui->lineEdit->text();

    if(!a.logina(text1, text2))
    {
        string text3 = ui->lineEdit_2->text().toStdString();
        int id = stoi(text3);
        if(s.logins(id, text2))
        {
            studentw = new StudentWindow(this, id);
            studentw->show();
            hide();
        }

        else{
            QMessageBox::warning(this, "Title", "user name or password unvalid");
        }
    }
    else{
        adminw= new adminwindow(this);
        adminw->show();
        hide();
    }

}

