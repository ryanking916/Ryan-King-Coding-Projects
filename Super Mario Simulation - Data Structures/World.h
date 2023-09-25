/*
Ryan King
2385162
Ryanking@chapman.edu
CPSC-350-02
Programming Assignment 2: Not So Super Mario Bros
Description: This is the header file for the World class
*/

#ifndef WORLD_H //header guard
#define WORLD_H

#include <string>
using namespace std;

class World{
    public:
        World(); //default constructor
        World(int levels); //overloaded constructor with number of levels provided at runtime
        virtual ~World(); //default destructor
        void moveMarioOneLevel();
        bool isGameLost();
    private:
        int levels; //member variable
};

#endif