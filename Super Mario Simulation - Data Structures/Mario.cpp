/*
Ryan King
2385162
Ryanking@chapman.edu
CPSC-350-02
Programming Assignment 2: Not So Super Mario Bros
Description: Class Mario is used to keep track of the numerical values needed for our game.
It contains function that output what mario has done each move, check mario lives, coins, and powerlevel.
*/

#include "Mario.h"
#include "Level.h"
#include "FileProcessor.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//default constructor
Mario::Mario(){} 
int enemiesDefeated = 0;
string actionName;
int numberOfMoves = 0;
bool isAlive = true;

// overload constructor
Mario::Mario(int V, int coins, string powerLevel, string outputFileName){
    lives = V;
    numCoins = coins;
    pL = powerLevel;
    std::ofstream outfile (outputFileName);
}
//destructor
Mario::~Mario(){} 

// This function returns an int value of marios lives
int Mario::getLives(){
    return lives;
}
// This function decreases a life of marios total
void Mario::loseLife(){
    lives = lives - 1;
    log += "Mario loses a life\n";
}
// This function adds a life to marios total
void Mario::addLife(){
    lives = lives + 1;
    log += "Mario adds a life\n";
}
// This function returns an int value of the number of coins mario has
int Mario::getCoins(){
    return numCoins;
}
// This function adds a coin to marios total
void Mario::addCoin(){
    numCoins = numCoins + 1;
    log += "Mario adds a coin\n";
}
// This function resets marios coin total to 0
void Mario::resetCoins(){
    numCoins = 0;
    log += "Mario's amount of coins gets reset\n";
}
// This function returns a string value of marios power level
string Mario::getPowerLevel(){
    return pL;
}
// This function increases marios power level
void Mario::increasePowerLevel(){
    if (pL == "PL0"){
        pL = "PL1";
    }else if (pL == "PL1"){
        pL = "PL2";
    }
}
// This function decreases marios power level
void Mario::decreasePowerLevel(){
    if (pL == "PL1"){
        pL = "PL0";
    }else if (pL == "PL2"){
        pL = "PL1";
    }
}
// This function adds an enemy to marios total enemies defeated
void Mario::addEnemyDefeated(){
    if (enemiesDefeated < 6){
        enemiesDefeated += 1;
        }
    else{
        addLife();
        resetEnemiesDefeated();
    }
}
// This function resets marios enemies defeated
void Mario::resetEnemiesDefeated(){
    enemiesDefeated = 0;
}
// This function returns an int value of marios enemies defeated
int Mario::getEnemiesDefeated(){
    return enemiesDefeated;
}
// This function checks if mario is still alive and returns a bool based on that
bool Mario::isMarioAlive(){
    if (getLives() != 0){
        return true;
    }
    return false;
}
// This function kills mario
bool Mario::killMario(){
    isAlive = false;
}
// This function returns a string value of our log
string Mario::dumpLog(){
    return log;
}
// This function deletes the log
void Mario::deleteLog(){
    log = "\n";
}
// This function returns information based on which char mario is interacting with
void Mario::marioDoingThingsFromLevel(char key){
    if (key == 'm'){
        actionName = "Mario ate a mushroom";
        increasePowerLevel();
        numberOfMoves = numberOfMoves + 1;
    }
    else if (key == 'c'){
        if (numCoins < 19){
            addCoin();
            actionName = "Mario collected a coin";
            numberOfMoves = numberOfMoves + 1;
        }
        else {
            actionName = "Mario collected a coin";
            addLife();
            resetEnemiesDefeated();
            resetCoins();
            numberOfMoves = numberOfMoves + 1;
        }
    }
    else if (key == 'g'){
        bool goombaAlive = true;
        while (goombaAlive == true){
            int rand_num_goopa = rand() % 99;
            if(rand_num_goopa <= 79){ //mario wins
                addEnemyDefeated();
                goombaAlive = false;
                actionName = "Mario fought a koopa and won";
                numberOfMoves = numberOfMoves + 1;
            }
            else if (getPowerLevel() != "PL0"){
                decreasePowerLevel();
                goombaAlive = true;
                actionName = "Mario fought a goomba and lost";
                numberOfMoves = numberOfMoves + 1;
            }
            else if (getPowerLevel() == "PL0"){
                if (getLives() > 1){
                    loseLife();
                    resetEnemiesDefeated();
                    goombaAlive = true;
                    actionName = "Mario fought a goomba and lost";
                    numberOfMoves = numberOfMoves + 1;
                }
                else{
                    loseLife();
                    
                    actionName = "Mario fought a goomba and lost";
                    numberOfMoves = numberOfMoves + 1;
                    break;
                }
            }
        }
    }
    else if (key == 'k'){
        bool koopaAlive = true;
        while (koopaAlive == true){
            int rand_num_koopa = rand() % 99;
            if(rand_num_koopa <= 64){ //mario wins
                addEnemyDefeated();
                koopaAlive = false;
                actionName = "Mario fought a koopa and won";
                numberOfMoves = numberOfMoves + 1;
            }
            else if (getPowerLevel() != "PL0"){
                decreasePowerLevel();
                koopaAlive = true;
                //cout << "Mario loses to koopa" << endl;
                actionName = "Mario fought a koopa and lost";
                numberOfMoves = numberOfMoves + 1;
            }
            else if (getPowerLevel() == "PL0"){
                if (getLives() > 1){
                    loseLife();
                    resetEnemiesDefeated();
                    koopaAlive = true;
                    actionName = "Mario fought a koopa and lost";
                    numberOfMoves = numberOfMoves + 1;
                }
                else{
                    loseLife();
                    actionName = "Mario fought a koopa and lost";
                    numberOfMoves = numberOfMoves + 1;
                    break;
                }
            }
        }
    }
    else if (key == 'b'){
        bool isBossAlive = true;
        while (isBossAlive == true){
            int rand_num_boss = rand() % 99;
            if(rand_num_boss <= 49){ //mario wins
                addEnemyDefeated();
                isBossAlive = false;
                actionName = "Mario fought the level boss and won";
                numberOfMoves = numberOfMoves + 1;
            }
            else if (getPowerLevel() != "PL0"){
                decreasePowerLevel();
                isBossAlive = true;
                actionName = "Mario fought the level boss and lost";
                numberOfMoves = numberOfMoves + 1;
            }
            else if (getPowerLevel() == "PL0"){
                if (getLives() > 1){
                    loseLife();
                    resetEnemiesDefeated();
                    isBossAlive = true;
                    actionName = "Mario fought the level boss and lost";
                    numberOfMoves = numberOfMoves + 1;
                }
                else{
                    loseLife();
                    actionName = "Mario fought the level boss and lost";
                    numberOfMoves = numberOfMoves + 1;
                    break;
                }
            }
        }
    }
    else if (key == 'w'){
        actionName = "Mario warped";
        numberOfMoves = numberOfMoves + 1;
    }
    else if (key == 'x'){
        actionName = "The position is empty";
        log += "Empty Position\n";
        numberOfMoves = numberOfMoves + 1;
    }
}
// This function returns a string value of the action mario has taken
string Mario::getAction(){
    return actionName;
}
// This function gives a summary of the move mario makes. It is used to add to the output file
string Mario::collectMarioMoveLine(int level, string position, string currentPL, string action, int livesAfterInteraction, int coinsAfterInteraction){
    return "Level number: " + to_string(level) + ", " + position + ", " + "Power Level before interaction: " + currentPL + ", " + action + ", Lives after interaction: " + to_string(livesAfterInteraction) + ", Coins after interaction: " + to_string(coinsAfterInteraction);
}




