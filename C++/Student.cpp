#include "Student.h"
#include <iostream>

using namespace std;

Student::Student()
{}



void Student::setName(string n){
    this->name = n;
}
string Student::getName(){
    return this->name;
}

void Student::setFacNum(long long fn){
    this->facNum = fn;
}
int Student::getFacNum(){
    return this->facNum;
}

void Student::setGrpNum(int gn){
    this->grpNum = gn;
}
int Student::getGrpNum(){
    return this->grpNum;
}

void Student::setCourse(int c){
    this->course = c;
}
int Student::getCourse(){
    return this->course;
}
