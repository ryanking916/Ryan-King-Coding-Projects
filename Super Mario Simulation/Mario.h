/*
Ryan King
2385162
Ryanking@chapman.edu
CPSC-350-02
Programming Assignment 2: Not So Super Mario Bros
Description: This is a header file for the Mario class where we defined 
public member variables and functions to use in our program
*/

#ifndef MARIO_H 
#define MARIO_H

#include <string>
using namespace std;

class Mario{
    public:
        Mario(); 
        Mario(int V, int coins, string powerLevel, string outputFileName); 
        virtual ~Mario(); 
        int enemiesDefeated;
        bool isAlive;
        int rand_num;
        int numCoins;
        int lives;
        int numberOfMoves;
        string pL;
        string log;
        string outputFileName;
        string actionName;
        string dumpLog();
        void deleteLog();
        void resetEnemiesDefeated();
        int getEnemiesDefeated();
        void addEnemyDefeated();
        int getLives();  //accessor
        void loseLife(); //mutator
        void addLife(); //mutator
        int getCoins(); //accessor
        void addCoin(); //mutator
        void resetCoins(); //mutator
        string getPowerLevel(); //accessor
        void increasePowerLevel(); //mutator
        void decreasePowerLevel(); //mutator
        void marioDoingThingsFromLevel(char key); 
        string collectMarioMoveLine(int level, string position, string currentPL, string action, int livesAfterInteraction, int coinsAfterInteraction);
        string getAction();
        bool isMarioAlive();
        bool killMario();
        void getPosition();
    private:
};

#endif