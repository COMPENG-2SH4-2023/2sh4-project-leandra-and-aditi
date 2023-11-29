#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* food); // updated to hold food reference as well
                                                  // need food reference in move player
                                                  // to check if snake eats food so we can increase length
        ~Player(); // destructor

        objPosArrayList* getPlayerPos(); // upgraded for snake body

        bool CheckSelfCollision(); // head and body are same position = collision -- end game

        void updatePlayerDir();

        void movePlayer(); // implementing wraparound logic,
                           // food collision checking and increasing length,
                           // general "snake" like movement

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