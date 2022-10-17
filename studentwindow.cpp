#include "studentwindow.h"
#include "ui_studentwindow.h"
#include"admin.h"
StudentWindow::StudentWindow(QWidget *parent,int i) :
    QDialog(parent),
    ui(new Ui::StudentWindow)
{
    id = i;
    QString ID = QString::number(i);
    ui->setupUi(this);
    ui->lineEdit->setText(ID);
    ui->lineEdit->setReadOnly(true);
    on_lineEdit_7_textChanged("");
    on_lineEdit_8_textChanged("");
    on_lineEdit_9_textChanged("");
    on_lineEdit_10_textChanged("");
}

StudentWindow::~StudentWindow()
{
    delete ui;
}

void StudentWindow::on_pushButton_7_clicked()
{
    Student s;
    string id = ui->lineEdit->text().toStdString();
    int ID = stoi(id);
    s.Edit_my_data(ui->lineEdit_2->text(),ID,ui->lineEdit_3->text());
}


void StudentWindow::on_pushButton_10_clicked()
{
    ui->frame_4->show();
    ui->frame_5->show();
    ui->frame_6->hide();
    ui->frame_7->hide();
    ui->frame_8->hide();
    Student s;
    vector<QString>available=s.available_courses(id);
    for(int i = 0 ; i < s.available_courses(id).size(); i++)
    {
        ui->comboBox->addItem(available[i]);
    }


}


void StudentWindow::on_pushButton_11_clicked()
{
    Student s;
    s.Register_course(id,ui->comboBox->currentText());
}


void StudentWindow::on_pushButton_9_clicked()
{
    ui->frame_4->show();
    ui->frame_5->hide();
    ui->frame_6->hide();
    ui->frame_7->hide();
    ui->frame_8->hide();
    QString ID = QString::number(id);
    ui->lineEdit->setText(ID);
}


void StudentWindow::on_pushButton_13_clicked()
{
    ui->frame_4->show();
    ui->frame_5->show();
    ui->frame_6->show();
    ui->frame_7->hide();
    ui->frame_8->hide();
    Student s;
    vector<QString> names = s.View_all_my_courses(id);
    ui->listWidget->clear();
    for(int i=0;i<names.size();i++)
    {
        ui->listWidget->addItem(names[i]);
    }
}


void StudentWindow::on_pushButton_14_clicked()
{
    Admin a;
    ui->frame_4->show();
    ui->frame_5->show();
    ui->frame_6->show();
    ui->frame_7->show();
    ui->frame_8->hide();
    ui->comboBox_2->clear();
    for(int i=0;i<a.all_courses.size();i++)
    {
        ui->comboBox_2->addItem(a.all_courses[i].course_name);
    }

}


void StudentWindow::on_pushButton_8_clicked()
{
    Student s1;
    vector<QString> names = s1.detail_specific_course(ui->comboBox_2->currentText());
    ui->lineEdit_4->setText(names[1]);
    ui->lineEdit_5->setText(names[2]);
    ui->lineEdit_6->setText(names[3]);
    ui->lineEdit->clear();
    for(int i = 4 ; i < names.size(); i++){
        ui->listWidget_2->addItem(names[i]);
    }
}


void StudentWindow::on_lineEdit_7_textChanged(const QString &arg1)
{
    Admin a;
    for(int i=0;i<a.all_student.size();i++)
    {
        if(a.all_student[i].id==id)
        {
            ui->lineEdit_7->setText(a.all_student[i].name1);
            break;
        }
    }
}


void StudentWindow::on_lineEdit_8_textChanged(const QString &arg1)
{
    ui->lineEdit_8->setText(QString::number(id));
}


void StudentWindow::on_lineEdit_9_textChanged(const QString &arg1)
{
    Admin a;
    for(int i=0;i<a.all_student.size();i++)
    {
        if(a.all_student[i].id==id)
        {
            ui->lineEdit_9->setText(a.all_student[i].password1);
            break;
        }
    }
}


void StudentWindow::on_lineEdit_10_textChanged(const QString &arg1)
{
    Admin a;
    for(int i=0;i<a.all_student.size();i++)
    {
        if(a.all_student[i].id==id)
        {
            ui->lineEdit_10->setText(QString::number(a.all_student[i].academic_year));
            break;
        }
    }
}


void StudentWindow::on_pushButton_clicked()
{
    ui->frame_4->show();
    ui->frame_5->show();
    ui->frame_6->show();
    ui->frame_7->show();
    ui->frame_8->show();
}

