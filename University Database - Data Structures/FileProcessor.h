/*
Ryan King
2385162
Ryanking@chapman.edu
CPSC-350-02
Programming Assignment 5: The GOAT
Description: This is the header file for the FileProcessor class. It defines the methods needed for the class.
*/

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H
#include <fstream>
#include <iostream>
#include <string>
#include "Student.h"
#include "Faculty.h"
#include "ScapegoatST.h"

class FileProcessor{
public:
    FileProcessor();
    ~FileProcessor();
    void createFile();
    void printStudentInfo();
    void printFacultyInfo();
    void writeHeaderInfo(string header);
    void writeFileStudent(Student student);
    void writeFileFaculty(Faculty faculty);
private:

};
#endif