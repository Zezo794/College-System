#include"QFile"
#include "student.h"
#include "admin.h"
#include <QDebug>
#include<sstream>
#include<fstream>
Student::Student(void)
{
    this->name1 = "";
    this->id = 0;
    this->password1 = "";
    this->academic_year = 0;
}

bool Student::logins(int id, QString password)
{
    Admin a;
    for (int i = 0; i < a.all_student.size(); i++)
    {
        if (a.all_student[i].id == id && a.all_student[i].password1 == password)
            return true;

    }
    return false;
}



vector<QString> Student::detail_specific_course(QString name)
{
    Admin a;
    vector<QString> names;
    for (int i = 0; i < a.all_courses.size(); i++)
    {
        if (a.all_courses[i].course_name == name)
        {
            names.push_back(a.all_courses[i].course_name);
            names.push_back(a.all_courses[i].code);
            names.push_back(QString::number(a.all_courses[i].hours)) ;
            names.push_back(QString::number(a.all_courses[i].max_num_of_student)) ;
            for (int j = 0; j < a.all_courses[i].pre_cources.size(); j++)
                names.push_back(a.all_courses[i].pre_cources[j]) ;
            break;
        }
    }
    return names;
}

void Student::Register_course(int l, QString u)
{
    Admin a;
    vector<QString>s = available_courses(l);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == u)
        {
            for (int j = 0; j < a.all_student.size(); j++) {
                if (a.all_student[j].id == l) {
                    a.all_student[j].progress_cources.push_back(u);
                    QFile file("C:/Users/Zezo/Documents/student/Student.txt");
                    file.open(QFile::WriteOnly | QFile::Text);
                    file.close();
                    file.open(QFile::Append | QFile::Text);
                    if (file.isOpen()) {
                        QTextStream myfile(&file);
                        for (int n = 0; n < a.all_student.size(); n++) {
                            myfile << a.all_student[n].name1 << ",";
                            myfile << a.all_student[n].id << ",";
                            myfile << a.all_student[n].password1 << ",";
                            myfile << a.all_student[n].academic_year << ",";
                            for (int k = 0; k < a.all_student[n].finish_cources.size(); k++) {
                                myfile << a.all_student[n].finish_cources[k] << ":";
                            }
                            myfile << ",";
                            for (int k = 0; k < a.all_student[n].progress_cources.size(); k++) {
                                myfile << a.all_student[n].progress_cources[k] << "/";
                            }
                            myfile << "\n";
                        }

                        file.close();
                    }

                    break;
                }
            }
            break;
        }
    }
}



vector<QString> Student::View_all_my_courses(int id)
{
    Admin a;
    vector<QString> names;
    for (int i = 0; i < a.all_student.size(); i++)
    {
        if (a.all_student[i].id == id)
        {
            names.push_back("Finished cources");
            for (int j = 0; j < a.all_student[i].finish_cources.size(); j++)
            {

                names.push_back(a.all_student[i].finish_cources[j]);
            }
            names.push_back("progress cources");
            for (int j = 0; j < a.all_student[i].progress_cources.size(); j++)
            {
                names.push_back(a.all_student[i].progress_cources[j]);
            }
            break;
        }
    }
    return names;
}



void Student::Edit_my_data(QString n, int h, QString c)
{
    Admin a1;
    for (int i = 0; i < a1.all_student.size(); i++) {
        if (a1.all_student[i].id == h) {
            a1.all_student[i].name1 = n;
            a1.all_student[i].password1 = c;
        }
    }
    QFile file("C:/Users/Zezo/Documents/student/Student.txt");
    file.open(QFile::WriteOnly | QFile::Text);
    file.close();
    file.open(QFile::Append | QFile::Text);
    if (file.isOpen()) {
        QTextStream myfile(&file);
        for (int n = 0; n < a1.all_student.size(); n++) {
            myfile << a1.all_student[n].name1 << ",";
            myfile << a1.all_student[n].id << ",";
            myfile << a1.all_student[n].password1 << ",";
            myfile << a1.all_student[n].academic_year << ",";
            for (int k = 0; k < a1.all_student[n].finish_cources.size(); k++) {
                myfile << a1.all_student[n].finish_cources[k] << ":";
            }
            myfile << ",";
            for (int k = 0; k < a1.all_student[n].progress_cources.size(); k++) {
                myfile << a1.all_student[n].progress_cources[k] << "/";
            }
            myfile << "\n";
        }
        file.close();
    }
}

vector<QString>Student::available_courses(int Id)
{
    Admin a1;
    vector<QString>availablecourses;
    for (int i = 0; i < a1.all_student.size(); i++)
    {
        if (a1.all_student[i].id == Id)
        {

            bool flag1 = false;
            bool flag2 = true;
            for (int k = 0; k < a1.all_courses.size(); k++)
            {
                flag2 = true;
                for (int q = 0; q < a1.all_student[i].finish_cources.size(); q++)
                {
                    if (a1.all_student[i].finish_cources[q] == a1.all_courses[k].course_name)
                    {
                        flag2 = false;
                        break;
                    }
                }

                for (int q = 0; q < a1.all_student[i].progress_cources.size(); q++)
                {
                    if (a1.all_student[i].progress_cources[q] == a1.all_courses[k].course_name)
                    {
                        flag2 = false;
                        break;
                    }

                }


                int t = 0;
                for (int z = 0; z < a1.all_student.size(); z++)
                {
                    for (int s = 0; s < a1.all_student[z].progress_cources.size(); s++)
                    {
                        if (a1.all_student[z].progress_cources[s] == a1.all_courses[k].course_name)
                            t++;
                    }

                }

                if (a1.all_courses[k].max_num_of_student <= t)
                    flag2 = false;

                if (flag2 == false)
                    continue;

                int l = a1.all_courses[k].pre_cources.size();
                int o = a1.all_student[i].finish_cources.size();
                for (int p = 0; p < l; p++)
                {
                    flag1 = false;

                    for (int e = 0; e < o; e++)
                    {
                        if (a1.all_courses[k].pre_cources[p] == a1.all_student[i].finish_cources[e])
                        {
                            flag1 = true;
                            break;
                        }

                    }
                    if (flag1 == false)
                        break;
                }
                if (flag1 == true)
                {
                    qDebug() << a1.all_courses[k].course_name;
                    availablecourses.push_back(a1.all_courses[k].course_name);
                }

            }

            break;
        }

    }
    return availablecourses;
}

