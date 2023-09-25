/*
Ryan King
2385162
Ryanking@chapman.edu
CPSC-350-02
Programming Assignment 5: The GOAT
Description: This is the FileProcessor class. It contains functions that help create a file, and write to a file.
*/
#include "FileProcessor.h"
using namespace std;

// Default constructor
FileProcessor::FileProcessor(){
}

// Destructor
FileProcessor::~FileProcessor(){
}

// This method creates a file then closes it.
void FileProcessor::createFile(){
    ofstream outputFile("runLog.txt");
    outputFile.close();
}

// This method writes header info to the file
void FileProcessor::writeHeaderInfo(string header){
    ofstream outputFile("runLog.txt", ofstream::out | ofstream::app); // Used to append to file
    if(outputFile.is_open()){
        outputFile << header << "\n";
    }
}

// This method writes all of a students info to a file
void FileProcessor::writeFileStudent(Student student){
    
    ofstream outputFile("runLog.txt", ofstream::out | ofstream::app);
    if(outputFile.is_open()){
        outputFile << "\nStudent ID: " << student.getStudentID() << "\n";
        outputFile << "Name: " << student.getStudentName() << "\n";
        outputFile << "Class Level: " << student.getStudentLevel() << "\n";
        outputFile << "Major: " << student.getStudentMajor() << "\n";
        outputFile << "GPA: " << student.getStudentGpa() << "\n";
        outputFile << "Student Advisor ID: " << student.getStudentAdvisorID() << "\n";
        
    }
    outputFile.close();
}

// This method writes all of a faculty members info to the file.
void FileProcessor::writeFileFaculty(Faculty faculty){
    ofstream outputFile("runLog.txt", ofstream::out | ofstream::app);
    if(outputFile.is_open()){
        outputFile << "\nFaculty ID: " << faculty.getFacultyID() << "\n";
        outputFile << "Name: " << faculty.getFacultyName() << "\n";
        outputFile << "Faculty Level: " << faculty.getFacultyLevel() << "\n";
        outputFile << "Faculty Department: " << faculty.getFacultyDepartment() << "\n";
        outputFile << "Faculty Advisee IDs: " << "\n";
        DblList<int> adviseelist = faculty.getStudentIdList();
        while(adviseelist.getSize() != 0){
            outputFile << adviseelist.removeFront() << "\n";
        }
    }
    outputFile.close();
}