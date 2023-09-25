/*
Ryan King
2385162
Ryanking@chapman.edu
CPSC-350-02
Programming Assignment 2: Not So Super Mario Bros
Description: This is the header file for the FileProcessor class where we defined
public functions and private member variables
*/

#ifndef FILEPROCESSER_H //header guard
#define FILEPROCESSER_H

#include <string>
using namespace std;

class FileProcessor{
    public:
        FileProcessor(); //default constructor
        virtual ~FileProcessor(); //destructor
        void processFile(string textFile, string outPutOfMario); //file processor method
        void readFile(string fileName);
        int getArrayValue(int a, string fileName);
    private:
        int fileArray[8];

    

};

#endif