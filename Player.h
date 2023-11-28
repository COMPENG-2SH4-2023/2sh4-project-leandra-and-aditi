#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* food); // updated to hold food reference as well
        ~Player(); // destructor

        objPosArrayList* getPlayerPos(); // upgraded for snake body
        void updatePlayerDir();
        void movePlayer();

    private:
    
        objPosArrayList *playerPosList;   // Upgraded in iteration 3 for snake body      
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;

        // Need a reference to Food for iteration 3
        Food* mainFoodRef;

        int** myPlayer; // heap data member
};

#endif