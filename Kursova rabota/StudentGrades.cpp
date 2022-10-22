#include "StudentGrades.h"
#include "Student.h"
#include <iostream>
#include <string>

using namespace std;
StudentGrades::StudentGrades()
{}

void StudentGrades::addElement(int el){
    this->dynArr.push_back(el);
}

void StudentGrades::getDynArr(){
    for(int i =0; i <dynArr.size(); i++ ){

        cout << dynArr.at(i) << " ";
    }
}

int StudentGrades::sizeOfDynArr(){

    return this->dynArr.size();
}



string StudentGrades::getInfo(){
    string info = "Student: " + this->getName() + " | FacultyNumber: " + to_string(this->getFacNum()) +
    " | GroupNumber: " + to_string(this->getGrpNum()) + " | YearOfStudy: " + to_string(this->getCourse()) + " | Grades: ";

    for(int i=0; i< dynArr.size(); i++){
        info = info + to_string(this->dynArr.at(i)) + " ";
    }
    info = info + "\n";
    return info;

}

string StudentGrades::saveInfoToFile(){
    string info = "Student:" + this->getName() + "|FacultyNumber:" + to_string(this->getFacNum()) +
    "|GroupNumber:" + to_string(this->getGrpNum()) + "|YearOfStudy:" + to_string(this->getCourse()) + "|Grades:";

    for(int i=0; i< dynArr.size(); i++){
        info = info + to_string(this->dynArr.at(i)) + " ";
    }
    info = info + "\n";
    return info;

}


double StudentGrades:: getAvgGrade (){
    double avgGrade = 0;
    double sum = 0;
    int count = 0;
        for(int i = 0; i < this->dynArr.size(); i++ ){
            sum = sum + dynArr.at(i);
            count++;
        }
        avgGrade = sum / count;
    return avgGrade;
}





