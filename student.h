#ifndef STUDENT_H
#define STUDENT_H

#include"course.h"

class Student
{
public:
    QString name1;
    int id;
    QString password1;
    vector <QString> finish_cources;
    vector <QString> progress_cources;
    int academic_year;
public:
    bool logins(int, QString);
    vector<QString> available_courses(int);
    vector<QString> detail_specific_course(QString);
    void Register_course(int, QString);
    vector<QString> View_all_my_courses(int);
    void Edit_my_data(QString, int, QString);
    Student(void);
};

#endif // STUDENT_H
