#ifndef ADMIN_H
#define ADMIN_H
#include"student.h"
class Admin
{
public:
    QString name;
    QString password;
    static vector<Student> all_student;
    static vector<Course> all_courses;
public:
    bool logina(QString, QString);
    void Add_new_student(QString n, int h, QString c, int a, vector<QString> finish_course, vector<QString> progress_course);
    void Add_new_course(QString, QString, int, int, vector<QString>);
    void Enter_course_prerequisite(QString , vector<QString>);
    vector<QString> View_students_in_a_specific_course(QString);
    vector<QString> View_courses_Finished_Progressed_of_a_specific_student(QString);
    void Edit_course_data(QString, QString, int, int, vector<QString>);
    Admin(void);
};

#endif // ADMIN_H
