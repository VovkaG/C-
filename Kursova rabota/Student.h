#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student
{
    private:
        string name;
        int facNum;
        int grpNum;
        int course;

    public:
        Student();

        void setName(string n);
        string getName();

        void setFacNum(long long fn);
        int getFacNum();

        void setGrpNum(int gn);
        int getGrpNum();

        void setCourse(int c);
        int getCourse();



};

#endif // STUDENT_H
