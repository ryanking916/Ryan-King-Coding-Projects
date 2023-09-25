/*
Ryan King
2385162
Ryanking@chapman.edu
CPSC-350-02
Programming Assignment 2: Not So Super Mario Bros
Description: Class FileProcessor is used to write to a file given by input and 
read a file that is given by input
*/

#include "FileProcessor.h"
#include "Mario.h"
#include "Level.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

//default constructor
FileProcessor::FileProcessor(){
        int fileArray[8];
} 
//default destructor
FileProcessor::~FileProcessor(){
} 

// This function writes a given string to a given file
void FileProcessor::processFile(string textFile, string outPutOfMario){
        std::ofstream outfile (textFile);
        outfile << outPutOfMario << endl;
        outfile.close();
}

// This function reads a given read
void FileProcessor::readFile(string fileName){
    //int fileArray[8]; 
    int count = 0;
    int x;
    ifstream file(fileName); 
    if (file.is_open()) 
    {
        while (file >> x){
            fileArray[count] = x;
            //cout << x << endl;
            ++count;
        }
        file.close(); 
    }
    else{
        cout << "Error! Can't open the file" << endl; 
    } 
    
}

// This function returns an index value of the fileArray that is given as a parameter
int FileProcessor::getArrayValue(int a, string fileName){
    readFile(fileName);
    return fileArray[a];
}