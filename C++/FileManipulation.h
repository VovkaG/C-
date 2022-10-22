#ifndef FILEMANIPULATION_H
#define FILEMANIPULATION_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "studentgrades.h"
#include "Student.h"

using namespace std;

class FileManipulation
{
public:
    FileManipulation();

    void addStudent(StudentGrades *pt);
    StudentGrades* getStudentByName(string name);
    StudentGrades* getStudentByFacultyNumber(int facnum);
    int sizeOfList();
    StudentGrades* getAllStudents(int x);
    StudentGrades* getGradesOfAGroup(int x);


    bool    readFromFile();
    bool    saveToFile();
    vector<string> splitstr(string st,char delim);

protected:
    vector<StudentGrades*> _liststudents;
};

#endif // FILEMANIPULATION_H
