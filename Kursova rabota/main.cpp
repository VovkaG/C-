#include "StudentGrades.h"
#include "Student.h"
#include "FileManipulation.h"

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;


void InsertNewStudent(FileManipulation* fmp, StudentGrades* workp);
void AvarageGradeOfEveryStudent(FileManipulation* fmp, StudentGrades* stp);
void MaxAvarageGradeByGroup(FileManipulation* fmp, StudentGrades* workp);
void InformationAboutAStudentByName(FileManipulation* fmp, StudentGrades* workp);
void InformationAboutAStudentByFacultyNumber(FileManipulation* fmp, StudentGrades* workp);
void ShowAllStudents(FileManipulation* fmp, StudentGrades* workp);

int main()
{
    FileManipulation* fmp;
    fmp = new FileManipulation();
    StudentGrades* workp;

    fmp->readFromFile();

    int choice; //while

    while (choice != 8){
    cout << "\n---------------------------------------------------------" << endl;
    cout << "|           Choose one of the following:                |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "| 1 | - Insert new student                              |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "| 2 | - Avarage grade of every student                  |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "| 3 | - Max avarage grade by group                      |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "| 4 | - Information about a student by name             |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "| 5 | - Information about a student by faculty number   |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "| 6 | - Show all students                               |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "| 7 | - Save File                                       |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "| 8 | - Exit                                            |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "Your choice -> ";
    cin >> choice;

        switch(choice){
        case 1:
            InsertNewStudent(fmp, workp);
            break;
        case 2:
            AvarageGradeOfEveryStudent( fmp,  workp);
            break;
        case 3:
            MaxAvarageGradeByGroup(fmp, workp);
            break;
        case 4:
            InformationAboutAStudentByName(fmp, workp);
            break;
        case 5:
            InformationAboutAStudentByFacultyNumber(fmp, workp);
            break;
        case 6:
            ShowAllStudents(fmp,workp);
            break;
        case 7:
            fmp->saveToFile();
            if(fmp->saveToFile()){
                cout << "File Saved!";
            }
            break;
        case 8:
            cout << "Goodbye!";
            break;
        default:
            cout << "Error. Enter valid option!";
        }
    }
}


void ShowAllStudents(FileManipulation* fmp, StudentGrades* workp){
            cout << "\n----Show all students---\n\n" ;
            for(int i = 0; i< fmp->sizeOfList(); i++){
                workp = fmp->getAllStudents(i);
                cout << workp << endl;
            }
}


void InformationAboutAStudentByFacultyNumber(FileManipulation* fmp, StudentGrades* workp){
            cout << "\n----Information about a student by faculty number---\n" ;
            int input;
            cout<< "Enter faculty number:";
            cin >> input;
            workp = fmp->getStudentByFacultyNumber(input);
            if(workp == nullptr){
                cout << "There is no student with this faculty number!" << endl;
            }else{

                cout << workp;
            }

}


void InformationAboutAStudentByName(FileManipulation* fmp, StudentGrades* workp){
            cout << "\n----Information about a student by name---\n" ;
            cout << "Enter name:";
            string name1, name2;
            cin >> name1;
            cin >> name2;
            name1 = name1 + " " + name2;
            workp = fmp->getStudentByName(name1);
            if(workp != nullptr){
                cout << workp;
            }else {
                cout << "There is no student with such name!";
            }
}


void MaxAvarageGradeByGroup(FileManipulation* fmp, StudentGrades* workp){
            cout << "\n----Avarage grade by group---\n" ;
            cout << "Enter group:";
            double sum = 0, avarageGrade = 0;
            int count = 0;
            int grpn = 0;
            double hold = 0;
            double maxAvgGrade = 0;
            bool result = false;
            cin >> grpn;
            for(int i = 0; i < fmp->sizeOfList(); i++){
                workp=fmp->getGradesOfAGroup(i);
                    if(workp->getGrpNum() == grpn){
                        hold = workp->getAvgGrade();
                        result = true;
                        if(maxAvgGrade < hold){
                            maxAvgGrade = hold;
                        }
                    }
            }
            if(result == true){
                cout << "The Max Avarage grade for group " << grpn << " is : " << maxAvgGrade;
            }else{
                cout << "There is no such group!";
            }
}


void AvarageGradeOfEveryStudent(FileManipulation* fmp, StudentGrades* workp){
            cout << "\n----Avarage grade of every student---\n" ;
            double sum = 0, avarageGrade = 0;
            int count = 0;

            for(int i = 0; i< fmp->sizeOfList(); i++){
                workp = fmp->getAllStudents(i);
                avarageGrade = workp->getAvgGrade();
                cout << "Student: " << workp->getName() << " | Avarage grade: " << avarageGrade << endl;
                sum = 0;
                count = 0;
            }


}


void InsertNewStudent(FileManipulation* fmp, StudentGrades* workp){

            StudentGrades *sgp;
            sgp = new StudentGrades();
            string  n1, n2;

            int gn, c, element;
            long long fn = 0;
            cout << "----Insert new student---\n" ;
            cout << "Enter 2 names:";
            cin >> n1;
            cin >> n2;
            n1 = n1 + " " + n2;
            sgp->setName(n1);

            cout<< "Enter Faculty Number:";
            cin >> fn;
            sgp->setFacNum(fn);

            cout << "Enter Group Number:";
            cin >> gn;
            sgp->setGrpNum(gn);

            do{
            cout <<"Enter course: ";
                cin >> c;
                if(c>6 || c==0){cout << "Enter valid course (1 - 6)!" << endl;}
            }while( c > 6 || c ==0);
            sgp->setCourse(c);

            int s = sgp->getCourse()*2*5;
            cout << "You have to add " << s << " grades (One year has 2 semesters with 5 grades each)  Enter Grades:\n";
            for(int i = 0; i< s;i++){
                cout << "Grade "<< i+1 << " :";
                cin >> element;
                sgp->addElement(element);
            }

            fmp->addStudent(sgp);

}
