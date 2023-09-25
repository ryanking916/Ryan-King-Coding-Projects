/*
Ryan King
2385162
Ryanking@chapman.edu
CPSC-350-02
Programming Assignment 5: The GOAT
Description: This is the header file for the Student class. It defines all the member variables and functions for a student
*/

#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

class Student{
public:
    int studentId;
    string studentName;
    string studentLevel; // (fresh, soph, etc.)
    string studentMajor;
    double studentGpa;
    int studentAdvisorId; // contains Faculty ID of student's advisor

    Student();
    Student(int ID, string name, string level, string major, double Gpa, int advisorId);
    ~Student();
    void print();
    int getStudentID();
    string getStudentName();
    string getStudentLevel();
    string getStudentMajor();
    double getStudentGpa();
    int getStudentAdvisorID();
    bool operator==(Student s);
    bool operator>(Student s);
    bool operator<(Student s);
    
};
#endif