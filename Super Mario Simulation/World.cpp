/*
Ryan King
2385162
Ryanking@chapman.edu
CPSC-350-02
Programming Assignment 2: Not So Super Mario Bros
Description: This is the World class. We did not end up using this class in or program but used it 
as inspiration in other classes
*/

#include "World.h"

World::World(){} //default constructor

World::World(int levels){ //overloaded constructor
    levels = levels;
}

World::~World(){} //default destructor

void World::moveMarioOneLevel(){}; //method to move mario to next level

bool World::isGameLost(){
    return false;
}
