#ifndef FOOD_H
#define FOOD_H

#include <cstdlib> //provides srand() and rand()
#include <time.h> //provides time

#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h" 

using namespace std;


class Food
{
    public:
        Food(GameMechs* thisGMRef);
        ~Food(); // destructor

        void generateFood(objPosArrayList* blockList); // upgraded in iteration 3
                                                       // generates "food" and checks does not overlap with
                                                       // player pos
                                                       
        void getFoodPos(objPos &returnPos);


    private:
    
        objPos foodPos; 
        
        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
    
        int **food; //heap data
    
};


#endif