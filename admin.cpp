#include"admin.h"
#include "ui_adminwindow.h"
#include "adminwindow.h"
#include"QFile"
#include<QTextStream>
#include"QString"
#include <QDebug>
#include"QMessageBox"
vector<Course> Admin::all_courses = {};
vector<Student> Admin::all_student = {};


bool Admin::logina(QString name, QString password)
{
    if (name == "admin" && password == "admin") {
        return true;
    }
    else {
        return false;
    }
}

void Admin::Add_new_student(QString n, int h, QString c, int a, vector<QString> finish_course, vector<QString> progress_course)
{


        QFile file("C:/Users/Zezo/Documents/student/Student.txt");
        file.open(QFile::Append | QFile::Text);
        Student s;
        s.name1 = n;
        s.id = h;
        s.password1 = c;
        s.academic_year = a;
        s.finish_cources = finish_course;
        s.progress_cources = progress_course;
        if (file.isOpen())
        {
            QTextStream myfile(&file);
            myfile << n << "," << h << "," << c << "," << a << ",";
            for (int i = 0; i < finish_course.size(); i++)
            {
                myfile << finish_course[i] << ":";
            }
            myfile << ",";
            for (int i = 0; i < progress_course.size(); i++)
            {
                myfile << progress_course[i] << "/";
            }
            myfile << "\n";
            all_student.push_back(s);
            file.close();
        }


}

void Admin::Add_new_course(QString n, QString c, int h, int m, vector<QString> cources_names)
{


        QFile file2("C:/Users/Zezo/Documents/student/Course.txt");
        file2.open(QFile::Append | QFile::Text);
        Course s;
        s.course_name = n;
        s.code = c;
        s.hours = h;
        s.max_num_of_student = m;
        s.pre_cources = cources_names;
        if (file2.isOpen()) {
             QTextStream myfile(&file2);
            myfile << n << "," << c << "," << h << "," << m << ",";
            for (int i = 0; i < cources_names.size(); i++) {
                myfile << cources_names[i] << ":";
            }
            myfile << "\n";
            all_courses.push_back(s);
            file2.close();
        }

}

vector<QString> Admin::View_students_in_a_specific_course(QString c)
{
    vector<QString> stu_names;
    bool exist = false;
    for (int i = 0; i < all_courses.size(); i++)
    {
        if (all_courses[i].course_name == c)
        {
            exist = true;
            break;
        }
    }
    if (exist) {
        bool student_exist = false;
        for (int i = 0; i < all_student.size(); i++)
        {
            for (int j = 0; j < all_student[i].progress_cources.size(); j++)
            {
                if (all_student[i].progress_cources[j] == c) {
                    stu_names.push_back(all_student[i].name1);
                    student_exist = true;
                    break;
                }
            }
        }
        if (!student_exist)

            cout << "there is no student has this course" << endl;
    }
    else {
        cout << "course not found" << endl;
    }
    return stu_names;
}

vector<QString> Admin::View_courses_Finished_Progressed_of_a_specific_student(QString n)
{
    vector<QString> cources;
    bool student_exist = false;
    for (int i = 0; i < all_student.size(); i++)
    {
        if (all_student[i].name1 == n)
        {
            student_exist = true;
            cources.push_back("Fineshed cources");
            for (int j = 0; j < all_student[i].progress_cources.size(); j++)
                cources.push_back(all_student[i].progress_cources[j]);

            cources.push_back("progress cources");
            for (int j = 0; j < all_student[i].finish_cources.size(); j++)
                cources.push_back(all_student[i].finish_cources[j]);
        }
    }
    if (!student_exist)
        cout << " Name is wronge or there is no student has this name" << endl;

    return cources;
}

void Admin::Edit_course_data(QString n, QString c, int h, int m, vector<QString> cources_names)
{
    for (int i = 0; i < all_courses.size(); i++) {
        if (all_courses[i].code == c) {
            all_courses[i].course_name = n;
            all_courses[i].code = c;
            all_courses[i].hours = h;
            all_courses[i].max_num_of_student = m;
            all_courses[i].pre_cources = cources_names;
            cout << "Edit has done";
        }
    }
    QFile file3("C:/Users/Zezo/Documents/student/Course.txt");
    file3.open(QFile::WriteOnly | QFile::Text);
    file3.close();
    file3.open(QFile::Append | QFile::Text);
    if (file3.isOpen()) {
        for (int i = 0; i < all_courses.size(); i++)
        {
            QTextStream myfile(&file3);
            myfile << all_courses[i].course_name << ",";
            myfile << all_courses[i].code << ",";
            myfile << all_courses[i].hours << ",";
            myfile << all_courses[i].max_num_of_student << ",";
            for (int k = 0; k < all_courses[i].pre_cources.size(); k++) {
                myfile << all_courses[i].pre_cources[k] << ":";
            }
            myfile << "\n";
        }
        file3.close();
    }
}

Admin::Admin(void)
{
    this->name = "Ahmed";
    this->password = "1234";
    all_courses.clear();
    all_student.clear();

    QFile file4("C:/Users/Zezo/Documents/student/Student.txt");
    file4.open(QFile::ReadOnly | QFile::Text);
    QTextStream myfile(&file4);
    QString line;
    if (file4.isOpen()) {
        while (!file4.atEnd())
        {
            Student s1;
            QString line = file4.readLine();
            QStringList list = line.split(",");

            s1.name1 = list[0];

            s1.id = list[1].toInt();

            s1.password1 = list[2];
            s1.academic_year = list[3].toInt();

            QString finsh_cources = list[4];
            QStringList finshcources = finsh_cources.split(":");
            for(int i = 0 ; i < finshcources.length() - 1 ; i++) {
                s1.finish_cources.push_back(finshcources[i]);
            }
            QString progress_courses = list[5];
            QStringList progresscourses = progress_courses.split("/");
            for(int i = 0 ; i < progresscourses.length() - 1 ; i++) {
                s1.progress_cources.push_back(progresscourses[i]);
            }
            all_student.push_back(s1);
        }
        file4.close();
    }

    QFile file5("C:/Users/Zezo/Documents/student/Course.txt");
    file5.open(QFile::ReadOnly | QFile::Text);
    if (file5.isOpen())
    {

        while (!file5.atEnd())
        {
            Course c1;
            QString line = file5.readLine();
            QStringList list = line.split(",");
            c1.course_name = list[0];
            c1.code = list[1];
            c1.hours = list[2].toInt();
            c1.max_num_of_student = list[3].toInt();
            QString precources = list[4];
            QStringList pre_cources = precources.split(":");
            for(int i = 0 ; i < pre_cources.length() - 1 ; i++) {
                c1.pre_cources.push_back(pre_cources[i]);
            }
            all_courses.push_back(c1);
        }
        file5.close();
    }
}
void Admin::Enter_course_prerequisite(QString code, vector<QString> cn)
{
    for (int i = 0; i < all_courses.size(); i++)
    {
        if (all_courses[i].code == code)
        {
            all_courses[i].pre_cources = cn;
            break;
        }
    }
    QFile file3("C:/Users/Zezo/Documents/student/Course.txt");
    file3.open(QFile::WriteOnly | QFile::Text);
    file3.close();
    file3.open(QFile::Append | QFile::Text);
    if (file3.isOpen()) {
        for (int i = 0; i < all_courses.size(); i++)
        {
            QTextStream myfile(&file3);
            myfile << all_courses[i].course_name << ",";
            myfile << all_courses[i].code << ",";
            myfile << all_courses[i].hours << ",";
            myfile << all_courses[i].max_num_of_student << ",";
            for (int k = 0; k < all_courses[i].pre_cources.size(); k++) {
                myfile << all_courses[i].pre_cources[k] << ":";
            }
            myfile << "\n";
        }
        file3.close();
    }
}

