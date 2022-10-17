#ifndef COURSE_H
#define COURSE_H
#include<iostream>
#include <QString>
#include<vector>
using namespace std;

class Course
{
public:
    QString course_name;
    QString code;
    int max_num_of_student;
    int hours;
    vector<QString> pre_cources;

    Course(void);
};

#endif // COURSE_H
