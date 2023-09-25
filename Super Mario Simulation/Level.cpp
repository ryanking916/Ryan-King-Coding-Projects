/*
Ryan King
2385162
Ryanking@chapman.edu
CPSC-350-02
Programming Assignment 2: Not So Super Mario Bros
Description: Class Level is used to create the level array grid, find certain 
positions on the grid and move our mario char.
*/

#include "Level.h"
#include "Mario.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

 //default constructor
Level::Level(){}

//overload constructor
Level::Level(int row, int column){
    arr2D = new char*[row];
    for(int i = 0; i < row; i++){
        arr2D[i] = new char[column]; 
    }
}

//destructor. It destroys our array object we create
Level::~Level(){ 
    delete[] arr2D;
} 

// function is used to intiliaze our array
void Level::initialize(int row, int column){ 
    arr2D = new char*[row];
    for(int i = 0; i < row; i++){
        arr2D[i] = new char[column]; 
    }
}

/*This function is used to create our random grid where we plot the chars and then
take a percent input from user and plot chars based on that number*/
void Level::createLevelGrid(int row, int column, int p_coin, int p_nothing, int p_goomba, int p_koopa, int p_mushroom){
    //srand((unsigned int)time(NULL));
    int x = rand() % row; // randomly giving x and y values to our Mario char, boss char, and warpipe char
    int y = rand() % column;
    int x1 = rand() % row;
    int y1 = rand() % column;
    int x2 = rand() % row;
    int y2 = rand() % column;

    while(x == x1 && y == y1){
        x1 = rand() % row;
        y1 = rand() % column;
    }
    while((x1 == x2 && y1 == y2) || (x == x2 && y == y2)){
        x2 = rand() % row;
        y2 = rand() % column;
    }
    
    arr2D[x][y] = 'H'; // assigning our chars to random positions
    arr2D[x1][y1] = 'b';
    arr2D[x2][y2] = 'w';
    
    
    for (int i = 0; i < row; i++){ // Nested for loop to randomly create array
        for (int j = 0; j < column; j++){  
            //srand((unsigned int)time(NULL));
            if (arr2D[i][j] == 'b' || arr2D[i][j] == 'H' || arr2D[i][j] == 'w'){
                arr2D[i][j] = arr2D[i][j];
            }
            else{
                
                rand_num = rand() % 100;
                if (rand_num >= 0 && rand_num < p_nothing){
                    arr2D[i][j] = 'x'; // x represents nothing
                }
                else if (rand_num >= p_nothing && rand_num < p_nothing + p_mushroom){
                    arr2D[i][j] = 'm'; // m represents mushroom
                }
                else if (rand_num >= p_nothing + p_mushroom && rand_num < p_nothing + p_mushroom + p_coin){
                    arr2D[i][j] = 'c'; // c represents coins
                }
                else if (rand_num >= p_nothing + p_mushroom + p_coin && rand_num < p_nothing + p_mushroom + p_coin + p_goomba){
                    arr2D[i][j] = 'g'; // g represents a Goomba
                }
                else if (rand_num >= p_nothing + p_mushroom + p_coin + p_goomba && rand_num <= p_nothing + p_mushroom + p_coin + p_goomba + p_koopa){
                    arr2D[i][j] = 'k'; // k represents a Koopa Troopa
                }
            }
        }

    }
}

// This function is to print our created array
void Level::printArray(int row, int column){
    for (int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            cout << arr2D[i][j] << ' ';
        }
        cout << "\n";
    }
}

// This function turns our array into a string we can later add to the output file. It returns a string value
string Level::getArrayAsString(int row, int column){
    string arrayAsString = "";
    for (int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            arrayAsString.append(to_string(arr2D[i][j]) + ' ');
        }
        arrayAsString.append("\n");
    }
    return arrayAsString;
}

// This function gets Marios position in the array
string Level::getPositionMario(int rows, int columns){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if (arr2D[i][j] == 'H'){
                return  "Position: " + to_string(i) + " " + to_string(j);
            }
        }
    }
}

// This function gets the bosses array in the position
void Level::getPositionBoss(int rows, int columns){
     for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if (arr2D[i][j] == 'b'){
                cout << i << " " << j << endl;
            }
        }
    }
}
// This function is used to move mario along the grid.
char Level::moveMario(int rows, int columns){ //we randomly move mario
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            rand_numMarioMove = rand() % 8;
            if (arr2D[i][j] == 'H'){
                if (rand_numMarioMove == 0 || rand_numMarioMove == 1){
                arr2D[i][j] = 'x';
                if(j == columns - 1){
                        j = 0;
                    }
                    else{
                        j = j + 1;
                    }
                mover = marioInteract(i, j); //assigning mover with the char marioInteract returns
                isBossThere(rows, columns); // checking for boss
                isWarpPipeThere(rows, columns); // checking for warppipe
                arr2D[i][j] = 'H';
                return mover; // returning assigned char
                }
                else if (rand_numMarioMove == 2 || rand_numMarioMove == 3){
                    arr2D[i][j] = 'x';
                    if(j == 0){
                        j = columns - 1;
                    }
                    else{
                        j = j - 1;
                    }
                    mover = marioInteract(i, j); 
                    isBossThere(rows, columns);
                    isWarpPipeThere(rows, columns);
                    arr2D[i][j] = 'H';
                    return mover;
                }
                else if (rand_numMarioMove == 4 || rand_numMarioMove == 5){
                    arr2D[i][j] = 'x';
                    if(i == rows - 1){
                        i = 0;
                    }
                    else{
                        i = i + 1;
                    }
                    mover = marioInteract(i, j);
                    isBossThere(rows, columns);
                    isWarpPipeThere(rows, columns);
                    arr2D[i][j] = 'H';
                    return mover;
                }
                else if (rand_numMarioMove == 6 || rand_numMarioMove == 7){
                    arr2D[i][j] = 'x';
                    if(i == 0){
                        i = rows - 1;
                    }
                    else{
                        i = i - 1;
                    }
                    mover = marioInteract(i, j);
                    isBossThere(rows, columns);
                    isWarpPipeThere(rows, columns);
                    arr2D[i][j] = 'H';
                    return mover;
                }
            }
        }
    }
}


// This function returns the char of what mario interacts with when he moves along grid.
char Level::marioInteract(int row, int column){
    if (arr2D[row][column] == 'm'){ //encounter with mushroom
        return 'm';
    }
    else if (arr2D[row][column] == 'c'){ //coin encounter with mario
        return 'c';
    }
    else if (arr2D[row][column] == 'g'){ //goomba encounter with mario
        return 'g';
    }
    else if (arr2D[row][column] == 'k'){ //koopa troopa encounter with mario
        return 'k';
    }
    else if (arr2D[row][column] == 'B'){ //boss encounter
        return 'B';
    }
    else if (arr2D[row][column] == 'W'){ //warp pipe encounter
        return 'W';
    }
    else if (arr2D[row][column] == 'x'){
        return 'x';
    }
}

// This function checks if the boss is still in the grid and returns a boolean value
bool Level::isBossThere(int rows, int columns){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if (arr2D[i][j] == 'b'){
                return true;
            }
        }
    }
    return false;
}

// This function checks if the warppipe is still in the grid and returns a boolean value
bool Level::isWarpPipeThere(int rows, int columns){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if (arr2D[i][j] == 'w'){
                return true;
            }
        }
    }
    return false;
}

// This function continues to do level if boss is there
void Level::doOneLevel(int rows, int columns){
    while (isBossThere(rows, columns) == true){
        moveMario(rows, columns);
        //return mover;
    }
}

// This function gets an index value in the array and returns that value
char Level::getIndex(int row, int column){
    return arr2D[row][column];
}



