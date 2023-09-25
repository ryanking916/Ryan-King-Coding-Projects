/*
Ryan King
2385162
Ryanking@chapman.edu
CPSC-350-02
Programming Assignment 2:
Description: This is the header file for the Level class where we defined
public methods and variables to use
*/

#ifndef LEVEL_H 
#define LEVEL_H
#include "Mario.h"
#include <string>
using namespace std;

class Level{
    public: 
        char** arr2D;
        int rand_num;
        int rand_numMarioMove;
        int rand_num_marioR;
        int rand_num_MarioC;
        int rand_num_bossR;
        int rand_num_bossC;
        int rand_num_warpR;
        int rand_num_warpC;
        char mover;

        virtual ~Level(); 
        Level();
        Level(int row, int column);
        char getIndex(int row, int column);
        void createLevelGrid(int row, int column, int p_coin, int p_nothing, int p_goomba, int p_koopa, int p_mushroom);
        void printArray(int row, int column);
        string getArrayAsString(int row, int column);
        string getPositionMario(int rows, int columns);
        void getPositionBoss(int rows, int columns);
        char moveMario(int rows, int columns);
        char marioInteract(int row, int column);
        bool isBossThere(int rows, int columns);
        bool isWarpPipeThere(int rows, int columns);
        void doOneLevel(int rows, int columns);
        void initialize(int row, int column);
    private:
};

#endif
