/*
Ryan King
2385162
Ryanking@chapman.edu
CPSC-350-02
Programming Assignment 5: The GOAT
Description: This is the header file for the Menu class. It defines the member variables and functions needed.
*/

#ifndef MENU_H
#define MENU_H
#include <string>
#include "Student.h"
#include "ScapegoatST.h"
#include "Faculty.h"
#include "TreeNode.h"
#include "DblList.h"
#include "FileProcessor.h"
using namespace std;

class Menu{
public:
    Menu();
    ~Menu();
    BST<Student> studentBST;
    BST<Faculty> facultyBST;
    DblList<int> studentList;
    DblList<int> facultyList;
    void printAllStudents();
    void printAllFaculty();
    void searchOneStudent();
    void searchOneFaculty();
    void addStudentToTree(); // ScapegoatST<Student> treeS
    void deleteStudentFromTree();
    void addFacultyToTree();
    void deleteFacultyFromTree();
    void changeStudentAdvisor();
    void removeAdvisee();
    void exitProgram();
    void userChoices();
private: 

};
#endif