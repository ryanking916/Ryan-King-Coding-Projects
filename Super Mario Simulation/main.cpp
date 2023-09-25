/*
Ryan King
2385162
Ryanking@chapman.edu
CPSC-350-02
Programming Assignment 2: Not So Super Mario Bros
Description: This is the main class where the game is created and played. The program takes
two command line argument file names and uses those to produce the output file.
*/

#include "Mario.h"
#include "Level.h"
#include "FileProcessor.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
    FileProcessor r; // Creating FileProcessor object to use functions defined in that class
    int LEVELS = r.getArrayValue(0, argv[1]); // creating variables of the given data in input file
    int m_row = r.getArrayValue(1, argv[1]);
    int m_col =r.getArrayValue(1,argv[1]);
    int LIVES = r.getArrayValue(2,argv[1]);
    int coin_percentage = r.getArrayValue(3,argv[1]);
    int nothing_percentage = r.getArrayValue(4,argv[1]);
    int goomba_percentage = r.getArrayValue(5,argv[1]);
    int koopa_percentage = r.getArrayValue(6,argv[1]);
    int mushroom_percentage = r.getArrayValue(7,argv[1]);
    int moveCountStore = 0;

    ofstream outfile (argv[2]); 
    Level world[LEVELS]; // creating level and mario objects
    Mario mario1(LIVES, 0, "PL0", argv[2]);
    outfile << "Welcome to Not So Super Mario Bros!\n";
    for (int i = 0; i < LEVELS; i++){
        world[i].initialize(m_row, m_col); //initialize grid
        world[i].createLevelGrid(m_row, m_col, coin_percentage, nothing_percentage, goomba_percentage, koopa_percentage, mushroom_percentage); // populating grid

        while (world[i].isBossThere(m_row, m_col) == true && world[i].isWarpPipeThere(m_row, m_col) == true && mario1.isMarioAlive() == true){ // Checking for boss and warppipe, also seeing is mario is still alive
            mario1.marioDoingThingsFromLevel(world[i].moveMario(m_row, m_col)); // Having mario move and interact with environment
            moveCountStore = moveCountStore + 1; // Keeping track of total moves
            int marioAfterLives = mario1.getLives(); // getting the lives amount
            int marioAfterCoins = mario1.getCoins(); // getting the coins amount
            if (mario1.isMarioAlive() == true){ 
                string currentPosition = world[i].getPositionMario(m_row, m_col); // getting marios current position
                outfile << mario1.collectMarioMoveLine(i, currentPosition, mario1.getPowerLevel(), mario1.actionName, marioAfterLives, marioAfterCoins) << endl; // writing summary of move to the output file
                for (int l = 0; l < m_row; l++){ // writing our grid to output file
                    for (int j = 0; j < m_col; j++){
                        outfile << world[i].arr2D[l][j] << ' ';
                    }
                    outfile << "\n";
                }
                outfile << "\n";
            }
            else if (mario1.isMarioAlive() == false){ // If mario is dead do this
                string currentPositionOfBoi = world[i].getPositionMario(m_row, m_col);
                outfile << mario1.collectMarioMoveLine(i, currentPositionOfBoi, mario1.getPowerLevel(), mario1.actionName, marioAfterLives, marioAfterCoins) << endl; // giving summary of how mario died
                outfile << "Mario lost the game :( Number of moves: ";
                outfile << moveCountStore; //outputting our total amount of moves
                outfile << "\n";
                break; // ending/breaking program
            }
            
        }
    }
    
    if (mario1.isMarioAlive() == true){ // If mario has won
            outfile << mario1.actionName; // write to file how he won
            outfile << "\n";
            outfile << "Mario Won the game!! Number of moves: ";
            outfile << moveCountStore; // output total amount of moves
            outfile << "\n";
        }
    
    return 0;
}