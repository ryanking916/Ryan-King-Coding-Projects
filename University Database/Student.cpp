/*
Ryan King
2385162
Ryanking@chapman.edu
CPSC-350-02
Programming Assignment 5: The GOAT
Description: This is the Student class. This contains all the necessary functions to create a student and get their information
*/
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

// Default Constructor
Student::Student(){
    studentId = -1;
    studentName = "Name";
    studentLevel = "Freshman"; // (fresh, soph, etc.)
    studentMajor = "Undeclared";
    studentGpa = 0.0;
    studentAdvisorId = -1;
}

//Overloaded Constructor
Student::Student(int ID, string name, string level, string major, double Gpa, int advisorId){
    studentId = ID;
    studentName = name;
    studentLevel = level;
    studentMajor = major;
    studentGpa = Gpa;
    studentAdvisorId = advisorId;
}

// Destructor
Student::~Student(){

}

void Student::print(){
    cout << "Student ID: " << studentId << endl;
    cout << "Name: " << studentName << endl;
    cout << "Class Level: " << studentLevel << endl;
    cout << "Major: " << studentMajor << endl;
    cout << "GPA: " << studentGpa << endl;
    cout << "Student Advisor ID: " << studentAdvisorId << endl;

}

// This method returns the students ID number
int Student::getStudentID(){
    return studentId;
}

// This method returns the students name
string Student::getStudentName(){
    return studentName;
}

// This method returns the students class level
string Student::getStudentLevel(){
    return studentLevel;
}

// This method returns the students major
string Student::getStudentMajor(){
    return studentMajor;
}

// This method returns the students GPA
double Student::getStudentGpa(){
    return studentGpa;
}

// This method returns the student's advisor ID number
int Student::getStudentAdvisorID(){
    return studentAdvisorId;
}

// This method is the overload equality operator. It returns a boolean based on if two given student ID's are equal to each other.
bool Student::operator==(Student s){
    return(this->studentId == s.getStudentID());
}

// This method is the overload greater than operator. It returns boolean based on if student 1's ID number is greater than student 2's.
bool Student::operator>(Student s){
    return(this->studentId > s.getStudentID());
}
// This method is the overload less than operator. It returns a boolean based on if student 1's ID number is less than student 2's.
bool Student::operator<(Student s){
    return(this->studentId < s.getStudentID());
}

