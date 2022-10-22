#include "FileManipulation.h"

FileManipulation::FileManipulation()
{}

vector<string> FileManipulation::splitstr(string st,char delim)
{
    stringstream inflow(st);
    string segment;
    vector<string> segmentlist;

    while(getline(inflow, segment, delim))
    {
       segmentlist.push_back(segment);
    }

    return segmentlist;

}

bool    FileManipulation::readFromFile()
{

    int tmpint;
    bool ret = false;
    string line,tmpstr;
    vector<string> vs1,vs2,vs3;
    ifstream myfile ("example.txt");
    StudentGrades *sgp;

    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            vs1 = this->splitstr(line,'|');
            if(vs1.size() > 0) {
                sgp = new StudentGrades();
                for(int i=0;i<vs1.size(); i++) {
                    vs2 = this->splitstr(vs1.at(i),':');
                    if(vs2.at(0) == "Student") {
                        sgp->setName(vs2.at(1));
                    }
                    if(vs2.at(0) == "FacultyNumber") {
                       istringstream convert(vs2.at(1));
                       convert >> tmpint;
                       sgp->setFacNum(tmpint);
                    }
                    if(vs2.at(0) == "GroupNumber") {
                        sgp->setGrpNum(stoi(vs2.at(1)));
                    }
                    if(vs2.at(0) == "YearOfStudy") {
                       istringstream convert(vs2.at(1));
                       convert >> tmpint;
                       sgp->setCourse(tmpint);
                    }
                    if(vs2.at(0) == "Grades") {
                       vs3 = this->splitstr(vs2.at(1),' ');
                       for(int y=0;y<vs3.size(); y++) {
                           stringstream convert(vs3.at(y));
                           convert >> tmpint;
                           sgp->addElement(tmpint);
                       }
                    }
                }
                this->_liststudents.push_back(sgp);
            }
        }
        myfile.close();
        ret = true;

    }

    return ret;
}

bool    FileManipulation::saveToFile()
{
    string st;
    StudentGrades *sgp;
    bool ret = false;
    ofstream myfile ("example.txt");
    if (myfile.is_open()) {
        myfile.clear();
        for(int i=0; i < this->_liststudents.size(); i++) {
            sgp = this->_liststudents.at(i);
            myfile << sgp->saveInfoToFile();
        }
        myfile.flush();
        myfile.close();
        ret = true;
    }
    return ret;
}

void FileManipulation::addStudent(StudentGrades *pt){
     _liststudents.push_back(pt);
    cout << "Added new student";

}

StudentGrades* FileManipulation:: getStudentByName(string name){
    StudentGrades *rpt;

    for(int i  = 0; i<_liststudents.size(); i++){
        rpt = this->_liststudents.at(i);
        if(rpt->getName()== name){
            return rpt;
        }
    }
    return nullptr;
}

int FileManipulation:: sizeOfList(){
    int ret = this->_liststudents.size();
    return ret;
}

StudentGrades* FileManipulation:: getAllStudents(int x){
    StudentGrades * rpt;
        rpt = this->_liststudents.at(x);
        return rpt;



}

StudentGrades* FileManipulation:: getStudentByFacultyNumber(int facnum){
    StudentGrades *rpt;

    for(int i  = 0; i<_liststudents.size(); i++){
        rpt = this->_liststudents.at(i);
        if(rpt->getFacNum() == facnum){
            return rpt;
        }
    }
    return nullptr;
}

StudentGrades* FileManipulation:: getGradesOfAGroup(int x){
    StudentGrades * rpt;
    rpt = this->_liststudents.at(x);
        return rpt;


}






