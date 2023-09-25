/*
Ryan King
2385162
Ryanking@chapman.edu
CPSC-350-02
Programming Assignment 5: The GOAT
Description: This is the header file for the faculty class. It defines the methods and variables used in the faculty class.
*/

#ifndef FACULTY_H
#define FACULTY_H
#include <string>
#include "DblList.h"
using namespace std;

class Faculty{
public:
    int facultyId;
    string facultyName;
    string facultyLevel; // (lecturer, assistant, prof, associate prof, etc.)
    string facultyDepartment;
    //list;
    int studentAdvisorId; // contains Faculty ID of student's advisor
    DblList<int> studentIdsList;

    Faculty();
    Faculty(int ID, string name, string level, string department, DblList<int> studentIds); // add list to this
    ~Faculty();
    void print();
    int getFacultyID();
    string getFacultyName();
    string getFacultyLevel();
    string getFacultyDepartment();
    DblList<int> getStudentIdList();
    friend bool operator==(Faculty f1, Faculty f2);
    friend bool operator>(Faculty f1, Faculty f2);
    friend bool operator<(Faculty f1, Faculty f2);
    
};
#endif