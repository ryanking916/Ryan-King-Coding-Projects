/*
Ryan King
2385162
Ryanking@chapman.edu
CPSC-350-02
Programming Assignment 5: The GOAT
Description: This is the Menu method. It has all of the functions needed for the menu of our database. The functions are called based on the input given from the user.
*/

#include <iostream>
#include <string>
#include "Menu.h"
#include "ScapegoatST.h"
#include "TreeNode.h"
#include <array>
using namespace std;
// Default Constructor
Menu::Menu(){
    BST<Student> studentBST;
    BST<Faculty> facultyBST;
    DblList<int> studentList;
    DblList<int> facultyList;
}
// Destructor
Menu::~Menu(){
}

// This method prints all the students with their information. It is sorted by ascending ID #
void Menu::printAllStudents(){
    DblList<int> tempList;
    tempList = studentList;
    for(int i = 0; i < tempList.getSize(); i++){
        Student student = studentBST.find(tempList.get(i));
        student.print();
        cout << endl;
    }
    
}


// This method prints all the faculty members with their information. It is sorted by ascending ID #
void Menu::printAllFaculty(){
    DblList<int> tempList;
    tempList = facultyList;

    for(int i = 0; i < tempList.getSize(); i++){
        Faculty faculty = facultyBST.find(tempList.get(i));
        faculty.print();
        cout << endl;
    }
}

// This method finds a student, by a given ID, in the Scapegoat tree and prints that student's information
void Menu::searchOneStudent(){
    int studentId;
    cout << "Enter the student's ID: ";
    cin >> studentId;
    Student search = studentBST.find(studentId);
    if (search.getStudentID() == -1){
        cout << "Could not find student." << endl;
    }
    else{
        cout << "Student Found!" << endl;
        search.print();
    }
}

// This method finds a faculty member, by a given ID, in the Scapegoat tree and prints that faculty's information
void Menu::searchOneFaculty(){
    int facultyId;
    cout << "Enter the faculty's ID: ";
    cin >> facultyId;
    Faculty search = facultyBST.find(facultyId);
    if (search.getFacultyID() == -1){
        cout << "Could not find faculty member." << endl;
    }
    else{
        cout << "Faculty Found!" << endl;
        search.print();
    }
}

/* This method adds a new student to the Scapegoat tree. It asks the user to input all the information 
that is required to create a new student object. It creates that object then adds it to tree
*/
void Menu::addStudentToTree(){
    int m_studentId;
    string m_studentName;
    string m_studentLevel;
    string m_studentMajor1;
    string m_studentMajor2;
    string m_studentMajor;
    double m_studentGpa;
    int m_studentAdvisorId;
    cout << "Enter student's ID: ";
    cin >> m_studentId;
    cout << "Enter student's name: ";
    cin.ignore(); 
    getline(cin, m_studentName);
    //cin >> m_studentName;
    cout << "Enter student's grade level: ";
    cin >> m_studentLevel;
    cin.ignore();
    cout << "Enter student's major: "; 
    getline(cin, m_studentMajor);
    cout << "Enter student's GPA: ";
    cin >> m_studentGpa;
    cout << "Enter the student's advisor's ID: ";
    cin >> m_studentAdvisorId;
    //Student* newStudent(m_studentId, m_studentName, m_studentLevel, m_studentMajor, m_studentGpa, m_studentAdvisorId);
    Student newStudent(m_studentId, m_studentName, m_studentLevel, m_studentMajor, m_studentGpa, m_studentAdvisorId);
    studentBST.scapeGoatInsert(m_studentId, newStudent);
    //cout << "Size: " << studentBST.getSize() << endl;
    studentList.addFront(m_studentId);
    //cout << "The list size is: " << studentList.getSize() << endl;
}

// This method deletes a student from the Scapegoat tree. It asks the user to input the ID of the student they want to delete
void Menu::deleteStudentFromTree(){
    int studentId;
    cout << "Enter the ID of the student to delete: ";
    cin >> studentId;
    Student deletedStudent = studentBST.find(studentId);
    studentBST.remove(studentId);
    cout << "Student ID " << studentId << " has been deleted." << endl;
    studentList.remove(studentId);
}

// This method adds a new faculty member to the Scapegoat tree. It asks the user to input all the required information to create a new faculty member object.
void Menu::addFacultyToTree(){
    int m_facultyId;
    int count = 0;
    int studID = 1;
    string m_facultyName;
    string m_facultyLevel;
    string m_facultyDepartment;
    DblList<int> m_studentIdsList;
    
    cout << "Enter faculty member's ID: ";
    cin >> m_facultyId;
    cout << "Enter faculty member's name: ";
    cin.ignore();
    getline(cin, m_facultyName);
    //cin >> m_facultyName;
    cout << "Enter faculty member's level: ";
    cin >> m_facultyLevel;
    cout << "Enter faculty member's department: ";
    cin.ignore(); 
    getline(cin, m_facultyDepartment);
    //cin >> m_facultyDepartment;
    //m_studentIdsList = new DblList<int>();
    cout << "Enter faculty member's advisee's ID numbers (Enter 0 when finished inputting IDs): " << endl;;
    while(studID != 0){
        cout << "Student ID: ";
        cin >> studID;
        if (studID == 0){
            continue;
        }
        m_studentIdsList.addFront(studID);
        ++count;
    }
    Faculty newFaculty(m_facultyId, m_facultyName, m_facultyLevel, m_facultyDepartment, m_studentIdsList);
    facultyBST.scapeGoatInsert(m_facultyId, newFaculty);
    facultyList.addFront(m_facultyId);
}

// This method deletes a faculty member from the scapegoat tree. It asks the user to input the ID of the faculty member they want to delete then deletes that member
void Menu::deleteFacultyFromTree(){
    int facultyId;
    cout << "Enter the ID of the faculty member to delete: ";
    cin >> facultyId;
    Faculty deletedFaculty = facultyBST.find(facultyId);
    facultyBST.remove(facultyId);
    facultyList.remove(facultyId);
    cout << "Faculty member ID " << facultyId << " has been deleted." << endl;
}

// This method changes a student's advisor given the student's ID number and the new faculty/advisor ID number
void Menu::changeStudentAdvisor(){
    int newFacultyId;
    int studentId;
    cout << "Enter the student's ID: ";
    cin >> studentId;
    cout << "Enter the student's new advisor ID: ";
    cin >> newFacultyId;
    Student givenStudent = studentBST.find(studentId);
    int studentsPrevAdvisorID = givenStudent.getStudentAdvisorID();
    Faculty studentsNewAdvisor = facultyBST.find(newFacultyId);
    Faculty studentsOldAdvisor = facultyBST.find(studentsPrevAdvisorID);

    DblList<int> newAdviseeList = studentsNewAdvisor.getStudentIdList();
    newAdviseeList.addBack(studentId);
    newAdviseeList.print();
}

// This method removes an advisee from a faculty member given the ID numbers of the student and faculty member
void Menu::removeAdvisee(){
    int facultyId;
    int studentId;
    cout << "Enter the student/advisee ID to remove: ";
    cin >> studentId;
    cout << "Enter the ID of the student's faculty member: ";
    cin >> facultyId;
    Faculty advisor = facultyBST.find(facultyId);
    DblList<int> adviseelist = advisor.getStudentIdList();
    if (adviseelist.contains(studentId)){
        adviseelist.remove(studentId);
    }
    else{
        cout << "That is not an advisee of this faculty member." << endl;
    }
}

/* This method exits the program. It also calls method in the fileProcessor class to create
a file called runLog.txt. It will write the information of both the student table and the 
faculty table at the time the user wants to exit the program.
*/
void Menu::exitProgram(){
    FileProcessor f;
    f.createFile();
    f.writeHeaderInfo("Student Info:");
    DblList<int> tempListStud;
    tempListStud = studentList;
    for(int i = 0; i < tempListStud.getSize(); i++){
        Student student = studentBST.find(tempListStud.get(i));
        f.writeFileStudent(student);
    }

    f.writeHeaderInfo("\nFaculty Info:");
    DblList<int> tempListFaculty;
    tempListFaculty = facultyList;
    for(int i = 0; i < tempListFaculty.getSize(); i++){
        Faculty faculty = facultyBST.find(tempListFaculty.get(i));
        f.writeFileFaculty(faculty);
    }
}

/* This method displays the options to the user. The user enters input based on the option
they want to perform. It will then call a method based on the users input and perform that method.
Once the user chooses to exit the program will stop
*/
void Menu::userChoices(){
    string userInput;
    while (userInput != "11"){
        cout << "Select one: " << endl;
        cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
        cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
        cout << "3. Find and display student information given the students id" << endl;
        cout << "4. Find and display faculty information given the faculty id" << endl;
        cout << "5. Add a new student" << endl;
        cout << "6. Delete a student given the id" << endl;
        cout << "7. Add a new faculty member" << endl;
        cout << "8. Delete a faculty member given the id" << endl;
        cout << "9. Change a student's advisor given the student and the new faculty id" << endl;
        cout << "10. Remove an advisee from a faculty member given the ids" << endl;
        cout << "11. Exit" << endl;
        cin >> userInput;
        if(userInput == "1"){
            printAllStudents();
        }
        else if(userInput == "2"){
            printAllFaculty();
        }
        else if(userInput == "3"){
            searchOneStudent();
        }
        else if(userInput == "4"){
            searchOneFaculty();
        }
        else if(userInput == "5"){
            addStudentToTree();
        }
        else if(userInput == "6"){
            deleteStudentFromTree();
        }
        else if(userInput == "7"){
            addFacultyToTree();
        }
        else if(userInput == "8"){
            deleteFacultyFromTree();
        }
        else if(userInput == "9"){
            changeStudentAdvisor();
        }
        else if(userInput == "10"){
            removeAdvisee();
        }
        else if(userInput == "11"){
            exitProgram();
        }
        else{
            cout << "Please enter a number corresponding with the option:" << endl;
            userChoices();
        }
    }
}