#ifndef STUDENTGRADES_H
#define STUDENTGRADES_H
#include "Student.h"
#include <iostream>
#include <vector>

using namespace std;

class StudentGrades : public Student{
    private:
        vector<int> dynArr;

    public:
        StudentGrades();

        void addElement(int el);
        void getDynArr();
        int sizeOfDynArr();
        string getInfo();
        string saveInfoToFile();
        double getAvgGrade();

        friend ostream &operator<<(ostream &os, const StudentGrades &sg) {
            return (os << sg.getInfo() << endl) ;
        }

        friend ostream &operator<<(ostream &os, const StudentGrades *sg) {
            return (os << sg->getInfo() << endl) ;
        }






};

#endif // STUDENTGRADES_H
