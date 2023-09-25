/*
Ryan King
2385162
Ryanking@chapman.edu
CPSC-350-02
Programming Assignment 5: The GOAT
Description: This is the main class. It creates an object of Menu then runs the function userChoices.
*/

#include "ScapegoatST.h"
#include "Menu.h"
using namespace std;
int main(){
    BST<int> newBST;
    Menu m;
    
    m.userChoices();

    return 0;
}