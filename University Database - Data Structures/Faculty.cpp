/*
Ryan King
2385162
Ryanking@chapman.edu
CPSC-350-02
Programming Assignment 5: The GOAT
Description: This is the Faculty class. It contains all the variables and methods needed to create a faculty member.
*/

#include "Faculty.h"
#include <iostream>
#include <string>

using namespace std;

// Default Constructor
Faculty::Faculty(){
    facultyId = -1;
    facultyName = "Name";
    facultyLevel = "None";
    facultyDepartment = "None";
    
    
}

// Overloaded Constructor
Faculty::Faculty(int ID, string name, string level, string department, DblList<int> studentIds){
    facultyId = ID;
    facultyName = name;
    facultyLevel = level;
    facultyDepartment = department;
    studentIdsList = studentIds;

}

// Destructor
Faculty::~Faculty(){

}

// This method prints all the information of a faculty member
void Faculty::print(){
    cout << "ID: " << facultyId << endl;
    cout << "Name: " << facultyName << endl;
    cout << "Faculty Level: " << facultyLevel << endl;
    cout << "Faculty Department: " << facultyDepartment << endl;
    cout << "Faculty Advisee IDs listed below: " << endl;;
    studentIdsList.print();

}

// This method returns the faculty members ID number
int Faculty::getFacultyID(){
    return facultyId;
}

// This method returns the faculty members name
string Faculty::getFacultyName(){
    return facultyName;
}

// This method returns the faculty members level
string Faculty::getFacultyLevel(){
    return facultyLevel;
}

// This method returns the name of the department the faculty member works in
string Faculty::getFacultyDepartment(){
    return facultyDepartment;
}

// This method returns the Advisors list of student Ids.
DblList<int> Faculty::getStudentIdList(){
    return studentIdsList;
}

// This method is the overload equality operator. It returns a boolean based on if two given faculty ID's are equal to each other.
bool operator==(Faculty f1, Faculty f2){
    return(f1.getFacultyID() == f2.getFacultyID());
}

// This method is the overload greater than operator. It returns boolean based on if faculty 1's ID number is greater than faculty 2's.
bool operator>(Faculty f1, Faculty f2){
    return(f1.getFacultyID() > f2.getFacultyID());
}

// This method is the overload less than operator. It returns a boolean based on if faculty 1's ID number is less than faculty 2's.
bool operator<(Faculty f1, Faculty f2){
    return(f1.getFacultyID() < f2.getFacultyID());
}