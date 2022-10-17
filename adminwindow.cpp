#include "adminwindow.h"
#include "ui_adminwindow.h"
#include<QPixmap>
#include"admin.h"
#include"QMessageBox"
adminwindow::adminwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminwindow)
{
    ui->setupUi(this);
    on_lineEdit_20_textChanged("");
    on_lineEdit_21_textChanged("");
}

adminwindow::~adminwindow()
{
    delete ui;

}

void adminwindow::on_pushButton_4_clicked()
{

}


void adminwindow::on_pushButton_13_clicked()
{
    string ID = ui->lineEdit_3->text().toStdString();
    int id = stoi(ID);
    string year = ui->lineEdit_5->text().toStdString();
    int Year = stoi(year);
    QString finshed = ui->lineEdit_6->text();
    QString progress = ui->lineEdit_2->text();
    vector<QString> finshed_cources;
    vector<QString> progress_cources;
    QString test;
    Admin ad1;
    bool exist = false;
    for (int i = 0; i < ad1.all_student.size(); i++)
    {
        if (ad1.all_student[i].id ==id )
        {
            QMessageBox::information(this,"Title" , "student is already exist");
            exist=true;
            break;
        }
     }
    if(!exist)
    {
    for(int i = 0 ; i < finshed.length(); i++){
        if(finshed[i] == ',')
        {
            finshed_cources.push_back(test);
            test = "";
        }
        else
        {
            test += finshed[i];
        }
    }
    finshed_cources.push_back(test);
    test = "";
    for(int i = 0 ; i < progress.length(); i++){
        if(progress[i] == ',')
        {
            progress_cources.push_back(test);
            test = "";
        }
        else
        {
            test += progress[i];
        }
    }
     progress_cources.push_back(test);
    bool flag1 = false;
    for(int i = 0 ; i < finshed_cources.size(); i++)
    {
        flag1 = false;
        for(int j = 0 ; j < ad1.all_courses.size(); j++)
        {
            if(finshed_cources[i] == ad1.all_courses[j].course_name)
            {
                flag1 = true;
                break;
            }
        }
    }
    bool flag2 = false;
    for(int i = 0 ; i < progress_cources.size(); i++)
    {
        flag2 = false;
        for(int j = 0 ; j < ad1.all_courses.size(); j++)
        {
            if(progress_cources[i] == ad1.all_courses[j].course_name)
            {
                flag2 = true;
                break;
            }
        }
    }
    if(flag1 && flag2)
        {
     ad1.Add_new_student(ui->lineEdit->text(), id,ui->lineEdit_4->text(), Year ,finshed_cources, progress_cources);
     QMessageBox::information(this,"Title" , "add student has done");
        }
    else if(!flag1 && !flag2){
        QMessageBox::information(this,"Title" , "finished course not exist in cources and progress course not exist in cources");
    }
    else if(!flag1){
        QMessageBox::information(this,"Title" , "finished course not exist in cources");
    }
    else if(!flag2){
        QMessageBox::information(this,"Title" , "progress course not exist in cources");
    }
    }

}


void adminwindow::on_pushButton_14_clicked()
{
     QString NameCourse = ui->lineEdit_7->text();
     QString CodeCourse = ui->lineEdit_8->text();
     string HoursCourse = ui->lineEdit_9->text().toStdString();
     int hours = stoi(HoursCourse);
     string no_student = ui->lineEdit_10->text().toStdString();
     int number = stoi(no_student);
     bool exist = false;
     vector<QString> cources_names = { "" };
     Admin s;
     for (int i = 0; i < s.all_courses.size(); i++)
     {
         if (s.all_courses[i].code == CodeCourse )
         {
             QMessageBox::information(this,"Title" , "Course is already exist");
             exist=true;
             break;
         }
      }
        if (!exist)
         {
            s.Add_new_course(NameCourse,CodeCourse,hours,number,cources_names) ;
            QMessageBox::information(this,"Title" , "add course has done");
         }

}


void adminwindow::on_pushButton_15_clicked()
{

    QString progress = ui->lineEdit_11->text();
    QString CodeCourse = ui->lineEdit_12->text();
    vector<QString> progress_cources;
    QString test;
    Admin ad1;
            for(int i = 0 ; i < progress.length(); i++)
            {
                if(progress[i] == ',')
                {
                    progress_cources.push_back(test);
                    test = "";
                }
                else
                {
                    test += progress[i];
                }
            }
            progress_cources.push_back(test);
            ad1.Enter_course_prerequisite(CodeCourse,progress_cources);
            QMessageBox::information(this,"Title" , "add course prerequisite has done");
}


void adminwindow::on_pushButton_16_clicked()
{
            QString NameCourse = ui->lineEdit_13->text();
            QString CodeCourse = ui->lineEdit_14->text();
            string HoursCourse = ui->lineEdit_15->text().toStdString();
            int hours = stoi(HoursCourse);
            string no_student = ui->lineEdit_16->text().toStdString();
            int number = stoi(no_student);
            QString progress = ui->lineEdit_17->text();
            vector<QString> progress_cources;
            QString test;
            Admin b;
            bool exist = false;
            for (int i = 0; i < b.all_courses.size(); i++)
            {
                if (b.all_courses[i].code == CodeCourse )
                {

                    exist=true;
                    break;
                }
            }
            if(exist)
            {
            for(int i = 0 ; i < progress.length(); i++)
            {
                if(progress[i] == ',')
                {
                    progress_cources.push_back(test);
                    test = "";
                }
                else
                {
                    test += progress[i];
                }
            }
            progress_cources.push_back(test);

            b.Edit_course_data(NameCourse,CodeCourse,hours,number,progress_cources);
            QMessageBox::information(this,"Title" , "Edit course has done");
            }
            else
            {
                 QMessageBox::information(this,"Title" , "Course not found");
            }


}


void adminwindow::on_pushButton_9_clicked()
{

    ui->frame_4->show();
    ui->frame_5->hide();
    ui->frame_6->hide();
    ui->frame_7->hide();
    ui->frame_8->hide();
    ui->frame_9->hide();
    ui->frame_10->hide();

}


void adminwindow::on_pushButton_10_clicked()
{
    ui->frame_4->show();
    ui->frame_5->show();
    ui->frame_6->hide();
    ui->frame_7->hide();
    ui->frame_8->hide();
    ui->frame_9->hide();
    ui->frame_10->hide();
}


void adminwindow::on_pushButton_11_clicked()
{
    ui->frame_4->show();
    ui->frame_5->show();
    ui->frame_6->show();
    ui->frame_7->hide();
    ui->frame_8->hide();
    ui->frame_9->hide();
    ui->frame_10->hide();
}


void adminwindow::on_pushButton_12_clicked()
{
    ui->frame_4->show();
    ui->frame_5->show();
    ui->frame_6->show();
    ui->frame_7->show();
    ui->frame_8->hide();
    ui->frame_9->hide();
    ui->frame_10->hide();
}



void adminwindow::on_pushButton_18_clicked()
{
    Admin a;
    vector<QString> names = a.View_students_in_a_specific_course(ui->lineEdit_18->text());
    if(names.size() == 0)
    {
        QMessageBox::information(this, "Warnning", "course not found or thier is no student has this cource");
    }
    else
    {
        ui->listWidget->clear();
        for(int i = 0 ; i < names.size(); i++)
        {
            ui->listWidget->addItem(names[i]);
        }
    }
}


void adminwindow::on_pushButton_7_clicked()
{
    ui->frame_4->show();
    ui->frame_5->show();
    ui->frame_6->show();
    ui->frame_7->show();
    ui->frame_8->show();
    ui->frame_9->hide();
    ui->frame_10->hide();
}


void adminwindow::on_pushButton_17_clicked()
{
    Admin a;
    vector<QString> cources = a.View_courses_Finished_Progressed_of_a_specific_student(ui->lineEdit_19->text());
    if(cources.size() == 0){
         QMessageBox::information(this, "Warnning", "Student not found");
    }
    else
    {
         ui->listWidget_2->clear();
        for(int i = 0 ; i < cources.size(); i++)
        {
           ui->listWidget_2->addItem(cources[i]);
        }
    }
}


void adminwindow::on_pushButton_8_clicked()
{
    ui->frame_4->show();
    ui->frame_5->show();
    ui->frame_6->show();
    ui->frame_7->show();
    ui->frame_8->show();
    ui->frame_9->show();
    ui->frame_10->hide();
}


void adminwindow::on_lineEdit_20_textChanged(const QString &arg1)
{
    Admin a;
    QString s;
    s.setNum(a.all_courses.size());
    ui->lineEdit_20->setText(s);
}


void adminwindow::on_lineEdit_21_textChanged(const QString &arg1)
{
    Admin a;
    QString s;
    s.setNum(a.all_student.size());
    ui->lineEdit_21->setText(s);
}


void adminwindow::on_pushButton_clicked()
{
    ui->frame_4->show();
    ui->frame_5->show();
    ui->frame_6->show();
    ui->frame_7->show();
    ui->frame_8->show();
    ui->frame_9->show();
    ui->frame_10->show();
}

